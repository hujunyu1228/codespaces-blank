#include<bits/stdc++.h>
using namespace std;
struct node{
    int x,y,w;
};
node e[300001];
int fa[300001];
int cmp(node x,node y){
    return x.w<y.w;
}
int f(int x){
    if(x==fa[x])return x;
    return fa[x]=f(fa[x]);
}
int m(int a,int b){
    int x=f(a);
    int y=f(b);
    if(x!=y){
        fa[x]=y;
    }
}
int main(){
    int n,m;
    while(cin>>n>>m){
        int a,b;
        cin>>a>>b;
        m(a,b);
    }
}