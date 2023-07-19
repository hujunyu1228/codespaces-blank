#include<bits/stdc++.h>
using namespace std;
#define cint const int
cint N=1e6+10;
vector<int>a[N];
cint mod=100003;
int vis[N],fst[N];
int bfs(int st){
    queue<int>q;
    q.push(st);
    vis[st]=1;
    fst[st]=0;
    while(q.size()){
        int f=q.front();
        cout<<f<<endl;
        q.pop();
        for(int i=0;i<a[f].size();i++){
            int cnt=a[f][i];
            if(vis[cnt])continue;
            q.push(cnt);
        }
    }
}

int main(){
    
}