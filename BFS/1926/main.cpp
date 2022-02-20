#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int arr[501][501];
bool visit[501][501];
int dir[4][2] = {{0,  1},
                 {1,  0},
                 {0,  -1},
                 {-1, 0}};
int n, m;
int max_paint_area;
int paint_num;

int getPaintArea(int x, int y) {
    queue<pair<int, int>> q;
    int area = 1;

    q.push({x, y});
    visit[x][y] = true;

    while (!q.empty()) {
        int new_x = q.front().first;
        int new_y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int dir_x = new_x + dir[i][0];
            int dir_y = new_y + dir[i][1];

            if (dir_x < 1 || dir_y < 1 || dir_x > n || dir_y > m) continue;
            if (!arr[dir_x][dir_y] || visit[dir_x][dir_y]) continue;

            q.push({dir_x, dir_y});
            visit[dir_x][dir_y] = true;
            area += 1;
        }
    }

    return area;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (arr[i][j] && !visit[i][j]) {
                max_paint_area = max(max_paint_area, getPaintArea(i, j));
                paint_num++;
            }
        }
    }

    cout << paint_num << '\n';
    cout << max_paint_area << '\n';

    return 0;
}
