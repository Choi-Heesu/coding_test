
#include <iostream>
#include <vector>

using namespace std;

struct CCTV {
  int x, y;
  vector<int> direction;
};

vector<vector<int>> cctv_num = {{}, {1}, {1, 3}, {1, 4}, {1, 3, 4}, {1, 2, 3, 4}};
vector<CCTV> cctv;

int N, M;
int ans = 100;

void checkRange(vector<vector<int>> &arr) {
  int count = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (arr[i][j] == 0) {
        count++;
      }
    }
  }

  if (ans > count) ans = count;
}

void drawRange(CCTV &c, vector<vector<int>> &arr) {
  for (int i = 0; i < c.direction.size(); ++i) {
    int index;
    switch (c.direction[i]) {
      case 1:
        index = c.y + 1;
        while (true) {
          if (index >= M || arr[c.x][index] == 6) break;
          if (arr[c.x][index] == 0) arr[c.x][index] = -1;
          index++;
        }
        break;
      case 2:
        index = c.x + 1;
        while (true) {
          if (index >= N || arr[index][c.y] == 6) break;
          if (arr[index][c.y] == 0) arr[index][c.y] = -1;
          index++;
        }
        break;
      case 3:
        index = c.y - 1;
        while (true) {
          if (index < 0 || arr[c.x][index] == 6) break;
          if (arr[c.x][index] == 0) arr[c.x][index] = -1;
          index--;
        }
        break;
      case 4:
        index = c.x - 1;
        while (true) {
          if (index < 0 || arr[index][c.y] == 6) break;
          if (arr[index][c.y] == 0) arr[index][c.y] = -1;
          index--;
        }
        break;
    }
  }
}

void changeDirection(vector<int> &v) {
  for (int i = 0; i < v.size(); ++i) {
    v[i] += 1;
    if (v[i] >= 5) v[i] -= 4;
  }
}

void recursive(int index, vector<vector<int>> v) {
  if (index == cctv.size()) {
    checkRange(v);
    //printRange(v);
    return;
  }

  auto v0 = v;
  drawRange(cctv[index], v0);
  recursive(index + 1, v0);

  auto v1 = v;
  changeDirection(cctv[index].direction);
  drawRange(cctv[index], v1);
  recursive(index + 1, v1);

  auto v2 = v;
  changeDirection(cctv[index].direction);
  drawRange(cctv[index], v2);
  recursive(index + 1, v2);

  auto v3 = v;
  changeDirection(cctv[index].direction);
  drawRange(cctv[index], v3);
  recursive(index + 1, v3);
}

int main() {
  cin >> N >> M;

  vector<vector<int>> arr(8, vector<int>(8, 0));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> arr[i][j];
      if (arr[i][j] != 0 && arr[i][j] != 6) {
        CCTV c;
        c.x = i;
        c.y = j;
        c.direction = cctv_num[arr[i][j]];
        cctv.push_back(c);
      }
    }
  }

  recursive(0, arr);

  cout << ans << endl;

  return 0;
}

