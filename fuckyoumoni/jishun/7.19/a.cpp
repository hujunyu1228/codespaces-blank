#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
#define int long long
int a[N],d[N];
signed main(){
    int ans=0;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        d[i]=d[i-1]+a[i];
    }
    int flag=1;
    int st=1;
    while(flag){
        int i;
        int cnt;
        for(i=st+1;i<=n;i++){
            cnt=d[i];
            //cout<<i<<"->"<<d[i]<<";";
            if(cnt>0)break;
        }
        //cout<<cnt<<endl;
        if(i>=n){
            if(cnt>0)ans+=cnt;
            flag=0;
            break;
        }
        st=i;
        //cout<<st<<" "<<i<<" "<<ans<<endl;
        d[st]=cnt;
        ans+=cnt;
        
    }
    cout<<ans;
}