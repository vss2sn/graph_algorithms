#include "ford_fulkerson.hpp"

FordFulkerson::FordFulkerson(GraphM g, int source, int sink){
  this->g = g;
  this->source = source;
  this->sink = sink;
  Vertex tmp;
  adj_s = g.adj.size();
}

int FordFulkerson::FordFul(){
  GraphM rg(g.adj); //residual graph matrix
  int maxFlow = 0;
  int p_flow;
  int u;
  int count = 0;

  while(rg.DFS(source, sink)){
    p_flow = LARGE_NUM;
    for(int i = sink; i!=source; i = rg.v[i].pid){
      u = rg.v[i].pid;
      p_flow = std::min(p_flow, rg.adj[u][i]);
    }
    for(int i = sink; i!=source; i = rg.v[i].pid){
      u = rg.v[i].pid;
      rg.adj[u][i] -=p_flow;
      rg.adj[i][u] += p_flow;
    }
    maxFlow +=p_flow;
    std::cout << "---> Path flow: " << p_flow << std::endl;
  }
  return maxFlow;
}

int main() {
  std::vector<std::vector<int>> adj = {
    {0, 16, 13,  0,  0,  0},
    {0,  0,  0, 12,  0,  0},
    {0,  4,  0,  0, 14,  0},
    {0,  0,  9,  0,  0, 20},
    {0,  0,  0,  7,  0,  4},
    {0,  0,  0,  0,  0,  0},
  };

  GraphM g(adj);
  g.PrintGraphM();
  // For making all edges traversable in both directions.
  // for(int i=0;i<g.adj.size(); i++){
  //   for(int j=0;j<g.adj.size(); j++){
  //     if(g.adj[i][j]!=0)
  //       g.adj[j][i] = g.adj[i][j];
  //   }
  // }
  // g.PrintGraphM();

  int source = 0 , sink = adj.size()-1;
  FordFulkerson f(g, source, sink);
  std::cout <<"The max flow is "<< f.FordFul()<<std::endl;

  return 0;
}
