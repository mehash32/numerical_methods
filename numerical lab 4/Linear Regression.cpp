
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
    double x[n],y[n],a,b;
    cout<<"\nEnter the x-axis and y-asix values:\n";
    for (i=0;i<n;i++)
    {
        cin>>x[i];

        cin>>y[i];
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

    double y_fit[n];
    double y_ymean[n];
    double ea[n];
    for (i=0;i<n;i++)
    {
        y_fit[i]=a*x[i]+b;
        y_ymean[i] = (y[i] - ysum/n)*(y[i] - ysum/n);
        ea[i] = (y[i] - a0 - a*x[i])*(y[i] - a0 - a*x[i]);
    }
    cout<<"S.no"<<setw(5)<<"x"<<setw(15)<<"y"<<setw(15)<<"y-y'^2"<<setw(15)<<"Ea"<<endl;
    cout<<"-----------------------------------------------------------------\n";
    for (i=0;i<n;i++)
    {
         cout<<i+1<<"."<<setw(8)<<x[i]<<setw(15)<<y[i]<<setw(15)<<y_ymean[i]<<setw(15)<<ea[i]<<endl;
    }
    cout<<"\nThe linear fit line is of the form:\n\ny="<<a0<<" + "<<a<<"x"<<endl;
    return 0;
}
