#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> permutation;

void recursive(int num) {
  if (num == m) {
    for (int value : permutation) {
      cout << value << " ";
    }
    cout << "\n";
    return;
  }

  for (int i = 0; i < n; ++i) {
    if (!permutation.empty() && permutation.back() > i + 1) continue;
    permutation.push_back(i + 1);
    recursive(num + 1);
    permutation.pop_back();
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  recursive(0);

  return 0;
}
