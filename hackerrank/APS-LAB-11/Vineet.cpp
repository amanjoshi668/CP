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
#define INF 2510
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
lo counter=0;
struct node{
    lo color;
    lo size;
};
set<lo> g[INF*INF];
lo visited[INF][INF],a[INF][INF];
vl dx={0,-1,0,1};
vl dy={1,0,-1,0};
lo n,m;
vector<node>t;
set<ll>all_color_vis[INF*INF];
void dfs(lo x, lo y){
    visited[x][y]=t.size()-1;
    t.back().size++;
    REP(0,4){
        lo nx=x+dx[i];
        lo ny=y+dy[i];
        if(nx>=0 and ny>=0 and nx<n and ny<m){
            if(visited[nx][ny]==-1 and a[nx][ny]==a[x][y])dfs(nx,ny);
        }
    }
}
lo global_ans=0;
void dfs(lo node, lo color1, lo color2){
    global_ans+=t[node].size;
    all_color_vis[node].erase({color1,color2});
    TRV(g[node]){
        if(present(all_color_vis[it],mp(color1,color2))){
            dfs(it,color1,color2);
        }
    }
}
int main(int argc, char*argv[]){
    std::ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);cout.precision(20);
    cin>>n>>m;
    memset(visited,-1LL,sizeof(visited));
    REPE(0,n,0,m)cin>>a[i][j];
    REPE(0,n,0,m)if(visited[i][j]==-1){
        node temp{a[i][j],0};
        t.pb(temp);
        dfs(i,j);
        //debug4(i,j,t.back().color,t.back().size);
    }
    //print_matrix(visited,n,m);
    REPE(0,n,0,m){
        lo x=i;
        lo y=j;
        REPV(k,0,4){
            lo nx=x+dx[k];
            lo ny=y+dy[k];
            if(nx>=0 and ny>=0 and nx<n and ny<m){
                if(visited[nx][ny]!=visited[x][y])g[visited[nx][ny]].insert(visited[x][y]);
            }
        }
    }
    // REP(0,t.size()){
    //     debug3(i,t[i].color,t[i].size);
    //     cout<<endl;
    // }
    // REP(0,8)debug2(i,g[i]);
    REP(0,t.size()){
        TRV(g[i]){
            ll temp={t[it].color,t[i].color};
            if(temp.X>temp.Y)swap(temp.X,temp.Y);
            all_color_vis[i].insert(temp);
        }
    }
    lo res=0;
    REP(0,t.size()){
        TRV(all_color_vis[i]){
            global_ans=0;
            dfs(i,it.X,it.Y);
            res=max(res,global_ans);
        }
    }
    cout<<res;
    return 0;
}
