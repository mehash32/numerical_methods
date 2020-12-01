/// Lagrange's interpolation
#include<iostream>

using namespace std;
int main()
{
    int n,i,j;
    float mult,sum=0,x[10],f[10],a;


    cout<<"Enter no of  points:";
    cin>>n;
    cout<<"Enter x and corresponding f(x):\n";

    for(i=0; i<n; i++)
    {
         cin>>x[i]>>f[i];
    }

    cout<<"\nEnter x for calculation : ";
    cin>>a;
    int ff;
    for(i=0;i<n;i++)
    {
        if((x[i]<=a &&x[i+1]>=a))
        {
            ff=i;
        }
    }

    for(i=ff-1; i<=ff+2; i++)
    {
        float s=1;
        mult=1;
        for(j=ff-1; j<=ff+2; j++)
        {
            if(j!=i)
            {
                 //mult*=(a-x[j])/(x[i]-x[j]);
                 s=s*(a-x[j]);
                 mult=mult*(x[i]-x[j]);
            }
        }
        //sum+=mult*f[i];
        sum=sum+((s/mult)*f[i]);
    }
    cout<<"\nThe estimated value of f(x) = "<<sum;

}
