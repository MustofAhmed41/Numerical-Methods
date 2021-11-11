#include<bits/stdc++.h>
using namespace std;

struct Point
{
    double x;
    double y;
};

void polynomial(Point *a, int n, int N)
{
    double X[2*N+1];
    for(int i=0; i<2*N+1; i++)                  //this array will store summation of xi, xi^2......
    {
        X[i] = 0;
        for(int j=0; j<n; j++)
        {
            X[i] = X[i]+pow(a[j].x,i);
        }
    }

    double B[N+1][N+2],A[N+1];              //B is the Normal matrix(augmented) that will store the equations, a is for value of the final coefficients
    for(int i=0; i<=N; i++)
    {
        for(int j=0; j<=N; j++)
        {
            B[i][j] = X[i+j];               //Build the Normal matrix by storing the corresponding coefficients at the right positions except the last column of the matrix
        }
    }

    double Y[N+1];                          //Array to store the values of summation of (yi),sigma(xi*yi),sigma(xi^2*yi)...sigma(xi^n*yi)
    for(int i=0; i<N+1; i++)
    {
        Y[i] = 0;
        for(int j=0; j<n; j++)
        {
            Y[i] = Y[i]+ (pow(a[j].x,i)*a[j].y);       //consecutive positions will store sigma(yi),sigma(xi*yi),sigma(xi^2*yi)...sigma(xi^n*yi)
        }
    }

    for(int i=0; i<=N; i++)
    {
        B[i][N+1] = Y[i];                               //load the value of summation of yi summation of yi*xi....in the last column
    }

    N = N+1;
    /*cout<<"\nThe Normal(Augmented Matrix) is: \n\n";
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<=N; j++)
        {
            cout<<B[i][j]<<setw(16);
        }
        cout<<"\n";
    }*/

    // Gauss elimination with partial pivoting starts
    for(int i=0; i<N; i++)
    {
        for(int k=i+1; k<N; k++)
        {
            if(B[i][i] < B[k][i])
            {
                for (int j=0; j<=N; j++)
                {
                    double temp = B[i][j];
                    B[i][j] = B[k][j];
                    B[k][j] = temp;
                }
            }
        }
    }

    for(int i=0; i<N-1; i++)            //loop to perform the gauss elimination
    {
        for(int k=i+1; k<N; k++)
        {
            double t = B[k][i] / B[i][i];
            for(int j=0; j<=N; j++)
            {
                B[k][j] = B[k][j] - t*B[i][j];              //make the elements below the pivot elements equal to zero or eliminate the variables
            }
        }
    }

    // backward substitution
    for(int i=N-1; i>=0; i--)
    {
        A[i] = B[i][N];
        for (int j=0; j<N; j++)
        {
            if(j != i)
            {
                A[i] = A[i]-B[i][j]*A[j];
            }
        }
        A[i] = A[i]/B[i][i];
    }


    cout<<"\n\n";
    cout<<"X"<<"\t\t"<<"Approximated cube root\n";
    cout<<"-----------------------------------------\n";

    double m[100];
    m[0] = 1.25;
    int k = 0;
    cout<<m[0]<<"\t\t";
    for(int i=1; i<=45; i++)
    {
        double sum = 0;
        m[i] = m[i-1] + 0.01;
        //cout<<m[i]<<"\t\t";
        for(int j=0; j<N; j++)
        {
            sum = sum+ A[j]*pow(m[k], j);
        }
        cout<<sum<<"\n";
        cout<<m[i]<<"\t\t";
        //cout<<"\n";
        k++;
    }
    cout<<"\n\n";

    double sum_x = 0;
    double sum_y = 0;
    for(int i=0; i<n; i++)
    {
        sum_x = sum_x + a[i].x;
        sum_y = sum_y + a[i].y;
    }
    cout<<"Mean of X: "<<sum_x/n<<"\n";
    cout<<"Mean of y: "<<sum_y/n<<"\n";

    cout<<"\nThe values of the coefficients are: \n";
    for(int i=0; i<N; i++)
    {
        cout<<"A"<<i<<"="<<A[i]<<endl;
    }



}

int main()
{
    int n;
    //freopen("input.txt","r",stdin);
    cout<<setprecision(2)<<fixed;
    cout<<"Enter the number of data points: \n";
    cin>>n;

    Point *arr = new Point[n];
    cout<<"Enter the values of x and y: \n";
    for(int i=0; i<n; i++)
    {
        double x,y;
        cin>>x>>y;
        arr[i].x = x;
        arr[i].y = y;
    }

    int N;
    cout<<"Enter the degree of the polynomial: \n";
    cin>>N;
    polynomial(arr, n, N);

}


