#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <fstream>

using namespace std;
const int root = 1;
vector<vector<long> > edges;
vector<bool> broken;
vector<bool> visited;
vector<long> repairs;

void dfs(long node){

    if(visited[node]){return;}
    visited[node] = 1;
    //printf("Node: %ld\n", node);
    if(broken[node]){
        repairs[node] = 1;
        //printf("Node is broken\n");
    }

    for(long p = 0; p < edges[node].size(); p++){
        long child = edges[node][p];
        if(visited[child]){continue;}
        //printf("Will visit child %ld\n", child);
        dfs(child);
        repairs[node] += repairs[child];
        //printf("Adding child's %ld repairs to parent %ld, which now equals %ld\n", child, node, repairs[node]);
    }

    //printf("Repairs for node %ld equal %ld\n", node, repairs[node]);


}

int main(){

     ifstream fin("toy_ip20.txt");
    ofstream fout("toy_op20.txt");
    long n; fin>>n;
    edges.resize(n + 1); broken.resize(n + 1); repairs.resize(n + 1); visited.resize(n + 1);

    for(long p = 1; p < n; p++){
        long a, b, r; fin>>a>>b>>r;
        edges[a].push_back(b); edges[b].push_back(a);
        if(r == 2){broken[a] = 1; broken[b] = 1;}
    }

    dfs(root);

    vector<long> toVote;
    for(long p = 1; p <= n; p++){if(repairs[p] == 1){toVote.push_back(p);}}
    fout<<toVote.size()<<" ";
    fout<<endl;
    for(long p = 0; p < toVote.size(); p++){fout<<toVote[p]<<" ";}; fout<<" ";

    return 0;
}
