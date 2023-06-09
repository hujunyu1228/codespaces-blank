#include<bits/stdc++.h>
using namespace std;
// struct node{
//     int x,y,w;
// };
// node e[300001];
// int cmp(node x,node y){
//     return x.w<y.w;
// }
int fa[2000001];
int f(int x){
    if(x==fa[x])return x;
    return fa[x]=f(fa[x]);
}
int merge(int a,int b){
    int x=f(a);
    int y=f(b);
    if(x!=y){
        fa[x]=y;
    }
}
int main(){
    int n,m,k;
    while(cin>>n>>m>>k){
        for(int i=1;i<=n*m;i++)fa[i]=i;
        for(int i=1;i<=k;i++){
            int a,b;
            cin>>a>>b;
            merge(a,b);
        }
        set<int>s;
        for(int i=1;i<=n*m;i++)s.insert(f(i));
        cout<<s.size()<<endl;
    }
}