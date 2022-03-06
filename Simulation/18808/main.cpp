#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
vector<vector<int>> notebook;
vector<vector<vector<int>>> stickers;

vector<vector<int>> rotate(vector<vector<int>>& v) {
  int r = v.size();
  int c = v[0].size();

  vector<vector<int>> rotated(c, vector<int>(r));

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      rotated[j][r - 1 - i] = v[i][j];
    }
  }

  return rotated;
}

bool isPossible(vector<vector<int>>& v, int x, int y) {
  int r = v.size();
  int c = v[0].size();
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (v[i][j] == 1 && notebook[i + x][j + y] == 1) return false;
    }
  }
  return true;
}

pair<int, int> checkAll(vector<vector<int>>& v) {
  int r = v.size();
  int c = v[0].size();
  for (int i = 0; i < N - r + 1; ++i) {
    for (int j = 0; j < M - c + 1; ++j) {
      if (isPossible(v, i, j)) return {i, j};
    }
  }
  return {-1, -1};
}

void draw(vector<vector<int>>& v, int x, int y) {
  int r = v.size();
  int c = v[0].size();
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (v[i][j] == 1) {
        notebook[i + x][j + y] = v[i][j];
      }
    }
  }
}

int start() {
  for (auto& sticker : stickers) {
    auto check = checkAll(sticker);
    if (check.first != -1) {
      draw(sticker, check.first, check.second);
      continue;
    }

    auto sticker_90 = rotate(sticker);
    check = checkAll(sticker_90);
    if (check.first != -1) {
      draw(sticker_90, check.first, check.second);
      continue;
    }

    auto sticker_180 = rotate(sticker_90);
    check = checkAll(sticker_180);
    if (check.first != -1) {
      draw(sticker_180, check.first, check.second);
      continue;
    }

    auto sticker_270 = rotate(sticker_180);
    check = checkAll(sticker_270);
    if (check.first != -1) {
      draw(sticker_270, check.first, check.second);
      continue;
    }
  }

  int answer = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (notebook[i][j] == 1) answer++;
    }
  }

  return answer;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> K;
  notebook.assign(N, vector<int>(M));
  for (int k = 0; k < K; ++k) {
    int R, C;
    cin >> R >> C;
    vector<vector<int>> sticker(R, vector<int>(C));
    for (int r = 0; r < R; ++r) {
      for (int c = 0; c < C; ++c) {
        cin >> sticker[r][c];
      }
    }
    stickers.push_back(sticker);
  }

  cout << start() << endl;

  return 0;
}

