#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,sum=1;
vector<int>a[N];
int v[N],v2[N];
void dfs(int x,int cnt){
    if(v[x]==cnt)return;
    v[x]=cnt;
    v2[x]=max(v2[x],cnt);
    //cout<<x<<"-";
    for(int i=0;i<a[x].size();i++){
        dfs(a[x][i],cnt);
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        a[y].push_back(x);
    }
    for(int i=n;i>=1;i--){
        if(!v2[i])v2[i]=i;
        dfs(i,i);
        //cout<<endl;
        //if(sum==n)break;
        //memset(v,0,sizeof(v));
    }
    for(int i=1;i<=n;i++){
        cout<<v2[i]<<" ";
    }
}