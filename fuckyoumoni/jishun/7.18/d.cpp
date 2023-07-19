#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct codeforces{
    int a[N];
    int f(int x,int y){
        return a[y]-a[x-1];
    }
    int c(int x,int y){
        a[x]=a[x-1]+y;
    }
    void c(int x){c(x,0);}
}a;//0s,1s

int l[N],r[N];
int S__B(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>l[i]>>r[i];
    }
    int q;
    cin>>q;
    int arr[N];
    int sum[N];//qianzhuihe
    fill(arr+1,arr+n+1,q+1);
    for(int i=1;i<=q;i++){
        int x;cin>>x;
        arr[x]=i;
    }
    int mid;
    int ll=1,rr=q+1;
    auto chk=[&]{
        for(int i=1;i<=n;i++){
            sum[i]=sum[i-1]+(arr[i]<=mid);
        }
        for(int i=1;i<=m;i++){
            if(((sum[r[i]]-sum[l[i]-1])*2)>r[i]-l[i]+1)return 1;
        }
        return 0;
    };
    while(ll<rr){
        mid=ll+((rr-ll)/2);
        if(chk())rr=mid;
        else ll=mid+1;
        //cout<<1;
    }
    if(ll==q+1)cout<<-1<<endl;
    else cout<<ll<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--)S__B();
}
