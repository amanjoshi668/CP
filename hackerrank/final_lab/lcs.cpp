#include <bits/stdc++.h>
#include<unistd.h>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp> // Including seg_tree_order_statistics_node_update
#include <stdio.h>
#include <cassert>
using namespace std;
//using namespace __gnu_pbds;
typedef long long lo;
typedef long double ld;
#include <ctime>
typedef pair<lo,lo> ll;//pair
typedef vector<lo> vl;  //vector of long
typedef vector<ll > vll;   //vector of pair
typedef priority_queue<lo>p_q;
typedef vector< vl > vvl;  //vector of vectors
#define X first
#define Y second
#define mp(a,b) make_pair((a),(b))
#define REP(a,b) for(lo i=(a);i<(lo)b;i++)//no need to declare variable i
#define REPE(a,b,c,d) REP(a,b)for(lo j=(c);j<(lo)d;j++)//no need to declare vaiables i,j
#define REPV(a,b,c) for(lo(a)=b;(a)<(c);(a)++)//a is the variable
#define IREP(a,b) for(lo i=(a);i>=(b);i--)
#define IREPV(a,b,c) for(lo(a)=b;(a)>=(c);(a)--)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(v) (v).begin(),(v).end()
#define TRV(a) for(auto &it : a)
#define INF 100010
#define MOD 1000000007
#define M 1000000007
#define BLOCK 300
#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))
#define pb(a) push_back((a))
#define eps 1e-2
#define PI acos(-1.0)
#define debug(x) cout<<#x<<"="<<x<<endl
#define debug2(x,y) cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#define debug3(x,y,z) cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;
#define debug4(x,y,z,w) cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<" "<<#w<<"="<<w<<endl;
#define debug5(x,y,z,w,t) cout<<#x<<"="<<x <<" ";debug4(y,z,w,t);
#define debug6(p,x,y,z,w,t) cout<<#p<<" "<<p<<" "<<#x<<"="<<x <<" ";debug4(y,z,w,t);
#define debug7(o,p,x,y,z,w,t) cout<<#o<<" "<<o<<" ";debug6(p,x,y,z,w,t);
#define present(container, element) (container.find(element) != container.end())
#define print_matrix(a,n,m) REPE(0,n,0,m){cout<<(a)[i][j]<<((j==m-1)?'\n':' ');}
#define wait int xxxx;cin>>xxxx;
#define derr(x) cerr<<#x<<"="<<x<<endl;
#define derr2(x,y) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#define derr3(x,y,z) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;
#define derr4(x,y,z,w) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<" "<<#w<<"="<<w<<endl;
#define derr5(x,y,z,w,t) cerr<<#x<<"="<<x <<" ";derr4(y,z,w,t);
#define derr6(p,x,y,z,w,t) cerr<<#p<<" "<<p<<" "<<#x<<"="<<x <<" ";derr4(y,z,w,t);
#define derr7(o,p,x,y,z,w,t) cerr<<#o<<" "<<o<<" ";derr6(p,x,y,z,w,t);
#define endl "\n"
template<typename T> ostream& operator<< ( ostream &o,vector<T> v ) {
    if ( v.size() >0 )o<<v[0];
    for ( unsigned   i=1; i<v.size(); i++ )o<<" "<<v[i];
    return o<<" ";
}
template<typename U,typename V> ostream& operator<< ( ostream &o,pair<U,V> p ) {
    return o<<"("<<p.first<<", "<<p.second<<") ";
}
template<typename T> istream& operator>> ( istream &in,vector<T> &v ) {
    for ( unsigned   i=0; i<v.size(); i++ )in>>v[i];
    return in;
}
template<typename T> istream& operator>> ( istream &in,pair <T,T> &p ) {
    in>>p.X;
    in>>p.Y;
    return in;
}
template<typename T> ostream& operator<< ( ostream &o,set<T> v ) {
    TRV(v)o<<it<<" ";
    return o<<endl;
}
template<typename T,typename U> ostream& operator<< ( ostream &o,map<T,U> v ) {
    TRV(v)o<<it<<" ";
    return o<<endl;
}
vl tree(4*INF),ar,lazy(4*INF,0);
void build(lo node, lo l, lo r){
    lazy[node]=0;
    if(l==r){
        tree[node]=ar[l];
        return ;
    }
    lo mid=(l+r)/2;
    build(node*2+1, l, mid);
    build(node*2+2,mid+1,r);
    tree[node]=max(tree[node*2+1],tree[node*2+2]);
}
void update(lo node, lo beg,lo end, lo l, lo r, lo val){
    if(lazy[node]){
        tree[node]+=lazy[node];
        if(beg!=end){
            lazy[node*2+1]+=val;
            lazy[2*node+2]+=val;
        };
    }
    if(beg>end or l>end or r<beg)return ;
    if(beg>=l and end<=r){
        tree[node]+=val;
        if(beg!=end){
            lazy[2*node+1]+=val;
            lazy[2*node+2]+=val;
        }
        return;
    } 
    lo mid=(beg+end)/2;
    update(2*node+1,beg,mid,l,r,val);
    update(2*node+2,mid+1,end,l,r,val);
    tree[node]=max(tree[2*node+1],tree[2*node+2]);
}
int main(int argc, char*argv[]){
    std::ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);cout.precision(20);
    lo t;
    cin>>t;
    while(t--){
        lo n;
        cin>>n;
        vl a(n);
        cin>>a;
        if(n==1){
            cout<<a[0]<<endl;
            continue;
        }
        vl dp(101,0);
        REP(1,n){
            dp[0]=0;
            ar=dp;
            for(lo k=1;k<=a[i-1];k++){
                ar[k]+=abs(1-k);
            }
            // REPV(k,0,11)cout<<ar[k]<<" ";
            // cout<<"?????????????????????????"<<endl;
            build(0,0,a[i-1]);
            dp[1]=tree[0];
            REPV(j,2,a[i]+1){
                //debug2(j,min(a[i-1],j));
                update(0,0,a[i-1]+1,1,min(a[i-1],j-1),1);
                if(j<=a[i-1])update(0,0,a[i-1]+1,min(a[i-1],j-1),a[i-1],-1);
                if(lazy[0]){
                    tree[0]+=lazy[0];
                    lazy[1]+=lazy[0];
                    lazy[2]+=lazy[0];
                }
                dp[j]=tree[0];
            }
            // REPV(k,0,11)cout<<dp[k]<<" ";
            //cout<<endl;
        }
        lo ans=0;
        cout<<*max_element(all(dp))<<endl;;
    }
    return 0;
}
