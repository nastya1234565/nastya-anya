#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return pow(x, 3) + 0.2 * pow(x, 2) + 0.5 * x - 1.2;
}

double f_derivative(double x) {
    return 3 * pow(x, 2) + 0.4 * x + 0.5;
}

double newton_method(double x0, double eps) {
    double fx = f(x0);
    double f_dx = f_derivative(x0);
    double x1 = x0 - fx / f_dx;
    double fx1 = f(x1);
    while (abs(fx1) > eps) {
        x0 = x1;
        fx = fx1;
        f_dx = f_derivative(x0);
        x1 = x0 - fx / f_dx;
        fx1 = f(x1);
  
        if (iter > 1000) { // проверяем, не превысили ли лимит итераций
            cout << "Method failed to converge" << endl;
            return NAN;
        }
    }

    return x1;
}

int main() {
    setlocale(LC_ALL, "Russian");
    double x0, eps;
    cout << "Введите примерное значении функции: ";
    cin >> x0;
    cout << "Введите точность (h): ";
    cin >> eps;
    double root = newton_method(x0, eps);
    cout << "Корень: " << root << endl;
    return 0;
}
