
#include <bits/stdc++.h>
using namespace std;

struct DSU {
  vector<int> parent, sz;
  int components;
  DSU(int n) {
    parent.resize(n + 1);
    sz.assign(n + 1, 1);
    components = n;
    iota(parent.begin(), parent.end(), 0);
  }
  int find(int x) {
    if (parent[x] == x) {
      return x;
    }
    return parent[x] = find(parent[x]);
  }
  bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) {
      return false;
    }
    if (sz[a] < sz[b]) {
      swap(a, b);
    }
    parent[b] = a;
    sz[a] += sz[b];
    components--;
    return true;
  }
  bool same(int a, int b) {
    return find(a) == find(b);
  }
  int size(int x) {
    return sz[find(x)];
  }
  int count() {
    return components;
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  DSU dsu(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    dsu.unite(u, v);
  }
  cout << "Components: " << dsu.count() << '\n';
  cout << "Size of component containing 1: " << dsu.size(1) << '\n';
  cout << (dsu.same(1, n) ? "Connected" : "Not Connected") << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
