#include<iostream>
#include<iomanip>
#include<math.h>

using namespace std;

int main()
{
    cout.precision(6);
    cout.setf(ios::fixed);
    int order;
    order=3;
    double point[order+1];
    double f[order+1];
    cout<<"Enter the data points and values: "<<endl;
    for(int i=0; i<=order; i++)
    {
        cin>>point[i];
        cin>>f[i];
    }
    double value;
    cout<<"\nEnter the evaluation value: ";
    cin>>value;
    int asize=2*(order+1);
    double x[asize];
    double fv[asize];
    double eqn[order-1][order];
    int j,k;
    j=k=0;
    for(int i=1; i<=2; i++)
    {
        x[j]=(point[i]-point[i-1]);
        j++;
        x[j]=2*(point[i+1]-point[i-1]);
        j++;
        x[j]=(point[i+1]-point[i]);
        j++;
        fv[k]=f[i-1];
        k++;
        fv[k]=f[i];
        k++;
        fv[k]=f[i+1];
        k++;
        x[j]=((6/x[j-1])*(fv[k-1]-fv[k-2])+(6/x[j-3])*(fv[k-3]-fv[k-2]));
        j++;
    }

    for(int i=0; i<order-1; i++)
    {
        for(int j=0; j<order; j++)
        {
            if(i==0)
            {
                eqn[i][j]=x[j+1];
            }
            else if(i==1)
            {
                if((j+1)==order)
                {
                    eqn[i][j]=x[j+order+2];
                    break;
                }
                eqn[i][j]=x[j+order+1];
            }
        }
    }

    double b[order-1];
    double factor;

    for(int k=0; k<order-2; k++)
    {
        for(int i=k; i<order-2; i++)
        {
            factor= (eqn[i+1][k]/eqn[k][k]) ;

            for(int j=0; j<=order-1; j++)
            {
                eqn[i+1][j]=eqn[i+1][j]-factor*eqn[k][j];
            }
        }
    }

    double sum;
    for(int i=order-2; i>=0; i--)
    {
        sum=0;
        for(int j=i; j<=order-2; j++)
        {
            sum=sum+eqn[i][j]*b[j];
        }

        b[i]=(eqn[i][order-1]-sum)/eqn[i][i];
    }

    double ff[order+1];
    for(int i=1;i<order;i++){
        ff[i]=b[i-1];
    }
    double fa[order];
    for(int i=1;i<=order;i++){
        fa[i-1]=((ff[i-1]/(6*(point[i]-point[i-1])))*pow((point[i]-value),3))+((ff[i]/(6*(point[i]-point[i-1])))*pow((value-point[i-1]),3))+(((f[i-1]/(point[i]-point[i-1]))-(ff[i-1]*(point[i]-point[i-1]))/6)*(point[i]-value))+(((f[i]/(point[i]-point[i-1]))-(ff[i]*(point[i]-point[i-1]))/6)*(value-point[i-1]));
    }
    for(int i=0;i<order;i++){
        cout<<endl<<"Estimated value: f"<<i+1<<"("<<value<<") = "<<fa[i];
    }
    cout<<endl;
}
