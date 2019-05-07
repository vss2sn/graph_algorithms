#include "all_paths_between.hpp"

AllPathsBetween::AllPathsBetween(GraphL& g){
  this->g = g;
}

void AllPathsBetween::FindAllPathsBetween(int source, int sink){
  path.clear();
  paths.clear();
  g.ResetVisited();
  this->source = source;
  this->sink = sink;
  Backtrack(source);
}

void AllPathsBetween::Backtrack(int v){
  path.push_back(v);
  g.visited[v]=true;
  for(int i=0;i<g.adj[v].size(); i++){
    if(g.visited[g.adj[v][i].first]) continue;
    else if(g.adj[v][i].first==sink){
        path.push_back(sink);
        paths.push_back(path);
        path.pop_back();
    }
    else Backtrack(g.adj[v][i].first);
  }
  g.visited[v]=false;
  path.pop_back();
}

void AllPathsBetween::GetPaths(){
  if(paths.size() == 0) std::cout << "No paths found" << std::endl;
  else{
    std::cout << "Path(s) found:" << std::endl;
    for(int i=0;i<paths.size();i++){
      std::cout << paths[i][0];
      for(int j=1;j<paths[i].size();j++){
        std::cout << " --> " << paths[i][j];
      }
      std::cout << std::endl;
    }
  }
}


int main(){
  GraphL g(6, false, false);
  g.AddEdge(0, 1);
  g.AddEdge(0, 2);
  // g.AddEdge(1, 0);
  g.AddEdge(1, 2);
  g.AddEdge(1, 5);
  g.AddEdge(2, 3);
  g.AddEdge(2, 4);
  g.AddEdge(2, 5);
  //  g.AddEdge(3, 4);
  g.AddEdge(3, 5);
  g.AddEdge(4, 5);

  int source = 0, sink = 5;
  g.PrintGraph();
  AllPathsBetween apb(g);
  apb.FindAllPathsBetween(source, sink);
  apb.GetPaths();
  return 0;


}
