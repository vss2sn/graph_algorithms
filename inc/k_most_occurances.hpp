#include "utils.hpp"

class KMostOccurances{
private:
  std::vector<int> v;
  int n, k;
  std::unordered_map<int, int> freq_hash;
public:
    KMostOccurances(std::vector<int>& v, int k = 1);
    void FindKMostOccurances();
};

struct ComparePair{
  bool operator()(std::pair<int, int> p1, std::pair<int, int> p2);
};
