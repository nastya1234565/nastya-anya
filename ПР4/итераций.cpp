#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
	return pow(x, 3) + 0.2 * pow(x, 2) + 0.5 * x - 1.2;
}

double g(double x) {
	return pow((1.2 - 0.2 * pow(x, 2) - 0.5 * x), 1.0 / 3.0);
}

int main() {
	double x0, x1, eps;
	int n = 0;

	cout << "Enter initial approximation: ";
	cin >> x0;
	cout << "Enter epsilon: ";
	cin >> eps;

	do {
		x1 = g(x0);
		n++;
		if (fabs(x1 - x0) < eps) {
			cout << "Solution found: " << x1 << endl;
			cout << "Number of iterations: " << n << endl;
			return 0;
		}
		x0 = x1;
	} while (true);

	return 0;
}
