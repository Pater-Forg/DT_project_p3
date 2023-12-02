#include <iostream>
#include <ctime>
#include "mpi.h"
#include "Squirrel2.h"

int main(int argc, char** argv)
{
	srand(time(0));

	const int	PARTS_COUNT		= 200;
	const int	BAG_SIZE		= 1000000;
	const int	PART_SIZE		= BAG_SIZE / PARTS_COUNT;
	const float MIN_W			= 10.0f;
	const float MAX_W			= 20.0f;
	float*		bag				= nullptr;
	float*		bag_part;
	float*		part_avg;
	int			rank;

	MPI_Init(&argc, &argv);

	// get id of current proccess
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	// process 0 is root
	if (rank == 0) {
		// root proccess fills array
		bag = new float [BAG_SIZE];
		fill_bag(bag, BAG_SIZE, MIN_W, MAX_W);
	}

	// array is shared between all proccesses (equal parts)
	bag_part = new float[PART_SIZE];
	MPI_Scatter(bag, PART_SIZE, MPI_FLOAT, bag_part, PART_SIZE, MPI_FLOAT, 0, MPI_COMM_WORLD);

	// each proccess calculates average of elements in it's part of array
	float avg = 0;
	average(bag_part, PART_SIZE, avg);

	// calculated average is saved in shared array
	part_avg = new float[PARTS_COUNT];
	MPI_Allgather(&avg, 1, MPI_FLOAT, part_avg, 1, MPI_FLOAT, MPI_COMM_WORLD);

	// root proccess tells about average in every part
	if (rank == 0) {
		for (int i = 0; i < PARTS_COUNT; i++) {
			std::cout << "Part " << i << " Avg: " << part_avg[i] << std::endl;
		}
		// root proccess frees memory of main array
		delete[] bag;
	}
	// each proccess frees local memory
	delete[] bag_part;
	delete[] part_avg;

	MPI_Finalize();

	return 0;
}
