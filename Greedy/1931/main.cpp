#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> v;

int main() {

  cin >> N;
  for (int i = 0; i < N; ++i) {
    int a, b;
    cin >> a >> b;
    v.emplace_back(a, b);
  }

  sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
  });

  int count = 1;
  int num = v[0].second;
  for (int i = 1; i < v.size(); ++i) {
    if (num <= v[i].first) {
      count++;
      num = v[i].second;
    } else {
      if (num > v[i].second) {
        num = v[i].second;
      }
    }
  }

  cout << count << endl;

  return 0;
}

