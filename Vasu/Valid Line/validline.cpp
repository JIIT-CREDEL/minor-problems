#include <bits/stdc++.h>

using namespace std;

#define clr(x) memset((x), 0, sizeof(x))


int n;
int a[102400];
int d[102400];
int e[102400];

int main()
{
	 ifstream fin("valid_ip19.txt");
	ofstream fout("valid_op19.txt");

	fin>>n;
	for(int i=0; i<n; i++)
	{
		fin>>a[i];
	}
	sort(a, a + n);
	n = unique(a, a + n) - a;
	clr(d);
	int ans = 1;
	for(int i=0; i<n; i++)
	{
		int x = a[i];
		int t = 0;
		int z = 0;
		for (int j = 2; j * j <= x; j++)
		{
			if (x % j == 0)
			{
				e[t++] = j;
				x /= j;
				while (x % j == 0) x /= j;
				if (z < d[j] + 1) z = d[j] + 1;
			}
		}
		if (x > 1)
		{
			e[t++] = x;
			if (z < d[x] + 1) z = d[x] + 1;
		}
		for(int j = 0; j<t; j++)
		{
			int v = e[j];
			if (d[v] < z) d[v] = z;
		}
		if (ans < z) ans = z;
	}
	fout<<ans<<"\n";

	return 0;
}
