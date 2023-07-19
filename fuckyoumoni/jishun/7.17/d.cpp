#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],cnt[N];
void ac(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=0,iq=0;
    for(int i=n;i>=1;i--){
        if(a[i]<=iq)cnt[i]=1;
        else if(iq<q){iq++;cnt[i]=1;}
        else cnt[i]=0;
    }
    for(int i=1;i<=n;i++)cout<<cnt[i];
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        ac();
    }
}
