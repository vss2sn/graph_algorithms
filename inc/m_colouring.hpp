#include "utils.hpp"

class MColour{
private:
  GraphM g;
  int m;
  std::vector<int> colour;
public:
  MColour(GraphM& g, int m);
  bool ColourGraph();
  bool ColourGraphUtil(int v);
  bool IsSafe(int c, int v);
};
