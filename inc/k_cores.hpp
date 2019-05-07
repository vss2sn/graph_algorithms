#include "utils.hpp"

class KCores{
private:
  GraphL g;
  std::vector<int> vDegree;
  int k;
public:
  KCores(GraphL& g, int k=3);
  bool DFSDec(int v);
  void FindKCores();
  void PrintKCores();
};
