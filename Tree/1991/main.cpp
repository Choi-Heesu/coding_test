#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

int N;
int lnode[50];
int rnode[50];

void preorder_traversal(int node) {
  char cur = node + '.';
  cout << cur;
  if(lnode[node] != 0) {
    preorder_traversal(lnode[node]);
  }
  if(rnode[node] != 0) {
    preorder_traversal(rnode[node]);
  }
}

void inorder_traversal(int node) {
  char cur = node + '.';
  if(lnode[node] != 0) {
    inorder_traversal(lnode[node]);
  }
  cout << cur;
  if(rnode[node] != 0) {
    inorder_traversal(rnode[node]);
  }
}

void postorder_traversal(int node) {
  char cur = node + '.';
  if(lnode[node] != 0) {
    postorder_traversal(lnode[node]);
  }
  if(rnode[node] != 0) {
    postorder_traversal(rnode[node]);
  }
  cout << cur;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 0; i < N; ++i) {
    char n, l, r;
    cin >> n >> l >> r;
    lnode[n - '.'] = l - '.';
    rnode[n - '.'] = r - '.';
  }

  preorder_traversal('A' - '.');
  cout << endl;
  inorder_traversal('A' - '.');
  cout << endl;
  postorder_traversal('A' - '.');

  return 0;
}

