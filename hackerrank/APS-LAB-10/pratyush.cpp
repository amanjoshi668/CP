#include <bits/stdc++.h>
#include<unistd.h>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp> // Including seg_tree_order_statistics_node_update
#include <stdio.h>
#include <cassert>
using namespace std;
//using namespace __gnu_pbds;
typedef long lo;
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
#define INF 140100
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
vector<lo>g[INF],g_in[INF],conv_graph[INF];
lo n,m;
vector<lo>visited(INF,0),possible(INF,-1);
vector<lo>order, size_of_comp(INF);
void dfs(lo node){
    visited[node]=1;
    for(auto it :g[node])if(!visited[it])dfs(it);
    order.push_back(node);
}
void dfs(){
    REP(0,n+2)visited[i]=0;
    REP(1,n+1)if(!visited[i])dfs(i);
}
void rev_dfs(lo node,lo comp){
    visited[node]=comp;
    for(auto it :g_in[node])if(!visited[it])rev_dfs(it,comp);
}
void rev_dfs(){
    REP(0,n+2)visited[i]=0;
    reverse(order.begin(),order.end());
    //debug(order);
    lo comp=1;
    for(auto it:order)if(!visited[it]){
        //debug(it);
        rev_dfs(it,comp++);
    }
}
void dfs_conv(lo node){
    possible[node]=0;
    if(size_of_comp[node]>1)possible[node]=1;
    TRV(conv_graph[node]){
        dfs_conv(it);
        possible[node]=max(possible[node],possible[it]);
    }
}
void dfs_conv(){
    lo ma=*max_element(all(visited));
    //REP(1,ma+1)debug2(i,conv_graph[i]);
    REP(1,ma+1){
        if(possible[i]==-1)dfs_conv(i);
    }
}
int main(){
    std::ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);cout.precision(20);
    lo t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        //visited.resize(n+1,0);
        order.clear();
        vector<pair<lo,lo>> edges;
        REP(0,m){
            lo x,y;
            cin>>x>>y;
            edges.push_back(make_pair(x,y));
            g[x].push_back(y);
            g_in[y].push_back(x);
        }
        //debug2(n,m);
        dfs();
        rev_dfs();
        lo ans=0;
        REP(0,n+2)size_of_comp[i]=0;
        REP(0,n+2)size_of_comp[visited[i]]++;
        //debug(visited);
        for(auto it: edges){
            if(visited[it.first]==visited[it.second]){
                ans++;
            }
            else {
                conv_graph[visited[it.first]].push_back(visited[it.second]);
            }
        }
        //debug(size_of_comp);
        REP(0,n+2)possible[i]=-1;
        dfs_conv();
        //debug(ans);
        TRV(edges){
            if(visited[it.first]!=visited[it.second]){
                if(possible[visited[it.second]]==1){
                    //debug(it);
                    ans++;
                }
            }
        }
        REP(0,n+2){
            g[i].clear();
            g_in[i].clear();
            conv_graph[i].clear();
        }
        cout<<ans<<endl;
    }
    return 0;
}