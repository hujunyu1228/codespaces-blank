#include<bits/stdc++.h>
using namespace std;
const int N=5000;
int a[N][N];
priority_queue<int,vector<int>,greater<int>>b[N];
int n,m,k;
void floyd(){
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
                a[j][i]=a[i][j];
            }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j)b[i].push(a[i][j]);
        }
    }
}
int main(){
    cin>>n>>m>>k;
    memset(a,0x3f,sizeof(a));
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        a[x][y]=z;
        a[y][x]=z;
    }
    floyd();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            cout<<b[i].top()<<" ";
            b[i].pop();
        }
        cout<<endl;
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    return 0;
}
