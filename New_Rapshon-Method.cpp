#include<bits/stdc++.h>
#define EPSILON 0.001
using namespace std;
double func(double x)
{
    return x*x - 3*x + 2;
}
double derivFunc(double x)
{
    return 2*x-3;
}
void newtonRaphson(double x)
{
    double h = func(x) / derivFunc(x);
    int it=0;
    while (abs(h) >= EPSILON)
    {
        it++;
        h = func(x)/derivFunc(x);
        x = x - h;
         cout << x<<" "<<it<<endl;
    }
    cout<< "The value of the root is : " << x<<" "<<it;
}
int main()
{
    double x0 = 0;
    newtonRaphson(x0);
    return 0;
}
