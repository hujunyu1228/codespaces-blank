#include<bits/stdc++.h>
using namespace std;
int a[1001][1001];
int v[1001][1001];
int n,m,k;
int main(){
    //memset(a,0x0f,sizeof(a));
    0x0f0f3f3f;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y,z;
        scanf("%d %d",&x,&y);
        a[x][y]=a[y][x]=1;
    }
    for(int i=1;i<=n;i++)a[i][i]=1;
    for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
        if(a[i][j]==a[i][k]+a[k][j]){
            v[i][j]++;
        }
        else if(a[i][j]>a[i][k]+a[k][j]){
            v[i][j]=1;
            a[i][j]=a[i][k]+a[k][j];
        }
    }
    for(int i=1;i<=n;i++){
        cout<<v[1][i]<<v[i][1]<<endl;
    }
    return 0;
}