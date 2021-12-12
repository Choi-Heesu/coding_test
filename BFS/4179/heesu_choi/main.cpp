#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int human[1000][1000];
int fire[1000][1000];
string maze[1000];
int r, c;
int dir[4][2] = {{0,  1}, {1,  0}, {0,  -1}, {-1, 0}};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int, int>> q1;
    queue<pair<int, int>> q2;

    cin >> r >> c;
    for (int i = 0; i < r; ++i) {
        cin >> maze[i];
        for (int j = 0; j < c; ++j) {
            human[i][j] = -1;
            fire[i][j] = -1;
            if (maze[i][j] == 'F') {
                q1.push({i, j});
                fire[i][j] = 0;
            } else if (maze[i][j] == 'J') {
                q2.push({i, j});
                human[i][j] = 0;
            }
        }
    }

    while (!q1.empty()) {
        int cur_x = q1.front().first;
        int cur_y = q1.front().second;
        q1.pop();

        for (int i = 0; i < 4; ++i) {
            int next_x = cur_x + dir[i][0];
            int next_y = cur_y + dir[i][1];
            if (next_x < 0 || next_y < 0 || next_x >= r || next_y >= c) continue;
            if (maze[next_x][next_y] == '#' || fire[next_x][next_y] >= 0) continue;

            fire[next_x][next_y] = fire[cur_x][cur_y] + 1;
            q1.push({next_x, next_y});
        }
    }

    // fire가 벽에 갇혀서 업데이트 못하는 경우도 생각해야 함
    while (!q2.empty()) {
        int cur_x = q2.front().first;
        int cur_y = q2.front().second;
        q2.pop();

        for (int i = 0; i < 4; ++i) {
            int next_x = cur_x + dir[i][0];
            int next_y = cur_y + dir[i][1];
            if (next_x < 0 || next_y < 0 || next_x >= r || next_y >= c) {
                cout << human[cur_x][cur_y] + 1 << endl;
                return 0;
            }
            if (maze[next_x][next_y] == '#' || human[next_x][next_y] >= 0) continue;
            if (fire[next_x][next_y] != -1 && fire[next_x][next_y] <= human[cur_x][cur_y] + 1) continue;

            human[next_x][next_y] = human[cur_x][cur_y] + 1;
            q2.push({next_x, next_y});
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}
