#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

struct DSU {
  vector<int> par, rnk, sz;
  int c;
  DSU(int n) : par(n + 1), rnk(n + 1, 0), sz(n + 1, 1), c(n) {
    for (int i = 1; i <= n; ++i) par[i] = i;
  }
  int find(int i) {
    return (par[i] == i ? i : (par[i] = find(par[i])));
  }
  bool same(int i, int j) {
    return find(i) == find(j);
  }
  int get_size(int i) {
    return sz[find(i)];
  }
  int count() {
    return c;    // connected components
  }
  int merge(int i, int j) {
    if ((i = find(i)) == (j = find(j))) return -1;
    else --c;
    if (rnk[i] > rnk[j]) swap(i, j);
    par[i] = j;
    sz[j] += sz[i];
    if (rnk[i] == rnk[j]) rnk[j]++;
    return j;
  }
};

int32_t main() {
  int n = 10; 
  DSU dsu(n);

  dsu.merge(1, 2);
  dsu.merge(2, 3);
  dsu.merge(4, 5);
  dsu.merge(6, 7);
  dsu.merge(5, 6);

  cout << "Are 1 and 3 in the same set? " << (dsu.same(1, 3) ? "Yes" : "No") << endl;
  cout << "Are 4 and 7 in the same set? " << (dsu.same(4, 7) ? "Yes" : "No") << endl;
  cout << "Are 1 and 4 in the same set? " << (dsu.same(1, 4) ? "Yes" : "No") << endl;

  cout << "Size of set containing 1: " << dsu.get_size(1) << endl;
  cout << "Size of set containing 4: " << dsu.get_size(4) << endl;

  cout << "Number of connected components: " << dsu.count() << endl;

  return 0;
}
