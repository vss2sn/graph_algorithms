#include "kruskals_algo.hpp"
#include <algorithm>
Kruskal::Kruskal(GraphE& g){
  this->g = g;
  Edge tmp_e(0,0,0);
  Subset tmp;
  tmp.rank = 0;
  for(int i = 0; i<g.V; i++){
    mst.push_back(tmp_e);
    tmp.parent = i;
    subsets.push_back(tmp);
  }
}

void Kruskal::CreateMST(){
  std::sort(g.edges.begin(), g.edges.end(), CompareEdgeWeights());
  int rv1, rv2;
  while(e < g.V-1){
    rv1 = Find(g.edges[r].u);
    rv2 = Find(g.edges[r].v);
    if(rv1!=rv2){
      mst[e] = g.edges[r];
      Union(rv1, rv2);
      e++;
    }
    r++;
  }
}

void Kruskal::GetMST(){
  std::cout << "MST: " << std::endl;
  for (r = 0; r < e; ++r){
    std::cout << "Edge: " << mst[r].u << " --> " << mst[r].v << " Weight: " << mst[r].w << std::endl;
  }
}

int Kruskal::Find(int id){
  if(subsets[id].parent != id) subsets[id].parent = Find(subsets[id].parent);
  return subsets[id].parent;
}

void Kruskal::Union(int v1, int v2){
  int rv1 = Find(v1);
  int rv2 = Find(v2);
  if(subsets[rv1].rank < subsets[rv2].rank) subsets[rv1].parent = rv2;
  else if(subsets[rv1].rank > subsets[rv2].rank) subsets[rv2].parent = rv1;
  else{
    subsets[rv1].parent = rv2;
    subsets[rv2].rank++;
  }
}

int main(){
  GraphE g;
  // g.AddEdge(0,1,10);
  // g.AddEdge(0,2,6);
  // g.AddEdge(0,3,5);
  // g.AddEdge(1,3,15);
  // g.AddEdge(2,3,4);

  g.AddEdge(0, 1, 4);
  g.AddEdge(0, 7, 8);
  g.AddEdge(1, 2, 8);
  g.AddEdge(1, 7, 11);
  g.AddEdge(2, 3, 7);
  g.AddEdge(2, 8, 2);
  g.AddEdge(2, 5, 4);
  g.AddEdge(3, 4, 9);
  g.AddEdge(3, 5, 14);
  g.AddEdge(4, 5, 10);
  g.AddEdge(5, 6, 2);
  g.AddEdge(6, 7, 1);
  g.AddEdge(6, 8, 6);
  g.AddEdge(7, 8, 7);

  g.PrintGraphE();
  Kruskal k(g);
  k.CreateMST();
  k.GetMST();
  return 0;
}
