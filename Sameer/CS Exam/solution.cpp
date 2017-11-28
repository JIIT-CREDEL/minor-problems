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

vector <int> adj[N], radj[N];
int dist[N];
queue <int> Q;
bool vis[N];
vector <int> solution;
bool comp(int a, int b) {
   if (dist[a] != dist[b]) return dist[a] < dist[b];
   else return (a < b);
}
int main() {
   csl;
   cin >> n;
   for (int i = 1; i <= n; ++i) {
      cin >> arr[i];
      for (int j = 1; j <= arr[i]; ++j) {
         cin >> m;
         adj[m].push_back(i);
         radj[i].push_back(m);
      }
   }
   int tar;
   cin >> tar;
   for (int i = 1; i <= n; ++i) {
      if (radj[i].size() == 0) {
         Q.push(i);
         dist[i] = 0;
      }
   }
   
   while (!Q.empty()) {
      int x = Q.front();
      Q.pop();
      for (int u: adj[x]) {
         arr[u]--;
         if (arr[u] == 0) {
            Q.push(u);
            dist[u] = dist[x] + 1;
         }
      }
   }
   
   Q.push(tar);
   /*for (int i = 1; i <= n; ++i) cout << dist[i] << " ";
   cout << endl;*/
   while (!Q.empty()) {
      int x = Q.front();
      Q.pop();
      if (vis[x]) continue;
      vis[x] = true;
      solution.push_back(x);
      for (int u: radj[x]) {
         Q.push(u);
      }
   }
   
   sort(solution.begin(), solution.end(), comp);
   for (int u: solution)
   cout << u << " ";
   cout << endl;
}











