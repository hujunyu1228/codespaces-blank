int lg[1145];
// lg[1]=0;
// lg[2]=1;
// for(int i=1;i<=n;i++)lg[i]=lg[i/2]+1; 
int pre(){
    lg[1]=0;
    lg[2]=1;
    for(int i=3;i<=30;i++)lg[i]=lg[i/2]+1;
}
int f[][];
struct ST{
    int a[];
    int start()
}
