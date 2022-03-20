#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int N, K;
vector<pair<int, int>> jewelry;
multiset<int> bag;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;

  for (int i = 0; i < N; ++i) {
    int m, v;
    cin >> m >> v;
    jewelry.emplace_back(v, m);
  }

  sort(jewelry.begin(), jewelry.end(), [](pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
  });

  for (int i = 0; i < K; ++i) {
    int k;
    cin >> k;
    bag.insert(k);
  }

  long long ans = 0;
  auto iter = jewelry.begin();
  while (!bag.empty() && iter != jewelry.end()) {
    int cost = iter->first;
    int weight = iter->second;

    auto check = bag.lower_bound(weight);
    if (check != bag.end()) {
      bag.erase(check);
      ans += cost;
    }
    iter++;
  }

  cout << ans << endl;

  return 0;
}

