#include "utils.hpp"

class UnionFindRankCompression{
private:
  GraphE g;
  std::vector<int> parent;
  std::vector<Subset> subsets;
public:
  UnionFindRankCompression(GraphE& g);
  int Find(int id);
  void Union(int v1, int v2);
  bool DetectCycle();
};
