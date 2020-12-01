#include<bits/stdc++.h>
using namespace std;

main()
{
    int i,j;
    double f21,f31,f32,x1,x2,x3,input[3][4],eq[3][4];
    for(i=0;i<3;i++){
        //cout<<"Enter the co-efficients of x1,x2,x3 and constant of equation "<<i+1<<":\n";
        for(j=0;j<4;j++){
            cin>>eq[i][j];
        }
    }
    f21=eq[1][0]/eq[0][0];
    f31=eq[2][0]/eq[0][0];
    for(i=0;i<1;i++){
        for(j=0;j<4;j++){
            eq[i+1][j]=eq[i+1][j]-(f21*eq[i][j]);
            eq[i+2][j]=eq[i+2][j]-(f31*eq[i][j]);
        }
    }
    eq[1][0]=eq[2][0]=0;
    cout<<"\nThe equation::\n";
    for(i=0;i<3;i++){
        cout<<"\n";
        for(j=0;j<4;j++){
            cout<<eq[i][j]<<"\t";
        }
    }
    f32=eq[2][1]/eq[1][1];
    for(j=1;j<4;j++){
        eq[2][j]=eq[2][j]-(f32*eq[1][j]);
    }
    eq[2][1]=0;
    cout<<"\nThe equation::\n";
    for(i=0;i<3;i++){
        cout<<"\n";
        for(j=0;j<4;j++){
            cout<<eq[i][j]<<"\t";
        }
    }
    x3 = eq[2][3] / eq[2][2];
    x2 = (eq[1][3]-(eq[1][2]*x3))/eq[1][1];
    x1 = (eq[0][3]-(eq[0][2]*x3)-(eq[0][1]*x2))/eq[0][0];
    cout<<"\n\n\nx1="<<x1<<"\nx2="<<x2<<"\nx3="<<x3<<"\n";
    return 0;
}
