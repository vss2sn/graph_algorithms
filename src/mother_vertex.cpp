#include "mother_vertex.hpp"

MotherVertex::MotherVertex(GraphL& g){
  this->g = g;
}

bool MotherVertex::FindMotherVertex(){
  int v;
  for(int i=0;i<g.V;++i){
    if(!g.visited[i]){
      g.DFS(i);
      v = i;
    }
  }
  //Minor optimization
  // if(v==0){
  //   mother_vertex = v;
  //   found = true;
  //   return true;
  // }
  g.ResetVisited();
  g.DFS(v);
  std::vector<bool>::iterator it;
  for(it = g.visited.begin(); it!=g.visited.end();++it){
    if(!(*it)) break;
  }
  if(it!=g.visited.end()) return false;
  mother_vertex = v;
  found = true;
  return true;
}

bool MotherVertex::Found(){
  return found;
}

int MotherVertex::MotherVertexID(){
  if(found) return mother_vertex;
  return -1;
}

int main()
{
    // int k = 3;
    GraphL g(6, false, true);
    // g.AddEdge(0, 1);
    g.AddEdge(0, 2);
    // g.AddEdge(1, 0);
    g.AddEdge(1, 2);
    g.AddEdge(1, 5);
    g.AddEdge(2, 3);
    g.AddEdge(2, 4);
    g.AddEdge(2, 5);
    g.AddEdge(3, 4);

    MotherVertex mv(g);
    mv.FindMotherVertex();
    if(mv.Found()) std::cout << "At least 1 mother vertex exists. Id: " << mv.MotherVertexID() << std::endl;
    else std::cout << "No mother vertex exists" << std::endl;
    return 0;
}
