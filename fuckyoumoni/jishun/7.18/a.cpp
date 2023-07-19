#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int a[N];
int cmp(int a,int b){return a>b;}
int main(){
    int n;
    cin>>n;
    int m1=-1,m2=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        // if(a[i]==m1)m2++;
        // if(a[i]>m1)m1=a[i],m2=1;
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++){
        //a[i]+=i;
        if(a[i]+i>m1)m1=a[i]+i;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]+n>=m1)ans++;
    }
    cout<<ans;
}
