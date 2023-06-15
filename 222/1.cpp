#include<bits/stdc++.h>
#include<numeric>
using namespace std;
#define ll long long
int main(){
    ll x,y,z,cnt,cnt2;
    
    ll minn=1e14;
    cin>>y>>z;
    if(z<=100000000000+y){
        cout<<100000000000+y-z<<endl;
        return 0;
    }
    else for(ll i=100000000000/*1e12*/;i<=999999000000/*~1e13*/;i+=1000000){
        cnt=i+y;
        if(abs(cnt-z)>=minn)break;
        else {
            minn=abs(cnt-z);
            
        }
    }
    cout<<minn;
}