#include<bits/stdc++.h>
using namespace std;
#define ll unsigned int
const int N=1e5+10;
ll n, a[N], m;
ll cnt[N];
ll ysum(int p){
    ll ans=0;
    for (int i = 1; i <= n;i++){
        if(i!=p)
            ans = ans ^ a[i];
    }
    return ans;
}
void xall(){
    for (int i = 1; i <= n;i++){
        cnt[i] = ysum(i);
    }
    for (int i = 1; i <= n;i++){
        a[i] = cnt[i];
    }
}
int main(){
    // freopen("xor3.in", "r", stdin);
    // freopen("ans.out", "w", stdout);
    int t;
    cin >> t;
    //int n, m;
    for (int tt = 1; tt <= t;tt++){
        cin >> n >> m;
        m = m % 2;
        for (int i = 1; i <= n;i++){
            cin >> a[i];
        }
        for (int i = 1; i <= m;i++){
            xall();
        }
        for (int i = 1; i <= n;i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
}