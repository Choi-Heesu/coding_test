#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v;
vector<int> permutation;
bool check[10];

void recursive(int num) {
  if (num == m) {
    for (int i = 0; i < m; ++i) {
      cout << permutation[i] << " ";
    }
    cout << "\n";
    return;
  }

  for (int i = 0; i < n; ++i) {
    permutation.push_back(v[i]);
    recursive(num + 1);
    permutation.pop_back();
  }

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    int value;
    cin >> value;
    v.push_back(value);
  }

  sort(v.begin(), v.end());

  recursive(0);

  return 0;
}
