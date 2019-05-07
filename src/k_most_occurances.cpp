#include "k_most_occurances.hpp"

bool ComparePair::operator()(std::pair<int, int> p1, std::pair<int, int> p2){
  if(p1.second == p2.second) return p1.first > p2.first;
  return p1.second > p2.second;
}

KMostOccurances::KMostOccurances(std::vector<int>& v, int k){
  this->v = v;
  this->n = v.size();
}

void KMostOccurances::FindKMostOccurances(){
  for(int i=0;i<n;i++) freq_hash[v[i]]++;
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int,int>>, ComparePair> pq(freq_hash.begin(), freq_hash.end());
  for(int i=0;i<k-1;i++){
    std::cout << pq.top().first << std::endl;
    pq.pop();
  }
}

int main(){
  std::vector<int> v{3, 1, 4, 4, 5, 2, 6, 1};
  int k = 2;
  KMostOccurances kmo(v);
  kmo.FindKMostOccurances();
  return 0;
}
