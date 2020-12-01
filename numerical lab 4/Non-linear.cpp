/*
2.5 3.5 5 6 7.5 10 12.5 15 17.5 20
 13 11 8.5 8.2 7 6.2 5.2 4.8 4.6 4.3
 */
///Linear Fit
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
    int i,j,k,n;
    cout<<"\nEnter the no. of data pairs to be entered:\n";
    cin>>n;
    double x[n],y[n],a,b,X[n],Y[n],m;
    cout<<"\nEnter the x-axis and y-asix values:\n";
    for (i=0;i<n;i++)
    {
        cin>>X[i];
       x[i]=log10(X[i]);
        cin>>Y[i];
          y[i]=log10(Y[i]);
    }
    double xsum=0,x2sum=0,ysum=0,xysum=0;
    for (i=0;i<n;i++)
    {
        xsum=xsum+x[i];
        ysum=ysum+y[i];
        x2sum=x2sum+pow(x[i],2);
        xysum=xysum+x[i]*y[i];
    }
    a=(n*xysum-xsum*ysum)/(n*x2sum-xsum*xsum);
    b=(x2sum*ysum-xsum*xysum)/(x2sum*n-xsum*xsum);            ///calculate intercept

    double a0 = ysum/n - a*xsum/n;     /// a0 = y' - a1x' Equivalent of b :-)
     m=pow(10,a0);
    cout<<"y = "<<m<<"x"<<"^"<<a<<endl;
    return 0;
}

