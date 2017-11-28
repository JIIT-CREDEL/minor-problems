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
const int N = 2e5 + 500;
const int SN = 331;
const long long mod = 1e9 + 7;
const long long INF = 1LL << 57;

long long arr[N], brr[N];
string str, ss;
long long tree[2 * N];


const long long M = 1000000007; // modulo
map<long long, long long> F;

long long f(long long n) {
   if (F.count(n)) return F[n];
   long long k=n/2;
   if (n%2==0) { // n=2*k
      return F[n] = (f(k)*f(k) + f(k-1)*f(k-1)) % M;
   } else { // n=2*k+1
      return F[n] = (f(k)*f(k+1) + f(k-1)*f(k)) % M;
   }
}


long long gcd(long long x, long long y) {
   x = abs(x), y = abs(y);
   while (x > 0 && y > 0) {
      if (x > y) x %= y;
      else y %= x;
   }
   return x + y;
}
void init(int l, int r, int i) {
   if (l == r) {
      tree[i] = arr[l];
      return;
   }
   
   int mid = (l + r) / 2;
   init(l, mid, i + 1 + i);
   init(mid + 1, r, i + 2 + i);
   
   tree[i] = gcd(tree[2 * i + 1], tree[i + 2 + i]);
   
}

long long query(int i, int l, int r, int rl, int rr) {
   if (l > rr || rl > r) return 0;
   if (rl <= l && r <= rr) return tree[i];
   int mid = (l + r) / 2;
   return gcd(query(i + 1 + i, l, mid, rl, rr), query(i + 2 + i, mid + 1, r, rl, rr));
}
int main() {
   csl;
   F[0]=F[1]=1;
   cin >> n >> q;
   for (int i = 1; i <= n; ++i) {
      cin >> arr[i];
   }
   
   init(1, n, 0);
   
   while (q--) {
         int l, r;
         cin >> l >> r;
         long long val = query(0, 1, n, l, r);
         cout << (val==0 ? 0 : f(val-1)) << '\n';
   }
}

