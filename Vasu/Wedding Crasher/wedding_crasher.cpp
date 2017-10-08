#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("wedding_ip9.txt");
ofstream fout("wedding_op9.txt");

int main()
{
    //This function stores the output per test case
    unsigned long int N;
    int n, m;
    char temp;

    fin>>N;
    //cout<<N<<" ";
    for(int i = 0; i<N; i++)
    {
        fin>>n;
        //fin>>temp;
        fin>>m;
        //cout<<n<<" "<<m;
        //corner case, when m=n=1
        if(n == m && m == 0)
        {
            fout<<"Yes"<<endl;
        }
        //for other cases in which he will get caught
        else if(m%n == 0)
        {
            //cout<<"yes";
            fout<<"Yes"<<endl;
        }
        //all cases in which he will not get caught
        else
        {
            fout<<"No"<<endl;
        }
    }
    fout<<endl;
    return 0;

}
