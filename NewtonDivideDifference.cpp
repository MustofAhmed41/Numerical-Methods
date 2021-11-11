#include <bits/stdc++.h>
using namespace std;

float Term(int i, float value, float x[]);
float Formula(float value, float x[], float y[][50], int n);

int main()
{
    int n = 4;
    int N;
    float value, sum, y[50][50];
    float x[50];
    cout << "Enter number of data : ";
    cin >> N;
    cout << "Enter data " << endl;
    for(int i = 0; i < N;i++){
        cin >> x[i];
        cin >> y[i][0];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            y[j][i] = (y[j][i - 1] - y[j + 1]
                         [i - 1]) / (x[j] - x[i + j]);
        }
    }



    for(int i = 2020 ; i <=2040 ;i++){
        value = i;
        cout << "Value at " << value << " is \t"
            << Formula(value, x, y, n) << endl;
    }


    float sum_y=0;

    for(int i = 1993; i<= 2013;i++){
        value = i;
        sum_y = pow( (y[i-1993][0]-Formula(value,x,y,n)),2 );
    }

    sum_y = sum_y/N;
    cout << "Mean squared is : " << sum_y << endl;

    for (int i = 1; i <= n; i++)
    {
        cout << "Coefficient of x^" << i-1 <<" is " << y[i][0]<<endl;
    }

    return 0;
}

float Term(int i, float value, float x[])
{
    float p = 1;
    for (int j = 0; j < i; j++)
    {
        p = p * (value - x[j]);
    }
    return p;
}

float Formula(float value, float x[],
              float y[][50], int n)
{
    float sum = y[0][0];

    for (int i = 1; i < n; i++)
    {
        sum = sum + (Term(i, value, x) * y[0][i]);
    }
    return sum;
}

/*
5
5
150
7
392
11
1452
13
2366
21
9702


21
1993 25.00317
1994 25.26167
1995 25.41583
1996 25.44025
1997 24.85925
1998 25.52417
1999 25.71483
2000 25.15017
2001 25.337
2002 25.38033
2003 25.28083
2004 25.38633
2005 25.532
2006 25.76567
2007 25.34375
2008 25.3895
2009 25.90492
2010 25.94033
2011 25.20508
2012 25.53358
2013 25.9675
*/
