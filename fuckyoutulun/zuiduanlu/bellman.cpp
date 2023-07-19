#include<bits/stdc++.h>
using namespace std;
#define f(i,j,k) for(int i=j;i<=k;i++)
const int N=1e4+10,M=5e5+10;
struct edge{
    int v,w;
    bool operator<(const edge &a)const{
        return w>a.w;
    }
};
int n,m,k;
priority_queue<edge>q;
vector<edge>a[N];
int d[N],v[N],b[N];
const int inf = 0x3f3f3f3f;

// bool bellman(int s=1){
//     memset(d, 63, sizeof(d));
//     d[s] = 0;
//     bool flag;  // 判断一轮循环过程中是否发生松弛操作
//     for (int i = 1; i <= n; i++) {
//         flag = false;
//         for (int u = 1; u <= n; u++) {
//             if (d[u] == inf) continue;
//             // 无穷大与常数加减仍然为无穷大
//             // 因此最短路长度为 inf 的点引出的边不可能发生松弛操作
//             for (auto ed : a[u]) {
//                 int v = ed.v, w = ed.w;
//                 if (d[v] > d[u] + w) {
//                 d[v] = d[u] + w;
//                 flag = true;
//                 }
//             }
//         }
//         // 没有可以松弛的边时就停止算法
//         if (!flag) break;
//     }
//     // 第 n 轮循环仍然可以松弛时说明 s 点可以抵达一个负环
//     return flag;
// }

int spfa(int s=0){
    queue<int>q;
    q.push(s);

    memset(d, 63, sizeof(d));
    d[s] = 0;
    
    v[s]=1;
    while(q.size()){
        int u=q.front();q.pop();
        v[u]=0;
        for(auto i:a[u]){
            int v=i.v,w=i.w;
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                q.push(v);
            }
        }
    }
}

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

// void prim(int s=1){
//     memset(d,0x3f,sizeof(d));
//     d[s]=0;
//     int ans=0,cnt=0;
//     q.push({s,0});
//     while(q.size()){
//         // for(int j=1;j<=n;j++){
//         //     if(v[j]==0&&d[j]<minn){minn=d[j];u=j;}
//         // }
//         auto c=q.top();
//         q.pop();
//         int u=c.v;
//         if(v[u]!=0)continue;
//         v[u]=1;
//         ans+=d[u];cnt++;
//         for(int j=0;j<a[u].size();j++){
//             int v1=a[u][j].v,w1=a[u][j].w;
//             if(v[v1]==0&&d[v1]>w1){
//                 d[v1]=w1;
//                 q.push({v1,d[v1]});
//             }
//         }
//     }
//     if(cnt!=n-1)cout<<ans;else cout<<"orz";
// }

void print(){
    for(int i=1;i<=n;i++){
        if(d[i]>=0x3f3f3f00){
             cout<<0x7fffffff<<" ";
        }
         else cout<<d[i]<<" ";
    }
}
int main(){
    cin>>n>>m;
    int s,t;
    cin>>s>>t;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        a[u].push_back({v,w});
        //a[v].push_back({u,w});
    }
    //bellman();
    spfa(s);
    cout<<d[t];
    //dij(1);
    //prim(1);
    //print();
}