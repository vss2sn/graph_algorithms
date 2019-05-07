#include "utils.hpp"

class UnionFind{
private:
  GraphE g;
  std::vector<int> parent;
public:
  UnionFind(GraphE& g);
  int Find(int id);
  void Union(int v1, int v2);
  bool DetectCycle();
};
