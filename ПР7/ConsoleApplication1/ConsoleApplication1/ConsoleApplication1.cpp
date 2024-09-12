#include <iostream>
#include <vector>

using namespace std;

double lagrangeInterpolation(vector<double> x, vector<double> f, double xi) {
    double result = 0.0;
    for (int i = 0; i < x.size(); i++) {
        double term = f[i];
        for (int j = 0; j < x.size(); j++) {
            if (j != i) {
                term = term * (xi - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }
    return result;
}

int main() {
    vector<double> x = { 1, 2, 3, 4, 5 };
    vector<double> f = { 48, 24, 8, 12, 24 };
    double xi = 2; // Ваше значение xi для интерполяции

    double interpolatedValue = lagrangeInterpolation(x, f, xi);
    cout << "Значение интерполяционного многочлена в точке  " << xi << "= " << interpolatedValue << endl;

    return 0;
}