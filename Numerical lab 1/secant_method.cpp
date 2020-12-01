#include <bits/stdc++.h>
using namespace std;

double f(double X)
{
    return 3*X + sin(X) - exp(X);
}

int main()
{
    int i=0;
    double Xl, Xu, Xr, fl, fu, fr, error, minerr, xold=0;

    cout << "Enter the value of Xl : ";
    cin >> Xl;
    cout << "Enter the value of Xu : ";
    cin >> Xu;
    cout << "The Approximate error : ";
    cin >> minerr;

    do
    {
        fl=f(Xl);
        fu=f(Xu);
        Xr=((Xl*fu)-(Xu*fl))/(fu-fl);

        error=fabs((Xr-xold)/Xr)*100;
        xold = Xr;
        fr=f(Xr);
        fl=fu;
        fu=fr;
        Xl=Xu;
        Xu=Xr;
        i++;

        cout << endl << "No of Iteration : " << i << '\t' << "Root : " << Xr << '\t' << "Error : " << error;
    } while (error>minerr);

    return 0;
}
