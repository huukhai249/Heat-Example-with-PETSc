// this is main function to solve Heat Steady Transfer
// Include "petscsles.h" so that we can use SLES solvers. Note that this file
// automatically includes:
//      petsc.h - base PETSc routines
//      petscvec.h - vectors
//      petscsys.h - system routines
//      petscmat.h - matrices
//      petscis.h - index sets
//      petscksp.h - Krylov subspace methods
//      petscviewer.h - viewers
//      petscpc.h - preconditioners
static char help[] = "Solves a thermal linear system with KSP.\n\
Input parameters include:\n\
  -view_exact_sol   : write exact solution vector to stdout\n\
  -m <mesh_x>       : number of mesh points in x-direction\n\
  -n <mesh_y>       : number of mesh points in y-direction\n\n";


int main(int argc, char **args)
{
  Vec               x, b, u; // approx solution, RHS, exact solution
  Mat               A;       // linear system matrix 
  SLES              sles;    // linear solver context
  PetscRandom       rctx;    // random number generator context
  PetscReal         norm;    // norm of solution error
  int               i,j, I, J, Istart, Iend, ierr, m=4, n=4, its;
  PetscTruth        flg; 
  PetscScalar       v, h, one=1.0, neg_one= -1.0;
  KSP               ksp;
  KSPType           ksptype;
  PC                pc;
  PCType            pctype;
  PetscInitialize(&argc, &args, (char *)0, help);
  PetscOptionsGetInt(PETSC_NULL, "-m", &m, PETSC_NULL);
  PetscOptionsGetInt(PETSC_NULL, "-n", &n, PETSC_NULL);
  //-----------------------------------------------------------------------------------------------//
  //-------------------- Now we continue to Matric create -----------------------------------------//
  //-----------------------------------------------------------------------------------------------//
  /*  When using MatCreate(), the matrix format can be specified at runtime.
      Also, the parallel partitioning of the matrix is determined by PETSc at runtime.
      Performance tuning note: 
            For problems of substantial size, preallocation of matrix memory is crucial for
            attaining good performance. 
            Since preallocation is not possible via the generic matrix creation routine MatCreate(),
            we recommend for practical problems instead to use the creation routine for a particular
            matrix format, e.g., MatCreateMPIAIJ() – parallel AIJ (compressed sparse row)
            MatCreateMPIBAIJ() – parallel block AIJ
            See the matrix chapter of the users manual for details
  */
  MatCreate(PETSC_COMM_WORLD,PETSC_DECIDE,PETSC_DECIDE,m*n,m*n,&A);
}
  
