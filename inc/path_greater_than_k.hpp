#include "utils.hpp"

class PathGreaterThanK{
private:
  GraphL g;
  int k, source, sink;
  std::vector<int> path;
  int path_length = 0;
  std::vector<std::vector<int>> paths;
  std::vector<int> chosen_paths_length;
public:
  PathGreaterThanK(GraphL& g, int k = 0); // Defualt value causes it to degenerate to find a path.
  void FindPathGreaterThanK(int source);
  bool Backtrack(int v);
  void GetPaths();
};
