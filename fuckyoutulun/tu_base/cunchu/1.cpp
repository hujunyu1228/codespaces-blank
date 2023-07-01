#include<bits/stdc++.h>
using namespace std;
int a[1010][1010];
priority_queue<int,vector<int>,greater<int>>b[1010];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        a[u][v]=a[v][u]=1;
        b[u].push(v);
        b[v].push(u);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=1;i<=n;i++){
        int s=b[i].size();
        cout<<s<<" ";
        for(int j=1;j<=s;j++){
            cout<<b[i].top()<<" ";
            b[i].pop();
        }
        cout<<endl;
    }
    return 0;
}
