#include <hupf/ik.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  //distances
  double a[6] = {0.0,-0.425,-0.39225,0.0,0.0,0.0}; 
  //offset
  double d[6] = {0.089159,0.0,0.0,0.10915,0.09465,0.0};
  //rotation offset
  double theta[6] = {0.0,0.0,0.0,0.0,0.0,0.0};
  //twists
  double alpha[6] = {1.5708,0.0,0.0,1.5708,-1.5708,0.0};
  //R or P
  bool rots[6] = {1,1,1,1,1,1};

  LibHUPF::ik_solver ik(a,d,theta,alpha,rots);

  double flat_ee[16] = {-0.582564,0.694272,0.422618,-0.333226,-0.271654,0.323744,-0.906308,-0.275819,-0.766044,-0.642788,0,-0.489578,0,0,0,1};  

  std::vector< std::vector<double> > sols;
  sols = ik.solve(flat_ee);
  cout << "Size of solutions: " << sols.size() << endl;
  for (size_t i=0; i<sols.size(); ++i)
  {
    for (size_t j=0; j<sols[i].size(); ++ j)
      cout << "Joint " << j << ": " << sols[i][j] << endl;
    cout << endl;
  }

}
