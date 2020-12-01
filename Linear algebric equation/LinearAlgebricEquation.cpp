#include<iostream>
#include<stdio.h>

using namespace std;

void LUDecomposition()
{
    float A[20][20]= {0},L[20][20]= {0}, U[20][20];
    float B[20]= {0}, X[20]= {0},Y[20]= {0};
    int i,j,k,n;
    printf("Enter the order of square matrix: ");
    scanf("%d",&n);
    printf("\nEnter matrix element:\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            //printf("Enter A[%d][%d] element: ", i,j);
            scanf("%f",&A[i][j]);
        }
    }
    printf("\nEnter the constant terms: \n");
    for(i=0; i<n; i++)
    {
        printf("B[%d] = ",i);
        scanf("%f",&B[i]);
    }
    for(j=0; j<n; j++)
    {
        for(i=0; i<n; i++)
        {
            if(i<=j)
            {
                U[i][j]=A[i][j];
                for(k=0; k<i-1; k++)
                    U[i][j]-=L[i][k]*U[k][j];
                if(i==j)
                    L[i][j]=1;
                else
                    L[i][j]=0;
            }
            else
            {
                L[i][j]=A[i][j];
                for(k=0; k<=j-1; k++)
                    L[i][j]-=L[i][k]*U[k][j];
                L[i][j]/=U[j][j];
                U[i][j]=0;
            }
        }
    }
    printf("[L]: \n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf("%9.3f",L[i][j]);
        printf("\n");
    }
    printf("\n\n[U]: \n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf("%9.3f",U[i][j]);
        printf("\n");
    }
    for(i=0; i<n; i++)
    {
        Y[i]=B[i];
        for(j=0; j<i; j++)
        {
            Y[i]-=L[i][j]*Y[j];
        }
    }
    printf("\n\n[D]: \n");
    for(i=0; i<n; i++)
    {
        printf("%9.3f",Y[i]);
    }
    for(i=n-1; i>=0; i--)
    {
        X[i]= Y[i];
        for(j=i+1; j<n; j++)
        {
            X[i]-=U[i][j]*X[j];
        }
        X[i]/=U[i][i];
    }
    printf("\n\n[X]: \n");
    for(i=0; i<n; i++)
    {
        printf("%9.3f",X[i]);
    }

}
         /*
void NaiveGaussElimination()
{
    int i,j,k,n;
    float A[20][20],c,x[10],sum=0.0;
    printf("\nEnter the order of matrix: ");
    scanf("%d",&n);
    printf("\nEnter the elements of augmented matrix row-wise:\n\n");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=(n+1); j++)
        {

            scanf("%f",&A[i][j]);
        }
    }
    for(j=1; j<=n; j++)
    {
        for(i=1; i<=n; i++)
        {
            if(i>j)
            {
                c=A[i][j]/A[j][j];
                for(k=1; k<=n+1; k++)
                {
                    A[i][k]=A[i][k]-c*A[j][k];
                }
            }
        }

        printf("Step %d:\n",j);
        for(int row=1; row<=n; row++)
        {
            for(int col=1; col<=(n+1); col++)
            {
                if( A[row][col]==0.0000)
                {
                    printf("  ");

                }
                else
                {
                    printf("%.4f\t",A[row][col]);
                }

            }
            printf("\n");
        }
    }
    x[n]=A[n][n+1]/A[n][n];

    /// Backward substitution
    for(i=n-1; i>=1; i--)
    {
        sum=0;
        for(j=i+1; j<=n; j++)
        {
            sum=sum+A[i][j]*x[j];
        }
        x[i]=(A[i][n+1]-sum)/A[i][i];
    }
    printf("\nThe solution is: \n");
    for(i=1; i<=n; i++)
    {
        printf("\nx%d=%f\t",i,x[i]); /// x1, x2, x3 are the required solutions
    }

}


*/
void GaussSeidel()
{
    int m,n,es;
    printf("Enter the number of Equations,Co-efficient and Es:\n");
    cin>>m>>n>>es;
    int r=0;
    float a[m][n];
    float u[m][n],b[m][n],w[10],x[m-1],er[m-1];
    for(int i=0; i<m; i++)
    {
        x[i]=0;
        er[i]=0;
    }
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>a[i][j];
            u[i][j]=a[i][j];
        }
    }
    printf("value \t\t\t error\n");
    float n1,n2,n3;
    int flag;
    for(;;)
    {
        flag=0;
        for(int i=0; i<m; i++)
        {
            n2=0;
            for(int j=0; j<n; j++)
            {
                if(i==j)
                {
                    n1=a[i][j];
                }
                else
                {
                    if(j==n-1)
                    {
                        n2=n2+(a[i][j]);
                    }
                    else
                    {
                        n2=n2-(a[i][j]*x[j]);
                    }
                }
            }
            n3=n2/n1*1.0;
            x[i]=n3;
        }

        for(int i=0; i<m; i++)
        {
            printf("x%d = ",i+1);
            printf("%.3f ",x[i]);
            float e1=x[i]-er[i];
            float e2=(e1/x[i])*100;
            if(e2<0)
                e2=e2*(-1);
            printf("\t\t %.3f \n",e2);
            if(e2<es)
            {
                flag=1;
                break;
            }
            else
                er[i]=x[i];
        }
        printf("\n");
        if(flag==1)
            break;
    }
}
/*
void GaussJordan()
{
    int n;
    cout<<"Enter No of equations: ";
    cin>>n;
    cout<<"Enter augmented matrix(row wise): "<<endl;
    double eqn[n][n+1];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n+1; j++)
        {
            cin>>eqn[i][j];
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            printf("%.6lf\t",eqn[i][j]);
        }
        cout<<endl;
    }
    cout<<endl;

    double b;
    int c;

    for(int i=0; i<n; i++)
    {
        c=0;
        b=eqn[i][i];
        for(int j=0; j<=n; j++)
        {
            eqn[i][j]=eqn[i][j]/b;
        }
        for(int p=0; p<n; p++)
        {
            for(int q=0; q<=n; q++)
            {
                printf("%.6lf\t",eqn[p][q]);
            }
            cout<<endl;
        }
        cout<<endl;
        int k=i+1;
        if(i+1>=n)
        {
            k=0;
        }
        for(k; k<n; k++)
        {
            if(k==i)
            {
                break;
            }
            if(k<n)
            {
                b=eqn[k][i];
                for(int j=0; j<=n; j++)
                {
                    eqn[k][j]=eqn[k][j]-b*eqn[i][j];
                }
            }
            c++;

            if(k+1>=n&&c<n-1)
            {
                k=-1;
            }
        }

        for(int p=0; p<n; p++)
        {
            for(int q=0; q<=n; q++)
            {
                printf("%.6lf\t",eqn[p][q]);
            }
            cout<<endl;
        }
        cout<<endl;
    }


}
*/
int main()
{
    int func=0;
    cout<<"Choose a method:\n1.Gauss Jordan\n2.Gauss Seidels\n3.Naive Gauss Elimination\n4.LU Decomposition\n";
    cin>>func;

    /* if(func==1)
    {
        GaussJordan();
    }
    */
     if(func==2)
    {
        GaussSeidel();
    }
   /* else if(func==3)
    {
        NaiveGaussElimination();
    }
    */
    if(func==4)
    {
        LUDecomposition();
    }
    else
    {
        cout<<"Please ";
    }
    main();
}
