#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

ifstream fin("rohit_ip20.txt");
ofstream fout("rohi_op20.txt");

int gcd(int a, int b)
{
    if(a == 0 || b == 0)
    {
        return 0;
    }

    if(a == b)
    {
        return a;
    }

    if(a>b)
    {
        return gcd (a-b, b);
    }
    return gcd(a, b-a);
}

int main()
{
    unsigned long long int N;
    fin>>N;
    int n, m;
    int g;
    unsigned long long int ans;
    for( int i = 0; i<N; i++)
    {
        fin>>n>>m;
        g = gcd(n, m);
        ans = pow(2, g) -1;
        fout<<ans<<endl;
    }
}
