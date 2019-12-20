#include <iostream>
#include <fstream>

using namespace std;
//
//      create polinom
//
void input_polinom(int polinom[100][4])
{
    ifstream in;
    in.open("input.txt");
//    cout << "g[0][0] = ";
    in >> polinom[0][0];
    polinom[0][0]++;
    for(int i = 1; i < polinom[0][0]; i++)
    {
        for(int j = 0; j < 4; j++)
        {
//            cout << "g[" << i << "][" << j << "] = ";
            in >> polinom[i][j];
        }
    }
    in.close();
}
//
//      output polinom
//
void output_polinom(int polinom[10][100][4])
{
    for( int num = 1; num <= polinom[0][0][0]; num++)
    {
        cout << endl << "g" << num << " = ";
        for(int i = 1; i < polinom[num][0][0]; i++)
        {
            if(polinom[num][i][0] > 1)
            {
                cout <<"+";
            }
            cout << polinom[num][i][0];

            if(polinom[num][i][1] != 0)
                cout << "X^" << polinom[num][i][1];

            if(polinom[num][i][2] != 0)
                cout << "Y^" << polinom[num][i][2];

            if(polinom[num][i][3] != 0)
                cout << "Z^" << polinom[num][i][3];
        }
        cout << endl;
    }
}
//
//      output senior member
//
void output_senior_member(int senior_mem[10][4])
{
    for( int num = 1; num <= senior_mem[0][0]; num++)
    {
        cout << endl << "LT_g" << num << " = ";
        cout << senior_mem[num][0];
        if(senior_mem[num][1] != 0)
            cout << "X^" << senior_mem[num][1];
        if(senior_mem[num][2] != 0)
            cout << "Y^" << senior_mem[num][2];
        if(senior_mem[num][3] != 0)
            cout << "Z^" << senior_mem[num][3];
        cout << endl;
    }
}
//
//      LT(g)
//
void Senior_member(int polinom[100][4], int senior_mem[4])
{
    senior_mem[0] = polinom[1][0]; senior_mem[1] = polinom[1][1]; senior_mem[2] = polinom[1][2]; senior_mem[3] = polinom[1][3];

    for(int i = 1; i < polinom[0][0]; i++)
    {
        if((senior_mem[1] < polinom[i][1])
        ||(senior_mem[1] == polinom[i][1] && senior_mem[2] < polinom[i][2])
        ||(senior_mem[1] == polinom[i][1] && senior_mem[2] == polinom[i][2] && senior_mem[3] < polinom[i][3]))
        {
            senior_mem[0] = polinom[i][0];
            senior_mem[1] = polinom[i][1];
            senior_mem[2] = polinom[i][2];
            senior_mem[3] = polinom[i][3];
        }
    }
    cout << endl << senior_mem[0] << ' ' << senior_mem[1] << ' ' << senior_mem[2] << ' ' << senior_mem[3] << ' ' << endl;
}
//
//          NOD(LT_g1[0], LT_g2[0])
//
int NOD(int a, int b)
{
    int i, j;
    i = abs(a);
    j = abs(b);
    while (i && j)
        if (i >= j)
           i %= j;
        else
           j %= i;
    return i | j;
}
//
//      W = NOD(LT_g1, LT_g2)
//
void Omega(int W[4], int senior_mem_1[4], int senior_mem_2[4])
{
    W[0] = -1;

    if (senior_mem_1[1] > senior_mem_2[1])
        W[1] = senior_mem_2[1];
    else
        W[1] = senior_mem_1[1];
    if (senior_mem_1[2] > senior_mem_2[2])
        W[2] = senior_mem_2[2];
    else
        W[2] = senior_mem_1[2];
    if (senior_mem_1[3] > senior_mem_2[3])
        W[3] = senior_mem_2[3];
    else
        W[3] = senior_mem_1[3];
    if(W[1] != 0 || W[2] != 0 || W[3] != 0)
    {
        W[0] = NOD(senior_mem_1[0], senior_mem_2[0]);
    }
}
//
//      q = LT(g) / W
//
void division(int q[4], int senior_mem[4], int W[4])
{
    q[0] = senior_mem[0] / W[0];
    q[1] = senior_mem[1] - W[1];
    q[2] = senior_mem[2] - W[2];
    q[3] = senior_mem[3] - W[3];
}
//
//      shift polinom
//
void shift_polinom(int polinom[100][4])
{
    int i = 1, j = 1;
    while(i < polinom[0][0])
    {
        if(polinom[i][0] == 0)
        {
            j = i;
            polinom[0][0]--;
            while(j < polinom[0][0])
            {
                polinom[j][0] = polinom[j+1][0];
                polinom[j][1] = polinom[j+1][1];
                polinom[j][2] = polinom[j+1][2];
                polinom[j][3] = polinom[j+1][3];
                j++;
            }
            i--;
        }
        i++;
    }
    if(polinom[0][0] == 1)
        polinom[0][0] = -1;
}
//
//      F=g_1*q_2 - g_2*q_1
//
void difference(int F[100][4], int polinom_1[100][4], int q_1[4], int polinom_2[100][4], int q_2[4])
{
    F[0][0] = polinom_1[0][0];
    for(int i = 1; i < polinom_1[0][0]; i++)
    {
        F[i][0] = polinom_1[i][0] * q_2[0];
        F[i][1] = polinom_1[i][1] + q_2[1];
        F[i][2] = polinom_1[i][2] + q_2[2];
        F[i][3] = polinom_1[i][3] + q_2[3];
    }
    int F_add[100][4];
    F_add[0][0] = polinom_2[0][0];
    for(int i = 1; i < polinom_2[0][0]; i++)
    {
        F_add[i][0] = polinom_2[i][0] * q_1[0];
        F_add[i][1] = polinom_2[i][1] + q_1[1];
        F_add[i][2] = polinom_2[i][2] + q_1[2];
        F_add[i][3] = polinom_2[i][3] + q_1[3];
    }

    for(int j = 1; j < F_add[0][0]; j++)
    {
        for(int i = 1; i < F[0][0]; i++)
        {
            if(F[i][1] == F_add[j][1]
            && F[i][2] == F_add[j][2]
            && F[i][3] == F_add[j][3]
            && F_add[j][0] != 0)
            {
                F[i][0] = F[i][0] - F_add[j][0];
                F[i][1] = F[i][1];
                F[i][2] = F[i][2];
                F[i][3] = F[i][3];
                F_add[j][0] = 0;
            }
        }
        if(F_add[j][0] != 0)
        {
            F[F[0][0]][0] = -1*F_add[j][0];
            F[F[0][0]][1] = F_add[j][1];
            F[F[0][0]][2] = F_add[j][2];
            F[F[0][0]][3] = F_add[j][3];
            F_add[j][0] = 0;
            F[0][0]++;
        }
    }
    shift_polinom(F);
}

int main()
{
    int Arr_polinom[10][100][4] = {}, Arr_senior_member[10][4] = {}, W[4] = {}, q_1[4] = {}, q_2[4] = {}, F[100][4] = {};
    Arr_polinom[0][0][0] = 3; Arr_senior_member[0][0] = 3;
    input_polinom(Arr_polinom[1]);
    input_polinom(Arr_polinom[2]);
    input_polinom(Arr_polinom[3]);

    Senior_member(Arr_polinom[1], Arr_senior_member[1]);
    Senior_member(Arr_polinom[2], Arr_senior_member[2]);
    Senior_member(Arr_polinom[3], Arr_senior_member[3]);
/*
    Omega(W, Arr_senior_member[1], Arr_senior_member[2]);

    division(q_1, Arr_senior_member[1], W);
    division(q_2, Arr_senior_member[2], W);

    difference(F, Arr_polinom[1], q_1, Arr_polinom[2], q_2);

    output_senior_member(Arr_senior_member);

    cout << endl << W[0] << ' ' << W[1] << ' ' << W[2] << ' ' << W[3] << endl;
    cout << endl << q_1[0] << ' ' << q_1[1] << ' ' << q_1[2] << ' ' << q_1[3] << endl;
    cout << endl << q_2[0] << ' ' << q_2[1] << ' ' << q_2[2] << ' ' << q_2[3] << endl;

    output_polinom(Arr_polinom);



    for(int i = 1; i < F[0][0]; i++)
    {
        if(F[i][0] > 1)
        {
            cout <<"+";
        }
        cout << F[i][0];

        if(F[i][1] != 0)
            cout << "X^" << F[i][1];

        if(F[i][2] != 0)
            cout << "Y^" << F[i][2];

        if(F[i][3] != 0)
            cout << "Z^" << F[i][3];
    }
*/
    int i = 1, j = 2;
    while(j > i)
    {
        Omega(W, Arr_senior_member[i], Arr_senior_member[j]);
        if(W[0] != -1)
        {
            division(q_1, Arr_senior_member[i], W);
            division(q_2, Arr_senior_member[j], W);
            difference(F, Arr_polinom[i], q_1, Arr_polinom[j], q_2);
            if(F[0][0] != -1)
            {
                Arr_polinom[0][0][0]++;
                Arr_senior_member[0][0]++;
                Arr_polinom[Arr_polinom[0][0][0]][0][0] = F[0][0];
                Senior_member(Arr_polinom[Arr_polinom[0][0][0]], Arr_senior_member[Arr_polinom[0][0][0]]);
                for(int counter = 1; counter < F[0][0]; counter++)
                {
                    Arr_polinom[Arr_polinom[0][0][0]][counter][0] = F[counter][0];
                    Arr_polinom[Arr_polinom[0][0][0]][counter][1] = F[counter][1];
                    Arr_polinom[Arr_polinom[0][0][0]][counter][2] = F[counter][2];
                    Arr_polinom[Arr_polinom[0][0][0]][counter][3] = F[counter][3];

                }

            }
            i++;
            if(i == j)
            {
                i = 1;
                j++;
            }
            else
            {
                i++;
                if(i == j)
                {
                    i = 1;
                    j++;
                }
            }
        }
        else
        {
            i++;
            if(i == j)
            {
                i = 1;
                j++;
            }
        }
        if(Arr_polinom[0][0][0] == 8 || Arr_polinom[0][0][0] < j)
            break;

    }

    output_polinom(Arr_polinom);
    //cout << "Hello World!" << endl;
    return 0;
}
