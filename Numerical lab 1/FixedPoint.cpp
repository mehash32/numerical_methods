#include<bits/stdc++.h>
using namespace std;
double co_efficient[10];
int position;

double g(double X)
{
   // return cos(X)/exp(X);
    //return 3*(X)+sin(X)-exp(X);
    return (exp(X)/3-sin(X)/3);

}
int main()
{
    double X0,x0,Xr,Ea,p=0.0;
    cout<<"The equation is: (exp(X)/3-sin(X)/3)"<<endl;
    cout<<"Value of X0 = ";
    cin>>X0;
    cout<<"Percentage of Error = ";
    cin>>Ea;
    for(int i=1;;i++)
    {
        x0 = X0;
        Xr = g(x0);
        X0 = Xr;
        cout<<i<<"\tX0 = "<<x0<<"\t\tXr = "<<Xr<<"\t\tEa = "<< abs((Xr-p)/Xr)*100.0<<endl;
        if((abs((Xr-p)/Xr)*100.0)<=Ea)
        {
            cout<<"\nApproximate Root: "<<Xr;
            break;
        }
        p=Xr;
    }
}
