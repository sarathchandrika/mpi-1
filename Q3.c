#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) 
{
    
	MPI_Init(NULL, NULL);
	int rank;

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int num1,num2;
	if(rank == 0)
	{
		
		printf("Root process %d Enter a value\n",rank);
		scanf("%d",&num1);
	
	}
	MPI_Bcast(&num1, 1, MPI_INT, 0, MPI_COMM_WORLD);

	printf("process %d - Value received - %d\n",rank,num1);

	MPI_Finalize();

}
