#pragma once

#include <hupf/libdef.h>
#include <vector>
#include <string>
//a class is constructed by Input
//use below to populate input vector
//vector<Input> IP = Input::parseFile("robot info");

//#include <Input.h>
//if IP.empty() then do nothing, otherwise
//for every end effector (12 doubles) compute the angles in radians
//output angles (double)

namespace LibHUPF
{

class LIBHUPF_LIBRARY_INTERFACE ik_solver
{
private:
  void* _input;
public:
  ik_solver(const std::string& ik_file);
  //with DH-parameters as 6 arrays for distance, offset and twist respectively.
  ik_solver(double* a, double* d, double* theta, double* alpha, bool* rots);
  ~ik_solver();

  //end effector as an 16-valued double array, assuming row-major!
  std::vector< std::vector<double> > solve(double* ee);
};

}

#ifdef __cplusplus
extern "C"
{ 
#endif

LIBHUPF_LIBRARY_INTERFACE LibHUPF::ik_solver* create_ik_solver(double* a, double* d, double* theta, double* alpha, __int8* rots);

LIBHUPF_LIBRARY_INTERFACE void destroy_ik_solver(LibHUPF::ik_solver* iks)
{
  delete iks;
}

LIBHUPF_LIBRARY_INTERFACE int solve_ik(LibHUPF::ik_solver* iks, double* ee, double* ret)
{
  std::vector<std::vector<double>> sol = iks->solve(ee);
  size_t k=0;
  for (size_t i=0; i<sol.size(); ++i)
  {
    for (size_t j=0; j<sol[i].size();++j)
    {
      ret[k++] = sol[i][j];
    }
  }
  return sol.size();
}

#ifdef __cplusplus
}
#endif