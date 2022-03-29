#include <iostream>
#include <vector>

using namespace std;

int H, W;
int block[501];
vector<int> water[501];
int ans;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> H >> W;

  for (int i = 1; i <= W; ++i) {
    cin >> block[i];
  }

  for (int i = 1; i <= W; ++i) {
    for (int j = 1; j <= block[i]; ++j) {
      if (water[j].empty()) {
        water[j].push_back(i);
      } else {
        ans += i - water[j].back() - 1;
        water[j].pop_back();
        water[j].push_back(i);
      }
    }
  }

  cout << ans << endl;

  return 0;
}

