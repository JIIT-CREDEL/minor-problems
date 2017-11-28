#include <bits/stdc++.h>
#define maxn 100005
#define MOD 1000000007
using namespace std;
typedef long long ll;

int num[maxn], d[maxn<<1];
vector<int> v[maxn];
int find(int p){
	int r = p;
	while(r != d[r])
	 r = d[r];
	int h = p;
	while(h != d[h]){
		p = d[h];
		d[h] = r;
		h = p;
	}
	return r;
}
int main(){
//	freopen("in.txt", "r", stdin);
 	ifstream fin("happy_ip19.txt");
	ofstream fout("happy_op19.txt");
	int n, m;
	fin>>n>>m;
	for(int i = 1; i <= n; i++)
	fin>>num[i];
	for(int i = 1; i <= m; i++){
		int s, a;
		fin>>s;
		while(s--){
			fin>>a;
			v[a].push_back(i);
		}
	}
	for(int i = 1; i <= 2 * m; i++)
	  d[i] = i;
	for(int i = 1; i <= n; i++){
		int k1 = find(v[i][0]), k2 = find(v[i][0]+m);
		int k3 = find(v[i][1]), k4 = find(v[i][1]+m);
		if(num[i]){
			if(k1 == k4 || k2 == k3){
				fout<<"NO";
				return 0;
			}
			d[k1] = k3;
			d[k2] = k4;
		}
		else{
			if(k1 == k3 || k2 == k4){
				fout<<"NO";
				return 0;
			}
			d[k1] = k4;
			d[k2] = k3;
		}
	}
	fout<<"YES";
	return 0;
}
