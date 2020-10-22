#include <stdio.h>

int main() {
	
	/* Runge Kutta 2nd Order*/
	
	double L = 0.6, g = 9.81, h = 0.15;
	int ti = 0, tf = 6, N = (tf-ti)/h;
	double y[N], theta[N];
	double k1, k2;
	double y1, y2;
	double B = (g*h)/L;
	
	theta[0]=10; 
	y[0]=0;
	
	
	for (int i = 0;i < N;i++) {
		
		k1 = h*y[i];
		y1 = -B*theta[i];
		
		k2 = h*(y[i] + y1/2);
		y2 = -B*(theta[i] + k1/2);
			
			
		theta[i+1]= theta[i] + k2;
		y[i+1]= y[i] + y2;
	
	}
	
	
	for (int i=0;i<N;i++) {
				
				printf("%lf\n", theta[i]);
				
			}
	
	
	
	
	
	
}