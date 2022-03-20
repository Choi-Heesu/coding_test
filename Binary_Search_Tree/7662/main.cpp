#include <algorithm>
#include <functional>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int T;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for (int i = 0; i < T; ++i) {
    int K;
    cin >> K;
    multiset<int> Q;
    for (int j = 0; j < K; ++j) {
      string s;
      int num;
      cin >> s >> num;

      if (s == "I") {
        Q.insert(num);
      } else {
        if (Q.empty()) continue;

        if (num == -1) {
          Q.erase(Q.begin());
        } else {
          Q.erase(--Q.end());
        }
      }
    }

    if (Q.empty()) {
      cout << "EMPTY\n";
    } else {
      auto min = Q.begin();
      auto max = --Q.end();
      cout << *max << " " << *min << "\n";
    }
  }

  return 0;
}

