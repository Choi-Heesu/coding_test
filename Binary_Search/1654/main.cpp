#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int K, N;
long long MAX;
vector<int> lan;

int getLanCount(int length) {
    int count = 0;
    for(int i = 0; i < K; ++i) {
        count += lan[i] / length;
    }
    return count;
}

int search() {
    long long start = 1;
    long long end = MAX + 1;
    
    while (start < end) {
        long long mid = (start + end) / 2;
        if (getLanCount(mid) < N) {
            end = mid;
        }else {
            start = mid + 1;
        }
    }

    return start - 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> K >> N;
    lan.assign(K, 0);
    for(int i = 0; i < K; ++i) {
        cin >> lan[i];
    }
    
    sort(lan.begin(), lan.end());
    
    MAX = lan[lan.size() - 1];
    
    cout << search() << endl;
    
    return 0;
}

