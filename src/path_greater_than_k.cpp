#include "path_greater_than_k.hpp"

PathGreaterThanK::PathGreaterThanK(GraphL& g, int k){
  this->g = g;
  this->k = k;
}

bool PathGreaterThanK::Backtrack(int v){
  path.push_back(v);
  g.visited[v] = true;
  for(int i=0;i<g.adj[v].size(); i++){
    if(g.visited[g.adj[v][i].first]) continue;
    else{
      path_length += g.adj[v][i].second;
      if(path_length > k){
        paths.push_back(path);
        chosen_paths_length.push_back(path_length);
        return true; // Comment line to find all paths greater than k
      }
      if(Backtrack(g.adj[v][i].first)) return true;
      path_length -= g.adj[v][i].second;
    }
  }
  g.visited[v] = false;
  path.pop_back();
  return false;
}
void PathGreaterThanK::GetPaths(){
  if(paths.size() == 0) std::cout << "No paths found" << std::endl;
  else{
    std::cout << "Path found:" << std::endl;
    for(int i=0;i<paths.size();i++){
      std::cout << paths[i][0];
      for(int j=1;j<paths[i].size();j++){
        std::cout << " --> " << paths[i][j];
      }
      std::cout << std::endl;
      std::cout << "Length of path: " << chosen_paths_length[i] << std::endl;
    }
  }
}

void PathGreaterThanK::FindPathGreaterThanK(int source){
  this->source = source;
  Backtrack(source);
}

int main(){
  GraphL g(6, false, false);
  g.AddEdge(0, 1, 2);
  g.AddEdge(0, 2, 2);
  g.AddEdge(1, 0, 2);
  g.AddEdge(1, 2, 2);
  g.AddEdge(1, 5, 2);
  g.AddEdge(2, 3, 2);
  g.AddEdge(2, 4, 2);
  g.AddEdge(2, 5, 2);
  g.AddEdge(3, 4, 2);
  g.AddEdge(3, 5, 2);
  g.AddEdge(4, 5, 2);


  // GraphL g(9, false, true);
  // g.AddEdge(0, 1, 4);
  //  g.AddEdge(0, 7, 8);
  //  g.AddEdge(1, 2, 8);
  //  g.AddEdge(1, 7, 11);
  //  g.AddEdge(2, 3, 7);
  //  g.AddEdge(2, 8, 2);
  //  g.AddEdge(2, 5, 4);
  //  g.AddEdge(3, 4, 9);
  //  g.AddEdge(3, 5, 14);
  //  g.AddEdge(4, 5, 10);
  //  g.AddEdge(5, 6, 2);
  //  g.AddEdge(6, 7, 1);
  //  g.AddEdge(6, 8, 6);
  //  g.AddEdge(7, 8, 7);

   int source = 0;
   int k = 2;//60;
  g.PrintGraph();
  PathGreaterThanK pgtk(g, k);
  pgtk.FindPathGreaterThanK(source);
  pgtk.GetPaths();
  return 0;
}
