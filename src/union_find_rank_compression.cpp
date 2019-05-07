#include "union_find_rank_compression.hpp"

UnionFindRankCompression::UnionFindRankCompression(GraphE& g){
  this->g = g;
  Subset tmp;
  tmp.rank = 0;
  for(int i=0; i<g.V; i++){
    tmp.parent = i;
    subsets.push_back(tmp);
  }
}

int UnionFindRankCompression::Find(int id){
  if(subsets[id].parent != id) subsets[id].parent = Find(subsets[id].parent);
  return subsets[id].parent;
}

void UnionFindRankCompression::Union(int v1, int v2){
  int rv1 = Find(v1);
  int rv2 = Find(v2);
  if(subsets[rv1].rank < subsets[rv2].rank) subsets[rv1].parent = rv2;
  else if(subsets[rv1].rank > subsets[rv2].rank) subsets[rv2].parent = rv1;
  else{
    subsets[rv2].parent = rv1;
    subsets[rv1].rank++;
  }
}

bool UnionFindRankCompression::DetectCycle(){
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
  UnionFindRankCompression uf(g);
  uf.DetectCycle();
  return 0;
}
