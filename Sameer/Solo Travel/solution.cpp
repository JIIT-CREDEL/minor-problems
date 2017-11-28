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

using namespace std;

#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)

long long t, n, m, u, v, q, k, l, r, c;
const int N = 2e5 + 500;
const int SN = 331;
const int LN = 21;
const long long mod = 1e9 + 7;
const long long INF = 1LL << 57;

long long arr[N], brr[N];

vector <int> adj[N], cst[N];
vector <int> allCosts;
queue <int> Q;
bool vis[N];
bool bfs(int cost) {
   Q = queue <int> ();
   for (int i = 1; i <= n; ++i) vis[i] = false;
   Q.push(1);
   while (!Q.empty()) {
      int v = Q.front();
      Q.pop();
      if (vis[v]) continue;
      vis[v] = true;
      for (int i = 0; i < adj[v].size(); ++i) {
         int u = adj[v][i];
         int c = cst[v][i];
         if (c > cost) continue;
         Q.push(u);
      }
   }
   int sum = 0;
   for (int i = 1; i <= n; ++i) sum += vis[v];
   return (sum == n);
}
int main() {
   csl;
   cin >> n >> m;
   for (int i = 1; i <= m; ++i) {
      cin >> u >> v >> c;
      adj[u].push_back(v);
      adj[v].push_back(u);
      cst[v].push_back(c);
      cst[u].push_back(c);
      allCosts.push_back(c);
   }
   sort(allCosts.begin(), allCosts.end());
   int lo = 0, hi = allCosts.size() - 1;
   while (lo < hi) {
      int mid = (lo + hi) / 2;
      if (bfs(allCosts[mid])) hi = mid;
      else lo = mid + 1;
   }
   cout << allCosts[lo] << endl;
}





