#include <iostream>

using namespace std;
//
//        NOD(a, b) == d
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
//        main...
//
int main()
{
    int a, b, c, x = 0, y = 0, d = 0;
    cout << "Ax + By = C";
    cout << endl << "input A = ";
    cin >> a;

    cout << endl << "input B = ";
    cin >> b;

    cout << endl << "input C = ";
    cin >> c;
    system("cls");
    cout << a << "x ";
    if(b < 0)
        cout << b << "y = " << c << endl;
    else
        cout << "+ " << b << "y = "<< c << endl;
    if(a == b && a == 0)
    {
        if(c == 0)
        {
            cout << "x == Z" << endl << "y == Z";
            return 0;
        }
        else
        {
            cout << "No solution ;c";
            return 0;
        }
    }
    else if(a == 0 && b != 0)
    {
        y = c / b;
        if(y != 0)
        {
            cout << "x == Z" << endl << "y = " << y;
            return 0;
        }
        else
        {
            cout << "No solution ;c";
            return 0;
        }

    }
    else if(a != 0 && b == 0)
    {
        x = c / a;
        if(x != 0)
        {
            cout << "x = " << x << endl << "y = Z";
            return 0;
        }
        else
        {
            cout << "No solution ;c";
        }
    }
    else if(a != 0 && b != 0)
    {
        d = NOD(a, b);
        if(c / d * d != c)
        {
            cout << "No solution ;c";
            return 0;
        }
        else
        {
            a /= d;
            b /= d;
            c /= d;
            for(int i = 0; i < 1001; i++)
            {
                y = i * a - c;
                if(y / b * b == y)
                {
                    y /= -b;

                    x = i;
                    break;
                }
            }
        }
//        return 404;
    }

    cout << "x = " << x;
    if(b > 0)
        cout << " + " << b << "t" << endl;
    else
        cout << " - " << b << "t" << endl;

    cout << "y = " << y;
    if(a > 0)
        cout << " - " << a << "t" << endl;
    else
        cout << " + " << a << "t" << endl;

    cout << "t == Z";
//    cout << "Hello World!" << endl;
    return 0;
}
