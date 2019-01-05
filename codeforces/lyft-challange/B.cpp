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
typedef long long lint;
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
template<typename T> ostream& operator<< ( ostream &o,set<T> v ) {
	TRV(v)o<<it<<" ";
    return o<<endl;
}
template<typename T,typename U> ostream& operator<< ( ostream &o,map<T,U> v ) {
	TRV(v)o<<it<<" ";
    return o<<endl;
}
lo gcd(lo a, lo b){
    if(b==0)return a;
    return gcd(b,a%b);
}
namespace miller_rabin{
lint mul(lint x, lint y, lint mod){ return (lint) x * y % mod; }
lint ipow(lint x, lint y, lint p){
lint ret = 1, piv = x % p;
while(y){
if(y&1) ret = mul(ret, piv, p);
piv = mul(piv, piv, p);
y >>= 1;
}
return ret;
}
bool miller_rabin(lint x, lint a){
if(x % a == 0) return 0;
lint d = x - 1;
while(1){
lint tmp = ipow(a, d, x);
if(d&1) return (tmp != 1 && tmp != x-1);
else if(tmp == x-1) return 0;
d >>= 1;
}
}
bool isprime(lint x){
for(auto &i : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37,41}){
if(x == i) return 1;
if(x > 40 && miller_rabin(x, i)) return 0;
}
if(x <= 40) return 0;
return 1;
}
}
namespace pollard_rho{
    lint f(lint x, lint n, lint c){
        return (c + miller_rabin::mul(x, x, n)) % n;
    }
    void rec(lint n, vector<lint> &v){
    if(n == 1) return;
    if(n % 2 == 0){
        v.push_back(2);
        rec(n/2, v);
        return;
    }
    if(miller_rabin::isprime(n)){
        v.push_back(n);
        return;
    }
    lint a, b, c;
    lo t=38000;
    while(t--){
        a = rand() % (n-2) + 2;
        b = a;
        c = rand() % 20 + 1;
        do{
            a = f(a, n, c);
            b = f(f(b, n, c), n, c);
        }while(gcd(abs(a-b), n) == 1);
        if(a != b) break;
    }
        lint x = gcd(abs(a-b), n);
        rec(x, v);
        rec(n/x, v);
        }
        vector<lint> factorize(lint n){
        vector<lint> ret;
        rec(n, ret);
        return ret;
    }
};

int main(int argc, char*argv[]){
    //std::ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);cout.precision(20);
    lo n;
    cin>>n;
    map<lo,lo> ma;
    map<lo,lo>other;
    REP(0,n){
        lo x;
        cin>>x;
        lo y = ld(sqrt(ld(x)));
        if(y*y==x){
            lo z= ld(sqrt(ld(y)));
            if(z*z==y){
                if(present(ma,z))ma[z]+=4;
                else ma[z]=4;
            }
            else{
                if(present(ma,y))ma[y]+=2;
                else ma[y]=2;
            }
        }
        else{
            y = ld(cbrt(ld(x)));
            if(y*y*y==x){
                if(present(ma,y))ma[y]+=3;
                else ma[y]+=3;
            }
            else{
                if(present(other,x))other[x]++;
                else other[x]=1;
            }
        }
        //cout<<"Whoopie";
    }
    // debug(ma);
    // debug(other);
    set<lo>possible;
    for(auto it= other.begin();it!=other.end();it++){
        bool first=true;
        for(auto it2=it;it2!=other.end();it2++){
            if(!first)possible.insert(gcd(it->X, it2->X));
            first=false;
        }
    }    
    possible.erase(1);
    vl t;
    // debug(other);
    TRV(other){
        for(auto it2:possible){
            if(it.X%it2==0){
                t.pb(it.X);
                if(present(ma,it2))ma[it2]+=it.Y;
                else ma[it2]=it.Y;
                lo cc=it.X/it2;
                if(present(ma,cc))ma[cc]+=it.Y;
                else ma[cc]=it.Y;
                break;
            }
        }
    }
    TRV(t){
        other.erase(it);
    }
    t.clear();
    // debug(ma);
    TRV(ma){
        for(auto it2:other){
            if(it2.X%it.X==0){
                t.pb(it2.X);
                ma[it.X]++;
                if(present(ma,it2.X/it.X))ma[it2.X/it.X]+=it2.Y;
                else ma[it2.X/it.X]=it2.Y;
                break;
            } 
        }
        TRV(t){
            other.erase(it);
        }
        t.clear();
    }
    t.clear();
    lo res=1;
    TRV(ma)res=(res*(it.Y+1))%998244353LL;
    TRV(other)res=(res*(it.Y+1)*(it.Y+1))%998244353LL;
    cout<<res<<endl;
    return 0;
}
