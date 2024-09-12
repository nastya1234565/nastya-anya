#include <iostream>
#include <cmath>

using namespace std;

double f(double x) 
{
    return pow(x, 3) + 0.2 * pow(x, 2) + 0.5 * x - 1.2;
}

double chord_method(double a, double b, double eps)
{
    double fa = f(a);
    double fb = f(b);
    double c = a - (fa * (b - a)) / (fb - fa);
    double fc = f(c);
    while (abs(fc) > eps) 
    {
        if (fa * fc < 0)
        {
            b = c;
            fb = fc;
        }
        else 
        {
            a = c;
            fa = fc;
        }
        c = a - (fa * (b - a)) / (fb - fa);
        fc = f(c);
    }
    return c;
}

int main() {
    setlocale(LC_ALL, "Russian");

    double a, b, eps;
    cout << "Введите промежуток [a, b]: ";
    cin >> a >> b;
    cout << "Введите точность (h): ";
    cin >> eps;
    double root = chord_method(a, b, eps);
    cout << "Корень " << root << endl;
    return 0;
}