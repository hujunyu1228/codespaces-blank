#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>a[N];
int in[N];
stack<int>q;
int n,m;
//int v[N];
void topo(){
    int cnt=0;
    vector<int>s;
    while(q.size()){
        int t=q.top();
        q.pop();
        cnt++;
        //s+=t;s+=" ";
        //cout<<t<<" ";
        s.push_back(t);
        for(int i=0;i<a[t].size();i++){
            in[a[t][i]]--;
            if(in[a[t][i]]==0)q.push(a[t][i]);
        }
    }
    if(cnt==n)for(int i=0;i<s.size();i++)cout<<s[i]<<" ";
    else cout<<-1;
    
}
int main(){
    //int n;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int j,k;
        cin>>j>>k;
        //if(j==0)break;
        a[j].push_back(k);
        in[k]++;
    }
    for(int i=1;i<=n;i++)if(in[i]==0)q.push(i);
    topo();
    
}