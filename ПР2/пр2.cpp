#include <iostream>

int main()
{
	double a = 0,b=10,h=0.001;
	double x1 = a,x2=a+h, y1=exp(-2*x1)-2*x1+1;
	while (x2 < b)
	{
		double y2 = exp(-2 * x2) - 2 * x2 + 1;
		if (y1 * y2 < 0)
		{
			std::cout << x1<< std::endl << x2;
		   
		}
		
			x1 = x2;
			x2 = x1 + h; 
			y1 = y2;
	}
	return 0;
}

