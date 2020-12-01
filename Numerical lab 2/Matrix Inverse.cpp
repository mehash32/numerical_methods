#include<bits/stdc++.h>
using namespace std;

main()
{
    int i,j;
    double f21,f31,f32,d1,d2,d3,x1,x2,x3,A[3][3],input[3][3],eq[3][3],U[3][3],L[3][3];
    for(i=0;i<3;i++){
        //cout<<"Enter the co-efficients of x1,x2 and x3 of equation "<<i+1<<":\n";
        for(j=0;j<3;j++){
            cin>>input[i][j];
            eq[i][j]=input[i][j];
        }
    }
    f21=eq[1][0]/eq[0][0];
    f31=eq[2][0]/eq[0][0];
    for(i=0;i<1;i++){
        for(j=0;j<3;j++){
            eq[i+1][j]=eq[i+1][j]-(f21*eq[i][j]);
            eq[i+2][j]=eq[i+2][j]-(f31*eq[i][j]);
        }
    }
    eq[1][0]=eq[2][0]=0;
    f32=eq[2][1]/eq[1][1];
    for(j=1;j<3;j++){
        eq[2][j]=eq[2][j]-(f32*eq[1][j]);
    }
    eq[2][1]=0;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            U[i][j]=eq[i][j];
        }
    }
    L[0][1]=L[0][2]=L[1][2]=0;
    L[0][0]=L[1][1]=L[2][2]=1;
    L[1][0]=f21;
    L[2][0]=f31;
    L[2][1]=f32;
    /*cout<<"Upper triangular matrix::";
    for(i=0;i<3;i++){
        cout<<"\n";
        for(j=0;j<3;j++){
            cout<<U[i][j]<<"\t\t";
        }
    }
    cout<<"\n\nLower triangular matrix::";
    for(i=0;i<3;i++){
        cout<<"\n";
        for(j=0;j<3;j++){
            cout<<L[i][j]<<"\t\t";
        }
    }*/
    ///for the first column
    d1=1;
    d2=0-(L[1][0]*d1);
    d3=0-(L[2][0]*d1)-(L[2][1]*d2);
    x3 = d3 / U[2][2];
    x2 = (d2-(U[1][2]*x3))/U[1][1];
    x1 = (d1-(U[0][2]*x3)-(U[0][1]*x2))/U[0][0];
    A[0][0]=x1;
    A[1][0]=x2;
    A[2][0]=x3;
    ///for the second column
    d1=0;
    d2=1-(L[1][0]*d1);
    d3=0-(L[2][0]*d1)-(L[2][1]*d2);
    x3 = d3 / U[2][2];
    x2 = (d2-(U[1][2]*x3))/U[1][1];
    x1 = (d1-(U[0][2]*x3)-(U[0][1]*x2))/U[0][0];
    A[0][1]=x1;
    A[1][1]=x2;
    A[2][1]=x3;
    ///for the third column
    d1=0;
    d2=0-(L[1][0]*d1);
    d3=1-(L[2][0]*d1)-(L[2][1]*d2);
    x3 = d3 / U[2][2];
    x2 = (d2-(U[1][2]*x3))/U[1][1];
    x1 = (d1-(U[0][2]*x3)-(U[0][1]*x2))/U[0][0];
    A[0][2]=x1;
    A[1][2]=x2;
    A[2][2]=x3;

    cout<<"\n\nThe inverse matrix::";
    for(i=0;i<3;i++){
        cout<<"\n";
        for(j=0;j<3;j++){
            cout<<A[i][j]<<"\t\t";
        }
    }
    cout<<"\n\n\n";
}
