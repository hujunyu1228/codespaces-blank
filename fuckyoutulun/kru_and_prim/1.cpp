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
// int m(int x,int y){}
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        e[i]={a,b,c};
    }
    for(int i=1;i<=n;i++)fa[i]=i;
    sort(e+1,e+m+1,cmp);
    int cnt=0,sum=0;
    for(int i=1;i<=m;i++){
        int a=e[i].x,b=e[i].y;
        int aa=f(a);
        int bb=f(b);
        if(aa!=bb){
            cnt++;
            sum=sum+e[i].w;
            fa[aa]=bb;
        }
        set<int>fas;
        for(int i=1;i<=n;i++){
            fas.insert(f(i));
        }
        if(fas.size()==k)break;
    }
    set<int>fas;
    for(int i=1;i<=n;i++){
        fas.insert(f(i));
    }
    if(fas.size()!=k)cout<<"No Answer";
    else cout<<sum;
}