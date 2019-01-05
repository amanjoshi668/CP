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
class SEGMENT_TREE
{
    lo n;
    vl seg_tree;
    vl lazy;
    public:
    SEGMENT_TREE(lo n)
    {
        this->n = n;
        seg_tree.resize(4*(n + 1));
        lazy.resize(4*(n + 1));
        fill(all(seg_tree), 0LL);
        fill(all(lazy), 0LL);
    }
    void build(lo node, lo start, lo end, vl &a)
    {
        if (start == end)
        {
            seg_tree[node] = a[node];
        }
        else
        {
            lo mid = (start + end) / 2;
            build(2 * node + 1, start, mid, a);
            build(2 * node + 2, mid + 1, end, a);
            seg_tree[node] = seg_tree[node * 2 + 1] + seg_tree[node * 2 + 2];
            return;
        }
    }
    void update(lo node, lo start, lo end, lo l, lo r, lo val)
    {
        if (lazy[node] != 0)
        {
            // This node needs to be updated
            seg_tree[node] = lazy[node]; // Update it
            if (start != end)
            {
                lazy[node * 2 + 1] = lazy[node]; // Mark child as lazy
                lazy[node * 2 + 2] = lazy[node]; // Mark child as lazy
            }
            lazy[node] = 0; // Reset it
        }
        if (start > end or start > r or end < l)
            return;
        if (start >= l and end <= r)
        {
            // Segment is fully within range
            seg_tree[node] = val;
            if (start != end)
            {
                // Not leaf node
                lazy[node * 2 + 1] = val;
                lazy[node * 2 + 2] = val;
            }
            return;
        }
        lo mid = (start + end) / 2;
        update(node * 2 + 1, start, mid, l, r, val);                      // Updating left child
        update(node * 2 + 2, mid + 1, end, l, r, val);                    // Updating right child
        seg_tree[node] = max(seg_tree[node * 2 + 1] , seg_tree[node * 2 + 2]); // Updating root with max value
    }
    lo queryRange(lo node, lo start, lo end, lo l, lo r)
    {
        if (start > end or start > r or end < l)
            return 0; // Out of range
        if (lazy[node] != 0)
        {
            // This node needs to be updated
            seg_tree[node] = lazy[node]; // Update it
            if (start != end)
            {
                lazy[node * 2 + 1] = lazy[node]; // Mark child as lazy
                lazy[node * 2 + 2] = lazy[node]; // Mark child as lazy
            }
            lazy[node] = 0; // Reset it
        }
        if (start >= l and end <= r)
            return seg_tree[node];
        lo mid = (start + end) / 2;
        lo p1 = queryRange(node * 2 + 1, start, mid, l, r);   // Query left child
        lo p2 = queryRange(node * 2 + 2, mid + 1, end, l, r); // Query right child
        return max(p1 , p2);
    }
    void update(lo l, lo r, lo val)
    {
        update(0, 0, n-1, l, r, val);
    }
    void update(lo l, lo val)
    {
        update(l, l, val);
    }
    lo query(lo l, lo r)
    {
        return queryRange(0, 0, n-1, l, r);
    }
};
vl g[INF],entry(INF),exile(INF);
lo tim=0;
void dfs(lo node, lo par){
    entry[node] = tim++;
    TRV(g[node])if(it!=par){
        dfs(it,node);
    }
    exile[node] = tim;
}
int main(int argc, char*argv[]){
    std::ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);cout.precision(20);
    lo n;
    cin>>n;
    REP(1,n){
        lo x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1,0);
    SEGMENT_TREE tree1(n),tree2(n);
    lo Q;
    cin>>Q;
    REPV(q,1,Q+1){
        lo query;
        cin>>query;
        lo node;
        cin>>node;
        if(query==1){
            tree1.update(entry[node], exile[node]-1,q);
        }
        else if(query==2){
            tree2.update(entry[node],entry[node], q);
        }
        else {
            if(tree1.query(entry[node], entry[node]) > tree2.query(entry[node],exile[node]-1))cout<<1<<endl;
            else cout<<0<<endl;
        }
    }
    return 0;
}
