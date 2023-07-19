#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10,M=1e5+10;
struct node{
    int v,w;
    bool operator<(const node &a)const{
        return w>a.w;
    }
};
int n,m;
priority_queue<node>q;
vector<node>a[N];
int d[N],v[N];
// void dij(int s){
//     memset(dis,0x3f,sizeof(dis));
//     dis[s]=0;
//     q.push({s,0});
//     while(q.size()){
//         auto cnt=q.top();
//         q.pop();
//         if(vis[cnt.v]==1)continue;
//         vis[cnt.v]=1;
//         for(int i=0;i<a[cnt.v].size();i++){
//             auto c=a[cnt.v][i];
//             int v=c.v,w=c.w;
//             if(dis[v]>dis[cnt.v]+w){
//                 dis[v]=dis[cnt.v]+w;
//                 q.push({v,dis[v]});
//             }
//         }
//     }
// }
#define inf 0x3fffffff;
void prim(int s=1){
    memset(d,0x3f,sizeof(d));
    d[s]=0;
    int ans=0,cnt=0;
    q.push({s,0});
    while(q.size()){
        // for(int j=1;j<=n;j++){
        //     if(v[j]==0&&d[j]<minn){minn=d[j];u=j;}
        // }
        auto c=q.top();
        q.pop();
        int u=c.v;
        if(v[u]!=0)continue;
        v[u]=1;
        ans+=d[u];cnt++;
        for(int j=0;j<a[u].size();j++){
            int v1=a[u][j].v,w1=a[u][j].w;
            if(v[v1]==0&&d[v1]>w1){
                d[v1]=w1;
                q.push({v1,d[v1]});
            }
        }
    }
    if(cnt!=n-1)cout<<ans;else cout<<"orz";
}
// void print(){
//     for(int i=1;i<=n;i++){
//         if(d[i]>=0x3f3f3f00){
//              cout<<-1<<" ";
//         }
//          else cout<<d[i]<<" ";
//     }
// }
int main(){
    cin>>n>>m;
    int s=1;
    //cin>>s;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        a[u].push_back({v,w});
        a[v].push_back({u,w});
    }
    //dij(1);
    prim(1);
    //print();
}