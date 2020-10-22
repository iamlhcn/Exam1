	#include <mpi.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <math.h>
	#define PI acos(-1.0)

	int main(int argc, char** argv) {
		// Initialize the MPI environment
		
		int i, N = 100;
		double x[N], drv[N];
		double dx = PI/(N-1);
		
		MPI_Init(NULL, NULL);
		MPI_Status status;
		// Find out rank, size
		int rank;
		MPI_Comm_rank(MPI_COMM_WORLD, &rank);
		int size;
		MPI_Comm_size(MPI_COMM_WORLD, &size);
		
		if (rank == 0) 
			{
				int i;
				
				for(i = 0; i< N/4; i++)
					{
						x[i] = (PI*i)/99;
					}
				
				for(i = 0; i < N/4; i++)
				{
					if (i == 0) 
					{
						drv[i] = (sin(x[i+1])-sin(x[i]))/(dx);
					}
					
					if (i == (N/4) - 1) 
					{
						MPI_Recv(&x[i+1], 1, MPI_DOUBLE, 1, 1, MPI_COMM_WORLD, &status);
						MPI_Send(&x[i-1], 1, MPI_DOUBLE, 1, 1, MPI_COMM_WORLD);
						drv[i] = (sin(x[i+1])-sin(x[i-1]))/(2*dx);
					}
							
					else 
					{
						drv[i] = (sin(x[i+1])-sin(x[i-1]))/(2*dx);
					}
					
					
				}	
			} 


			if (rank == 1) 
					{
						int i;
						
						for(i = (N/4 - 1); i< N/2; i++)
							{
								x[i] = (PI*i)/99;
							}
						
						for(i = (N/4 - 1); i < N/2; i++)
						{
							if (i == (N/4 - 1)) 
							{
								MPI_Recv(&x[i-1], 1, MPI_DOUBLE, 0, 1, MPI_COMM_WORLD,&status);
								MPI_Send(&x[i+1], 1, MPI_DOUBLE, 0, 1, MPI_COMM_WORLD);
								drv[i] = (sin(x[i+1])-sin(x[i-1]))/(2*dx);
							}
							
							if (i == (N/2) - 1) 
							{
								MPI_Recv(&x[i+1], 1, MPI_DOUBLE, 2, 1, MPI_COMM_WORLD, &status);
								MPI_Send(&x[i-1], 1, MPI_DOUBLE, 2, 1, MPI_COMM_WORLD);
								drv[i] = (sin(x[i+1])-sin(x[i-1]))/(2*dx);
							}
									
							else 
							{
								drv[i] = (sin(x[i+1])-sin(x[i-1]))/(2*dx);
							}
							
						}	
					}

			if (rank == 2) 
					{
						int i;
						
						for(i = (N/2 - 1); i < (3*(N/4)) - 1; i++)
							{
								x[i] = (PI*i)/99;
							}
						
						for(i = (N/2 - 1); i < (3*(N/4)) - 1; i++)
						{
							if (i == (N/2 - 1)) 
							{
								MPI_Recv(&x[i-1], 1, MPI_DOUBLE, 1, 1, MPI_COMM_WORLD,&status);
								MPI_Send(&x[i+1], 1, MPI_DOUBLE, 1, 1, MPI_COMM_WORLD);
								drv[i] = (sin(x[i+1])-sin(x[i-1]))/(2*dx);
							}
							
							if (i == (3*(N/4)) - 1) 
							{
								MPI_Recv(&x[i+1], 1, MPI_DOUBLE, 3, 1, MPI_COMM_WORLD, &status);
								MPI_Send(&x[i-1], 1, MPI_DOUBLE, 3, 1, MPI_COMM_WORLD);
								drv[i] = (sin(x[i+1])-sin(x[i-1]))/(2*dx);
							}
									
							else 
							{
								drv[i] = (sin(x[i+1])-sin(x[i-1]))/(2*dx);
							}
							
						}	
					} 

			if (rank == 3) 
						{
							int i;
							
							for(i = (3*(N/4)) - 1; i < N; i++)
								{
									x[i] = (PI*i)/99;
								}
							
							for(i = (3*(N/4)) - 1; i < N; i++)
							{
								if (i == 3*(N/4) - 1) 
								{
									MPI_Recv(&x[i-1], 1, MPI_DOUBLE, 2, 1, MPI_COMM_WORLD,&status);
									MPI_Send(&x[i+1], 1, MPI_DOUBLE, 2, 1, MPI_COMM_WORLD);
									drv[i] = (sin(x[i+1])-sin(x[i-1]))/(2*dx);
								}
								
								if (i == (N - 1)) 
								{
									drv[i] = (sin(x[i])-sin(x[i-1]))/(dx);
								}
										
								else 
								{
									drv[i] = (sin(x[i+1])-sin(x[i-1]))/(2*dx);
								}
								
							}	
						} 
						
	MPI_Finalize();
	}