#include<bits/stdc++.h>
using namespace std;
int main()
{
int n;
double x[n],y[n],XX0,XX1,XX2,XX3,YY0,YY1,YY2,YY3,input,x1,x2,x3,Result;

cout<<"Enter the number of points: ";
cin>>n;

cout<<"Enter the value of X:\n";
for( int i = 0 ; i < n ; i++ )
{
cin>>x[i];
}

cout<<"Enter the value of Y:\n";
for( int i = 0 ; i < n ; i++ )
{
cin>>y[i];
}

cout<<"Enter the value of y: ";
cin>>input;
for( int i = 0 ; i < n-1 ; i++ )
{
if( ( input >= x[i] && input<= x[i+1] ) )
{
XX0=x[i-1];
XX1=x[i];
XX2=x[i+1];
XX3=x[i+2];
YY0=y[i-1];
YY1=y[i];
YY2=y[i+1];
YY3=y[i+2];
}
}

x1=( YY1 - YY0 ) / ( XX1 - XX0 );
x2=( ( ( YY2 - YY1 ) / ( XX2 - XX1 ) ) - ( YY1 - YY0 ) / ( XX1 - XX0 ) )/ ( XX2 - XX0 );
x3=( ( ( ( ( YY3 - YY2 ) / ( XX3 - XX2 ) ) - ( ( YY2 - YY1 ) / ( XX2 - XX1 ) ) ) / ( XX3 - XX1 ) ) - ( ( ( YY2 - YY1 )/ ( XX2 - XX1 ) ) - ( YY1 - YY0 ) / ( XX1 - XX0 ) )/ ( XX2 - XX0 ) ) / ( XX3 - XX0 );

Result=YY0+(x1*(input-XX0))+(x2*(input-XX0)*(input-XX1))+(x3*(input-XX0)*(input-XX1)*(input-XX2));
cout<<endl<<"Result is: "<<Result;
return 0;
}

/*

x= 0 1 2 5.5 11 13 16 18

y= 0.5 3.134 5.3 9.9 10.2 9.35 7.2 6.2


*/
