#include <iostream>
#include <cmath>

using namespace std;

double equation(double x) {
    return pow(x, 3) + 0.2 * pow(x, 2) + 0.5 * x - 1.2;
}

double derivative(double x) {
    return 3 * pow(x, 2) + 0.4 * x + 0.5;
}

double chordMethod(double a, double b) {
    double x0 = a;
    double x1 = b;
    double x;

    do {
        x = x1 - (equation(x1) * (x0 - x1)) / (equation(x0) - equation(x1));
        x0 = x1;
        x1 = x;
    } while (abs(equation(x)) >= 0.001);

    return x;
}

double newtonMethod(double x0) {
    double x = x0;

    do {
        x0 = x;
        x = x0 - equation(x) / derivative(x);
    } while (abs(equation(x)) >= 0.001);

    return x;
}

int main() {
    setlocale(LC_ALL, "Russian");
    double a = -0.006;  // Начальное значение интервала
    double b = 0.006;   // Конечное значение интервала

    double rootChord = chordMethod(a, b);
    double rootNewton = newtonMethod(1.5);

    cout << "Корень найдет с помощью метода хорд: " << rootChord << endl;
    cout << "Корень найден с помощью касательных: " << rootNewton << endl;

    return 0;
}