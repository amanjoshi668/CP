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
#define REPE(a, b, c, d) \
    REP(a, b)            \
    for (lo j = (c); j < (lo)d; j++)                    //no need to declare vaiables i,j
#define REPV(a, b, c) for (lo(a) = b; (a) < (c); (a)++) //a is the variable
#define IREP(a, b) for (lo i = (a); i >= (b); i--)
#define IREPV(a, b, c) for (lo(a) = b; (a) >= (c); (a)--)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(v) (v).begin(), (v).end()
#define TRV(a) for (auto &it : a)
#define INF 1000010
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
struct StringBuilder
{
    char *data;
    bool normal;
    StringBuilder *First;
    StringBuilder *Second;
    StringBuilder();
    StringBuilder(char *s);
    //StringBuilder(StringBuilder &S);
    char *to_string();
};
StringBuilder ::StringBuilder()
{
    this->data = "";
    this->normal = true;
    this->First = this->Second = NULL;
}
StringBuilder ::StringBuilder(char *s)
{
    this->data = s;
    this->normal = true;
    this->First = this->Second = NULL;
}
// StringBuilder :: StringBuilder( StringBuilder &S){
//     this->data = S.data;
//     this->normal = S.normal;
//     this->First = S.First;
//     this->Second = S.Second;
// }
StringBuilder stringAppend(StringBuilder &S1, StringBuilder &S2)
{
    StringBuilder S3;
    S3.normal = false;
    S3.First = &S1;
    S3.Second = &S2;
    return S3;
}
StringBuilder StringInitialize(char *s)
{
    StringBuilder S(s);
    return S;
}
void make_string(StringBuilder &S, char *text)
{
    //debug2(S.normal,S.data);
    if (S.normal)
    {
        strcat(text, S.data);
        return;
    }
    make_string(*S.First, text);
    make_string(*S.Second, text);
}

lo find_length(StringBuilder &S)
{
    if (S.normal)
    {
        return strlen(S.data);
    }
    return find_length(*S.First) + find_length(*S.Second);
}
lo findSubstring(StringBuilder &S, const char *pattern)
{
    //memset(b, 0, sizeof b);
    lo size_of_string = find_length(S);
    vl b(size_of_string + strlen(pattern) + 10);
    lo m = strlen(pattern);
    lo i = 0, j = -1;
    b[0] = -1;

    while (i < m)
    {
        while (j >= 0 and pattern[i] != pattern[j])
        {
            j = b[j];
        }
        j = b[j];
        i++;
        j++;
        b[i] = j;
    }
    i = 0, j = 0;
    lo n = 0;
    stack<StringBuilder *> Stack;
    Stack.push(&S);
    StringBuilder *current;
    while (!Stack.empty())
    {
        current = Stack.top();
        Stack.pop();
        if (current->normal)
        {
            n += strlen(current->data);
        }
        else
        {
            Stack.push(current->First);
            Stack.push(current->Second);
        }
        lo k = 0;
        while (i < n)
        {
            while (j >= 0 and current->data[k] != pattern[j])
            {
                j = b[j];
            }
            i++;
            j++;
            k++;
            if (j == m)
            {
                return (i - j);
                j = b[j];
            }
        }
    }

    return -1;
}
char *StringBuilder ::to_string()
{
    char *result = "";
    make_string(*this, result);
    return result;
}
int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);
    StringBuilder s1 = StringInitialize("hello");
    //cout<<s1.to_string()<<endl;
    StringBuilder s2 = StringInitialize("world");
    auto index1 = findSubstring(s2, "or");
    cout << index1 << endl;
    // index1 will have value 1. Starting index of substring
    // index2 will have value -1. No substring found
    StringBuilder s3 = stringAppend(s1, s2);
    cout << endl;
    //cout << s3.to_string() << endl;
    StringBuilder s5 = StringInitialize("new");
    StringBuilder s4 = stringAppend(s3, s5);
    index1 = findSubstring(s4, "loworldn");
    cout << index1 << endl;
    //cout << s4.to_string();
    wait;
    return 0;
}
