#include <iostream>
 double F(double p) 
 {
	return pow(0.5, p) - 1 - pow(p + 2, 2);
 }
int main()
{
	double a = -10, b = 0, e = 0.1, x;
	
	while ((b - a) > 2 * e)
	{
		double c = (a + b )/ 2;
		if (F(a) * F(c) < 0)
		{
			b = c;
		}
		else a = c;
	}
	x = (a + b )/ 2;
std:: cout << x << std::endl;
	return 0;
}
