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

long long t, n, m, u, v, q, k, l, r;
const int N = 2e5 + 500;
const int SN = 331;
const int LN = 21;
const long long mod = 1e9 + 7;
const long long INF = 1LL << 57;

long long arr[N], brr[N];
vector <int> adj[N];
int sol[N];
map <int, int> *M[N];
int sz[N];
int solve(int v, int p) {
   int bigChild = -1;
   sz[v] = 1;
   int best = arr[v];
   int cnt = 1;
   for (int u: adj[v]) {
      if (u == p) continue;
      int t = solve(u, v);
      if ((*M[u])[t] > cnt || ((*M[u])[t] == cnt && t > best)) {
         best = t;
         cnt = (*M[u])[t];
      }
      sz[v] += sz[u];
      if (bigChild == -1 || sz[bigChild] < sz[u]) bigChild = u;
   }
   if (bigChild == -1) {
      M[v] = new map <int, int> ();
      (*M[v])[arr[v]] = 1;
   } else {
      M[v] = M[bigChild];
      (*M[v])[arr[v]] += 1;
      int t = arr[v];
      if ((*M[v])[t] > cnt || ((*M[v])[t] == cnt && t > best)) {
         best = t;
         cnt = (*M[v])[t];
      }
      for (int u: adj[v]) {
         if (u == p || u == bigChild) continue;
         for (auto s: (*M[u])) {
            int t = s.first;
            (*M[v])[t] += (*M[u])[t];
            if ((*M[v])[t] > cnt || ((*M[v])[t] == cnt && t > best)) {
               best = t;
               cnt = (*M[v])[t];
            }
         }
      }
   }
   sol[v] = best;
   return best;
}
int main() {
   csl;
   cin >> n;
   for (int i = 1; i <= n; ++i) {
      cin >> arr[i];
   }
   for (int i = 1; i <= n - 1; ++i) {
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }
   solve(1, 0);
   for (int i = 1; i <= n; ++i)
   cout << sol[i] << " ";
   cout << endl;
}





