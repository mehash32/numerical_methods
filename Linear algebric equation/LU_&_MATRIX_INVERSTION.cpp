#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
#include<conio.h>

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
void MatrixInverse()
{

		 float a[10][10], x[10], ratio;
		 int i,j,k,n;

		 /* Inputs */
		 /* 1. Reading order of matrix */
		 printf("Enter order of matrix: ");
		 scanf("%d", &n);
		 /* 2. Reading Matrix */
		 printf("Enter coefficients of Matrix:\n");
		 for(i=1;i<=n;i++)
		 {
			  for(j=1;j<=n;j++)
			  {
				   //printf("a[%d][%d] = ",i,j);
				   scanf("%f", &a[i][j]);
			  }
		 }
		 /* Augmenting Identity Matrix of Order n */
		 for(i=1;i<=n;i++)
		 {
			  for(j=1;j<=n;j++)
			  {
				   if(i==j)
				   {
				    	a[i][j+n] = 1;
				   }
				   else
				   {
				    	a[i][j+n] = 0;
				   }
			  }
		 }
		 /* Applying Gauss Jordan Elimination */
		 for(i=1;i<=n;i++)
		 {
			  if(a[i][i] == 0.0)
			  {
				   printf("Mathematical Error!");

			  }
			  for(j=1;j<=n;j++)
			  {
				   if(i!=j)
				   {
					    ratio = a[j][i]/a[i][i];
					    for(k=1;k<=2*n;k++)
					    {
					     	a[j][k] = a[j][k] - ratio*a[i][k];
					    }
				   }
			  }
		 }
		 /* Row Operation to Make Principal Diagonal to 1 */
		 for(i=1;i<=n;i++)
		 {
			  for(j=1;j<=2*n;j++)
			  {
			   	a[i][j] = a[i][j]/a[i][i];
			  }
		 }
		 /* Displaying Inverse Matrix */
		 printf("\nInverse Matrix is:\n");
		 for(i=1;i<=n;i++)
		 {
			  for(j=n+1;j<=2*n;j++)
			  {
			   	printf("%0.3f\t",a[i][j]);
			  }
			  printf("\n");
		 }




}

void GaussSeidel()
{
    int m,n,es;
    cout<<"\n\n\n\n";
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

int main()
{
    int func=0;
    cout<<"Choose a method:\n1.Gauss Seidels\n2.LU Decomposition\n3.Matrix Inverse\n";
    cin>>func;

     if(func==1)
    {
        GaussSeidel();
    }

    else if(func==2)
    {
        LUDecomposition();
    }
     else if(func==3)
    {
        MatrixInverse();
    }
    else
    {
        cout<<"Please ";
    }
    main();
}

