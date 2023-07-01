#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int f=1;
        for(int i=2;i<n;i++){
            if(n%i==0){
                cout<<"no"<<endl;;
                f=0;
                break;
            }
        }
        if(f)cout<<"yes"<<endl;
    }
}