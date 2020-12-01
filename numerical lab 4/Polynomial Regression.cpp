//Polynomial Regression
#include<iostream>
#include<iomanip>
#include<cmath>
#include<math.h>
using namespace std ;
int main ()
{
    cout<<"              Polynomial Regression"<<endl;
    int i,j,k,n,N;
    cout .precision (4); ///set precision
    cout .setf (ios::fixed);
    cout << "\nEnter the no. of data pairs to be entered:\n" ;
    cin >> N ;
    double x[N],y[N],aa,bb;
    cout << "\nEnter the x-axis and y-axis values:\n" ; ///Input
    for(i=0;i<N;i++)
    {
        cin >> x[i];
        cin >> y[i];
    }

    cout << "\nDegree of Polynomial:(m)";
    cin >> n;
    double X[2*n+1];
    for (i=0;i<2*n+1;i++)
    {
        X[i]=0;
        for(j=0;j<N;j++)
            X[i]=X[i]+ pow(x[j],i);
    }
    double B[n+1][n+2],a[n+1];
    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
            B[i][j]=X[i+j]; ///Build the Normal matrix
    double Y[n+1]; ///Array to store the value
    for (i=0;i<n+1;i++)
    {
        Y[i]=0;
        for(j=0;j<N;j++)
            Y[i]=Y[i]+pow(x[j],i)*y[j]; ///consecutive position
    }
    for (i=0;i<=n;i++)
        B[i][n+1]=Y[i]; ///load the values of Y
    n=n+1; ///n is made n+1
    cout<<"\nThe Normal(Augmented Matrix) is as follows:\n" ;
    for(i=0;i<n;i++) ///print the Normal-augmented ma
    {
        for(j=0;j<=n;j++)
        {
            cout<<B[i][j]<<setw(16);
        }
        cout<< "\n" ;
    }
    for(i=0;i<n;i++) ///From now Gaussian Eli
        for(k=i+1;k<n;k++)
            if(B[i][i]<B[k][i])
                for (j=0;j<=n;j++)
                {
                    double temp =B[i][j];
                    B [ i][ j ]= B [ k ][ j ];
                    B [ k][ j ]= temp ;
                }
    for (i=0;i<n-1;i++) ///loop to perform the gauss
        for (k=i+1;k<n;k++)
        {
            double t =B[k][i]/B[i][i];
            for(j=0;j<=n;j++)
                B[k][j]=B[k][j]-t*B[i][j];
        }
    for(i=n-1;i>=0;i--) ///back-substitution
    {
        a[i]=B[i][n];
        for(j=0;j<n;j++)
            if (j != i ) ///then subtract all [the lhs val
            {
                a[i]=a[i]-B[i][j]*a[j];
            }
        a[i]=a[i]/B[i][i]; ///now finally divide
    }


    cout << "\nThe values of the coefficients are as follows:\n" ;
    for(i=0;i<n;i++)
    {
        cout<<"x^"<<i<<"="<<a[i]<< endl ;
    }



    /// Same as Linear

    double xsum=0,x2sum=0,ysum=0,xysum=0;
    for (i=0;i<N;i++)
    {
        xsum=xsum+x[i];
        ysum=ysum+y[i];
        x2sum=x2sum+pow(x[i],2);
        xysum=xysum+x[i]*y[i];
    }

    aa=(N*xysum-xsum*ysum)/(N*x2sum-xsum*xsum);
    bb=(x2sum*ysum-xsum*xysum)/(x2sum*N-xsum*xsum);


    double y_ymean[N];
    double ea[N],eaSum=0,tr=0;
    for (i=0;i<N;i++)
    {

        y_ymean[i] = (y[i] - ysum/N)*(y[i] - ysum/N);
        tr += y_ymean[i];
        ea[i] = (y[i] - a[0] - a[1]*x[i]-a[2]*x[i]*x[i])*(y[i] - a[0] - a[1]*x[i]-a[2]*x[i]*x[i]);
        eaSum += ea[i];
    }
    cout<<"S.no"<<setw(5)<<"x"<<setw(15)<<"y"<<setw(15)<<"y-y'^2"<<setw(15)<<"Ea"<<endl;
    cout<<"-----------------------------------------------------------------\n";
    for (i=0;i<N;i++)
    {
         cout<<i+1<<"."<<setw(8)<<x[i]<<setw(15)<<y[i]<<setw(15)<<y_ymean[i]<<setw(15)<<ea[i]<<endl;
    }

    double r =sqrt((tr-eaSum)/tr);
    cout<<"\nr = "<<r<<endl;

    double Syx = sqrt(eaSum/(N-n));   /// Here n = n+1;
    cout <<"Sy/x = "<<Syx<<endl;

    cout << "\The fitted Polynomial is:\ny=" ;
    for (i = 0 ; i < n ; i ++)
    {
        cout << " + ("<<a[i]<<")"<< "x^"<<i;
    }
    cout << "\n";

}
