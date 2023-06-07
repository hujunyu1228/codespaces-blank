#include<bits/stdc++.h>
using namespace std;
int a[101][101],n,m;
int main(){
    cin>>n>>m;
    memset(a,0x3f,sizeof(a));
    for(int i=1;i<=n;i++)a[i][i]=0;
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        a[x][y]=z;
        a[y][x]=z;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                if(a[i][j]>a[i][k]+a[k][j]){
                    a[i][j]=a[i][k]+a[k][j];
                }
            }
    // int max2=0x3f3f3f3e,want=0; 
    // for(int i=1;i<=n;i++){
    //     int maxx=0;
    //     for(int j=1;j<=n;j++){
    //         if(i!=j)continue;
    //         maxx=max(maxx,a[i][j]);
    //     }
    //     if(max2<maxx){
    //         want=i;
    //         max2=maxx;
    //     }
    // }
    for     
}