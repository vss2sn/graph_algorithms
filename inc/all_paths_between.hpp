#include "utils.hpp"

class AllPathsBetween{
private:
  GraphL g;
  int source, sink;
  std::vector<std::vector<int>> v;
  std::vector<std::vector<int>> paths;
  std::vector<int> path;
public:
  AllPathsBetween(GraphL& g);
  void FindAllPathsBetween(int source, int sink);
  void Backtrack(int source);
  void GetPaths();
};
