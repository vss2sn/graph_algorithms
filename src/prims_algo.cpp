#include "prims_algo.hpp"
#include <algorithm>

Prim::Prim(GraphL& g){
  this->g  = g;
  std::pair<int,int> tmp(0, 0);
  min_heap.push_back(tmp);
  tmp.second = std::numeric_limits<int>::max();
  for(int i=1;i<g.V;++i){
    tmp.first = i;
    min_heap.push_back(tmp);
  }
  parent = std::vector<int>(g.V);
  std::fill(parent.begin(), parent.end(), -1); // Helps check if all reached if requried
  parent[0] = 0;
}

bool compare::operator()(std::pair<int,int>& p1, std::pair<int,int>& p2){
  if(p1.second > p2.second) return false;
  return true;
}

void Prim::CreateMST(){
  std::sort(min_heap.begin(), min_heap.end(), compare());
  int current = min_heap[0].first;
  while(!min_heap.empty()){
    current = min_heap[0].first;
    min_heap.erase(min_heap.begin());
    for(int i=0;i<g.adj[current].size();i++){
      for(int j=0;j<min_heap.size();j++){
        if(min_heap[j].first==g.adj[current][i].first
        && min_heap[j].second>g.adj[current][i].second){
          min_heap[j].second = g.adj[current][i].second;
          parent[min_heap[j].first] = current;
        }
      }
    }
    std::sort(min_heap.begin(), min_heap.end(), compare());
  }
}

void Prim::GetMST(){
  std::cout << "MST: " << std::endl;
  for(int i=1;i<g.V;i++){
    if(parent[i]>=0) std::cout << parent[i] << " --> " << i << std::endl;
    else std::cout << "No edge leading to " << i << std::endl;
  }
}

int main(){
  GraphL g(9, false, true);
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

  g.PrintGraph();
  Prim p(g);
  p.CreateMST();
  p.GetMST();
  return 0;
}
