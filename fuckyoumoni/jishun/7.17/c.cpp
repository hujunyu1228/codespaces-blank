#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
#define lb(x) (x&-x)
#define int long long
struct szsz{
    int a[N];
    int n;
    void c(int x,int y){
        // int z=y-a[x];
        // cout<<"c.y = "<<z<<";    ";
        // cout<<"c.a[x] = "<<a[x]<<";"<<endl;
        while(x<=n){
            a[x]+=y;
            x+=lb(x);
        }
    }
    int f(int x,int y){
        return __f(y)-__f(x-1);
    }
    int __f(int x){
        int s=0;
        while(x>0){
            s+=a[x];
            x-=lb(x);
        }
        return s;
    }
};
szsz a,b;
signed main(){
    int n,m;
    cin>>n>>m;
    a.n=n+10;
    b.n=n+10;
    for(int i=1;i<=m;i++){
        int q;
        cin>>q;
        if(q==1){
            int x,y;
            cin>>x>>y;

            a.c(x,-a.f(x,x));
            a.c(x,1);
            b.c(x,-b.f(x,x));
            b.c(y,1);
        }
        if(q==2){
            int x,y;
            cin>>x>>y;
            a.c(x,-a.f(x,x));
            b.c(x,-b.f(x,x));
        }
        if(q==3){
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            if(a.f(x1,x2)>=x2-x1+1){
                cout<<"Yes"<<endl;
            }
            else if(b.f(y1,y2)>=y2-y1+1){
                cout<<"Yes"<<endl;
            }
            else cout<<"No"<<endl;
            cout<<i<<": "<<a.f(x1,x2)<<","<<b.f(y1,y2)<<endl;
        }
    }
    // int aaa;
    // while(cin>>aaa){
    //     if(aaa==1){
    //         int x,y;
    //         cin>>x>>y;
    //         a.c(x,y);
    //     }
    //     if(aaa==2){
    //         int x;
    //         cin>>x;
    //         cout<<a.__f(x)<<endl;
    //     }
    // }
}