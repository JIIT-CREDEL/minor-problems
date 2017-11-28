#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include <fstream>
using namespace std;

typedef long long  LL;
typedef vector<long long>   vi;
typedef pair<long long,long long>  pii;

long long tree[1111111];
long long treeind[1111111];
long long arr[111111];

void make_tree(long long node,long long l,long long r){
    if(l>r)return ;
    if(l==r){
        tree[node]=0;
        treeind[node]=0;
        return ;
    }
    make_tree(node*2,l,(l+r)/2);
    make_tree(node*2+1,(l+r)/2+1,r);
}
void update_tree(long long node,long long ind,long long l,long long r,long long val,long long valind){
  //  cout<<ind<<" "<<l<<" "<<r<<endl;
    if(tree[node]<val){
        tree[node]=val;
        treeind[node]=valind;
    }
    if(l==r){

        return ;
    }
    if(ind<=(l+r)/2 && ind>=l)update_tree(node*2,ind,l,(l+r)/2,val,valind);
    else update_tree(node*2+1,ind,(l+r)/2+1,r,val,valind);

}
pii query(long long node,long long l,long long r,long long lft,long long rgh){
    if(rgh<l || lft>r)return pii(0,0);

    if(lft<=l && rgh>=r)    {
  //  cout<<l<<" -&&&- "<<r<<endl;
 //   cout<<lft<<" -&&&- "<<rgh<<endl;

//    cout<< node<<" "<<tree[node]<<" "<<treeind[node]<<endl;
        return pii(tree[node],treeind[node]);
    }
    pii p=query(node*2,l,(l+r)/2, lft,rgh);
    pii q=query(node*2+1,(l+r)/2+1,r, lft,rgh);

  //  cout<<p.first<<"----"<<p.second<<endl;
 //   cout<<q.first<<"----"<<q.second<<endl;
    return max(p,q);
}
pii pr[111111];
pii ans[111111];
long long arr1[111111];
int main()
{
     ifstream fin("road_ip20.txt");
    ofstream fout("road_op20.txt");
    long long n,d;
    fin>>n>>d;
    for(long long i=1;i<=n;i++){
        fin>>arr[i];
        arr1[i]=arr[i];
        pr[i].first=arr[i];
        pr[i].second=i;
    }
    map<pii,long long>mp;
    sort(arr1+1,arr1+1+n);
    sort(pr+1,pr+n+1);
    for(long long i=1;i<=n;i++){
        mp[pr[i]]=i;
    }
    pii as;
    as=pii(0,0);
    make_tree(0,1,n);
    long long ind=-1;
    for(long long i=1;i<=n;i++){

        long long *up=std::upper_bound (arr1+1 , arr1+n+1, arr[i]+d-1);
        long long rgh=up-arr1;
        long long *low=std::lower_bound (arr1+1 , arr1+n+1, arr[i]-d+1);
        long long lft=low-arr1-1;
        //cout<<lft<<" "<<rgh<<endl;
        pii p1 =query(1,1,n,1,lft);
        pii p2 =query(1,1,n,rgh,n);
        //cout<<p1.first<<"--"<<p1.second<<endl;
        //cout<<p2.first<<"--"<<p2.second<<endl;
        p1=max(p1,p2);
        ans[i]=p1;
        ans[i].first++;
        //cout<<" "<<mp[pii(arr[i],i)]<<endl;
        update_tree(1,mp[pii(arr[i],i)],1,n,ans[i].first,i);
        if(ans[i]>as){
                as=ans[i];
                ind=i;
        }
    }
    fout<<as.first<<endl;
    int x=as.first;
    vector<int> v;
    v.push_back(ind);
    for(int i=0;i<x-1;i++){
        //cout<<as.first<<",";
        v.push_back(as.second);
        as=ans[as.second];

    }
    reverse(v.begin(),v.end());
    for(int i=0;i<x;i++){
        fout<<v[i]<<" "<<endl;
    }
    return 0;
}
