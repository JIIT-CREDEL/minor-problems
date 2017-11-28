#include <iostream>
#include <iosfwd>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <cctype>
#include <climits>
#include <vector>
#include <bitset>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <deque>
#include <string>
#include <list>
#include <iterator>
#include <sstream>
#include <complex>
#include <fstream>
#include <functional>
#include <numeric>
#include <utility>
#include <algorithm>
#include <assert.h>
#include <unordered_map>
using namespace std;


#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)

long long t, n, m, u, v, q, r, ql, qr, k, l, s, x, y, w, h, c, z, d;
const int N = 1e5 + 500;
const int LN = 21;
const long long mod = 1e9 + 7;
const long long INF = 1LL << 62LL;
vector <long long> adj[N], vert, st, _adj[N];
long long L[N][LN], tin[N], H, tout[N], sum[N], dep[N], dd[N];
bool imp[N];
vector <long long> cst[N];
void dfs(int u, int p, int D, long long di) {
   tin[u] = ++H;
   L[u][0] = p;
   dep[u] = D;
   dd[u] = di;
   for (int i = 0; i < adj[u].size(); ++i) {
      int v = adj[u][i];
      if (v == p) continue;
      dfs(v, u, D + 1, di + cst[u][i]);
   }
   tout[u] = ++H;
}
inline void pre() {
   for (int j = 1; j < LN; ++j) {
      for (int i = 1; i <= n; ++i)
      L[i][j] = L[L[i][j - 1]][j - 1];
   }
}
inline int lca(int u, int v) {
   if (dep[u] > dep[v]) swap(u, v);
   int diff = dep[v] - dep[u];
   for (int i = LN - 1; i >= 0; --i) {
      if (diff & (1 << i)) v = L[v][i];
   }
   if (u == v) return u;
   for (int i = LN - 1; i >= 0; --i) {
      if (L[u][i] != L[v][i]) {
         u = L[u][i];
         v = L[v][i];
      }
   }
   return L[u][0];
}
inline bool anc(int u, int v) {
   if (tin[u] <= tin[v] && tout[u] >= tout[v]) return true;
   else return false;
}
bool comp(int a, int b) {
   return tin[a] < tin[b];
}
int main() {
   csl;
   cin >> n >> q;
   for (int i = 0; i < n - 1; ++i) {
      cin >> u >> v >> c;
      adj[u].push_back(v);
      adj[v].push_back(u);
      cst[v].push_back(c);
      cst[u].push_back(c);
   }
   H = 0;
   dfs(1, 0, 0, 0);
   pre();
   while (q--) {
      cin >> k;
      vert.clear();
      for (int i = 0; i < k; ++i) {
         cin >> u;
         vert.push_back(u);
      }
      // compress the tree to only containt O(K) vertices
      // sort by enter time in dfs
      sort(vert.begin(), vert.end(), comp);
      for (int i = 0; i < k - 1; ++i) {
         vert.push_back(lca(vert[i], vert[i + 1]));
      }
      sort(vert.begin(), vert.end(), comp);
      vert.resize(unique(vert.begin(), vert.end()) - vert.begin());
      st.clear();
      st.push_back(vert[0]);
      // use stack to determine parent child relations in the compressed
      // tree
      long long sol = 0;
      for (int i = 1; i < vert.size(); ++i) {
         while (!anc(st.back(), vert[i])) st.pop_back();
         _adj[st.back()].push_back(vert[i]);
         sol += dd[vert[i]] - dd[st.back()];
         st.push_back(vert[i]);
      }
      cout << sol << '\n';
   }
}








