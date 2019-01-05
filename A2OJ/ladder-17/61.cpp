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
vll g[INF];
vl visited(INF,LLONG_MAX), blocked(INF), par(INF);
struct entry{
    lo distance;
    lo block;
    lo node;
};
bool operator < (const entry &l, const entry &t){
    if(l.distance == t.distance){
        if(l.block!=t.block)return l.block<t.block;
        return l.node<t.node;
    }
    return l.distance<t.distance;
}
bool operator == (const entry &l, const entry &t){
    return l.distance == t.distance and l.block == t.block and l.node == t.node;
}
int main(int argc, char*argv[]){
    std::ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);cout.precision(20);
    lo n,m;
    cin>>n>>m;
    set<ll> good_edges;
    REP(0,m){
        lo x,y,z;
        cin>>x>>y>>z;
        g[x].pb(mp(y,z));
        g[y].pb(mp(x,z));
        if(x>y)swap(x,y);
        if(z)good_edges.insert(mp(x,y));
    }
    set<entry>Q;
    Q.insert(entry({0,0,1}));
    blocked[1] = 0;
    visited[1] = 0;
    par[1] = 0;
    while(!Q.empty()){
        lo node = (*Q.begin()).node;
        debug2(node, Q.size());
        Q.erase(Q.begin());
        //if(node == n)break;
        TRV(g[node]){
            lo to = it.X;
            lo is_blocked = it.Y;
            if(visited[to] > visited[node] + 1){
                if(present(Q, entry({visited[to], blocked[to], to})))Q.erase(entry({visited[to], blocked[to], to}));
                visited[to] = visited[node] + 1;
                blocked[to] = blocked[node] + !is_blocked;
                par[to] = node;
                Q.insert(entry({visited[to], blocked[to], to}));
            }
            else if(visited[to] == visited[node] + 1 and blocked[node] + !is_blocked < blocked[to]){
                if(present(Q, entry({visited[to], blocked[to], to})))Q.erase(entry({visited[to], blocked[to], to}));
                blocked[to] = blocked[node] + !is_blocked;
                par[to] = node;
                Q.insert(entry({visited[to], blocked[to], to}));
            }
        }
    }
    lo node = n;
    vector<ll> ans;
    while(par[node]!=0){
        lo x = node;
        lo y = par[node];
        if(x>y)swap(x,y);
        if(!present(good_edges,mp(x,y))){
            ans.pb(mp(x,y));
        }
        else{
            good_edges.erase(mp(x,y));
        }
        node = par[node];
    }
    cout<<ans.size() + good_edges.size()<<endl;
    TRV(ans)cout<<it.X<<" "<<it.Y<<" 1"<<endl;
    TRV(good_edges)cout<<it.X<<" "<<it.Y<<" "<<0<<endl;
    return 0;
}
