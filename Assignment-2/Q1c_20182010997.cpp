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
    for ( unsigned   i=1; i<v.size(); i++ )o<<'\t'<<v[i];
    return o<<'\t';
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
struct entry {
        lo nr[2], p;
};
vl cont(6000000);
vector<entry> output(6000000);
void cont_sort(const vector<entry > & L , lo index){
    lo i;
    fill(all(cont),lo(0));
for(i = 0; i<L.size(); ++i){
        ++cont[L[i].nr[index]+1];
    }
    for (i = 1; i <6000000; ++i)cont[i] += cont[i-1];
for (i=L.size()-1;i>=0; --i){
        output[cont[L[i].nr[index]+1]-1] = L[i];
        --cont[L[i].nr[index]+1];
    }
}
pair<vl,vl> suffix_lcp_array(string A){
    lo n=A.length();
    vl current(n);
    vl prev(n);
    vector <entry> L(n);
    lo i, stp, cnt;
    REP(0,n)prev[i]=int(A[i]);
    for (stp = 1, cnt = 1; cnt >> 1 < n; stp ++, cnt <<= 1) {
        for (i = 0; i < n; i ++){
            L[i].nr[0] = prev[i];
            L[i].nr[1] = i + cnt < n ? prev[i + cnt] : -1;
            L[i].p = i;
        }
        cont_sort(L,1);
        REP(0,L.size())L[i]=output[i];
        cont_sort(L,0);
        REP(0,L.size())L[i]=output[i];
        for (i=0;i<n;i ++) current[L[i].p]=i>0 && L[i].nr[0]==L[i-1].nr[0] && L[i].nr[1]==L[i - 1].nr[1] ?
        current[L[i - 1].p] : i;
        prev=current;
    }
    vl sa=current;
    lo k=0;
    vl lcp(n,0);
    vl ranks(n,0);
    REP(0,n)ranks[sa[i]]=i;
    swap(ranks,sa);
    for(lo i=0; i<n; i++){
        if(ranks[i]==n-1){
            k=0;
            continue;
        }
        lo j=sa[ranks[i]+1];
        while(i+k<n && j+k<n && A[i+k]==A[j+k])k++;
        lcp[ranks[i]]=k;
        if(k>0)k--;
    }
    return mp(sa,lcp);
}
int main(int argc, char*argv[]){
    std::ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);cout.precision(20);
    string s;
    cin>>s;
    string y = s;
    reverse(all(y));
    y = s+char('z'+1)+y;
    auto result = suffix_lcp_array(y);
    //debug(result);
    lo pos=0;
    long long longest_length = 0;
    // debug(result.X);
    // debug(result.Y);
    // for(int i =0; i < y.length(); ++i)
    //     printf("%d \t %d \t %s \n",result.X[i], result.Y[i], y.begin() + result.X[i]);
   // debug2(y,y.length());
    REP(1,y.length()){
        if(result.Y[i-1]>longest_length){
            if((result.X[i-1]<s.length() and result.X[i]>s.length()) or (result.X[i-1]>s.length() and result.X[i]<s.length())){
            
            lo a = result.X[i];
            lo b = result.X[i-1];
            if((a +b + result.Y[i-1]) == y.length()){
               // cout<<i<<" "<<min(a,b)<<endl;
                longest_length = result.Y[i-1];
                pos = result.X[i];
            }
            }
        }
    }
    //debug2(pos,longest_length);
    //longest_length = max(longest_length, 1LL);
    cout<<y.substr(pos,longest_length);
    return 0;
}
