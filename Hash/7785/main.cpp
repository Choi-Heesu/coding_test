#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int N;
unordered_map<string, int> m;
vector<string> v;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 0; i < N; ++i) {
    string s1, s2;
    cin >> s1 >> s2;

    if (s2 == "enter") {
      m[s1]++;
    } else {
      m[s1]--;
    }
  }

  for (auto& value : m) {
    if (value.second == 1) {
      v.emplace_back(value.first);
    }
  }

  sort(v.begin(), v.end(), greater<>());

  for (auto& value : v) {
    cout << value << "\n";
  }

  return 0;
}

