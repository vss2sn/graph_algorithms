#include "union_find.hpp"

UnionFind::UnionFind(GraphE& g){
  this->g = g;
  parent = std::vector<int>(g.V);
  for (int i=0;i<g.V;i++){
    parent[i] = -1;
  }
}

int UnionFind::Find(int id){
  if(parent[id]==-1) return id;
  return Find(parent[id]);
}

void UnionFind::Union(int v1, int v2){
  int rv1 = Find(v1);
  int rv2 = Find(v2);
  if(rv1!=rv2){
    parent[rv2]=rv1;
  }
}

bool UnionFind::DetectCycle(){
  for(int i=0;i<g.edges.size();i++){
    int v1 = Find(g.edges[i].u);
    int v2 = Find(g.edges[i].v);
    if(v1 == v2){
      std::cout << "Cycle detected: " << std::endl;
      std::cout << "Edge: " << g.edges[i].u << " --- " << g.edges[i].v << std::endl;
      // std::cout << "Common root: " << v1 << std::endl;
      return true;
    }
    Union(v1, v2);
  }
  std::cout << "No cycle detected: " << std::endl;
  return false;
}

int main(){
  GraphE g;
  g.AddEdge(0, 1);
  g.AddEdge(1, 2);
  g.AddEdge(2, 3);
  g.AddEdge(3, 4);
  g.AddEdge(3, 5);
  g.AddEdge(3, 6);
  g.AddEdge(5, 6);
  UnionFind uf(g);
  uf.DetectCycle();


}
