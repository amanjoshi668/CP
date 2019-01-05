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
template<typename T, typename U> ostream& operator<< ( ostream &o,map<T,U> v ) {
    if ( v.size()>0 )o<<*v.begin();
    bool used=true;
    TRV(v){
        if(!used)o<<" "<<it;
        used=false;
    }
    return o<<" ";
}
struct Node{
    lo ans;
    map<lo,lo> numbers;
    Node(){
        ans=0;
        numbers.clear();
    }
};
void merge(Node &c, Node &a,Node &b){
    c.numbers=a.numbers;
    TRV(b.numbers){
        if(present(c.numbers,it.X))c.numbers[it.X]+=it.Y;
        else c.numbers[it.X]=it.Y;
    }
    c.ans = a.ans+b.ans;
    return;
}
vector<Node> tree(4*INF);
vl a(INF),b(INF),lazy(4*INF);
void build(lo node, lo l, lo r){
    lazy[node]=0;
    tree[node].numbers.clear();
    if(l==r){
        tree[node].numbers[b[l]]=1;
        if(a[l]==b[l])tree[node].ans=1;
        return;
    }
    lo mid=(l+r)/2;
    build(2*node+1,l,mid);
    build(2*node+2,mid+1,r);
    merge(tree[node],tree[2*node+1],tree[2*node+2]);
}
void updateRange(lo node, lo start, lo end, lo l, lo r, lo val){
    if(lazy[node] != 0){ 
        // This node needs to be updated
        if(present(tree[node].numbers,lazy[node]))tree[node].ans = tree[node].numbers[lazy[node]];
        else tree[node].ans=0;   // Update it
        if(start != end){
            lazy[node*2+2] = lazy[node];                  // Mark child as lazy
            lazy[node*2+1] = lazy[node];                // Mark child as lazy
        }
        lazy[node] = 0;                                  // Reset it
    }
    if(start > end or start > r or end < l)              // Current segment is not within range [l, r]
        return;
    if(start >= l and end <= r){
        // Segment is fully within range
       cd  if(present(tree[node].numbers,lazy[node]))tree[node].ans = tree[node].numbers[lazy[node]];
        else tree[node].ans=0;   // Update it
        if(start != end)
        {
            // Not leaf node
            lazy[node*2+2] = val;
            lazy[node*2+1] = val;
        }
        return;
    }
    lo mid = (start + end) / 2;
    updateRange(node*2+1, start, mid, l, r, val);        // Updating left child
    updateRange(node*2 + 2, mid + 1, end, l, r, val);   // Updating right child
    tree[node].ans=tree[2*node+1].ans+tree[2*node+2].ans;
    //debug3(node,tree[node].ans,tree[node].numbers);
}
#define gc getchar_unlocked
#define pc putchar_unlocked
inline void lprint( lo a){
    lo i=0;
    char S[20];
    if(a==0)pc('0');
    while(a>0){
        S[i++]=a%10+'0';
        a=a/10;
    }
    --i;
    while(i>=0)pc(S[i--]);
    pc('\n');
}
inline lo uscan(){
    lo n=0,c=gc();
    while(c<'0' or c>'9')c=gc();
    while(c<='9' and c>='0'){
        n=n*10+c-'0';
        c=gc();
    }
    return n;
}
int main(int argc, char*argv[]){
    std::ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);cout.precision(20);
    lo t;
    t=uscan();
    while(t--){
        lo n,q;
        n=uscan();q=uscan();
        for(int i=0;i<n;i++)a[i]=uscan();
        for(int i=0;i<n;i++)b[i]=uscan();
        build(0,0,n-1);
        lo pr = tree[0].ans;
        lo x,y,z;
        while(q--){
            x=uscan();y=uscan();z=uscan();
            lo l=x^pr;
            lo r=y^pr;
            lo c=z^pr;
            if(l>r)swap(l,r);
            l--;r--;
            updateRange(0,0,n-1,l,r,c);
            pr=tree[0].ans;
            lprint(pr);
        }
    }
    return 0;
}
