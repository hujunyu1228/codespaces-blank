#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
int st[100010];
int nxt[100010];
int a[100010];
int h=1;

inline void push(int a){
    st[h]=a;
    h++;
}
inline int popfront(){
    int cnt=st[h-1];
    h--;
    return cnt;
}
inline int front(){
    return st[h-1];
}
int main(){
    st[0]=-1;
    int t;
    cin>>t;
    for(int tt=1;tt<=t;tt++){
        memset(st,0,sizeof(st));
        st[0]=-1;
        int n;
        cin>>n;
        for(int i=n;i>=1;i--){
            cin>>a[i];
        }
        //cout<<"test"<<endl;
        for(int i=1;i<=n;i++){
            if(a[i]<front()||front()==-1){
                nxt[i]=front();
                push(a[i]);
            }
            else {
                while(1){
                    if(a[i]>=front()&&front()!=-1){
                        h--;
                    }
                    if(a[i]<front()||front()==-1){
                        nxt[i]=front();
                        push(a[i]);
                        break;
                    }
                    //cout<<"-";
                }
            }
        }
        for(int i=n;i>=1;i--){
            cout<<a[i]<<"-->"<<nxt[i]<<endl;
        }
        cout<<endl;
    }
}