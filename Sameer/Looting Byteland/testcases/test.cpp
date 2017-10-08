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



int main() {
   csl;
   cout << 20 << " " << 2 << endl;
   for (int i = 1; i <= 20; ++i) {
      for (int j = 1; j <= 20; ++j) {
         int x = (rand() + rand() + rand()) % 10;
         if (x < 0) x += 10;
         cout << x;
         if (j < 20) cout << " ";
         else cout << endl;
      }
   }
   
}

