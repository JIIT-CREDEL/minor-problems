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
string str, rstr;
struct SuffixArray {
   const int L;
   string s;
   vector<vector<int> > P;
   vector<pair<pair<int,int>,int> > M;
   SuffixArray(const string s) : L(s.size()), s(s), P(1, vector<int>(L, 0)), M(L) {
      for (int i = 0; i < L; i++) {
         P[0][i] = int(s[i]);
         //cout << s[i] << endl;
      }
      for (int skip = 1, level = 1; skip < L; skip *= 2, level++) {
         P.push_back(vector<int>(L, 0));
         for (int i = 0; i < L; i++)
         M[i] = make_pair(make_pair(P[level-1][i], i + skip < L ? P[level-1][i + skip] : -1000), i);
         sort(M.begin(), M.end());
         for (int i = 0; i < L; i++)
         P[level][M[i].second] = (i > 0 && M[i].first == M[i-1].first) ? P[level][M[i-1].second] : i;
      }
   }
   vector<int> GetSuffixArray() { return P.back(); }
   // returns the length of the longest common prefix of s[i...L-1] and s[j...L-1]
   int LongestCommonPrefix(int i, int j) {
      int len = 0;
      if (i == j) return L - i;
      for (int k = P.size() - 1; k >= 0 && i < L && j < L; k--) {
         if (P[k][i] == P[k][j]) {
            i += 1 << k;
            j += 1 << k;
            len += 1 << k;
         }
      }
      return len;
   }
};

int len[N];
int main() {
   csl;
   cin >> str;
   rstr = str;
   reverse(rstr.begin(), rstr.end());
   rstr = str + rstr;
   SuffixArray S = SuffixArray(rstr);
   n = str.size();
   for (int i = 0; i < str.size(); ++i) {
      int lo = 0, hi = min(i, (int)n - 1 - i);
      while (lo < hi) {
         int mid = (lo + hi + 1) / 2;
         if (S.LongestCommonPrefix(i - mid, n + (n - 1 - i - mid)) >= mid) lo = mid;
         else hi = mid - 1;
      }
     // cout << S.LongestCommonPrefix(i - lo, n + (n - 1 - i - lo)) << " " << 2* lo + 1 << endl;
      len[i] = 2 * lo + 1;
   }
   long long sol = 0;
   for (int i = 0; i < str.size(); ++i) {
      sol += (len[i] + 1) / 2;
   }
   cout << sol;
   cout << endl;

}





