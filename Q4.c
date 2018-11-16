#include <mpi.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>



int main(int argc, char** argv) 
{
    
	MPI_Init(NULL, NULL);
	int rank;
	int size;
    	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	int a[size];
	int i,sum=0;
	float avg;
	if(rank == 0)
	{
		printf("Random numbers\n");
		for(i=0;i<size;i++)
		{
			a[i]=rand()%20;
			printf("%d\n",a[i]);
			sum = sum + a[i];
		}
		avg = sum / size;
	}
	MPI_Bcast(&avg, 1, MPI_FLOAT, 0, MPI_COMM_WORLD);
	float std = (a[rank] - avg)*(a[rank] - avg);
	float *std_avgs = NULL;
	if(rank == 0)
	{
		std_avgs = malloc(sizeof(float) * size);

	}
	MPI_Gather(&std, 1, MPI_FLOAT, std_avgs,1, MPI_FLOAT, 0, MPI_COMM_WORLD);
	double savg;
	float ssum=0;
	if(rank == 0)
	{
		for(i=0;i<size;i++)
		{
			ssum = ssum + std_avgs[i];
		}
		savg = (ssum / size);
		savg = sqrt(savg);
		printf("Standard Deviation = %f\n",savg);
		
	}
	
	MPI_Finalize();

}

