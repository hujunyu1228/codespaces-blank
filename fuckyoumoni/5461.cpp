#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<pow(2,n);i++){
        for(int j=0;j<pow(2,n);j++){
            if((i|j)==(1<<n)-1)cout<<1<<" ";
            else cout<<0<<" ";
        }
        cout<<endl;
    }
}