#include <iostream>

using namespace std;
//
//      create polinom
//
void input_polinom(int polinom[100][4])
{
    cout << "g[0][0] = ";
    cin >> polinom[0][0];
    polinom[0][0]++;
    for(int i = 1; i < polinom[0][0]; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cout << "g[" << i << "][" << j << "] = ";
            cin >> polinom[i][j];
        }
    }
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
        if(senior_mem[1] < polinom[i][1])
        {
            senior_mem[0] = polinom[i][0]; senior_mem[1] = polinom[i][1]; senior_mem[2] = polinom[i][2]; senior_mem[3] = polinom[i][3];
        }
        else if(senior_mem[1] == polinom[i][1] && senior_mem[2] < polinom[i][2])
        {
            senior_mem[0] = polinom[i][0]; senior_mem[1] = polinom[i][1]; senior_mem[2] = polinom[i][2]; senior_mem[3] = polinom[i][3];
        }
        else if(senior_mem[1] == polinom[i][1] && senior_mem[2] == polinom[i][2] && senior_mem[3] < polinom[i][3])
        {
            senior_mem[0] = polinom[i][0]; senior_mem[1] = polinom[i][1]; senior_mem[2] = polinom[i][2]; senior_mem[3] = polinom[i][3];
        }
    }
    cout << endl << senior_mem[0] << ' ' << senior_mem[1] << ' ' << senior_mem[2] << ' ' << senior_mem[3] << ' ' << endl;
}
//
//          NOD(LT_g1[0], LT_g2[0])
//
int NOD(int a, int b)
{
    if(a < 0)
        a *= -1;
    if(b < 0)
        b *= -1;
    while (a && b)
        if (a >= b)
           a %= b;
        else
           b %= a;
    return a | b;
}
//
//          W = NOD(LT_g1, LT_g2)
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
    if(W[1] != W[2] != W[3] != 0)
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





int main()
{
    int Arr_polinom[10][100][4] = {}, Arr_senior_member[10][4] = {}, W[4] = {}, q_1[4] = {}, q_2[4] = {};
    Arr_polinom[0][0][0] = 2; Arr_senior_member[0][0] = 2;
    input_polinom(Arr_polinom[1]);
    input_polinom(Arr_polinom[2]);

    Senior_member(Arr_polinom[1], Arr_senior_member[1]);
    Senior_member(Arr_polinom[2], Arr_senior_member[2]);

    Omega(W, Arr_senior_member[1], Arr_senior_member[2]);

    division(q_1, Arr_senior_member[1], W);
    division(q_2, Arr_senior_member[2], W);

    output_senior_member(Arr_senior_member);
    cout << endl << W[0] << ' ' << W[1] << ' ' << W[2] << ' ' << W[3] << endl;
    cout << endl << q_1[0] << ' ' << q_1[1] << ' ' << q_1[2] << ' ' << q_1[3] << endl;
    cout << endl << q_2[0] << ' ' << q_2[1] << ' ' << q_2[2] << ' ' << q_2[3] << endl;

    output_polinom(Arr_polinom);
    cout << "Hello World!" << endl;
    return 0;
}
