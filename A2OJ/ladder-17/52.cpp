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
#define INF 1000010
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
struct EDGE{
    lo x,y,c;
    EDGE(lo _x=0, lo _y=0, lo _z=0):x(_x),y(_y),c(_z){}
};
vl pset;
lo find(lo x){
    if(x!=pset[x])return pset[x]=find(pset[x]);
    return x;
}
void union_set(lo x,lo y){
    x=find(x);
    y=find(y);
    pset[x]=y;
}
int main(int argc, char*argv[]){
    std::ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);cout.precision(20);
    lo n,m,k;
    cin>>n>>m>>k;
    vl l(k),r(k);
    lo cur=1;
    REP(0,k){
        lo x;
        cin>>x;
        l[i]=cur;
        cur+=x;
        r[i]=cur-1;
    }
    pset.resize(n+1);
    REP(0,n+1)pset[i]=i;
    vector<EDGE> edge(m);
    REP(0,m){
        cin>>edge[i].x>>edge[i].y>>edge[i].c;
        if(!edge[i].c)union_set(edge[i].x, edge[i].y);
    }
    bool err=false;
    vl to(n+1);
    REP(0,k){
        REPV(j,l[i],r[i])if(find(j)!=find(j+1))err=true;
        REPV(j,l[i],r[i]+1)to[j]=i;
    }
    if(err)cout<<"No";
    else{
        lo ee[k][k];
        REP(0,k){
            REPV(j,0,k)ee[i][j]=MOD;
            ee[i][i]=0;
        }
        REP(0,m){
            if(to[edge[i].x]!=to[edge[i].y]){
                ee[to[edge[i].x]][to[edge[i].y]]=min(edge[i].c,ee[to[edge[i].x]][to[edge[i].y]]);
                ee[to[edge[i].y]][to[edge[i].x]]=min(edge[i].c,ee[to[edge[i].y]][to[edge[i].x]]);
            }
        }
        REPV(ko,0,k){
            REP(0,k)
                REPV(j,0,k)ee[i][j]=min(ee[i][ko]+ee[ko][j],ee[i][j]);
        }
        cout<<"Yes"<<endl;
        REP(0,k){
            REPV(j,0,k){
                if(ee[i][j]==MOD)cout<<"-1";
                else cout<<ee[i][j];
                cout<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
