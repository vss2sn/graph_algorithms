#include "k_cores.hpp"

KCores::KCores(GraphL& g, int k){
  this->g = g;
  this->k = k;
  this->vDegree = std::vector<int>(g.V);
}

bool KCores::DFSDec(int v)
{
    g.visited[v] = true;
    for (auto i = g.adj[v].begin(); i != g.adj[v].end(); ++i)
    {
        if (vDegree[v] < k)
            vDegree[i->first]--;
        if (!g.visited[i->first])
        {
            if (DFSDec(i->first)) vDegree[v]--;
        }
    }
    return (vDegree[v] < k);
}

void KCores::FindKCores()
{
    int mindeg = std::numeric_limits<int>::max();;
    int startvertex = 0;

    for (int i=0; i<g.V; i++)
    {
        vDegree[i]  = g.adj[i].size();
        if (vDegree[i] < mindeg)
        {
            mindeg = vDegree[i];
            startvertex=i;
        }
    }
    DFSDec(startvertex);
    for (int i=0; i<g.V; i++)
        if (g.visited[i] == false)
            DFSDec(i);
}

void KCores::PrintKCores(){
  std::cout << "K-Cores : \n";
  for (int v=0; v<g.V; v++)
  {
      if (vDegree[v] >= k)
      {
          std::cout << v << " ---> ";
          for (auto itr = g.adj[v].begin(); itr != g.adj[v].end(); ++itr)
              if (vDegree[itr->first] >= k)
                  std::cout << itr->first << " , ";
          std::cout << std::endl;
      }
   }
}

int main()
{
    int k = 3;
    GraphL g(9, false, false);
    g.AddEdge(0, 1);
    g.AddEdge(0, 2);
    g.AddEdge(1, 2);
    g.AddEdge(1, 5);
    g.AddEdge(2, 3);
    g.AddEdge(2, 4);
    g.AddEdge(2, 5);
    g.AddEdge(2, 6);
    g.AddEdge(3, 4);
    g.AddEdge(3, 6);
    g.AddEdge(3, 7);
    g.AddEdge(4, 6);
    g.AddEdge(4, 7);
    g.AddEdge(5, 6);
    g.AddEdge(5, 8);
    g.AddEdge(6, 7);
    g.AddEdge(6, 8);

    KCores kc(g, k);
    kc.FindKCores();
    kc.PrintKCores();
    std::cout << std::endl;

    return 0;
}
