#include<iostream>
#include<cstdio>
#include<cstring>
#include <fstream>
using namespace std;
int temp_arr[100001];
int m[100001];
int arr[100001];
int main()
{
    ifstream fin("bad_ip19.txt");
    ofstream fout("bad_op19.txt");
    int n,i;
    fin>>n;
    int curr_val = 1;

    memset(temp_arr,-1,sizeof(temp_arr));
    memset(m,-1,sizeof(m));
    for(i = 0; i< n;i++)
    {
        fin>>arr[i];
        m[arr[i]] = 1;
    }

    i = 0;
    while( i < n)
    {
        if(temp_arr[arr[i]] == -1 && arr[i] <=n )
        {
            temp_arr[arr[i]] = 1;
        }
        else
        {
            while(temp_arr[curr_val] == 1 || m[curr_val] == 1)
                curr_val++;
            temp_arr[curr_val] = 1;
            arr[i] = curr_val;
        }
        i++;
    }

    for(i = 0 ; i< n;i++)
    {
        fout<<arr[i]<<" ";
    }
    fout<<endl;

    return 0;
}
