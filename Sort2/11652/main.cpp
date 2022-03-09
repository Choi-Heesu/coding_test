#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  unordered_map<long long, int> m;
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    long long value;
    cin >> value;

    m[value]++;
  }

  vector<pair<long long, int>> v(m.begin(), m.end());
  sort(v.begin(), v.end(), [](pair<long long, int> a, pair<long long, int> b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
  });

  cout << v[0].first << endl;

  return 0;
}

