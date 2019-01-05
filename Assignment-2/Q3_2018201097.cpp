#include <bits/stdc++.h>
#include <unistd.h>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp> // Including seg_tree_order_statistics_node_update
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
#define REPE(a, b, c, d) REP(a, b) \
for (lo j = (c); j < (lo)d; j++)                        //no need to declare vaiables i,j
#define REPV(a, b, c) for (lo(a) = b; (a) < (c); (a)++) //a is the variable
#define IREP(a, b) for (lo i = (a); i >= (b); i--)
#define IREPV(a, b, c) for (lo(a) = b; (a) >= (c); (a)--)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(v) (v).begin(), (v).end()
#define TRV(a) for (auto &it : a)
#define INF 1000
#define MOD 1000000007
#define M 1000000007
#define BLOCK 300
#define CHECK_BIT(var, pos) ((var) & (1 << (pos)))
#define pb(a) push_back((a))
#define eps 1e-2
#define PI acos(-1.0)
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
#define present(container, element) (container.find(element) != container.end())
#define print_matrix(a, n, m) \
    REPE(0, n, 0, m) { cout << (a)[i][j] << ((j == m - 1) ? '\n' : ' '); }
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
lo fun(vl &a, lo i, lo x)
{
    sort(a.begin() + i, a.begin() + i + x);
    return a[i + x / 2];
}
lo partition(vl &a, lo l, lo r, lo k)
{
    REP(l, r)
    if (a[i] == k)
    {
        swap(a[i], a[r]);
        break;
    }
    lo i = l;
    REPV(j, l, r)
    {
        if (a[j] <= k)
        {
            swap(a[j], a[i]);
            i++;
        }
    }
    swap(a[i], a[r]);
    return i;
}
lo councnt = 0;
lo kth_smallest(vl &a, lo l, lo r, lo k)
{
    //derr5(l,r,k,a.size(),a);
    if (k > 0 and k <= r - l + 1)
    {
        councnt++;
        lo n = r - l + 1;
        lo i;
        vl median((n + 4) / 5);
        for (i = 0; i < n / 5; i++)
            median[i] = (fun(a, l + i * 5, 5));
        if (n % 5 != 0)
        {
            median.back() = (fun(a, l + i * 5, n % 5));
        }
        lo med_median;
        if (median.size() == 1)
        {
            med_median = median[0];
        }
        else
        {
            med_median = kth_smallest(median, 0LL, lo(median.size() - 1), lo(median.size() / 2));
        }
        lo pos = partition(a, l, r, med_median);
        if (pos - l == k - 1)
            return a[pos];
        if (pos - l > k - 1)
            return kth_smallest(a, l, pos - 1, k);
        return kth_smallest(a, pos + 1, r, k - pos + l - 1);
    }
    return LLONG_MAX;
}
int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);
    vl a;
    REP(0, INF)
    a.pb(i);
    lo finddd = rand() % INF;
    random_shuffle(all(a));
    vl b = a;
    clock_t start, end;
    start = clock();
    kth_smallest(a, 0, a.size() - 1, 10);
    end = clock();
    double duration_sec = double(end - start) / CLOCKS_PER_SEC;
    cout << duration_sec << endl;
    a = b;
    start = clock();
    nth_element(a.begin(), a.begin() + INF, a.end());
    end = clock();
    duration_sec = double(end - start) / CLOCKS_PER_SEC;
    cout << duration_sec << endl;
    cout << councnt << endl;
    return 0;
}
