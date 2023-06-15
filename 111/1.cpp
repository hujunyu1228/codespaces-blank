#include<bits/stdc++.h>
using namespace std;
stack<char>s;
string _no="NO";
char c;
int main(){
    while(cin>>c){
        if(c=='('){
            s.push(c);
        }
        if(c==')'){
            if(s.empty()){
                cout<<_no;
                return 0;
            }
            s.pop();
        }
        if(c=='@')break;
    }
    if(s.empty())cout<<"YES";
    else cout<<_no;
    return 0;
}