#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v;
vector<int> uv;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    v.assign(N, 0);
    uv.assign(N, 0);
    
    for(int i = 0; i < N; ++i) {
        cin >> v[i];
        uv[i] = v[i];
    }
    
    sort(uv.begin(), uv.end());
    uv.erase(unique(uv.begin(), uv.end()), uv.end());

    for(int i = 0; i < N; ++i) {
        auto iter = lower_bound(uv.begin(), uv.end(), v[i]);
        cout << iter - uv.begin() << " ";
    }
    
    return 0;
}
