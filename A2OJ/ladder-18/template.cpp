/*
DORAEMON
:ANURAG MAITHANI
:SHOBHIT JOSHI
:AMAN JOSHI
*/
vl dx = {0, 0, -1, 1};
vl dy = {-1, 1, 0, 0};
inline bool correct(lo nx, lo ny)
{
    return (nx >= 0 && nx < n && ny >= 0 & ny < n);
}
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp> // Including seg_tree_order_statistics_node_update
#include <stdio.h>
#include <cassert>
using namespace std;
//using namespace __gnu_pbds;
typedef long long lo;
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
#define all(v) (v).begin(), (v).end()
#define TRV(a) for (auto it : a)
#define INF 100000007
#define MOD 1000000009
#define M 1000000007
#define CHECK_BIT(var, pos) ((var) & (1 << (pos)))
#define pb(a) push_back((a))
#define endl "\n"
#define eps 1e-8
#define PI 3.141592653589793
#define debug(x) cout << #x << "=" << x << endl
#define debug2(x, y) cout << #x << "=" << x << " " << #y << "=" << y << endl;
#define debug3(x, y, z) cout << #x << "=" << x << " " << #y << "=" << y << " " << #z << "=" << z << endl;
#define debug4(x, y, z, w) cout << #x << "=" << x << " " << #y << "=" << y << " " << #z << "=" << z << " " << #w << "=" << w << endl;
#define print_matrix(a, n, m) \
    REPE(0, n, 0, m) { cout << (a)[i][j] << ((j == m - 1) ? '\n' : ' '); }
template <typename T>
ostream &operator<<(ostream &o, vector<T> v)
{
    if (v.size() > 0)
        o << v[0];
    for (unsigned i = 1; i < v.size(); i++)
        o << " " << v[i];
    return o << endl;
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
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////LCA IN O(1)
const lo MAXN = INF;
const lo MAXLIST = INF * 2;
const lo LOG_MAXLIST = 18;
const lo SQRT_MAXLIST = 447;
const lo MAXBLOCKS = MAXLIST / ((LOG_MAXLIST + 1) / 2) + 1;
lo root;
vl g[MAXN];
lo h[MAXN];                                              // vertex height
vl a;                                                    // dfs list
lo a_pos[MAXN];                                          // positions in dfs list
lo block;                                                // block size = 0.5 log A.size ()
lo bt[MAXBLOCKS][LOG_MAXLIST + 1];                       // sparse table on blocks (relative minimum positions in blocks)
lo bhash[MAXBLOCKS];                                     // block hashes
lo brmq[SQRT_MAXLIST][LOG_MAXLIST / 2][LOG_MAXLIST / 2]; // rmq inside each block, indexed by block hash
lo log20[2 * MAXN];                                      // precalced logarithms (floored values)
// walk graph
void dfs(lo v, lo curh)
{
    h[v] = curh;
    a_pos[v] = (lo)a.size();
    a.push_back(v);
    for (size_t i = 0; i < g[v].size(); ++i)
        if (h[g[v][i]] == -1)
        {
            dfs(g[v][i], curh + 1);
            a.push_back(v);
        }
}
lo log(lo n)
{
    lo res = 1;
    while (1 << res < n)
        ++res;
    return res;
}
// compares two indices in a
inline lo min_h(lo i, lo j)
{
    return h[a[i]] < h[a[j]] ? i : j;
}
// O (N) preprocessing
void build_lca()
{
    lo sz = (lo)a.size();
    block = (log(sz) + 1) / 2;
    lo blocks = (sz + block - 1) / block;
    // precalc in each block and build sparse table
    memset(bt, 255, sizeof bt);
    for (lo i = 0, bl = 0, j = 0; i < sz; ++i, ++j)
    {
        if (j == block)
            j = 0, ++bl;
        if (bt[bl][0] == -1 || min_h(i, bt[bl][0]) == i)
            bt[bl][0] = i;
    }
    for (lo j = 1; j <= log(sz); ++j)
        for (lo i = 0; i < blocks; ++i)
        {
            lo ni = i + (1 << (j - 1));
            if (ni >= blocks)
                bt[i][j] = bt[i][j - 1];
            else
                bt[i][j] = min_h(bt[i][j - 1], bt[ni][j - 1]);
        }
    // calc hashes of blocks
    memset(bhash, 0, sizeof bhash);
    for (lo i = 0, bl = 0, j = 0; i < sz || j < block; ++i, ++j)
    {
        if (j == block)
            j = 0, ++bl;
        if (j > 0 && (i >= sz || min_h(i - 1, i) == i - 1))
            bhash[bl] += 1 << (j - 1);
    }
    // precalc RMQ inside each unique block
    memset(brmq, 255, sizeof brmq);
    for (lo i = 0; i < blocks; ++i)
    {
        lo id = bhash[i];
        if (brmq[id][0][0] != -1)
            continue;
        for (lo l = 0; l < block; ++l)
        {
            brmq[id][l][l] = l;
            for (lo r = l + 1; r < block; ++r)
            {
                brmq[id][l][r] = brmq[id][l][r - 1];
                if (i * block + r < sz)
                    brmq[id][l][r] =
                        min_h(i * block + brmq[id][l][r], i * block + r) - i * block;
            }
        }
    }
    for (lo i = 0, j = 0; i < sz; ++i)
    {
        if (1 << (j + 1) <= i)
            ++j;
        log20[i] = j;
    }
}
inline lo lca_in_block(lo bl, lo l, lo r)
{
    return brmq[bhash[bl]][l][r] + bl * block;
}
// answers LCA in O (1)
lo lca(lo v1, lo v2)
{
    lo l = a_pos[v1], r = a_pos[v2];
    if (l > r)
        swap(l, r);
    lo bl = l / block, br = r / block;
    if (bl == br)
        return a[lca_in_block(bl, l % block, r % block)];
    lo ans1 = lca_in_block(bl, l % block, block - 1);
    lo ans2 = lca_in_block(br, 0, r % block);
    lo ans = min_h(ans1, ans2);
    if (bl < br - 1)
    {
        lo pw2 = log20[br - bl - 1];
        lo ans3 = bt[bl + 1][pw2];
        lo ans4 = bt[br - (1 << pw2)][pw2];
        ans = min_h(ans, min_h(ans3, ans4));
    }
    return a[ans];
}
/////////////////////////////////////////////////////////////////////SEGMENT TREE
class SEGMENT_TREE
{
    vl seg_tree;
    vl lazy;
    SEGMENT_TREE(lo n)
    {
        seg_tree.resize(n + 1);
        lazy.resize(n + 1);
        fill(all(seg_tree), 0LL);
        fill(all(lazy), 0LL);
    }
    void build(lo node, lo start, lo end, vl &a)
    {
        if (start == end)
        {
            seg_tree[node] = a[start];
        }
        else
        {
            lo mid = (start + end) / 2;
            build(2 * node + 1, start, mid, a);
            build(2 * node + 2, mid + 1, end, a);
            seg_tree[node] = seg_tree[node * 2 + 1] + seg_tree[node * 2 + 2];
            return;
        }
    }
    void update(lo node, lo start, lo end, lo l, lo r, lo val)
    {
        if (lazy[node] != 0)
        {
            // This node needs to be updated
            seg_tree[node] += (end - start + 1) * lazy[node]; // Update it
            if (start != end)
            {
                lazy[node * 2 + 1] += lazy[node]; // Mark child as lazy
                lazy[node * 2 + 2] += lazy[node]; // Mark child as lazy
            }
            lazy[node] = 0; // Reset it
        }
        if (start > end or start > r or end < l)
            return;
        if (start >= l and end <= r)
        {
            // Segment is fully within range
            seg_tree[node] += (end - start + 1) * val;
            if (start != end)
            {
                // Not leaf node
                lazy[node * 2 + 1] += val;
                lazy[node * 2 + 2] += val;
            }
            return;
        }
        lo mid = (start + end) / 2;
        update(node * 2 + 1, start, mid, l, r, val);                      // Updating left child
        update(node * 2 + 2, mid + 1, end, l, r, val);                    // Updating right child
        seg_tree[node] = seg_tree[node * 2 + 1] + seg_tree[node * 2 + 2]; // Updating root with max value
    }
    lo queryRange(lo node, lo start, lo end, lo l, lo r)
    {
        if (start > end or start > r or end < l)
            return 0; // Out of range
        if (lazy[node] != 0)
        {
            // This node needs to be updated
            seg_tree[node] += (end - start + 1) * lazy[node]; // Update it
            if (start != end)
            {
                lazy[node * 2 + 1] += lazy[node]; // Mark child as lazy
                lazy[node * 2 + 2] += lazy[node]; // Mark child as lazy
            }
            lazy[node] = 0; // Reset it
        }
        if (start >= l and end <= r)
            return seg_tree[node];
        lo mid = (start + end) / 2;
        lo p1 = queryRange(node * 2 + 1, start, mid, l, r);   // Query left child
        lo p2 = queryRange(node * 2 + 2, mid + 1, end, l, r); // Query right child
        return (p1 + p2);
    }
    void update(lo l, lo r, lo val)
    {
        update(0, 0, n, l, r, val);
    }
    void update(lo l, lo val)
    {
        update(l, l, val);
    }
    lo query(lo l, lo r)
    {
        return queryRange(0, 0, n, l, r);
    }
};
///////////////////////////////////////////////////////////Z_FUNCTION
vl z_function(std ::string &s)
{
    lo n = (lo)s.length();
    vl z(n);
    for (lo i = 1, l = 0, r = 0; i < n; ++i)
    {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
////////////////////////////////////////////////////////MATH
lo gcd(lo a, lo b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
lo power(lo base, lo exp, lo m)
{
    lo res = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            res = (res * base) % m;
        base = (base * base) % m;
        exp /= 2;
    }
    return res % m;
}
lo inv(lo a, lo m)
{
    lo m0 = m, t, q;
    lo x0 = 0, x1 = 1;
    if (m == 1)
        return 0;
    while (a > 1)
    {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0)
        x1 += m0;
    return x1;
}
////////////////////////////////////////////////////////////nCr
lo power(lo base, lo exp)
{
    lo res = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            res = (res * base);
        base = (base * base);
        exp /= 2;
    }
    return res;
}
lo factor_power(lo n, lo p)
{
    lo res = 0;
    while (n > 0)
    {
        n /= p;
        res += n;
    }
    return res;
}
lo nCr3(lo n, lo k, lo p, lo e)
{
    lo pe = power(p, e);
    lo r = n - k;
    vl fact_pe;
    fact_pe.pb(1);
    lo acc = 1;
    REP(1, pe)
    {
        if (i % p != 0)
            acc = (acc * i) % pe;
        fact_pe.pb(acc);
    }
    lo top, bottom;
    top = bottom = 1;
    lo is_neg = 0;
    lo digits = 0;
    while (n > 0)
    {
        if (acc != 1)
            if (digits >= e)
            {
                is_neg ^= (n & 1);
                is_neg ^= (r & 1);
                is_neg ^= (k & 1);
            }
        top = (top * fact_pe[n % pe]) % pe;
        bottom = (bottom * fact_pe[r % pe]) % pe;
        bottom = (bottom * fact_pe[k % pe]) % pe;
        n /= p;
        r /= p;
        k /= p;
        digits++;
    }
    lo res = (top * inv(bottom, pe)) % pe;
    if (p != 2 or e < 3)
    {
        if (is_neg)
            res = pe - res;
    }
    return res;
}
lo nCr2(lo n, lo k, lo p, lo e)
{
    lo r = n - k;
    lo prime_part = factor_power(n, p);
    prime_part -= factor_power(k, p);
    prime_part -= factor_power(r, p);
    if (prime_part >= e)
        return 0;
    lo modpow = e - prime_part;
    r = nCr3(n, k, p, modpow);
    return (power(p, prime_part) * r) % power(p, e);
}
lo nCr(lo n, lo r, lo m)
{
    vll factors;
    lo y = m;
    for (lo i = 2; i * i <= m; i++)
    {
        if (y % i == 0)
        {
            lo x = 0;
            while (y % i == 0)
            {
                y /= i;
                x++;
            }
            factors.pb(mp(i, x));
        }
    }
    if (y > 1)
        factors.pb(mp(y, 1));
    vll result;
    REP(0, factors.size())
    {
        lo x = nCr2(n, r, factors[i].first, factors[i].second);
        result.pb(mp(x, power(factors[i].X, factors[i].Y)));
    }
    lo prod = 1;
    REP(0, result.size())
    prod *= result[i].second;
    lo ans = 0;
    REP(0, result.size())
    {
        lo pp = prod / result[i].second;
        ans += result[i].first * inv(pp, result[i].second) * pp;
    }
    return ans % prod;
}
lo fast_exp(lo base, lo exp, lo m)
{
    lo res = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            res = (res * base) % m;
        base = (base * base) % m;
        exp /= 2;
    }
    return res % m;
}
lo inv(lo a, lo m)
{
    lo m0 = m, t, q;
    lo x0 = 0, x1 = 1;

    if (m == 1)
        return 0;
    // Apply extended Euclid Algorithm
    while (a > 1)
    {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0)
        x1 += m0;
    return x1;
}
/////////////////////////////////////////////////////////////////////////union find
class UNION_FIND
{
    vl pset;
    UNION_FIND(lo n)
    {
        pset.resize(n + 1);
        REP(0, n + 1)
        pset[i] = i;
    }
    void initSet(lo _size)
    {
        pset.resize(_size);
        REP(0, _size - 1)
        pset[i] = i;
    }
    lo findSet(lo i) { return (pset[i] == i) ? i : (pset[i] = findSet(pset[i])); }
    void unionSet(lo i, lo j) { pset[findSet(i)] = findSet(j); }
    bool isSameSet(lo i, lo j) { return findSet(i) == findSet(j); }
};
/////////////////////////////////////////////////////////////////////////sieve
class SIEVE
{
    lo _sieve_size; // ll is defined as: typedef long long ll;
    bitset<500> bs; // 10^7 + small extra bits should be enough for most prime-related problems
    vl primes;      // compact list of primes in form of vector<lo>
    void sieve(lo upperbound)
    {                                 // create list of primes in [0 .. upperbound]
        _sieve_size = upperbound + 1; // add 1 to include upperbound
        bs.reset();
        bs.flip(); // set all numbers to 1
        bs.set(0, false);
        bs.set(1, false); // except index 0 and 1
        for (lo i = 2; i <= _sieve_size; i++)
            if (bs.test((size_t)i))
            {
                for (lo j = i * i; j <= _sieve_size; j += i)
                    bs.set((size_t)j, false);
                primes.push_back((lo)i);
            }
    }
};
//////////////////////////////////////////////////////////////////////////suffix array lcp
struct entry
{
    lo nr[2], p;
};
vl cont(60000);
vector<entry> output(60000);
void cont_sort(const vector<entry> &L, lo index)
{
    lo i;
    fill(all(cont), lo(0));
    for (i = 0; i < L.size(); ++i)
    {
        ++cont[L[i].nr[index] + 1];
    }
    for (i = 1; i < 60000; ++i)
        cont[i] += cont[i - 1];
    for (i = L.size() - 1; i >= 0; --i)
    {
        output[cont[L[i].nr[index] + 1] - 1] = L[i];
        --cont[L[i].nr[index] + 1];
    }
}
pair<vl, vl> suffix_lcp_array(std ::string &A)
{
    lo n = A.length();
    vl current(n);
    vl prev(n);
    vector<entry> L(n);
    lo i, stp, cnt;
    REP(0, n)
    prev[i] = int(A[i]);
    for (stp = 1, cnt = 1; cnt >> 1 < n; stp++, cnt <<= 1)
    {
        for (i = 0; i < n; i++)
        {
            L[i].nr[0] = prev[i];
            L[i].nr[1] = i + cnt < n ? prev[i + cnt] : -1;
            L[i].p = i;
        }
        cont_sort(L, 1);
        REP(0, L.size())
        L[i] = output[i];
        cont_sort(L, 0);
        REP(0, L.size())
        L[i] = output[i];
        for (i = 0; i < n; i++)
            current[L[i].p] = i > 0 && L[i].nr[0] == L[i - 1].nr[0] && L[i].nr[1] == L[i - 1].nr[1] ? current[L[i - 1].p] : i;
        prev = current;
    }
    vl sa = current;
    lo k = 0;
    vl lcp(n, 0);
    vl ranks(n, 0);
    REP(0, n)
    ranks[sa[i]] = i;
    swap(ranks, sa);
    for (lo i = 0; i < n; i++)
    {
        if (ranks[i] == n - 1)
        {
            k = 0;
            continue;
        }
        lo j = sa[ranks[i] + 1];
        while (i + k < n && j + k < n && A[i + k] == A[j + k])
            k++;
        lcp[ranks[i]] = k;
        if (k > 0)
            k--;
    }
    return mp(sa, lcp);
}
#define gc getchar_unlocked
#define pc putchar_unlocked
inline void sprint(lo a)
{
    if (a < 0)
    {
        pc('-');
        a = abs(a);
    }
    lo i = 0;
    char S[20];
    if (a == 0)
        pc('0');
    if (a < 0)
    {
        pc('-');
        a *= -1;
    }
    while (a > 0)
    {
        S[i++] = a % 10 + '0';
        a = a / 10;
    }
    --i;
    while (i >= 0)
        pc(S[i--]);
    pc(' ');
}
inline void lprint(lo a)
{
    if (a < 0)
    {
        pc('-');
        a = abs(a);
    }
    lo i = 0;
    char S[20];
    if (a == 0)
        pc('0');
    if (a < 0)
    {
        pc('-');
        a *= -1;
    }
    while (a > 0)
    {
        S[i++] = a % 10 + '0';
        a = a / 10;
    }
    --i;
    while (i >= 0)
        pc(S[i--]);
    pc('\n');
}
inline lo uscan()
{
    lo n = 0, c = gc();
    while (c < '0' || c > '9')
        c = gc();
    while (c <= '9' && c >= '0')
    {
        n = n * 10 + c - '0';
        c = gc();
    }
    return n;
}
#define MAXV 256
#define MAXE 100010
class MCMRF
{
    struct Edge
    {
        lo u, v, next;
        lo flow;
        lo cost;
    } edge[MAXE];
    lo head[MAXV], nEdge;
    lo cur[MAXV], que[MAXV * MAXV * 2], front, rear;
    lo dis[MAXV];
    bool vis[MAXV];
    inline void init()
    {
        memset(head, -1, sizeof(head));
        nEdge = 0;
    }
    inline void _addEdge(lo a, lo b, lo f, lo c)
    {
        edge[nEdge].u = a;
        edge[nEdge].v = b;
        edge[nEdge].flow = f;
        edge[nEdge].cost = c;
        edge[nEdge].next = head[a];
        head[a] = nEdge++;
    }
    inline void addEdge(lo a, lo b, lo f, lo c)
    {
        _addEdge(a, b, f, c);
        _addEdge(b, a, 0, -c);
    }
    lo dfs(lo x, lo dst, lo pre)
    {
        lo i, y;
        lo curFlow = pre, d;
        if (x == dst)
            return pre;
        for (vis[x] = true, i = cur[x]; ~i; i = edge[i].next)
        {
            if (edge[i].flow && !edge[i].cost && !vis[y = edge[i].v])
            {
                cur[x] = i;
                d = dfs(y, dst, min(curFlow, edge[i].flow));
                edge[i].flow -= d;
                edge[i ^ 1].flow += d;
                if (!(curFlow -= d))
                    break;
            }
        }
        if (!curFlow)
            vis[x] = false;
        return pre - curFlow;
    }
    bool spfa(lo v, lo src, lo dst)
    {
        lo i, x, y;
        memset(dis, 0x3F, sizeof(dis));
        memset(vis, 0, sizeof(vis));
        front = rear = v;
        dis[src] = 0;
        vis[que[rear++] = src] = true;
        while (front < rear)
        {
            vis[x = que[front++]] = false;
            for (i = head[x]; ~i; i = edge[i].next)
            {
                if (edge[i].flow && dis[y = edge[i].v] > dis[x] + edge[i].cost)
                {
                    dis[y] = dis[x] + edge[i].cost;
                    if (!vis[y])
                    {
                        if (front < rear && dis[y] < dis[que[front]])
                            que[--front] = y;
                        else
                            que[rear++] = y;
                        vis[y] = true;
                    }
                }
            }
        }
        return dis[dst] < INF;
    }
    ////////////////////////MINCOST RESTRICTED FLOW
    lo minCostMaxFlow(lo v, lo src, lo dst, lo lim, lo &netCost)
    {
        lo i;
        lo curFlow, totalFlow = 0;
        lo d = 0;
        for (netCost = 0; spfa(v, src, dst);)
        {
            d += dis[dst];
            for (i = 0; i < nEdge; ++i)
                edge[i].cost += dis[edge[i].u] - dis[edge[i].v];
            memcpy(cur, head, sizeof(head));
            memset(vis, 0, sizeof(vis));
            curFlow = dfs(src, dst, INF);
            if (lim - netCost < d * curFlow)
            {
                totalFlow += (lim - netCost) / d;
                break;
            }
            else
            {
                totalFlow += curFlow;
                netCost += d * curFlow;
            }
        }
        return totalFlow;
    }
};
//////////////////////////////////////////////////////////////SUFFIX AUTOMATON
class SUFFIX_AUTOMATON
{
    std ::string s, t;
    struct sanode
    {
        sanode *f, *ch[26];
        lo l, nl, ml;
        lo ct;
    } pool[INF * 2 + 18], *init = pool, *tail = pool, *p[INF * 2 + 18];
    lo n, tot, l;
    void add(lo c)
    {
        sanode *q = pool + (++tot), *p = tail;
        memset(q, 0, sizeof(sanode));
        q->l = q->ml = p->l + 1;
        q->nl = 0;
        q->ct = -1;
        tail = q;
        while (p and !p->ch[c])
        {
            p->ch[c] = q;
            p = p->f;
        }
        if (!p)
            q->f = init;
        else if (p->ch[c]->l == p->l + 1)
            q->f = p->ch[c];
        else
        {
            sanode *r = pool + (++tot), *u = p->ch[c];
            memcpy(r->ch, u->ch, sizeof(r->ch));
            r->nl = 0;
            r->ct = -1;
            r->l = r->ml = p->l + 1;
            r->f = u->f;
            u->f = q->f = r;
            while (p and p->ch[c] == u)
            {
                p->ch[c] = r;
                p = p->f;
            }
        }
    }
    void dfs(sanode *node)
    {
        if (node->ct >= 0)
            return;
        if (node->ct == -1)
            node->ct = 0;
        else
            node->ct = 1;
        REP(0, 26)
        if (node->ch[i])
        {
            dfs(node->ch[i]);
            node->ct += node->ch[i]->ct;
        }
    }
};
class LCA
{
    lo dep[INF], fa[INF][18];
    void dfs(lo node, lo par, lo lv)
    {
        dep[node] = lv;
        fa[node][0] = par;
        REP(1, 18)
        {
            if (fa[node][i - 1] == -1)
                fa[node][i] = -1;
            else
                fa[node][i] = fa[fa[node][i - 1]][i - 1];
        }
        TRV(g[node])
        if (it != par)
            dfs(it, node, lv + 1);
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
};
const lo mxN = 150;
const lo inf = 2e9;
struct Edgee
{
    lo to, cost, cap, flow, backEdge;
};
struct MCMF
{
    lo s, t, n;
    vector<Edgee> g[mxN];
    MCMF(lo _s, lo _t, lo _n)
    {
        s = _s, t = _t, n = _n;
    }
    void add_edge(lo u, lo v, lo cost, lo cap)
    {
        Edgee e1 = {v, cost, cap, 0, g[v].size()};
        Edgee e2 = {u, -cost, 0, 0, g[u].size()};
        g[u].push_back(e1);
        g[v].push_back(e2);
    }
    pair<lo, lo> minCostMaxFlow()
    {
        lo flow = 0, cost = 0;
        vector<lo> state(n), from(n), from_edge(n), d(n);
        deque<lo> q;
        while (true)
        {
            for (lo i = 0; i < n; i++)
                state[i] = 2, d[i] = inf, from[i] = -1;
            state[s] = 1;
            q.clear();
            q.push_back(s);
            d[s] = 0;
            while (!q.empty())
            {
                lo v = q.front();
                q.pop_front();
                state[v] = 0;
                for (lo i = 0; i < (lo)g[v].size(); i++)
                {
                    Edgee e = g[v][i];
                    if (e.flow >= e.cap || d[e.to] <= d[v] + e.cost)
                        continue;
                    lo to = e.to;
                    d[to] = d[v] + e.cost;
                    from[to] = v;
                    from_edge[to] = i;
                    if (state[to] == 1)
                        continue;
                    if (!state[to] || (!q.empty() && d[q.front()] > d[to]))
                        q.push_front(to);
                    else
                        q.push_back(to);
                    state[to] = 1;
                }
            }
            if (d[t] == inf)
                break;
            lo it = t, addflow = inf;
            while (it != s)
            {
                addflow = min(addflow,
                              g[from[it]][from_edge[it]].cap - g[from[it]][from_edge[it]].flow);
                it = from[it];
            }
            it = t;
            while (it != s)
            {
                g[from[it]][from_edge[it]].flow += addflow;
                g[it][g[from[it]][from_edge[it]].backEdge].flow -= addflow;
                cost += g[from[it]][from_edge[it]].cost * addflow;
                it = from[it];
            }
            flow += addflow;
        }
        return {cost, flow};
    }
};

class FFT
{
    typedef complex<double> base;

    void fft(vector<base> &a, bool invert)
    {
        lo n = (lo)a.size();

        for (lo i = 1, j = 0; i < n; ++i)
        {
            lo bit = n >> 1;
            for (; j >= bit; bit >>= 1)
                j -= bit;
            j += bit;
            if (i < j)
                swap(a[i], a[j]);
        }

        for (lo len = 2; len <= n; len <<= 1)
        {
            double ang = 2 * PI / len * (invert ? -1 : 1);
            base wlen(cos(ang), sin(ang));
            for (lo i = 0; i < n; i += len)
            {
                base w(1);
                for (lo j = 0; j < len / 2; ++j)
                {
                    base u = a[i + j], v = a[i + j + len / 2] * w;
                    a[i + j] = u + v;
                    a[i + j + len / 2] = u - v;
                    w *= wlen;
                }
            }
        }
        if (invert)
            for (lo i = 0; i < n; ++i)
                a[i] /= n;
    }
    vl mult(vl a, vl b)
    {
        //cout << a.size() << "%" << b.size() << endl;
        vector<base> fa(a.begin(), a.end()), fb(b.begin(), b.end());
        size_t n = 1;
        while (n < max(a.size(), b.size()))
            n <<= 1;
        n <<= 1;
        //cout << a.size() << " " << b.size() << endl;
        fa.resize(n), fb.resize(n);
        fft(fa, false), fft(fb, false);
        for (size_t i = 0; i < n; ++i)
            fa[i] *= fb[i];
        fft(fa, true);
        vl res;
        res.resize(n);
        for (size_t i = 0; i < n; ++i)
            res[i] = int(fa[i].real() + 0.5);
        return res;
    }
};
const int MAXN = 1515;        // число вершин
const int INFIN = 1000000000; // константа-бесконечность
struct edge
{
    int a, b, cap, flow;
};
int n, s, t, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> e;
vector<int> g[MAXN];
void add_edge(int a, int b, int cap)
{
    edge e1 = {a, b, cap, 0};
    edge e2 = {b, a, 0, 0};
    g[a].push_back((int)e.size());
    e.push_back(e1);
    g[b].push_back((int)e.size());
    e.push_back(e2);
}
bool bfs()
{
    int qh = 0, qt = 0;
    q[qt++] = s;
    memset(d, -1, n * sizeof d[0]);
    d[s] = 0;
    while (qh < qt && d[t] == -1)
    {
        int v = q[qh++];
        for (size_t i = 0; i < g[v].size(); ++i)
        {
            int id = g[v][i],
                to = e[id].b;
            if (d[to] == -1 && e[id].flow < e[id].cap)
            {
                q[qt++] = to;
                d[to] = d[v] + 1;
            }
        }
    }
    return d[t] != -1;
}
int dfs(int v, int flow)
{
    if (!flow)
        return 0;
    if (v == t)
        return flow;
    for (; ptr[v] < (int)g[v].size(); ++ptr[v])
    {
        int id = g[v][ptr[v]],
            to = e[id].b;
        if (d[to] != d[v] + 1)
            continue;
        int pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
        if (pushed)
        {
            e[id].flow += pushed;
            e[id ^ 1].flow -= pushed;
            return pushed;
        }
    }
    return 0;
}
int dinic()
{
    int flow = 0;
    for (;;)
    {
        if (!bfs())
            break;
        memset(ptr, 0, n * sizeof ptr[0]);
        while (int pushed = dfs(s, INFIN))
            flow += pushed;
    }
    return flow;
}
struct Node
{
    vl adj;
};
Node graf[INF];
struct TreeNode
{
    int parent;
    int depth;
    int chainTop;
    int subTreeSize;
};
TreeNode T[INF];
int DFS(int root, int parent, int depth)
{
    T[root].parent = parent;
    T[root].depth = depth;
    T[root].subTreeSize = 1;
    for (int i = 0; i < graf[root].adj.size(); i++)
    {
        int xt = graf[root].adj[i];
        if (xt == parent)
            continue;
        T[root].subTreeSize += DFS(xt, root, depth + 1);
    }
    return T[root].subTreeSize;
}
void HLD(int root, int parent, int chainTop)
{
    T[root].chainTop = chainTop;
    for (int i = 0; i < graf[root].adj.size(); i++)
    {
        int xt = graf[root].adj[i];
        if (xt == parent)
            continue;
        if (T[xt].subTreeSize * 1.0 > T[root].subTreeSize * 0.5)
            HLD(xt, root, chainTop);
        else
            HLD(xt, root, xt);
    }
}
inline int LCA(int u, int v)
{
    while (T[u].chainTop != T[v].chainTop)
    {
        if (T[T[u].chainTop].depth < T[T[v].chainTop].depth)
            v = T[T[v].chainTop].parent;
        else
            u = T[T[u].chainTop].parent;
    }
    if (T[u].depth < T[v].depth)
        return u;
    else
        return v;
} /*
//////////////////////////////////////////////////////////////////
• sum of the first n Fibonacci: f (n + 2) - 1 .
• The sum of the first n Fibonacci square: f (n) f * (n + 1) .
• sum of squares of all numbers from 1 to n: n * (n + 1) * (2n + 1) / 6 .
• Formula Cayley: there are n n-2 spanning trees in a complete graph of n vertices.
• Breakdown: the number der (n) of permutations of n elements in which none of the elements is in the original position is
given by der (n) = (n - 1) (der (n - 1) + der (n - 2)) where der (0) = 1 and give (1) = 0 .
• Theorem Erdos Gallai: it is a sufficient condition for an array represents the degrees of the vertices of a node: d 1 ≥
d 2 ≥ ... ≥ d n , Σ n

i = 1 d i = 2 k , Σ ki = 1 d i ≤ k (k - 1) + Σ k i k + 1 = min (d i , k) .
• Euler formula for planar graphs: V - E + F = 2 , where F is the number of faces.
• Moser Circle: the number of pieces in which a circle can be divided by ropes attached to n points such that no
has 3 strings internally competitors is given by g (n) = C n

4 + C n2 + 1 .

• Pick's Theorem: If I is the number of integer points within a polygon, the area of the polygon and b the number of
integer points on the edge, then A = i + b / 2 - 1 , .
• The number of generators trees in a complete bipartite graph is m n-1 × C m-1 .
• Kirchhoff's theorem: the number of spanning trees in a graph is equal to the cofactor of its Laplacian matrix L .
U = D - A , where D is a diagonal matrix in which a ii = d i and A is the adjacency matrix.
• Konig Theorem: a minimum coverage of vertices in a bipartite graph (the minimum number of vertices to be
removed to remove all edges) is equal to the maximum of the graph matching.
• Zeckendorf theorem: any positive integer can be represented by the sum of Fibonacci numbers that do not
includes two consecutive numbers. To find this sum, use the greedy algorithm, always looking for the most
fibonacci less than the number.

• Dilworth Theorem: In a DAG representing a partially ordered set, a chain is a subset vertices such that all pairs within it are comparable; an anti-chain is a subset such that all pairs
vertices of it are not comparable. The theorem states that the minimum partition in chains is equal to the comprimenton
most anti-chain. To compute, create a bipartite graph: for each vertex x , double to u x and v x . an edge
x → y is written as u x → v y . The size of the minimum partition, also called set width is N the
maximum matching.
• Mirsky Theorem: similar to Dilworth's theorem, the minimum size of the partition in anti-chains is equal to
length of the longest chain.

*/