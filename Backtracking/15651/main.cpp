#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
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
    permutation.push_back(arr[i]);
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
