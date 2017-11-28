#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

int main() {
 	 ifstream fin("territory_ip1.txt");
	ofstream fout("territory_op1.txt");
	int n;
	fin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; i++)
		fin >> v[i];

	int homies = 0;
	int ballas = 0;

	for (int i = n - 1; i >= 0; i--) {
		if (v[i] + ballas > homies) {
			ballas += v[i];
			swap(ballas, homies);
		}
		else {
			ballas += v[i];
		}
	}

	fout << ballas << " " << homies << endl;
}
