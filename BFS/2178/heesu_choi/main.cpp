#include <iostream>
#include <string>
#include <queue>
#include <utility>

using namespace std;

int maze[101][101];
bool visit[101][101];
int dir[4][2] = {{0,  1},
                 {1,  0},
                 {0,  -1},
                 {-1, 0}};
int n, m;

int searchMaze(int x, int y) {
    queue<pair<pair<int, int>, int>> q;
    q.push({{x, y}, 1});
    visit[x][y] = true;

    while (!q.empty()) {
        int new_x = q.front().first.first;
        int new_y = q.front().first.second;
        int count = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int dir_x = new_x + dir[i][0];
            int dir_y = new_y + dir[i][1];

            if (dir_x < 1 || dir_y < 1 || dir_x > n || dir_y > m) continue;
            if (maze[dir_x][dir_y] == 0 || visit[dir_x][dir_y]) continue;
            if (dir_x == n && dir_y == m) return count + 1;

            q.push({{dir_x, dir_y}, count + 1});
            visit[dir_x][dir_y] = true;
        }
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        string str;
        cin >> str;
        for (int j = 1; j <= m; ++j) {
            maze[i][j] = str[j - 1] - '0';
        }
    }

    cout << searchMaze(1, 1) << '\n';

    return 0;
}
