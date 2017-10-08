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

ll t, n, m, u, v, q, r, ql, qr, k, l, s, w, z, x, y, d, p, c, b;
const int N = 2e5 + 500;
const int SN = 300;
const int NN = 1e4 + 4;
const long long mod = 1e9 + 7;
const long long INF = 1LL << 52LL;
typedef long long LL;
const double PI = 4*atan(1);
typedef complex<double> base;
vector<base> omega;
long long FFT_N;
void init_fft(long long n)
{
   FFT_N  = n;
   omega.resize(n);
   double angle = 2 * PI / n;
   for(int i = 0; i < n; i++)
   omega[i] = base( cos(i * angle), sin(i * angle));
}
void fft (vector<base> & a)
{
   long long n = (long long) a.size();
   if (n == 1)  return;
   long long half = n >> 1;
   vector<base> even (half),  odd (half);
   for (int i=0, j=0; i<n; i+=2, ++j)
   {
      even[j] = a[i];
      odd[j] = a[i+1];
   }
   fft (even), fft (odd);
   for (int i=0, fact = FFT_N/n; i < half; ++i)
   {
      base twiddle =  odd[i] * omega[i * fact] ;
      a[i] =  even[i] + twiddle;
      a[i+half] = even[i] - twiddle;
   }
}
void multiply (const vector<long long> & a, const vector<long long> & b, vector<long long> & res)
{
   vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
   long long n = 1;
   while (n < 2*max (a.size(), b.size()))  n <<= 1;
   fa.resize (n),  fb.resize (n);
   
   init_fft(n);
   fft (fa),  fft (fb);
   for (size_t i=0; i<n; ++i)
   fa[i] = conj( fa[i] * fb[i]);
   fft (fa);
   res.resize (n);
   for (size_t i=0; i<n; ++i)
   {
      res[i] = (long long) (fa[i].real() / n + 0.5);
      res[i]%=mod;
   }
}
int freq[N];
vector <ll> go(int l, int r) {
   if (l == r) {
      return vector <ll> (freq[l] + 1, 1);
   }
   int mid = (l + r) / 2;
   vector <ll> ret;
   vector <ll> A = go(l, mid);
   vector <ll> B = go(mid + 1, r);
   multiply(A, B, ret);
   ret.resize(A.size() + B.size() - 1);
   return ret;
}
int main() {
   csl;
   cin >> n >> k;
   for (int i = 1; i <= n; ++i) {
      cin >> x;
      freq[x]++;
   }
   cout << go(1, 2e5)[k] << '\n';
   return 0;
}





















