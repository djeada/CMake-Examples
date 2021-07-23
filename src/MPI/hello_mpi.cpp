#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <mpi.h>

int main() {

  auto ierr = MPI_Init(NULL, NULL);

  if (ierr != 0) {
    std::cout << "HELLO_MPI - Fatal error!" << std::endl;
    return 1;
  }

  int id;
  int p;

  ierr = MPI_Comm_size(MPI_COMM_WORLD, &p);
  ierr = MPI_Comm_rank(MPI_COMM_WORLD, &id);

  if (ierr != 0)
    return 1;

  std::cout << "HELLO_MPI - Master process:" << id << std::endl;
  std::cout << "The number of processes is " << p << std::endl;

  auto wtime = MPI_Wtime();

  if (id == 0) {
    wtime = MPI_Wtime() - wtime;
    std::cout << "Elapsed wall clock time = " << wtime << " seconds."
              << std::endl;
  }

  MPI_Finalize();

  if (id == 0)
    std::cout << "Normal end of execution." << std::endl;

  return 0;
}
