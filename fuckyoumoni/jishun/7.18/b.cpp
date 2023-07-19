#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct aaaaa{
    int c[N];
    int f(int a,int b){
        return c[b]-c[a-1];
    }
}a,b,c;
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        a.c[i]=a.c[i-1];
        b.c[i]=b.c[i-1];
        c.c[i]=c.c[i-1];
        int x;
        cin>>x;
        if(x==1)a.c[i]++;
        if(x==2)b.c[i]++;
        if(x==3)c.c[i]++;
    }
    while(m--){
        int l,r;
        cin>>l>>r;
        cout<<a.f(l,r)<<" "<<b.f(l,r)<<" "<<c.f(l,r)<<endl;
    }
}
