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

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef vector < long long > vll;
typedef pair <long long, long long> pll;
typedef pair <int, int> pii;
typedef vector < int > vii;
typedef complex < double > Point;

#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)
#define mp make_pair
#define fst first
#define snd second

ll t, n, m, u, v, q, r, ql, qr, k, l, s, w, z, x, y, d, p, c, L, b;
const int N = 21;
const int LN = 21;
const long long mod = 1e9 + 7;
const long long INF = 1LL << 52LL;

ll dp[1 << N][N][2];
vii adj[N][2];
vector <ll> cst[N][2];

int main() {
   csl;
   cin >> n >> m;
   
   for (int i = 1; i <= m; ++i) {
      char type;
      cin >> u >> v >> c >> type;
      u--, v--;
      if (type == 'B') {
         adj[u][0].push_back(v);
         adj[v][0].push_back(u);
         cst[u][0].push_back(c);
         cst[v][0].push_back(c);
      } else {
         adj[u][1].push_back(v);
         adj[v][1].push_back(u);
         cst[u][1].push_back(c);
         cst[v][1].push_back(c);
      }
   }
   
   for (int i = 0; i < (1 << n); ++i)
   for (int j = 0; j < n; ++j)
   dp[i][j][1] = dp[i][j][0] = INF;
   for (int i = 0; i < n; ++i) {
      dp[1 << i][i][0] = dp[1 << i][i][1] = 0;
   }
   
   for (int i = 1; i < (1 << n); ++i) {
      for (int j = 0; j < n; ++j) {
         for (int k = 0; k < 2; ++k) {
            if (dp[i][j][k] == INF) continue;
            for (int l = 0; l < adj[j][1 - k].size(); ++l) {
               int u = adj[j][1 - k][l];
               if (i & (1 << u)) continue;
               dp[i | (1 << u)][u][1 - k] = min(dp[i | (1 << u)][u][1 - k], dp[i][j][k] + cst[j][1 - k][l]);
            }
         }
      }
   }
   ll sol = INF;
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 2; ++j) {
         sol = min(sol, dp[(1 << n) - 1][i][j]);
      }
   }
   if (sol == INF) sol = -1;
   cout << sol << '\n';
   return 0;
}
