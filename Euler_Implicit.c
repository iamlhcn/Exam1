#include <stdio.h>

int main() {
	
	/* Implicit Euler */
	
	double L = 0.6, g = 9.81, h = 0.15;
	int ti = 0, tf = 6, N = (tf-ti)/h;
	double y[N], Theta[N];

	Theta[0] = 10;
	y[0] = 0;
	
	for (int i=0;i<N;i++) {
		
		y[i+1]=y[i]-(g/L)*Theta[i]*h;
		Theta[i+1]=Theta[i] + y[i+1]*h;

	}


	for (int i=0;i<N;i++) {
			
			printf("%lf\n", Theta[i]);
			
		}	
	
	
}