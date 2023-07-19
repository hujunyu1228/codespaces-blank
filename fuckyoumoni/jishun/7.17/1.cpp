#include<bits/stdc++.h>
using namespace std;
int cnt;
int dfs(int l,int r){
    if((l+r)%2==0){
        cnt++;
        dfs(l,(l+r)/2);
        dfs((l+r)/2,r);
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        cout<<(a-1)*((c&-c)-1ll)<<endl;
    }
}