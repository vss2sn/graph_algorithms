#include "k_most_occurances.hpp"

KMostOccurances::KMostOccurances(std::vector<int>& v, int k){
  this->v = v;
  this->n = v.size();
  this->k = k;
}

void KMostOccurances::FindKMostOccurances(){
  for(int i=0;i<n;i++) freq_hash[v[i]]++;
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int,int>>, SortDecendingPair> pq(freq_hash.begin(), freq_hash.end());
  for(int i=0;i<k;i++){
    std::cout << pq.top().first << std::endl;
    pq.pop();
  }
}

int main(){
  std::vector<int> v{3, 1, 4, 4, 5, 2, 6, 1};
  int k = 4;
  KMostOccurances kmo(v,k);
  kmo.FindKMostOccurances();
  return 0;
}
