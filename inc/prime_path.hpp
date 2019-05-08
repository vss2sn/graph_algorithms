#include "utils.hpp"

class PrimePath{
private:
  std::vector<int> v;
  GraphL g;
  int c, vs;
public:
  PrimePath();
  void SieveOfEratosthenes();
  bool compare(int n1, int n2);
  void FindShortestPath(int n1, int n2);
};
