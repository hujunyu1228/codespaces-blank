#include<bits/stdc++.h>
using namespace std;
int a[101][101],n,m;
int main(){
    cin>>n>>m;
    memset(a,0x3f,sizeof(a));
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        a[x][y]=z;
        a[y][x]=z;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                if(f[i][j]>f[i][k]+f[k][j]){

                }
            }
}