#include<bits/stdc++.h>
using namespace std;
int a[202][202];
int n,m,k;
int main(){
    memset(a,0x3f,sizeof(a));
    0x3f3f3f3f;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        a[x][y]=min(a[x][y],z);
    }
    for(int i=1;i<=n;i++)a[i][i]=0;
    for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
    for(int i=1;i<=k;i++){
        int x,y;
        cin>>x>>y;
        if(a[x][y]<0x3f300000)cout<<a[x][y]<<endl;
        else cout<<"impossible"<<endl;
    }
    return 0;
}