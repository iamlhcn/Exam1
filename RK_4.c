#include <stdio.h>

int main() {
	
	/* Runge Kutta 4th Order*/
	
	
	double L = 0.6, g = 9.81, h = 0.15;
	int ti = 0, tf = 6, N = (tf-ti)/h;
	double omega[N], theta[N];
	double k1, k2, k3, k4;
	double j1, j2, j3, j4;
	double B = (g*h)/L;
	
	theta[0]=10; 
	omega[0]=0;
	
	
	for (int i = 0;i < N;i++) {
		
		k1 = h*omega[i];
		j1 = -B*theta[i];
		
		k2 = h*(omega[i] + j1/2);
		j2 = -B*(theta[i] + k1/2);
			
		k3 = h*(omega[i] + j2/2);
		j3 = -B*(theta[i] + k2/2);
		
		k4 = h*(omega[i] + j3);
		j4 = -B*(theta[i] + k3);
			
		theta[i+1]= theta[i] + (k1 + 2*k2 + 2*k3 + k4)/6;
		omega[i+1]= omega[i] + (j1 + 2*j2 + 2*j3 + j4)/6;
	}
	
	
	for (int i=0;i<N;i++) {
				
			printf("%lf\n", theta[i]);
				
		}
	
	
	
	
	
	
}