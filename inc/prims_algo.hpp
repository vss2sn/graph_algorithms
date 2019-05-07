#include "utils.hpp"

class Prim{
private:
  std::vector<std::pair<int,int>> min_heap;
  GraphL g;
  std::vector<int> parent;
public:
  Prim(GraphL& g);
  void CreateMST();
  void GetMST();
};

struct compare{
  bool operator()(std::pair<int,int>& p1, std::pair<int,int>& p2);
};
