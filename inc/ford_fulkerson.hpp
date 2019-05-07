#include "utils.hpp"

#define LARGE_NUM 10000

class FordFulkerson{
private:
  GraphM g;
  int source, sink;
  int adj_s;
public:
  FordFulkerson(GraphM g, int source, int sink);
  int FordFul();
};
