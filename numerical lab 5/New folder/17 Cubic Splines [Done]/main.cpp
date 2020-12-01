#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,k,givenPoint;
    float point,temp,funcValue=0;
    cout << "\n";
    cout << "Cubic Splines\n";
    cout << "---------------------\n";
    cout << "This program is to solve equations for 4 given point\n";

    float x[4],fofx[4];
    float fppEquation[2][4];
    float fppValue[4]={0};

    cout << "Enter 4 given x and co-responding f(x) : \n";
    for(i=0;i<4;i++)
        cin >> x[i] >> fofx[i];
    cout << "Enter a point to find function value : ";
    cin >> point;
    for(i=1;i<3;i++)
    {
        fppEquation[i-1][0]=x[i]-x[i-1];
        fppEquation[i-1][1]=2*(x[i+1]-x[i-1]);
        fppEquation[i-1][2]=x[i+1]-x[i];
        fppEquation[i-1][3]=((6/(x[i+1]-x[i]))*(fofx[i+1]-fofx[i])) +
                                ((6/(x[i]-x[i-1]))*(fofx[i-1]-fofx[i]));
    }
    fppEquation[0][0]=fppEquation[1][2]=0;
    cout << "-----------------------------------\n";
    cout << fppEquation[0][1] << "*f``(" << x[1] << ") + " << fppEquation[0][2] << "*f``(" << x[2] << ") = " << fppEquation[0][3] << "\n";
    cout << fppEquation[1][0] << "*f``(" << x[1] << ") + " << fppEquation[1][1] << "*f``(" << x[2] << ") = " << fppEquation[1][3] << "\n";
    cout << "-----------------------------------\n";
    fppEquation[0][3]*=-1;
    fppEquation[1][3]*=-1;
    fppValue[1]=((fppEquation[1][3]*fppEquation[0][2])-(fppEquation[0][3]*fppEquation[1][1]))/
                    ((fppEquation[0][1]*fppEquation[1][1])-(fppEquation[1][0]*fppEquation[0][2]));
    fppValue[2]=((fppEquation[0][3]*fppEquation[1][0])-(fppEquation[1][3]*fppEquation[0][1]))/
                    ((fppEquation[0][1]*fppEquation[1][1])-(fppEquation[1][0]*fppEquation[0][2]));

    for(i=0;i<4;i++)
        if(point<x[i])
            break;
    float flag;
    flag=x[i]-x[i-1];
    funcValue+=(fppValue[i-1]/(6*flag))*pow((x[i]-point),3);
    funcValue+=(fppValue[i]/(6*flag))*pow((point-x[i-1]),3);
    funcValue+=((fofx[i-1]/flag)-((fppValue[i-1]*flag)/6))*(x[i]-point);
    funcValue+=((fofx[i]/flag)-((fppValue[i]*flag)/6))*(point-x[i-1]);

    cout << "\nFunction Value at point " << point << " is " << funcValue << "\n";
    cout << "-----------------------------------\n";

    return 0;
}
