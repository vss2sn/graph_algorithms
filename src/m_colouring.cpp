#include "m_colouring.hpp"

MColour::MColour(GraphM& g, int m){
  this->g = g;
  this->colour = std::vector<int>(g.V);
  this->m =m;
}

bool MColour::ColourGraphUtil(int v){
  if(v==g.V) return true;
  for(int c = 1; c<=m;c++){
    if(IsSafe(c, v)){
      colour[v]=c;
      if(ColourGraphUtil(v+1)) return true;
      colour[v] = 0;
    }
  }
  return false;
}

bool MColour::ColourGraph(){
  for(int i=0; i<g.V; i++) this->colour[i] = 0;
  if(ColourGraphUtil(0)) return true;
}

bool MColour::IsSafe(int c, int v){
  for(int i=0; i<g.V; i++){
    if(g.adj[v][i] && c == colour[i]) return false;
  }
  return true;
}

int main(){
  // std::vector<std::vector<int>> adj = {
  //   {0, 16, 13,  0,  0,  0},
  //   {0,  0,  0, 12,  0,  0},
  //   {0,  4,  0,  0, 14,  0},
  //   {0,  0,  9,  0,  0, 20},
  //   {0,  0,  0,  7,  0,  4},
  //   {0,  0,  0,  0,  0,  0},
  // };
  std::vector<std::vector<int>> adj = {
    {0, 1, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 0, 1},
    {1, 0, 1, 0},
  };
  GraphM g(adj);
  int m = 3;
  MColour mcol(g, m);
  if(mcol.ColourGraph()) std::cout << "The graph is coloured with " << m << " colours." << std::endl;
  else std::cout << "The graph cannot be coloured with " << m << " colours." << std::endl;
  return 0;
}
