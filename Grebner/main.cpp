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
            cout << "X^" << polinom[num][i][1];
            cout << "Y^" << polinom[num][i][2];
            cout << "Z^" << polinom[num][i][3];
        }
        cout << endl;
    }
}
int main()
{
    int Arr_polinom[10][100][4] = {}, Arr_senior_member[10][4] = {};
    Arr_polinom[0][0][0] = 3; Arr_senior_member[0][0] = 3;
    input_polinom(Arr_polinom[1]);
    output_polinom(Arr_polinom);
    cout << "He" << endl;

    return 0;
}
