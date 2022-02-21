#include <iostream>
#include <cmath>

using namespace std;

int answer = 0;
int r, c;
int dir[4][2] = {{0,0}, {0, 1}, {1, 0}, {1, 1}};

void recursive(int x, int y, int n, int size) {
    if (n == 1) {
        for(int i = 0; i < 4; ++i) {
            int new_x = x + dir[i][0];
            int new_y = y + dir[i][1];
            
            if(new_x == r && new_y == c) {
                return;  
            }
            answer++;
        }
        return;
    }
    
    n--;
    size /= 2;
    
    for(int i = 0; i < 4; ++i) {
        int new_x = x + dir[i][0] * size;
        int new_y = y + dir[i][1] * size;
        
        if((r >= new_x && r < new_x + size) && (c >= new_y && c < new_y + size)) {
            recursive(new_x, new_y, n, size);
            return;
        } else {
            answer += size * size;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n >> r >> c;
    
    recursive(0, 0, n, static_cast<int>(pow(2, n)));
    
    cout << answer << endl;

    return 0;
}
