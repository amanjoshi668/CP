#include <bits/stdc++.h>
#include <unistd.h>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp> // Including seg_tree_order_statistics_Node_update
#include <stdio.h>
#include <cassert>
using namespace std;
//using namespace __gnu_pbds;
typedef long long lo;
typedef long double ld;
#include <ctime>
typedef pair<lo, lo> ll; //pair
typedef vector<lo> vl;   //vector of long
typedef vector<ll> vll;  //vector of pair
typedef priority_queue<lo> p_q;
typedef vector<vl> vvl; //vector of vectors
#define X first
#define Y second
#define mp(a, b) make_pair((a), (b))
#define REP(a, b) for (lo i = (a); i < (lo)b; i++) //no need to declare variable i
#define REPE(a, b, c, d) \
    REP(a, b)            \
    for (lo j = (c); j < (lo)d; j++)                    //no need to declare vaiables i,j
#define REPV(a, b, c) for (lo(a) = b; (a) < (c); (a)++) //a is the variable
#define IREP(a, b) for (lo i = (a); i >= (b); i--)
#define IREPV(a, b, c) for (lo(a) = b; (a) >= (c); (a)--)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(v) (v).begin(), (v).end()
#define TRV(a) for (auto &it : a)
#define INF 500010
#define MOD 1000000007
#define M 1000000007
#define BLOCK 300
#define CHECK_BIT(var, pos) ((var) & (1LL << (pos)))
#define pb(a) push_back((a))
#define eps 1e-2
#define PI acos(-1.0)

#if _DEBUG
#define debug(x) cout << #x << "=" << x << endl
#define debug2(x, y) cout << #x << "=" << x << " " << #y << "=" << y << endl;
#define debug3(x, y, z) cout << #x << "=" << x << " " << #y << "=" << y << " " << #z << "=" << z << endl;
#define debug4(x, y, z, w) cout << #x << "=" << x << " " << #y << "=" << y << " " << #z << "=" << z << " " << #w << "=" << w << endl;
#define debug5(x, y, z, w, t)      \
    cout << #x << "=" << x << " "; \
    debug4(y, z, w, t);
#define debug6(p, x, y, z, w, t)                            \
    cout << #p << " " << p << " " << #x << "=" << x << " "; \
    debug4(y, z, w, t);
#define debug7(o, p, x, y, z, w, t) \
    cout << #o << " " << o << " ";  \
    debug6(p, x, y, z, w, t);
#define wait  \
    int xxxx; \
    cin >> xxxx;
#define derr(x) cerr << #x << "=" << x << endl;
#define derr2(x, y) cerr << #x << "=" << x << " " << #y << "=" << y << endl;
#define derr3(x, y, z) cerr << #x << "=" << x << " " << #y << "=" << y << " " << #z << "=" << z << endl;
#define derr4(x, y, z, w) cerr << #x << "=" << x << " " << #y << "=" << y << " " << #z << "=" << z << " " << #w << "=" << w << endl;
#define derr5(x, y, z, w, t)       \
    cerr << #x << "=" << x << " "; \
    derr4(y, z, w, t);
#define derr6(p, x, y, z, w, t)                             \
    cerr << #p << " " << p << " " << #x << "=" << x << " "; \
    derr4(y, z, w, t);
#define derr7(o, p, x, y, z, w, t) \
    cerr << #o << " " << o << " "; \
    derr6(p, x, y, z, w, t);

#else
#define debug(x) ;
#define debug2(x, y) ;
#define debug3(x, y, z) ;
#define debug4(x, y, z, q) ;
#define debug5(x, y, z, r, t) ;
#define debug6(x, y, z, r, t, s) ;
#define debug7(x, y, z, r, t, s, u) ;
#define wait ;
#define derr(x) ;
#define derr2(x, y) ;
#define derr3(x, y, z) ;
#define derr4(x, y, z, q) ;
#define derr5(x, y, z, r, t) ;
#define derr6(x, y, z, r, t, s) ;
#define derr7(x, y, z, r, t, f, u) ;
#endif

#define print_matrix(a, n, m) \
    REPE(0, n, 0, m) { cout << (a)[i][j] << ((j == m - 1) ? '\n' : ' '); }
#define present(container, element) (container.find(element) != container.end())
#define endl "\n"
template <typename T>
ostream &operator<<(ostream &o, vector<T> v)
{
    if (v.size() > 0)
        o << v[0];
    for (unsigned i = 1; i < v.size(); i++)
        o << " " << v[i];
    return o << " ";
}
template <typename U, typename V>
ostream &operator<<(ostream &o, pair<U, V> p)
{
    return o << "(" << p.first << ", " << p.second << ") ";
}
template <typename T>
istream &operator>>(istream &in, vector<T> &v)
{
    for (unsigned i = 0; i < v.size(); i++)
        in >> v[i];
    return in;
}
template <typename T>
istream &operator>>(istream &in, pair<T, T> &p)
{
    in >> p.X;
    in >> p.Y;
    return in;
}
template <typename T>
ostream &operator<<(ostream &o, set<T> v)
{
    TRV(v)
    o << it << " ";
    return o << endl;
}
template <typename T, typename U>
ostream &operator<<(ostream &o, map<T, U> v)
{
    TRV(v)
    o << it << " ";
    return o << endl;
}
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
lo indx;
lo dp[64][2][2][2][2];
lo num;
lo fun(lo i, bool carry, lo n, bool greater, bool equal1,bool equal2){
    // debug3(i,carry, n);
    if(i==indx+1){
        if(!greater)dp[i][carry][greater][equal1][equal2]=0;
        else{
            if(carry and equal1 and equal2)dp[i][carry][greater][equal1][equal2]=1;
            else dp[i][carry][greater][equal1][equal2]=0;
        }
        return dp[i][carry][greater][equal1][equal2];
    }
    if(dp[i][carry][greater][equal1][equal2]!=-1)return dp[i][carry][greater][equal1][equal2];
    lo ans = 0;
    lo bit = CHECK_BIT(n,i);
    lo bit_in = CHECK_BIT(num,i);
    if(carry){
        if(bit){
            if(greater){
                if(bit_in)ans+=fun(i+1, false, n,greater,true, true);
                else ans+=fun(i+1, false, n,greater,equal1, equal2);
                ans%=MOD;
                if(bit_in)ans+=fun(i+1,true, n,greater, true, equal2);
                else ans+=fun(i+1,true, n,greater, equal1, false);
                ans%=MOD;
                if(bit_in)ans+=fun(i+1,true, n,greater, equal1, true);
                else ans+=fun(i+1,true, n,greater, false, equal2);
                ans%=MOD;
                if(bit_in)ans+=fun(i+1,true, n,greater, equal1, equal2);
                else ans+=fun(i+1,true, n,greater, false, false);
                ans%=MOD;
            }
            else{
                if(bit_in)ans+=fun(i+1, false, n,greater,true, true);
                else ans+=fun(i+1, false, n,greater,equal1, equal2);
                ans%=MOD;
                if(bit_in)ans+=fun(i+1,true, n,true, true, equal2);
                else ans+=fun(i+1,true, n,true, equal1, false);
                ans%=MOD;
                if(bit_in)ans+=fun(i+1,true, n,greater, equal1, equal2);
                else ans+=fun(i+1,true, n,greater, false, false);
                ans%=MOD;
            }
            ans%=MOD;
        }
    }
    else{
        if(!bit){
            if(greater){
                // ans+=fun(i+1, true, n, greater);
                if(bit_in)ans+=fun(i+1, true, n,greater,true, true);
                else ans+=fun(i+1, true, n,greater,equal1, equal2);
                ans%=MOD;
                if(bit_in)ans+=fun(i+1,false, n,greater, true, equal2);
                else ans+=fun(i+1,false, n,greater, equal1, false);
                ans%=MOD;
                if(bit_in)ans+=fun(i+1,false, n,greater, equal1, true);
                else ans+=fun(i+1,false, n,greater, false, equal2);
                ans%=MOD;
                if(bit_in)ans+=fun(i+1,false, n,greater, equal1, equal2);
                else ans+=fun(i+1,false, n,greater, false, false);
                ans%=MOD;
            }
            else{
                if(bit_in)ans+=fun(i+1, true, n,greater,true, true);
                else ans+=fun(i+1, true, n,greater,equal1, equal2);
                ans%=MOD;
                if(bit_in)ans+=fun(i+1,false, n,true, true, equal2);
                else ans+=fun(i+1,false, n,true, equal1, false);
                ans%=MOD;
                if(bit_in)ans+=fun(i+1,false, n,greater, equal1, equal2);
                else ans+=fun(i+1,false, n,greater, false, false);
                ans%=MOD;
            }
                ans%=MOD;
        }
    }
    dp[i][carry][greater][equal1][equal2] = ans;
    return ans;
}
int main(int argc, char *argv[])
{
    // std::ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    // cout.precision(20);
    lo t;
    cin>>t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        lo n;
        cin>>n;
        lo num = n;
        lo cnt=0;
        lo xx=0;
        REP(1,n+1)xx^=i;
        debug(xx);
        REPE(1,n+1,i+1,n+1)if(!(i^j^xx^(i+j))){
            // debug2(i,j);
            cnt++;
        }
        debug(cnt);
        lo y = n&3;
        if(y==0)y = n;
        else if(y==1)y = 1;
        else if(y==2)y = n+1;
        else y = 0;
        debug(y);
        lo i=63;
        while(!CHECK_BIT(n,i))i--;
        indx = i;
        debug(indx);
        cout<<fun(0,0,y,0,true, true)<<endl;
        // REP(0,indx+1)cout<<dp[i][0][1]<<" ";cout<<endl;
        // REP(0,indx+1)cout<<dp[i][1][1]<<" ";cout<<endl;
    }
    return 0;
}
