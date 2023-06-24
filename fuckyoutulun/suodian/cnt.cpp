#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m;
vector<int>a[N];
int v[N];
int dfs(int x,int c){
    if(v[x]==c)return x;
    v[x]=c;
    int maxn=x;
    for(int i=0;i<a[x].size();i++)maxn=max(maxn,dfs(a[x][i],c));
    return maxn;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
    }
    for(int i=1;i<=n;i++)cout<<dfs(i,i)<<" ";
}