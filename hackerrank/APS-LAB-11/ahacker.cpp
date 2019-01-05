#include<bits/stdc++.h>
using namespace std;
typedef long long lo;
#define INF 100010
lo tree[4*(INF+10)];
void update(lo node,lo beg,lo end, lo index ,lo val){
    if(end<beg or end<index or beg>index)return;
    if(beg==end){
        tree[node]=val;
        return;
    }
    lo mid=(beg+end)/2;
    update(2*node+1,beg,mid,index,val);
    update(2*node+2,mid+1,end,index,val);
    tree[node]=max(tree[2*node+1],tree[2*node+2]);
}
#define debug3(x,y,z) cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;

int main(int argc, char*argv[]){
    std::ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);cout.precision(20);
    lo t;
    cin>>t;
    while(t--){
        memset(tree, -1LL, sizeof(tree));
        lo n;
        cin>>n;
        lo a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
            update(0,0,INF,i,a[i]);
        }
        lo ans=0;
        for(int i=0;i<n;i++){
            lo q=tree[0];
            debug3(i,a[i],q);
            if(q!=-1){
                ans+=abs(a[i]-q);
                update(0,0,INF,i,-1);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
