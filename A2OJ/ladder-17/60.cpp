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
#define INF 500010
#define MOD 1000000007
#define M 1000000007
#define BLOCK 300
#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))
#define pb(a) push_back((a))
#define eps 1e-2
#define PI acos(-1.0)

#if _DEBUG
#define debug(x) cout<<#x<<"="<<x<<endl
#define debug2(x,y) cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#define debug3(x,y,z) cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;
#define debug4(x,y,z,w) cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<" "<<#w<<"="<<w<<endl;
#define debug5(x,y,z,w,t) cout<<#x<<"="<<x <<" ";debug4(y,z,w,t);
#define debug6(p,x,y,z,w,t) cout<<#p<<" "<<p<<" "<<#x<<"="<<x <<" ";debug4(y,z,w,t);
#define debug7(o,p,x,y,z,w,t) cout<<#o<<" "<<o<<" ";debug6(p,x,y,z,w,t);
#define wait int xxxx;cin>>xxxx;
#define derr(x) cerr<<#x<<"="<<x<<endl;
#define derr2(x,y) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#define derr3(x,y,z) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;
#define derr4(x,y,z,w) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<" "<<#w<<"="<<w<<endl;
#define derr5(x,y,z,w,t) cerr<<#x<<"="<<x <<" ";derr4(y,z,w,t);
#define derr6(p,x,y,z,w,t) cerr<<#p<<" "<<p<<" "<<#x<<"="<<x <<" ";derr4(y,z,w,t);
#define derr7(o,p,x,y,z,w,t) cerr<<#o<<" "<<o<<" ";derr6(p,x,y,z,w,t);

#else
#define debug(x) ;
#define debug2(x,y) ;
#define debug3(x,y,z) ;
#define debug4(x,y,z,q) ;
#define debug5(x,y,z,r,t) ;
#define debug6(x,y,z,r,t,s) ;
#define debug7(x,y,z,r,t,s,u) ;
#define wait ;
#define derr(x) ;
#define derr2(x,y) ;
#define derr3(x,y,z) ;
#define derr4(x,y,z,q) ;
#define derr5(x,y,z,r,t) ;
#define derr6(x,y,z,r,t,s) ;
#define derr7(x,y,z,r,t,f,u) ;
#endif


#define print_matrix(a,n,m) REPE(0,n,0,m){cout<<(a)[i][j]<<((j==m-1)?'\n':' ');}
#define present(container, element) (container.find(element) != container.end())
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
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
ll fun(ll a, ll b){
    if(a.X<b.X)return a;
    return b;
}
vll tree(4*INF);
vl lazy(4*INF),a(INF);
void build(lo node, lo start , lo end){
    if(start == end){
        tree[node].X = a[start];
        tree[node].Y = start;
    }
    else{
        lo mid = (start +end) / 2;
        build( 2 * node + 1 , start , mid);
        build(2*node + 2, mid+1 ,end);
        tree[node] = fun(tree[node*2 +1] , tree[node*2+2]);
        return;
    }
}
void update(lo node, lo start, lo end, lo l, lo r, lo val){
    if(lazy[node] != 0){
        // This node needs to be updated
        tree[node].X += lazy[node];    // Update it
        if(start != end){
            lazy[node*2+1] += lazy[node];                  // Mark child as lazy
            lazy[node*2+2] += lazy[node];                // Mark child as lazy
        }
        lazy[node] = 0;                                  // Reset it
    }
    if(start > end or start > r or end < l)return;
    if(start >= l and end <= r){
        // Segment is fully within range
        tree[node].X +=  val;
        if(start != end){
            // Not leaf node
            lazy[node*2+1] += val;
            lazy[node*2+2] += val;
        }
        return;
    }
    lo mid = (start + end) / 2;
    update(node*2 + 1, start, mid, l, r, val);        // Updating left child
    update(node*2 + 2, mid + 1, end, l, r, val);   // Updating right child
    tree[node] = fun(tree[node*2 +1] , tree[node*2+2]);        // Updating root with max value
}
ll queryRange(lo node, lo start, lo end, lo l, lo r){
    if(start > end or start > r or end < l)return mp(LLONG_MAX,-1);         // Out of range
    if(lazy[node] != 0){
        // This node needs to be updated
        tree[node].X += lazy[node];            // Update it
        if(start != end){
            lazy[node*2+1] += lazy[node];         // Mark child as lazy
            lazy[node*2+2] += lazy[node];    // Mark child as lazy
        }
        lazy[node] = 0;                 // Reset it
    }
    if(start >= l and end <= r)return tree[node];
    lo mid = (start + end) / 2;
    ll p1 = queryRange(node*2 + 1, start, mid, l, r);         // Query left child
    ll p2 = queryRange(node*2 + 2, mid + 1, end, l, r); // Query right child
    return fun(p1 , p2);
}
lo N;
lo fun(lo l, lo r){
    if(r<l or l<0 or r>=N)return 0;
    ll temp = queryRange(0,0,N-1,l,r);
    debug3(l,r,temp);
    lo x = temp.X;
    lo index = temp.Y;
    lo n = r-l+1;
    if(x>=n)return n;
    update(0,0,N-1, l, r, -x);
    return min(n, x + fun(l, index-1) + fun(index+1, r));
}
int main(int argc, char*argv[]){
    // std::ios::sync_with_stdio(false);
	// cin.tie(0);cout.tie(0);cout.precision(20);
    cin>>N;
    REP(0,N)cin>>a[i];
    build(0,0,N-1);
    //cout<<queryRange(0,0,N-1,0,N-1);
    cout<<fun(0,N-1);
    return 0;
}
