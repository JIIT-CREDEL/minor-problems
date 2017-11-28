#include <bits/stdc++.h>
#include <fstream>

using namespace std;

const int N = 1000010;
typedef long long ll;
typedef std::pair <int, int> pii;

int cnt[N], a[N];
int n, x, y;
ll ans;
pii p[N];

ll calc(int num){
	ll ret = 0;
	for (int i = 0; i < n; ++ i){
		int u = (num - a[i] % num) % num;
		ret += std::min(1ll * x, 1ll * y * u);
		if (ret >= ans) return ans;
	}
	return ret;
}

int main(){
	 ifstream fin("padma_ip1.txt");
    ofstream fout("padma_op1.txt");
	fin>>n>>x>>y;
	for (int i = 0; i < n; ++ i){
		fin>>a[i];
		++ cnt[a[i]];
	}
	for (int i = 1; i < N; ++ i){
		for (int j = i << 1; j < N; j += i){
			cnt[i] += cnt[j];
		}
	}
	for (int i = 3; i < N; ++ i){
		p[i] = {cnt[i], -i};
	}
	std::sort(p + 3, p + N);
	ans = LLONG_MAX;
	ans = calc(2);
	for (int i = N - 1; i >= N - 500; -- i){
		ans = std::min(ans, calc(-p[i].second));
	}
	return fout<<ans, 0;
}
