#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> v;
bool arr[8];
int n, m;

void recursive(int count) {
  if (count == 0) {
    for (int i : v) {
      cout << i << " ";
    }
    cout << "\n";
    return;
  }

  for (int i = 0; i < n; ++i) {
    if (arr[i]) continue;
    arr[i] = true;
    v.push_back(i + 1);
    recursive(count - 1);
    v.pop_back();
    arr[i] = false;
  }
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  recursive(m);

  return 0;
}
