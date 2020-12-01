 #include "bits/stdc++.h"
using namespace std;


double f(double x)
{
   // double a=0.2+25*x-200*x*x+675*pow(x,3)-900*pow(x,4)+400*pow(x,5);
    double a = (exp(x)*sin(x))/(1+x*x);
    return a;
}

double romberg(double(*func)(double),double a,double b,int N)
{
    double h[N+1],r[N+1][N+1];
    for(int i=1;i<N+1;++i)
    {
        h[i]=(b-a)/pow(2,i-1);
    }


    r[1][1]=h[1]/2*(func(a)+func(b));   ///  I = h*f(a)*f(b) / 2  ( eqn 21.3)
    //cout<<"Trp.I = "<<r[1][1]<<endl;

    for(int i=2;i<N+1;++i)
    {
        double coeff=0;
        for(int k=1;k<=pow(2,i-2);++k)
        {
            coeff+=func(a+(2*k-1)*h[i]);
        }
        r[i][1]=0.5*(r[i-1][1]+h[i-1]*coeff);
        // cout<<"Trp.Ix = "<<r[i][1]<<endl;
    }

    for(int i=2;i<N+1;++i)
    {
        for(int j=2;j<=i;++j)
        {
            r[i][j]=r[i][j-1] + (r[i][j-1] - r[i-1][j-1])/(pow(4,j-1)-1);   /// Pdf: 22.8
        }
    }
    return r[N][N];
}


int main()
{
    cout.precision(4);
    cout.setf(ios::fixed);
    int n;
    double a,b;
    cout<<"Enter the limits of integration,\nInitial limit,a= ";
    cin>>a;
    cout<<"Final limit, b=";
    cin>>b;
    cout<<"\nEnter the no. of subintervals, n=";
    cin>>n;

    cout<<"I = "<<romberg(f,a,b,n)<<endl;
}
