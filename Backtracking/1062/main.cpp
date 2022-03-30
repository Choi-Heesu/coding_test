#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, K;
vector<string> words;
int alphabet[26];
int MAX;

void recursive(int index, int count) {
  if (count == 0) {
    int read_num = 0;
    for (auto s : words) {
      bool check = true;
      for (auto c : s) {
        if (!alphabet[c - 'a']) {
          check = false;
          break;
        }
      }
      if (check) read_num++;
    }

    if (MAX < read_num) MAX = read_num;
    return;
  }

  for (int i = index; i < 26; ++i) {
    if (!alphabet[i]) {
      alphabet[i]++;
      recursive(i + 1, count - 1);
      alphabet[i]--;
    }
  }
}

/*void recursive(int index, int count) {
  if(count == 0) {
    int read_num = 0;
    for(auto s : words) {
      bool check = true;
      for(auto c : s) {
        if(!alphabet[c - 'a']) {
          check = false;
          break;
        }
      }
      if(check) read_num++;
    }
        
    if(MAX < read_num) MAX = read_num;
    return;
  }
    
  if(index == 26) return;
    
  if(!alphabet[index]) {
    alphabet[index]++;
    recursive(index + 1, count - 1);
    alphabet[index]--;
  }
    
  recursive(index + 1, count);
}*/

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;

  alphabet['a' - 'a'] = 1;
  alphabet['c' - 'a'] = 1;
  alphabet['i' - 'a'] = 1;
  alphabet['n' - 'a'] = 1;
  alphabet['t' - 'a'] = 1;

  for (int i = 0; i < N; ++i) {
    string s;
    cin >> s;

    auto iter = s.find("tica");
    s = s.substr(4, iter - 4);
    words.push_back(s);
  }

  if (K < 5) {
    cout << 0 << endl;
    return 0;
  }

  K -= 5;
  recursive(0, K);

  cout << MAX << endl;

  return 0;
}

