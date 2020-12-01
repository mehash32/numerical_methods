#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int m,n;
    cout<<"Enter the equation Coefficients number:\n";
    cin>>m>>n;
    int r=0;
    float a[m][n];
    float u[m][n],b[m][n],w[10],L[m][n],U[m][n],x11[m];
    cout<<"Enter Co efficient:\n";
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>a[i][j];
            u[i][j]=a[i][j];
        }
    }
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==0)
            {
                continue;
            }
            else
            {
                int l=i;
                while(l<m)
                {
                    float x=a[l][i-1]/a[i-1][i-1];
                    w[r]=x;
                    r++;
                    for(int k=i-1; k<n; k++)
                    {
                        float b=a[i-1][k]*x;
                        a[l][k]=a[l][k]- b;
                    }
                    l++;
                }
                break;
            }
        }
    }
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            b[i][j]=a[i][j];
        }
    }
    printf("\n");
    printf("the value of [U] : \n");
    printf("\n");
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n-1; j++)
        {
            printf("%.4f\t",a[i][j]);
            U[i][j]=a[i][j];
        }
        printf("\n");
    }
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            a[i][j]=u[i][j];
        }
    }
    printf("\n");
    printf("the value of [L] : \n");
    printf("\n");
    int u1=0;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n-1; j++)
        {
            if(i==j)
                a[i][j]=1;
            else if(i>j)
            {
                a[i][j]=w[u1];
                u1++;
            }
            else
                a[i][j]=0;
        }
    }
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n-1; j++)
        {
            printf("%.4f\t",a[i][j]);
            L[i][j]=a[i][j];
        }
        printf("\n");
    }
    printf("\n");

    //CALCULATE INVERSE MATRIX


    float d1,d2,d3,x2;
    int y=0;
    float A[m][m];
    for(int k=0; k<m; k++)
    {
        y=k;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(j==n-1 && y==i)
                {
                    L[i][j]=1;
                }
                else if(j==n-1 && y!=i)
                {
                    L[i][j]=0;
                }
            }
        }
        float n1,n2,d[m-1];
        for(int i=0; i<m; i++)
        {
            d[i]=1.00;
        }
        for(int i=0; i<m; i++)
        {
            n2=0;
            for(int j=0; j<n; j++)
            {
                if(i==j)
                {
                    n1=L[i][j];
                }
                else
                {
                    if(j==n-1)
                    {
                        n2=n2+L[i][j];
                    }
                    else
                    {
                        n2=n2-(L[i][j]*d[j]);
                    }
                }
            }
            x2=n2/(n1*1.0);
            d[i]=x2;
            x2=0;
        }
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(j==n-1)
                {
                    U[i][j]=d[i];
                }
            }
        }

        float n11,n22,x22;
        for(int i=0; i<m-1; i++)
            x11[i]=1.00;
        for(int i=m-1; i>=0; i--)
        {
            n22=0;
            for(int j=n-1; j>=i; j--)
            {
                if(i==j)
                {
                    n11=U[i][j];
                }
                else
                {
                    if(j==n-1)
                    {
                        n22=n22+U[i][j];
                    }
                    else
                    {
                        n22=n22-(U[i][j]*x11[j]);
                    }
                }
            }
            x22=n22/(n11*1.0);
            x11[i]=x22;
            x22=0;
        }
        for(int j=0; j<m; j++)
            A[k][j]=x11[j];

    }
    printf("The inverse matrix is : \n");
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<m; j++)
        {
            printf("%.4f  ",A[j][i]);
        }
        printf("\n");
    }

    // solution
    float f1,f2,f3;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(j==n-1)
            {
                L[i][j]=a[i][j];
            }
        }
    }
    float d22[m-1];
    for(int i=0; i<m; i++)
    {
        d22[i]=1.00;
    }
    for(int i=0; i<m; i++)
    {
        f2=0;
        for(int j=0; j<n; j++)
        {
            if(i==j)
            {
                f1=L[i][j];
            }
            else
            {
                if(j==n-1)
                {
                    f2=f2+L[i][j];
                }
                else
                {
                    f2=f2-(L[i][j]*d22[j]);
                }
            }
        }
        f3=f2/(f1*1.0);
        d22[i]=f3;
        f2=0;
    }
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(j==n-1)
            {
                U[i][j]=d22[i];
            }
        }
    }


    float x1,x22,x3,n1,n2,x[m-1];
    for(int i=0; i<m-1; i++)
        x[i]=1.00;
    for(int i=m-1; i>=0; i--)
    {
        n2=0;
        for(int j=n-1; j>=i; j--)
        {
            if(i==j)
            {
                n1=U[i][j];
            }
            else
            {
                if(j==n-1)
                {
                    n2=n2+U[i][j];
                }
                else
                {
                    n2=n2-(U[i][j]*x[j]);
                }
            }
        }
        x22=n2/(n1*1.0);
        x[i]=x22;
        x22=0;
    }
    printf("\n");
    printf("Solutions of the Equations : \n");
    for(int i=0; i<m; i++)
    {
        printf("x%d = ",i+1);
        printf("%.3f \n",x[i]);
    }
}
