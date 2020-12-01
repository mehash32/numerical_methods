#include<stdio.h>
int main()
{
    int i,j,k,n,d=1;
    float A[20][20],c,x[10];
    printf("\nEnter the order of matrix: ");
    scanf("%d",&n);
    printf("\nEnter the elements of augmented matrix:\n");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=(n+1); j++)
        {

            scanf("%f",&A[i][j]);
        }
    }
    /* Now finding the elements of diagonal matrix */
    for(j=1; j<=n; j++)
    {
        double p = A[j][j];
        for(i=1; i<=n+1; i++)
        {
            A[j][i]=A[j][i]/p;

        }
        for(i=1; i<=n; i++)
        {

            printf("Step:%d\n",d++);
            for(int m=1; m<=n; m++)
            {
                for(int g=1; g<=(n+1); g++)
                {

                    printf("%.4f\t",A[m][g]);
                }
                printf("\n");
            }


            if(i!=j)
            {
                c=A[i][j]/A[j][j];
                for(k=1; k<=n+1; k++)
                {
                    A[i][k]=A[i][k]-c*A[j][k];
                }


            }

        }



    }
    printf("\nThe solution is:\n");
    for(i=1; i<=n; i++)
    {
        x[i]=A[i][n+1];
        printf("\n x%d=%f\n",i,x[i]);
    }
    return(0);
}

