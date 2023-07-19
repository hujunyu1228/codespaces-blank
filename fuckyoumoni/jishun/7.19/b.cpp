#include<bits/stdc++.h>
using namespace std;
const int N=120;
#define ll long long
bool a[N][N];
int vis[4][N][N];
int b[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int sx,sy,ex,ey,minn=0x3f3f3f3f;
int dfs(int x,int y,int d,int cnt){
    if(a[x][y]==1)return -1;
    if(x==ex&&y==ey){minn=min(minn,cnt);return 0;}
    if(cnt>=vis[d][x][y])return -2;
    for(int i=0;i<4;i++){

    }
}
signed main(){
    memset(vis,0x3f,sizeof vis);
}