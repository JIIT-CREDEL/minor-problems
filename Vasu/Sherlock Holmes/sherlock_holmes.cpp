#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("sherlock_ip20.txt");
ofstream fout("sherlock_op20.txt");

int main()
{

    int n,q;
    fin>>n;
    //fout<<n;
    //cout<<n<<endl;
    int a[n];
    int b[n];
    for(int i=0; i<n; i++)fin>>a[i];
    for(int i=0; i<n; i++)fin>>b[i];
    //for(int i=0; i<n; i++) cout<<a[i]<<" ";
    //cout<<endl;
    //for(int i=0; i<n; i++) cout<<b[i]<<" ";
    //cout<<endl;
    fin>>q;
    //cout<<q;
    long long mod = 1000000007;

    long long int x[40001]= {0};
    long long int y[40001]= {0};
    x[0]=1;
    y[0]=1;

    long long s=0;
    for(int j=0; j<n; j++)
    {
        s+=a[j];
        for(int i=s; i>=a[j]; i--)
            x[i]=(x[i]+x[i-a[j]])%mod;
    }

    long long s2=0;
    for(int j=0; j<n; j++)
    {
        s2+=b[j];
        for(int i=s2; i>=b[j]; i--)
            y[i]=(y[i]+y[i-b[j]])%mod;
    }

    long long Y[40002]= {0};
    Y[0]=0;
    for(int i=1; i<=40001; i++)
    {
        Y[i]=Y[i-1]+y[i-1];
    }
    long long ans=0;
    for(int i=0; i<=s; i++)
    {
        long long t = (Y[min(40001,i+q+1)]-Y[max(0,i-q)]+mod)%mod;
        ans = (ans+(x[i]*t)%mod+mod)%mod;
    }
    fout<<ans<<endl;

    return 0;

}
