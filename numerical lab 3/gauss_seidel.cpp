#include<bits/stdc++.h>
using namespace std;
int main()
{
    double input[3][4],equation[3][4],x1_1=0.0,x1_2=0.0,x1_3=0.0,x2_1=0.0,x2_2=0.0,x2_3=0.0,Es;
    cout<<"Please enter the Es:";
    cin>>Es;

    cout<<"\nPlease enter the co-efficients of the equation:\n";
    for( int i=0 ; i < 3 ; i++ ){
        for( int j=0 ; j < 4 ; j++ ){
            cin>>input[i][j];
        }
    }

    for( int i=0 ; i < 3 ; i++ ){
        if( abs(input[i][0]) > abs( input[i][1] + input[i][2] ) ){
            for( int j=0 ; j < 4 ; j++ ){
                equation[0][j]=input[i][j];
            }
        }else if( abs(input[i][1]) > abs( input[i][0] + input[i][2] ) ){
            for( int j=0 ; j < 4 ; j++ ){
                equation[1][j]=input[i][j];
            }
        }else if( abs(input[i][2]) > abs( input[i][0] + input[i][1] ) ){
            for( int j=0 ; j < 4 ; j++ ){
                equation[2][j]=input[i][j];
            }
        }
    }

    for(int i=0 ; ; i++ ){
        if( x2_2 == 0.0 && x2_3 == 0.0 ){
            x2_1=equation[0][3]/equation[0][0];
            x2_2=(equation[1][3]-(equation[1][0]*x2_1))/equation[1][1];
            x2_3=(equation[2][3]-(equation[2][0]*x2_1)-(equation[2][1]*x2_2))/equation[2][2];


            cout<<"\nAfter "<<i+1<<"st iteration:\n"<<"X1 = "<<x2_1<<"\nX2 = "<<x2_2<<"\nX3 = "<<x2_3<<endl;

            x1_1=x2_1;
            x1_2=x2_2;
            x1_3=x2_3;
        }else{
            x2_1=(equation[0][3]-(equation[0][1]*x1_2)-(equation[0][2]*x1_3))/equation[0][0];
            x2_2=(equation[1][3]-(equation[1][0]*x2_1)-(equation[1][2]*x1_3))/equation[1][1];
            x2_3=(equation[2][3]-(equation[2][0]*x2_1)-(equation[2][1]*x2_2))/equation[2][2];

            if(i==1)
                cout<<"\nAfter "<<i+1<<"nd iteration:\n"<<"X1 = "<<x2_1<<"\nX2 = "<<x2_2<<"\nX3 = "<<x2_3<<endl;
            else if(i==2)
                cout<<"\nAfter "<<i+1<<"rd iteration:\n"<<"X1 = "<<x2_1<<"\nX2 = "<<x2_2<<"\nX3 = "<<x2_3<<endl;
            else
                cout<<"\nAfter "<<i+1<<"th iteration:\n"<<"X1 = "<<x2_1<<"\nX2 = "<<x2_2<<"\nX3 = "<<x2_3<<endl;

            cout<<"Error of X1: Ea1 = "<<(abs((x2_1-x1_1)/x2_1)*100)<<"\nError of X2: Ea2 = "<<(abs((x2_2-x1_2)/x2_2)*100)<<"\nError of X3: Ea3 = "<<(abs((x2_2-x1_2)/x2_2)*100)<<endl;

            if((abs((x2_1-x1_1)/x2_1)*100) < Es && (abs((x2_2-x1_2)/x2_2)*100) < Es && (abs((x2_2-x1_2)/x2_2)*100) < Es ){
                break;
            }

            x1_1=x2_1;
            x1_2=x2_2;
            x1_3=x2_3;
        }
    }
    return 0;
}

/*2 -6 -1 -38
-3 -1 7 -34
-8 1 -2 -20*/
