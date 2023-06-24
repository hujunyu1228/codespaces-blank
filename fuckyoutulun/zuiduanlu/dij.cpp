#include<bits/stdc++.h>
using namespace std;
int id;//下标
const int N=2001,M=30001;
int n,m,s;
int h[N];//第一条边
int e[M];//顶点
int we[M];
int ne[M];//下一条边
bool vis[N];
int dis[N];
int pre[N];
void add(int u,int v){
    id++;
    e[id]=v;
    ne[id]=h[u];
    h[u]=id;
}
void print(){
    for(int i=1;i<=n;i++){
        for(int j=)
    }
}
int main(){
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v);add(v,u);
    }
}