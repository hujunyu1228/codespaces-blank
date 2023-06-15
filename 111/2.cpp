#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int m;
bool v[N];//i是不是质数
int p[N];//第i个质数
long long sum[N+10];
int prime(int n){
    for(int i=2;i<=n;i++){
        if(v[i]==0){
            v[i]=1;
            p[++m]=i;
        }
        for(int j=1;j<=m&&p[j]*i<=n;j++){
            v[i*p[j]]=1;
            if(i%p[j]==0)break;
        }
    }
}
int main(){
    int n,m,l,r;
    // std::ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    cin>>n>>m;
    prime(m);
    for(int i=1;i<=m;i++)sum[i]=sum[i-1]+v[i];
    while(cin>>l>>r){
        if(l<1||r>m)cout<<"Crossing the line"<<endl;
        else{
            cout<<sum[r]-sum[l-1]<<endl;
        }
    }
}