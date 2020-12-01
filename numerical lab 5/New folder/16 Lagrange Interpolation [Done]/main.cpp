#include <bits/stdc++.h>
using namespace std;

int main()
{
int i=0,j=0,givenPoint=0;
    float funcValue=0,temp=0,point=0;
    cout << "--------------------------------------------------------\n";
    cout << "Lagrange Interpolating Polynomial\n";
    cout << "--------------------------------------------------------\n";
    cout << "How many given point for this Polynomial : ";
    cin >> givenPoint;
    float x[givenPoint],fofx[givenPoint];

    cout << "Enter " << givenPoint << " x and co-responding f(x) :\n";
    for(i=0;i<givenPoint;i++)
        cin >> x[i] >> fofx[i];
    cout << "Enter a point to find function value : ";
    cin >> point;
    for(i=0;i<givenPoint;i++)
    {
        for(j=0,temp=fofx[i];j<givenPoint;j++)
        {
            if(i!=j)
                temp*=(point-x[j])/(x[i]-x[j]);
        }
        funcValue+=temp;
    }
    cout << "\n----------------------------------------------\n";
    cout << "Value of the function for point " << point << " is " << funcValue;
    cout << "\n----------------------------------------------\n";
    return 0;
}
