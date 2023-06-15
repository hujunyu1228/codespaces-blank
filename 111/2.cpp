#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize(2)
const int N=1e7+100;
int m;
char v[N];//i是不是质数
int p[N/15];//第i个质数
//prime:求质数
void prime(int n){  
    for(int i=2;i<=n;i++){
        if(v[i]==0){
            v[i]=1;
            p[++m]=i;
        }
        for(int j=1;j<=m&&p[j]*i<=n;j++){
            v[i*p[j]]=2;
            if(i%p[j]==0)break;
        }
    }
}
int main(){
    int n,m,l,r;
    prime(N);
    v[2]=2;
    for(;;){
        int i,cnt=1;
        cin>>i;
        if(i==0)break;
        for(int j=1;j<=i;j++){
            if(v[i-j]==1&&v[j]==1){
                cout<<i<<" = "<<j<<" + "<<i-j<<endl;
                cnt=0;
                break;
            }
        }
        if(cnt)cout<<"god bless you"<<endl;
    }
}