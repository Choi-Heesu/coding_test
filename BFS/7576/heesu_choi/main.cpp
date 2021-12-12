#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int tomato[1000][1000];
int days[1000][1000];
int m, n;
int ans;
int dir[4][2] = {{0,  1},
                 {1,  0},
                 {0,  -1},
                 {-1, 0}};

// 시작 점이 여러 곳일 경우 모두 큐에 넣고 시작
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int, int>> q;
    cin >> m >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> tomato[i][j];
            if (tomato[i][j] == 0) {
                days[i][j] = -1;
            } else if (tomato[i][j] == 1) {
                q.push({i, j});
            }
        }
    }

    while (!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int dir_x = cur_x + dir[i][0];
            int dir_y = cur_y + dir[i][1];
            if (dir_x < 0 || dir_y < 0 || dir_x >= n || dir_y >= m) continue;
            if (days[dir_x][dir_y] >= 0 || tomato[dir_x][dir_y] == -1 || tomato[dir_x][dir_y] == 1) continue;

            days[dir_x][dir_y] = days[cur_x][cur_y] + 1;
            q.push({dir_x, dir_y});
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (days[i][j] == -1) {
                cout << -1 << endl;
                return 0;
            }
            ans = max(ans, days[i][j]);
        }
    }

    cout << ans << endl;

    return 0;
}
