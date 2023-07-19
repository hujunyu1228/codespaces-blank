#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int a[N][N];
int n,m;
inline int add(int x,int y,int num){
    for(int i=1;i<=n;i++){
        a[i][y]+=num;
        a[x][i]+=num;
    }
}
string chk(int x1,int y1,int x2,int y2){
    for(int i=x1;i<=x2;i++){
        for(int j=y1;j<=y2;j++){
            if(a[i][j]<1){
                return "No";
            }
        }
    }
    return "Yes";
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int t;
        cin>>t;
        if(t==1){
            int x,y;
            cin>>x>>y;
            add(x,y,1);
        }
        if(t==2){
            int x,y;
            cin>>x>>y;
            add(x,y,-1);
        }
        if(t==3){
            int a,b,c,d;
            cin>>a>>b>>c>>d;
            cout<<chk(a,b,c,d)<<endl;
        }
    }
}