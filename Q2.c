#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    MPI_Init(NULL, NULL);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int num1, num2;
    if(rank == 0)
    {
	printf("Master process %d Enter input\n",rank);
	scanf("%d",&num1);
        MPI_Send(&num1, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    }
    else if(rank == 1)
    {
	MPI_Recv(&num2, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	printf("slave process %d - value received %d\n", rank,num2);
    }

    MPI_Finalize();
}
