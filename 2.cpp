#include<iostream>
using namespace std;
int st[100000];
int h=1;
void push(int a){
    st[h]=a;
    h++;
}
int pop(){
    int cnt=st[h-1];
    h--;
    return cnt;
}
int front(){
    return st[h-1];
}
int main(){
    int cnt=0;
    char c;
    while(1){
        cin>>c;
        if(c=='@'){
            cout<<front();
            return 0;
        }
        if(c=='+'){
            int a=pop(),b=pop();
            push(a+b);
        }
        else if(c=='-'){
            int a=pop(),b=pop();
            push(b-a);
        }
        else if(c=='*'){
            int a=pop(),b=pop();
            push(a*b);
        }
        else if(c=='/'){
            int a=pop(),b=pop();
            push(b/a);
        }
        else{
            while(c!='.'){
                cnt=cnt*10+(c-'0');
                cin>>c;
            }
            push(cnt);
            cnt=0;
        }
    }
    cout<<endl;
    return 0;
}