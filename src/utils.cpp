#include "utils.hpp"

Vertex::Vertex(int pid_in, int dist_in, int colour_in){
  this->pid = pid_in;
  this->dist = dist_in;
  this->colour = colour_in;
}
void Vertex::PrintStatus(){
  std::cout << "Vertex Status: "          << std::endl
            << "PID      ---> " << pid    << std::endl
            << "Distance ---> " << dist   << std::endl
            << "Colour   ---> " << colour << std::endl
            << std::endl;
}

Edge::Edge(int u, int v, int w){
  this->u = u;
  this->v = v;
  this->w = w;
}

bool Edge::operator > (Edge e){
  return (this->w > e.w);
}

bool Edge::operator >= (Edge e){
  return (this->w >= e.w);
}

bool Edge::operator < (Edge e){
  return (this->w < e.w);
}

bool Edge::operator <= (Edge e){
  return (this->w <= e.w);
}

void Edge::PrintEdge(){
  std::cout << "Edge: " << u << " --> " << v << " Weight: " << w << std::endl;
}

GraphM::GraphM(int V, bool random){
  this->V = V;
  std::vector<int> tmp(V);
  adj = std::vector<std::vector<int>>(V);
  for (int i = 0; i < V; i++){
    adj[i] = tmp;
  }
  this->v = std::vector<Vertex>(V);
  if(random){
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<int> distr(0,V); // define the range
    for(int i=0;i<V;i++){
      for(int j=0;j<V;j++){
        adj[i][j] = distr(eng);
      }
    }
  }
}

GraphM::GraphM(std::vector<std::vector<int>>& adj){
  this->V = adj.size();
  this->adj = adj;
  this->v = std::vector<Vertex>(V);
}

void GraphM::AddEdge(int u, int v, int w){
  adj[u][v] = w;
}

int GraphM::GetEdgeWeight(int u, int v){
  return adj[u][v];
}

void GraphM::PrintPath(int source, int l) {
  if (source == l) std::cout <<source<<" ";
  else if (v[l].pid == -1) std::cout <<"No path exists from "<<source<<" to "<<l<<std::endl;
  else {
    PrintPath(source, v[l].pid);
    std::cout <<l<<" ";
  }
}

bool GraphM::BFS(int source, int sink){
  std::vector<Vertex> v(V);
  v[source].dist = 0;
  v[source].colour = 1;
  std::queue <int> Q;
  int u;
  Q.push(source);
  while(!(Q.empty())){
    u = Q.front();
    Q.pop();
      // std::cout << "Popping: " << std::endl;
      // v[u].PrintStatus();
    for(int i = 0; i<adj.size(); i++){
      if(adj[u][i] != 0 && v[i].colour == 0){

        v[i].colour = 1;
        v[i].dist = v[u].dist + 1;
        v[i].pid = u;
        // std::cout << "Pushing: " << std::endl;
        // v[i].PrintStatus();
        Q.push(i);
      }
    }
    v[u].colour = 2;
  }
  this->v = v;
  PrintPath(source, sink);
  if(v[sink].colour == 2) return true;
  return false;
}

bool GraphM::DFS(int source, int sink){
  v = std::vector<Vertex>(V);
  v[source].dist = 0;
  DFSUtil(source);
  PrintPath(source, sink);
  if(v[sink].colour == 2) return true;
  return false;
}

void GraphM::DFSUtil(int source){
  v[source].colour = 1;
  for(int i = 0; i < V; i++){
    if(v[i].colour==0 && adj[source][i]!=0){
      v[i].pid = source;
      v[i].dist = v[source].dist +1;
      DFSUtil(i);
    }
  }
  v[source].colour = 2;
}

void GraphM::PrintGraphM(){
  std::cout << "-----------" << std::endl;
  std::cout << "Adjacency matrix for the graph: " << std::endl;
  std::cout << std::endl;
  for(int i=0;i<V;i++){
    for(int j=0;j<V;j++){
      std::cout << std::setw(2) << adj[i][j] << " , ";
    }
    std::cout << std::endl << std::endl;
  }
  std::cout << "-----------" << std::endl;
  std::cout << std::endl;
}

GraphL::GraphL(int V, bool random, bool undirected){
  this->V = V;
  this->undirected = undirected;
  adj = std::vector<std::vector<std::pair<int, int>>>(V);

  this->visited =  std::vector<bool>(this->V);
  for(auto it = this->visited.begin(); it!=this->visited.end(); ++it){
    *it = false;
  }

  if(random){
    int u,v;
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<int> distr(0,V); // define the range
    for(int i=0;i<V;i++){
      for(int j=0;j<V;j++){
        u = distr(eng);
        if(i!=u) adj[i].push_back(std::make_pair(v,distr(eng)));
      }
    }
  }
}

GraphL::GraphL(std::vector<std::vector<std::pair<int, int>>>& adj){
  this->undirected = false;
  this->V = adj.size();
  this->visited =  std::vector<bool>(this->V);
  ResetVisited();
  this->adj = adj;
}

void GraphL::ResetVisited(){
  for(auto it = this->visited.begin(); it!=this->visited.end(); ++it){
    *it = false;
  }
}

void GraphL::AddEdge(int u, int v, int w){
  std::vector<std::pair<int,int>> tmp;
  // std::cout << "Here" << std::endl;
  for(int i=adj.size();i<u+1 || i < v+1; i++){
    // std::cout << "Here" << std::endl;
    adj.push_back(tmp);
  }

  adj[u].push_back(std::make_pair(v,w));
  if(undirected) adj[v].push_back(std::make_pair(u,w));
  V = adj.size();
}

int GraphL::GetEdgeWeight(int u, int v){
  for(auto it = adj[u].begin(); it != adj[u].end(); ++it) {
      if(it->first = v) return it->second;
  }
  return NULL;
}

// No need for pair in BFS, can change to int
bool GraphL::BFS(int source, int sink){
  ResetVisited();
  visited[source] = true;
  std::vector<int> parent(V);
  // for(int i;i<V)
  // std::priority_queue<std::pair<int, int>,std::vector<std::pair<int,int>>, SortAscendingPair> Q;
  std::queue<std::pair<int,int>> Q;
  std::pair<int, int> current;
  Q.push(std::make_pair(source,0));
  while(!Q.empty()){
    current = Q.front();
    Q.pop();
    for(int j=0;j<adj[current.first].size();j++){
      if(!visited[adj[current.first][j].first]){
        visited[adj[current.first][j].first] = true;
        parent[adj[current.first][j].first] = current.first;
        Q.push(adj[current.first][j]);
        if(adj[current.first][j].first == sink) return true;
      }
    }
  }
  return false;
}

bool GraphL::DFS(int source, int sink){
  visited[source] = true;
  for(int i=0;i<adj[source].size();++i){
    if(!visited[adj[source][i].first]){
      DFS(adj[source][i].first);
    }
  }
  if(visited[sink]) return true;
  return false;
}

void GraphL::PrintPath(int source, int l){}

void GraphL::PrintGraph(){
  std::cout << "-----------" << std::endl;
  std::cout << "Adjacency list for the graph: " << std::endl;
  for(int i=0;i<adj.size();i++){
    std::cout << "[" << i << "]";
    for(int j=0;j<adj[i].size();j++){
      std::cout << " , " << adj[i][j].first ;
    }
    std::cout << std::endl;
  }
  std::cout << "-----------" << std::endl;
  std::cout << std::endl;
}

void GraphE::AddEdge(int u, int v, int w){
  edges.push_back(Edge(u,v,w));
  SetV();
}

void GraphE::SetV(){ //optimise to check only last edge
  int max = -1;
  for(int i=0;i<edges.size();++i){
    if(edges[i].u > max)  max = edges[i].u;
    if(edges[i].v > max)  max = edges[i].v;
  }
  V = max+1;
}

void GraphE::PrintGraphE(){
  std::cout << "-----------" << std::endl;
  std::cout << "Graph represented by edges:" << std::endl;
  for(int i=0;i<edges.size();i++){
    edges[i].PrintEdge();
  }
  std::cout << "-----------" << std::endl << std::endl;
}

bool SortDecendingPair::operator()(std::pair<int, int> p1, std::pair<int, int> p2){
  if(p1.second == p2.second) return p1.first < p2.first;
  return p1.second < p2.second;
}

bool SortAscendingPair::operator()(std::pair<int, int> p1, std::pair<int, int> p2){
  if(p1.second == p2.second) return p1.first > p2.first;
  return p1.second > p2.second;
}

bool CompareEdgeWeights::operator()(Edge e1, Edge e2){
  return e1.w < e2.w;
}
