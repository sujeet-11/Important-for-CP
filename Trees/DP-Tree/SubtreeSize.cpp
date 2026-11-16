#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define endl '\n'
#define sp ' '

vector<vector<int>> adj;
vector<int> sz;

void dfs(int u, int p) {
  sz[u] = 1;
  for (int v : adj[u]) {
    if (v == p) {
      continue;
    }
    dfs(v, u);
    sz[u] += sz[v];
  }
}
void solve() {
  int n;
  cin >> n;
  adj.resize(n + 1, {});
  sz.assign(n + 1, 0);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 0);
  for (int u = 1; u <= n; u++) {
    cout << sz[u] << sp;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
