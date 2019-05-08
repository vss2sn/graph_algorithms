#include "prime_path.hpp"

PrimePath::PrimePath(){
  SieveOfEratosthenes();
  vs = v.size();
  g = GraphL(vs);
  for(int i=0;i<vs-1;i++){
    for(int j=i+1;j<vs;j++){
      if(compare(v[i], v[j])) g.AddEdge(i,j,1);
    }
  }
}

void PrimePath::SieveOfEratosthenes(){
  int n = 9999;
  bool prime[n+1];
  std::memset(prime, true, sizeof(prime));
  for(int i=2;i*i<=n;i++){
    if(prime[i]){
      for(int j=i*i;j<=n;j+=i){
        prime[j]=false;
      }
    }
  }

  for(int i=0;i<=n;i++){
    if(prime[i]) v.push_back(i);
  }
}

bool PrimePath::compare(int n1, int n2){
  c=0;
  std::string sn1 = std::to_string(n1);
  std::string sn2 = std::to_string(n2);
  int ln1 = 4 - sn1.length();
  int ln2 = 4 - sn2.length();
	for (int i = 0; i < ln1; i++) sn1='0'+sn1;
  for (int i = 0; i < ln2; i++) sn2='0'+sn2;
  for(int i=0;i<4;i++){
    if(sn1[i]!=sn2[i]) c++;
  }
  if (c==1) return true;
  return false;
}

void PrimePath::FindShortestPath(int n1, int n2){
  int i1, i2, i;
  for(i=0;i<vs;i++){
    if(v[i]==n1){
      i1 = i;
      break;
    }
  }
  if(i==vs){
    std::cout << n1 <<" is not a prime number" << std::endl;
    return;
  }
  for(i=0;i<vs;i++){
    if(v[i]==n2){
      i2 = i;
      break;
    }
  }
  if(i==vs){
    std::cout << n2 <<" is not a prime number" << std::endl;
    return;
  }
  // For printing graph
  // for (int j=0;j<g.adj.size() ; j++){
  //   std::cout << "["<<v[j] << "] ";
  //   for(int i=0;i<g.adj[j].size(); i++){
  //     std::cout << v[g.adj[j][i].first] << ",";
  //   }
  //   std::cout << std::endl;
  // }
  // sleep(10);
  if(g.BFS(i1,i2)){
    std::cout << "Path found between " << n1 << " and " << n2 << "." <<std::endl;
  }
  else{
    std::cout << "No path found between " << n1 << " and " << n2 << "." <<std::endl;
  }
}

int main()
{
  GraphL g;
  g.AddEdge(0,1);
  g.AddEdge(1,2);
  g.AddEdge(2,3);
  g.AddEdge(3,4);
  // std::cout << g.BFS(0,4) << std::endl;
  // g.PrintGraph();


  PrimePath pp;
  pp.FindShortestPath(1033, 8179);
  pp.FindShortestPath(2, 8179);
  pp.FindShortestPath(3, 8179);
  pp.FindShortestPath(1032, 8179);

    return 0;
}
