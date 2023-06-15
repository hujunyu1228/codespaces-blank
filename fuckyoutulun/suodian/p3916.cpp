#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n,m;
char a[N][N];
char v[N];
int dfs(int x){
    if(v[x])return x;
    int maxn=-1;
    for(int i=1;i<=n;i++){
        if(a[x][i])maxn=max(maxn,dfs(i));
    }
    return maxn;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        a[x][y]=1;
    }
    for(int i=1;i<=n;i++)cout<<dfs(i)<<" ";
}