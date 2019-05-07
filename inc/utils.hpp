#include <iostream>
#include <vector>
#include <queue>
#include <random>
#include <unistd.h>
#include <iomanip>
#include <unordered_set>
#include <unordered_map> 
#include <list>

#define BLACK "\x1b[1;30m"
#define RED "\x1b[1;31m"
#define GREEN "\x1b[1;32m"
#define YELLOW "\x1b[1;33m"
#define BLUE "\x1b[1;34m"
#define MAGENTA "\x1b[1;35m"
#define CYAN "\x1b[1;36m"
#define WHITE "\x1b[1;37m"
#define RESET "\x1b[1;0m"

class Vertex{
public:
  int pid;
  int dist;
  int colour;
  Vertex(int pid_in = -1, int dist_in = 1000, int colour_in = 0);
  void PrintStatus();
};

class Edge{
public:
  int u, v, w; // end points and weight
  Edge(int u, int v, int w = 0);
  void PrintEdge();
  bool operator > (Edge e);
  bool operator >= (Edge e);
  bool operator < (Edge e);
  bool operator <= (Edge e);
};

// Add edge and vertex vector storage as well?
class GraphM {
public:
  int V;
  std::vector<std::vector<int>> adj;
  std::vector<Vertex> v;

  GraphM(int V=7, bool random = false);
  GraphM(std::vector<std::vector<int>>& adj);

  void AddEdge(int u, int v, int w);
  int GetEdgeWeight(int u, int v);

  bool BFS(int source, int sink = 0);
  bool DFS(int source, int sink = 0);
  void DFSUtil(int source);

  void PrintPath(int source, int l);
  void PrintGraphM();
};

class GraphL {
public:
  int V;
  std::vector<std::vector<std::pair<int, int>>> adj;
  std::vector<Vertex> v;
  std::vector<bool> visited;
  bool undirected;

  GraphL(int V=7, bool random = false, bool undirected = true);
  GraphL(std::vector<std::vector<std::pair<int, int>>>& adj);

  void ResetVisited();

  void AddEdge(int u, int v, int w = 0);
  int GetEdgeWeight(int u, int v);

  bool BFS(int source, int sink = 0);
  bool DFS(int source, int sink = 0);
  void DFSUtil(int source);

  void PrintPath(int source, int l);
  void PrintGraph();
};

class GraphE{
public:
  std::vector<Edge> edges;
  int V = 0;
  void AddEdge(int u, int v, int w=0);
  void SetV();
  void PrintGraphE();
};

struct Subset{
  int parent, rank;
};

struct CompareEdgeWeights{
  bool operator()(Edge e1, Edge e2);
};
