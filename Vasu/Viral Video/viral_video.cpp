#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

ifstream fin("viral_ip19.txt");
ofstream fout("viral_op19.txt");

unsigned long long int getNno(int n, int x1, int x2, int x3)
{
    unsigned long long int arr[n+1];//to store the numbers in the sequence

    //corner case
    if(x1==x2==x3)
    {
        return pow(x1, n);
    }

    int i1=0, i2=0, i3=0;
    unsigned long long int next_multiple_of_x1 = x1;
    unsigned long long int next_multiple_of_x2 = x2;
    unsigned long long int next_multiple_of_x3 = x3;
    unsigned long long int next_no = 1;

    arr[0]=1;
    for(int i=1; i<n+1; i++)
    {
        next_no = min(min(next_multiple_of_x1, next_multiple_of_x2), next_multiple_of_x3);
        arr[i] = next_no;
        if (next_no == next_multiple_of_x1)
       {
           i1 = i1+1;
           next_multiple_of_x1 = arr[i1]*x1;
       }
       if (next_no == next_multiple_of_x2)
       {
           i2 = i2+1;
           next_multiple_of_x2 = arr[i2]*x2;
       }
       if (next_no == next_multiple_of_x3)
       {
           i3 = i3+1;
           next_multiple_of_x3 = arr[i3]*x3;
       }
    }
    return arr[n];
}

int main()
{
    int t;
    fin>>t;
    int x1, x2, x3, k;
    for(int i = 0; i< t; i++)
    {
        fin>>x1>>x2>>x3>>k;
        unsigned long long int ans = getNno(k, x1, x2, x3);
        fout<<ans<<endl;
    }
    fout<<endl;
}


