#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 999999

int ans = MAX;
int N, M;
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;

int getDistance(int r1, int c1, int r2, int c2) {
  return abs(r1 - r2) + abs(c1 - c2);
}

int getCityDistance(vector<pair<int, int>>& v) {
  int sum = 0;
  for (auto& i : home) {
    int dist = MAX;
    for (auto& j : v) {
      int tmp = getDistance(i.first, i.second, j.first, j.second);
      if (dist > tmp) dist = tmp;
    }
    sum += dist;
  }
  return sum;
}

void recursive(int num, int index, vector<pair<int, int>> v) {
  if (num == M) {
    int tmp = getCityDistance(v);
    if (ans > tmp) ans = tmp;
    return;
  }

  if (index == chicken.size()) return;

  v.push_back(chicken[index]);
  recursive(num + 1, index + 1, v);
  v.pop_back();

  recursive(num, index + 1, v);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      int value;
      cin >> value;
      if (value == 1) {
        home.emplace_back(i, j);
      } else if (value == 2) {
        chicken.emplace_back(i, j);
      }
    }
  }

  vector<pair<int, int>> v;
  recursive(0, 0, v);

  cout << ans << endl;

  return 0;
}
