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

long long t, n, m, u, v, q, k, x;
const int N = 100;
const int SN = 331;
const long long mod = 1e9 + 7;
const long long INF = 1LL << 57;

long long arr[N][N], brr[N];
string str, ss;


typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long L;
typedef vector<L> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;
typedef vector<PII> VPII;


struct MinCostMaxFlow {
   int N;
   VVL cap, flow, cost;
   VI found;
   VL dist, pi, width;
   VPII dad;
   
   MinCostMaxFlow(int N) :
   N(N), cap(N, VL(N)), flow(N, VL(N)), cost(N, VL(N)),
   found(N), dist(N), pi(N), width(N), dad(N) {}
   
   void AddEdge(int from, int to, L cap, L cost) {
      this->cap[from][to] = cap;
      this->cost[from][to] = cost;
   }
   
   void Relax(int s, int k, L cap, L cost, int dir) {
      L val = dist[s] + pi[s] - pi[k] + cost;
      if (cap && val < dist[k]) {
         dist[k] = val;
         dad[k] = make_pair(s, dir);
         width[k] = min(cap, width[s]);
      }
   }
   
   L Dijkstra(int s, int t) {
      fill(found.begin(), found.end(), false);
      fill(dist.begin(), dist.end(), INF);
      fill(width.begin(), width.end(), 0);
      dist[s] = 0;
      width[s] = INF;
      
      while (s != -1) {
         int best = -1;
         found[s] = true;
         for (int k = 0; k < N; k++) {
            if (found[k]) continue;
            Relax(s, k, cap[s][k] - flow[s][k], cost[s][k], 1);
            Relax(s, k, flow[k][s], -cost[k][s], -1);
            if (best == -1 || dist[k] < dist[best]) best = k;
         }
         s = best;
      }
      
      for (int k = 0; k < N; k++)
      pi[k] = min(pi[k] + dist[k], INF);
      return width[t];
   }
   
   pair<L, L> GetMaxFlow(int s, int t) {
      L totflow = 0, totcost = 0;
      while (L amt = Dijkstra(s, t)) {
         totflow += amt;
         for (int x = t; x != s; x = dad[x].first) {
            if (dad[x].second == 1) {
               flow[dad[x].first][x] += amt;
               totcost += amt * cost[dad[x].first][x];
            } else {
               flow[x][dad[x].first] -= amt;
               totcost -= amt * cost[x][dad[x].first];
            }
         }
      }
      return make_pair(totflow, totcost);
   }
};


int main() {
   csl;
   
   cin >> n >> k;
   int delta = n * n;
   long long m = 0;
   for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
         cin >> arr[i][j];
         m = max(m, arr[i][j]);
      }
   }
   
   MinCostMaxFlow mcmf(4 * n * n + 2);
   for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
         int x = (i - 1) * n + j;
         int y = x + delta;
         int h = x + 3 * delta;
         int g = x + 2 * delta;
         mcmf.AddEdge(x, y, 1, m - arr[i][j]);
         mcmf.AddEdge(y, h, 1, m);
         mcmf.AddEdge(x, g, k - 1, m);
         mcmf.AddEdge(g, h, k - 1, m);
         if (i < n) {
            int z = i * n + j;
            mcmf.AddEdge(h, z, k, m);
         }
         if (j < n) {
            int z = (i - 1) * n + (j + 1);
            mcmf.AddEdge(h, z, k, m);
         }
      }
   }
   
   cout << k * m * 2 * (2 * n - 1) + k * m * 2 * (n - 1) - mcmf.GetMaxFlow(1, 4 * n * n).second << endl;
}

