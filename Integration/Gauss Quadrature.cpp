#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;


long double f(long double x)
{
   //long double a= 0.2 + 25*x - 200*x*x + 675*pow(x,3) - 900*pow(x,4) + 400*pow(x,5);
   long double a = (exp(x)*sin(x))/(1+x*x);
    return a;
}

/// For Legendre's Polynomial Pn(x)
long double pn(long double a[],int n,int m,long double x)
{
    int i;
    long double p=0;
    if(m==0)
    {
        for(i=0;i<=n;i=i+2)
        {
            if(x==0)
                break;
            p+=a[i]*pow(x,i);
        }
    }
    else
    {
        for(i=1;i<=n;i=i+2)
        {
            p+=a[i]*pow(x,i);
        }
    }
    return p;
}

/// Derivative of Pn(x)
long double dn(long double a[],int n,int m,long double x)
{
    int i;
    long double p=0;
    if(m==0)
    {
        for(i=0;i<=n;i=i+2)
        {
            if(x==0)
                break;
            p+=i*a[i]*pow(x,i-1);
        }
    }
    else
    {
        for(i=1;i<=n;i=i+2)
        {
            p+=i*a[i]*pow(x,i-1);
        }
    }
    return p;
}


long double fact(int n)
{
    int i;
    long double f=1;
    for(i=2;i<=n;i++)
    {
        f*=i;
    }
    return f;
}

int main()
{
    int n,m,i,N;
    double c,d;
    cout<<"Enter the limits of integration,\nInitial limit,a=";
    cin>>c;
    cout<<"Final limit, b=";
    cin>>d;
    cout<<"Enter the no. of subintervals, n=";
    cin>>n;

    long double a[n],b,x,y[n],z[n],w[n],l,v,s,g=0,u[n];
    m=n%2;
    if(m==0)
    {
        N=n/2;
    }
    else
    {
        N=(n-1)/2;
    }

    for(i=0;i<=N;i++)
    {
        a[n-2*i]=(pow(-1,i)*fact(2*n-2*i))/(pow(2,n)*fact(i)*fact(n-i)*fact(n-2*i));
    }


    ///Roots of Pn(x)

    for(i=0;i<n;i++)
    {
        z[i]=cos(3.14*(i+0.75)/(n+0.5));
        l=z[i];
        do
        {
            s=l-(pn(a,n,m,l)/dn(a,n,m,l));
            v=l;
            l=s;
        }
        while(fabs(l-v)>0.0000000000000001);

        y[i]=l;
        w[i]=2/((1-pow(l,2))*(dn(a,n,m,l)*dn(a,n,m,l)));
    }

    for(i=0;i<n;i++)
    {
        u[i]=((d-c)*y[i]/2)+(c+d)/2;
    }


    for(i=0;i<n;i++)
        g+=w[i]*f(u[i]);

    g=g*(d-c)/2;
    cout<<"I = "<<setprecision(10)<<g<<endl;
    return 0;
}
