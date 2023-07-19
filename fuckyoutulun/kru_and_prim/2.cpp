#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int fa[100010];
int n,m,k;
int find(int a){
    if(fa[a]==a)return a;
    return fa[a]=find(fa[a]);
}
struct edge{
    int u,v,w;
};
int cmp(edge a,edge b){
    return a.w>b.w;
}
edge e[N];
int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[i]={u,v,w};
    }
    for(int i=1;i<=n;i++)fa[i]=i;
    sort(e+1,e+m+1,cmp);
    int cnt=0,cnt2=1;
    for(int i=1;cnt2<=k;i++){
        int u=e[i].u,v=e[i].v;
        int fu=find(u),fv=find(v);
        if(fu!=fv){
            fa[fu]=fv;
            cnt+=e[i].w;
            cnt2++;
        }
        //cout<<cnt2<<" "<<e[i].w<<endl;
    }
    cout<<cnt;
}