
#include<bits/stdc++.h>
#define error 0.0001
#include <iomanip>
using namespace std;

int n;
double ar[100],apr[100],br[100];


double func(double x)
{
    double res=ar[n];

    for(int i=n-1;i>=0;i--)
    {
        res=res*x+ar[i];
    }
    return res;
}

double fprime(double x)
{
    for(int i=n;i>0;i--)
    {
       apr[i-1]=ar[i]*i;
    }
    double res=apr[n-1];
    for(int i=n-2;i>=0;i--)
    {
       res=res*x+apr[i];
    }
    return res;
}


void p(double x0)
{
    double xr;
    int roots=0;
     while(n>0)
    {   int iterations = 0;

        while(true)
        {
            double y=func(x0);
            double z=fprime(x0);
            xr=x0-(y/z);
            iterations++;
            double err=fabs((xr-x0)/xr);
            if(err<=error)
            {
                cout << "At order " << n << " Root is "<< setprecision(5) << fixed << xr << " after " << iterations;
                cout << " iterations and relative error " << setprecision(5) << fixed << err << endl;
                roots++;
                iterations = 0;
                if(err < 0.000001){
                    cout <<"The root is close to real root" << endl;
                }else{
                    cout << "The root is not real root" << endl;
                }

                break;
            }
            x0=xr;
        }

        br[n]=0;
        for(int i=n;i>0;i--)
        {
            br[i-1]=ar[i]+xr*br[i];
        }

        n--;
        for(int i=0;i<=n;i++)
        {
            ar[i]=br[i];
        }
        x0=xr;
    }

    cout << "There are " << roots << " Roots for the given polynomial";

    return;
}

//void syntheticDivision(){
//}

double maxRoot(){
    double temp = pow((ar[n-1]/ar[n] ), 2);
    temp = temp - (2*(ar[n-2]/ar[n]));
    temp = sqrt(temp);
    cout << "Largest possible root is "<< temp << endl;
    return temp;
}


int main()
{

    cout << "Enter number of degree : ";
    cin>>n;
    cout<<"Enter values of coefficient";

    for(int i=n;i>=0;i--)
    {
        cout << "Coefficient x[" << i<< "] = ";
        cin>>ar[i];
    }

    double x0 = maxRoot();
    p(x0);
    return 0;

}

/*
5
1
-5
-35
125
194
-280
*/
