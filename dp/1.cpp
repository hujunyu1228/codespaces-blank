#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 3e6 + 10;
ll inv[N];
void ny(ll n,int p){
    (inv[1] = 1);
    for (int i = 2; i <= n; i++){
        (inv[i] = (long long)(p - p / i) * inv[p % i] % p);
    }
}
int main(){
    //ios::sync_with_stdio(false);
    ll n, p;
    cin >> n >> p;
    ny(n,p);
    cout<<inv[n];
    return 0;
}