#include <bits/stdc++.h>
#include <unistd.h>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp> // Including seg_tree_order_statistics_Node_update
#include <stdio.h>
#include <cassert>
using namespace std;
//using namespace __gnu_pbds;
/*
    TYPENAME
*/
typedef long long lo;
typedef long double ld;
#include <ctime>
typedef pair<lo, lo> ll; //pair
typedef vector<lo> vl;   //vector of long
typedef vector<ll> vll;  //vector of pair
typedef priority_queue<lo> p_q;
typedef vector<vl> vvl; //vector of vectors

/*
    MACROS
*/
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
#define CHECK_BIT(var, pos) ((var) & (1 << (pos)))
#define pb(a) push_back((a))
#define eps 1e-2
#define PI acos(-1.0)

/*
    DEBUG STATEMENTS
*/
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

/*
    print statements for data types
*/

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
/*
    COMMON HELPER FUNCTIONS
*/
template <typename T>
T &&vmin(T &&val)
{
    return std::forward<T>(val);
}

template <typename T0, typename T1, typename... Ts>
auto vmin(T0 &&val1, T1 &&val2, Ts &&... vs)
{
    return (val1 < val2) ? vmin(val1, std::forward<Ts>(vs)...) : vmin(val2, std::forward<Ts>(vs)...);
}
template <typename T>
T &&vmax(T &&val)
{
    return std::forward<T>(val);
}

template <typename T0, typename T1, typename... Ts>
auto vmax(T0 &&val1, T1 &&val2, Ts &&... vs)
{
    return (val1 > val2) ? vmax(val1, std::forward<Ts>(vs)...) : vmax(val2, std::forward<Ts>(vs)...);
}
template <typename T, typename U>
void add(T &a, U b)
{
    a += b;
    if (a > MOD)
        a -= MOD;
    if (a > MOD)
        a %= MOD;
}
template <typename T, typename U>
void mul(T a, U b)
{
    a *= b;
    return a % MOD;
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
vl g[INF], par(INF,0), down(INF,0);
lo dep[INF], fa[INF][18];
void dfs(lo node, lo parent, lo lv)
{
    down[node] = 1;
    dep[node] = lv;
    fa[node][0] = par[node] = parent;
    REP(1, 18)
    {
        if (fa[node][i - 1] == -1)
            fa[node][i] = -1;
        else
            fa[node][i] = fa[fa[node][i - 1]][i - 1];
    }
    TRV(g[node]){
        if (it != parent){
            dfs(it, node, lv + 1);
            down[node] += down[it];
        }
    }
}
inline lo bit(lo x, lo i) { return (x >> i) & 1; }
lo lca(lo a, lo b)
{
    if (dep[a] > dep[b])
        swap(a, b);
    IREP(17, 0)
    if (bit(dep[b] - dep[a], i))
        b = fa[b][i];
    if (a == b)
        return a;
    IREP(17, 0)
    if (fa[a][i] != fa[b][i])
    {
        a = fa[a][i];
        b = fa[b][i];
    }
    return fa[a][0];
}
lo dist(lo a, lo b)
{
    return dep[a] + dep[b] - 2 * dep[lca(a, b)];
}
lo find_kth_par(lo node, lo k){
    IREP(17, 0)if(CHECK_BIT(k,i)){
        node = fa[node][i];
    }
    return node;
}
int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);
    lo n;
    cin>>n;
    REP(1,n){
        lo x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    lo m;
    cin>>m;
    dfs(1, 0, 0);
    down[0] = down[1];
    while(m--){
        lo x,y;
        cin>>x>>y;
        if (dep[x] < dep[y])swap(x, y);
        lo l = lca(x,y);
        lo d = dist(x, y);
        if(d == 0){
            cout << n << endl;
        }
        else if(d%2==1){
            cout << 0 << endl;
        }
        else if(dist(x,l) == dist(y,l)){
            lo par1 = find_kth_par(x, d/2 - 1);
            lo par2 = find_kth_par(y, d/2 - 1);
            cout << n - down[par1] - down[par2] << endl;
        }
        else{
            lo par1 = find_kth_par(x, d/2);
            lo par2 = find_kth_par(x, d/2 - 1);
            cout << down[par1] - down[par2] <<endl;
        }
    }
    REP(1, n+1)debug4(i, down[i], dep[i], par[i]);
    return 0;
}
