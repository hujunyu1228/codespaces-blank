#include<bits/stdc++.h>
using namespace std;
const int N=5e7+10;
#define ll long long
ll lian[N];
int main(){
    ll n,m,sum=0;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll a;
        cin>>a;
        ll cnt=0;
        for(ll j=1;j<=a*n;j++){
            if(lian[(a*j)%n]==i)break;
            if(!lian[(a*j)%n]){
                cnt++;
                sum++;
            }
            lian[(a*j)%n]=i;
            //cout<<(a*j)%n<<" "<<(n%(a*j))<<endl;
        }
        if(sum==n&&!cnt){
            for(int j=i;j<=m;j++){
                cout<<"0"<<" ";
            }
            return 0;
        }
        cout<<cnt<<" ";
        
    }
}