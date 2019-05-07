#include "utils.hpp"

class Kruskal{
private:
  GraphE g;
  std::vector<int> parent;
  std::vector<Subset> subsets;
  std::vector<Edge> mst;
  int e = 0, r = 0; // Edge counter in mst and couneer for sorted edges
public:
  Kruskal(GraphE& g);
  void CreateMST();
  void GetMST();
  void Union(int v1, int v2);
  int Find(int id);

};
