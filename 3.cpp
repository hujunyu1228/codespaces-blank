#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int i=a*(c/(a+b));
    int j=min(c%(a+b),a);
    cout<<i+j;
}