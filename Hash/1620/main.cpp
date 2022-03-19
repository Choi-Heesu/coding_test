#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int N, M;
unordered_map<string, int> m;
vector<string> v;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  v.assign(N + 1, "");
  for (int i = 1; i <= N; ++i) {
    cin >> v[i];
    m[v[i]] = i;
  }

  for (int i = 0; i < M; ++i) {
    string s;
    cin >> s;
    if (isdigit(s[0])) {
      cout << v[stoi(s)] << "\n";
    } else {
      cout << m[s] << "\n";
    }
  }

  return 0;
}

