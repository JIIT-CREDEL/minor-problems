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

ll A[N];

int main()
{
   ll ans = 0, sum = 0, val;
   
   scanf("%d", &n);
   assert(n >= 1 && n <= 100000);
   
   for ( int i = 1; i <= n; i++ ) {
      scanf("%lld", &A[i]);
      assert(A[i] >= -1000000000 && A[i] <= 1000000000);
      sum += A[i];
   }
   
   sort(A + 1, A + n + 1);
   
   int idx = 1;
   
   while ( idx <= n && A[idx] < 0 ) {
      ans += A[idx];
      idx++;
   }
   
   ans += (ll)(n - idx + 1)*(sum - ans);
   printf("%lld\n", ans);
   
   return 0;
}
