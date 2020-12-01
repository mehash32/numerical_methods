#include <bits/stdc++.h>
using namespace std;
#define SIZE 11
float x[SIZE],fofx[SIZE];
float valueofB[SIZE];
float dividedDifference(int start,int sz)
{
    float x1,x2,fx1,fx2;
    if(sz>2)
    {
        fx2=dividedDifference(start+1,sz-1);
        fx1=dividedDifference(start,sz-1);
        x2=x[start+sz-1];
        x1=x[start];
    }
    else
    {
        fx2=fofx[start+sz-1];
        fx1=fofx[start+sz-2];
        x2=x[start+sz-1];
        x1=x[start+sz-2];
    }
    return ((fx2-fx1)/(x2-x1));
}

int main()
{
    int i=0,j=0,givenPoint=0,order=0;
    float funcValue=0,temp=0,point=0;
    cout << "\n";
    cout << "Newton's Divided Difference Interpolating Polynomial\n";
    cout << "\n";
    cout << "Enter Order of the Polynomial (max 10) : ";
    cin >> order;
    givenPoint=order+1;

    cout << "Enter " << givenPoint << " x and co-responding f(x) :\n";
    for(i=0;i<givenPoint;i++)
        cin >> x[i] >> fofx[i];
    cout << "Enter a point to find function value : ";
    cin >> point;
    funcValue=valueofB[0]=fofx[0];

    cout << "\n";
    cout << "Newton's Interpolating Polynomial: \n";
    cout << "f" << order << "(x)= " << valueofB[i] << " ";
    for(i=1;i<givenPoint;i++)
    {
        temp=0;
        valueofB[i]=dividedDifference(0,i+1);
        temp=valueofB[i];
        if(valueofB[i]>=0)
            cout << "+";
        cout << valueofB[i];
        for(j=1;j<=i;j++)
        {
            cout << "(x";
            if(x[j-1]<=0)
                cout << "+";
            cout << (-1)*x[j-1] << ")";
            temp*=(point-x[j-1]);
        }
        funcValue+=temp;
        cout << " ";
    }
    cout << "\n";
    cout << "\nFunction value at point " << point << " is : " << funcValue;
    cout << "\n\n";
    return 0;
}
