#include<bits/stdc++.h>
using namespace std;
int id;//下标
const int N=2001,M=30001;

int n,m,s;
int h[N];//第一条边
int e[M];//顶点
int w[M];//weight
int ne[M];//下一条边
bool vis[N];//在不在s集合
int dis[N];
int pre[N];//
void add(int u,int v,int w1){
    id++;
    e[id]=v;
    ne[id]=h[u];
    w[id]=w1;
    h[u]=id;
}
void dij(int s){
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    for(int i=1;i<=n;i++){
        //1.找最短
        int minn=0x7fffffff;
        int u=0;
        for(int j=1;j<=n;j++){
            if(dis[j]<minn&&vis[j]==0){
                minn=dis[j];
                u=j;
            }
        }
        vis[u]=1;
        //pre[u]
        //2.松弛
        for(int j=h[u];j;j=ne[j]){
            int v=e[j];
            int w1=w[j];
            if(dis[v]>dis[u]+w1&&vis[v]==0){
                dis[v]=dis[u]+w1;
                //pre[v]=u;
            }
        }
    }
}
void print(){
    for(int i=1;i<=n;i++){
        if(dis[i]>=0x3f3f3f00){
             cout<<-1<<" ";
        }
         else cout<<dis[i]<<" ";
    }
}
int main(){
    cin>>n>>m>>s;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);//add(v,u,w);
    }
    dij(1);
    print();
}