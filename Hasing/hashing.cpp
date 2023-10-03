
#include <bits/stdc++.h>

#include "Arrays/rx.h"

template <typename T> class Hasing {

public:
  Hasing();

private:
};

std::map<int, int> map;

int hashFunction(char c) { return c - 'a'; }

int main() {

  std::string sentence;

  int numOfQuery;
  char query;

  std::cin >> sentence;
  std::cin >> numOfQuery;

  std::vector<int> hashMap(26, 0);

  for (auto c : sentence) {
    int index = hashFunction(c);
    hashMap[index]++;
  }

  for (auto i = 0; i < numOfQuery; i++) {
    std::cin >> query;
    std::cout << query << " appear: " << hashMap[hashFunction(query)]
              << " times" << std::endl;
  }

  map[3]++;

  std::cout << map[3];
  return 0;
}