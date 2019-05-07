#include "utils.hpp"

class MotherVertex{
private:
  GraphL g;
  int mother_vertex;
  bool found;
public:
  MotherVertex(GraphL& g);
  bool FindMotherVertex();
  bool Found();
  int MotherVertexID();
};
