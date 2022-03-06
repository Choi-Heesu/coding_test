#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int ans;
int N;


int getMaxBlock(vector<vector<int>>& board) {
  int num = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (num < board[i][j]) num = board[i][j];
    }
  }
  return num;
}

queue<int> moveBlock(queue<int>& block) {
  queue<int> moved;
  while (!block.empty()) {
    int front = block.front();
    block.pop();
    if (block.empty()) {
      moved.push(front);
    } else {
      if (front == block.front()) {
        moved.push(front * 2);
        block.pop();
      } else {
        moved.push(front);
      }
    }
  }
  return moved;
}

void moveLeft(vector<vector<int>>& board) {
  for (int i = 0; i < N; ++i) {
    queue<int> block;
    for (int j = 0; j < N; ++j) {
      if (board[i][j] != 0) {
        block.push(board[i][j]);
      }
    }

    queue<int> moved = moveBlock(block);
    for (int j = 0; j < N; ++j) {
      if (moved.empty()) {
        board[i][j] = 0;
      } else {
        board[i][j] = moved.front();
        moved.pop();
      }
    }
  }
}

void moveUp(vector<vector<int>>& board) {
  for (int j = 0; j < N; ++j) {
    queue<int> block;
    for (int i = 0; i < N; ++i) {
      if (board[i][j] != 0) {
        block.push(board[i][j]);
      }
    }

    queue<int> moved = moveBlock(block);
    for (int i = 0; i < N; ++i) {
      if (moved.empty()) {
        board[i][j] = 0;
      } else {
        board[i][j] = moved.front();
        moved.pop();
      }
    }
  }
}

void moveRight(vector<vector<int>>& board) {
  for (int i = 0; i < N; ++i) {
    queue<int> block;
    for (int j = N - 1; j >= 0; --j) {
      if (board[i][j] != 0) {
        block.push(board[i][j]);
      }
    }

    queue<int> moved = moveBlock(block);
    for (int j = N - 1; j >= 0; --j) {
      if (moved.empty()) {
        board[i][j] = 0;
      } else {
        board[i][j] = moved.front();
        moved.pop();
      }
    }
  }
}

void moveDown(vector<vector<int>>& board) {
  for (int j = 0; j < N; ++j) {
    queue<int> block;
    for (int i = N - 1; i >= 0; --i) {
      if (board[i][j] != 0) {
        block.push(board[i][j]);
      }
    }

    queue<int> moved = moveBlock(block);
    for (int i = N - 1; i >= 0; --i) {
      if (moved.empty()) {
        board[i][j] = 0;
      } else {
        board[i][j] = moved.front();
        moved.pop();
      }
    }
  }
}

void recursive(int num, vector<vector<int>> board) {
  if (num == 5) {
    int max = getMaxBlock(board);
    if (ans < max) ans = max;
    return;
  }

  auto board_left = board;
  moveLeft(board_left);
  recursive(num + 1, board_left);

  auto board_right = board;
  moveRight(board_right);
  recursive(num + 1, board_right);

  auto board_up = board;
  moveUp(board_up);
  recursive(num + 1, board_up);

  auto board_down = board;
  moveDown(board_down);
  recursive(num + 1, board_down);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  vector<vector<int>> board(N, vector<int>(N));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> board[i][j];
    }
  }

  recursive(0, board);

  cout << ans << endl;

  return 0;
}

