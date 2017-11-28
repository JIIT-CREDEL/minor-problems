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

#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)

long long t, n, m, u, v, q, k, l, r;
const int N = 2e5 + 500;
const int SN = 331;
const int LN = 21;
const long long mod = 1e9 + 7;
const long long INF = 1LL << 57;

long long arr[N], brr[N];
string str;
unsigned long long hashBase = 31;
unsigned long long hashPower = 1;
unordered_map <unsigned long long, int> hashTable;
unordered_map <unsigned long long, int> cntTable;
vector <int> idx;
unsigned long long Hash(string& str) {
   unsigned long long hashVal = 0;
   for (char it: str) {
      hashVal = (hashVal * hashBase) + (it - 'a' + 1);
   }
   return hashVal;
}
void FindIdx(string& s, vector <string>& words) {
   unsigned long long curHash = 0;
   for (int it = 0; it < words[0].size(); ++it) {
      curHash = (curHash * hashBase) + (s[it] - 'a' + 1);
   }
   if (hashTable.find(curHash) != hashTable.end()) {
      idx[0] = hashTable[curHash];
   }
   for (int it = words[0].size(); it < s.size(); ++it) {
      curHash = (curHash * hashBase) + (s[it] - 'a' + 1);
      curHash -= (hashPower * (s[it - words[0].size()] - 'a' + 1));
      if (hashTable.find(curHash) != hashTable.end()) {
         idx[it - words[0].size() + 1] = hashTable[curHash];
      }
   }
}
vector <int> seen;
int findSubstring(string s, vector<string>& words) {
   if (words[0].size() > s.size()) {
      return 0;
   }
   if (words.size() == 0 || s.size() == 0) {
      return 0;
   }
   idx.resize(s.size(), -1);
   for (int it = 0; it < words.size(); ++it) {
      if (hashTable.find(Hash(words[it])) == hashTable.end())
      hashTable[Hash(words[it])] = it;
      cntTable[hashTable[Hash(words[it])]]++;
   }
   for (int i = 0; i < words[0].size(); ++i) {
      hashPower = hashPower * hashBase;
   }
   FindIdx(s, words);
   seen.resize(words.size(), 0);
   int it = 0;
   int solution = 0;
   for (int i = 0; i < words[0].size(); ++i) {
      int count = 0;
      for (int j = i; j < s.size(); j += words[0].size()) {
         if (idx[j] == -1) {
            while (count) {
               seen[idx[j - count * words[0].size()]] = 0;
               count--;
            }
            continue;
         }
         if (seen[idx[j]] == cntTable[idx[j]]) {
            while (seen[idx[j]] == cntTable[idx[j]]) {
               seen[idx[j - count * words[0].size()]]--;
               count--;
            }
         }
         seen[idx[j]]++;
         if (count + 1 == words.size())
         solution++;
         count++;
      }
      for (int i = 0; i < words.size(); ++i)
      seen[i] = false;
   }
   return solution;
}
vector <string> words;
int main() {
   csl;
   cin >> str >> m;
   words.resize(m);
   for (int i = 0; i < m; ++i) {
      cin >> words[i];
   }
   cout << findSubstring(str, words) << endl;
}





