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

#define LOWER_BOUND ld(0.35)
#define UPPER_BOUND ld(0.75)

template <typename T>
class Vector
{
  private:
    // lo vector_capacity;
    lo vector_size;
    T *vector;
    void reallocate(lo x);

  public:
    lo operator[](unsigned int i);
    lo vector_capacity;
    void push_back(T x);
    void pop_back();
    Vector();
    Vector(lo n, T x);
    Vector(lo n);
    lo size();
    lo front();
    lo back();
    void insert(lo index, T value);
    void erase(lo index);
    void clear();
};

template <typename T>
void Vector<T>::clear()
{
    delete this->vector;
}

template <typename T>
void Vector<T>::erase(lo index)
{
    for (int i = index; i < this->vector_size; i++)
    {
        this->vector[i] = this->vector[i + 1];
    }
    this->pop_back();
}

template <typename T>
void Vector<T>::insert(lo index, T value)
{
    lo x = this->back();
    for (int i = this->vector_size; i > index; i--)
    {
        this->vector[i] = this->vector[i - 1];
    }
    this->vector[index] = value;
    this->push_back(x);
}

template <typename T>
lo Vector<T>::size()
{
    return this->vector_size;
}

template <typename T>
lo Vector<T>::front()
{
    if (this->vector_size == 0)
    {
        throw "Vector is empty can't remove files";
    }
    return this->vector[0];
}

template <typename T>
lo Vector<T>::back()
{
    if (this->vector_size == 0)
    {
        throw "Vector is empty can't remove files";
    }
    return this->vector[this->vector_size - 1];
}

template <typename T>
Vector<T>::Vector()
{
    this->vector_capacity = 1;
    this->vector_size = 0;
    this->vector = new T[1];
}

template <typename T>
Vector<T>::Vector(lo n, T x)
{
    this->vector_capacity = n * (1 + UPPER_BOUND);
    this->vector = new lo[this->vector_capacity];
    if (this->vector == NULL)
    {
        this->vector_capacity = 1;
        throw "Memory allocation failed";
    }
    for (int i = 0; i < n; i++)
    {
        this->vector[i] = x;
    }
    this->vector_size = 0;
}

template <typename T>
Vector<T>::Vector(lo n)
{
    this->vector_capacity = n * (1 + UPPER_BOUND);
    this->vector = new lo[this->vector_capacity];
    if (this->vector == NULL)
    {
        this->vector_capacity = 1;
        throw "Memory allocation failed";
    }
    for (int i = 0; i < n; i++)
    {
        this->vector[i] = 0;
    }
    this->vector_size = 0;
}

template <typename T>
lo Vector<T>::operator[](unsigned int i)
{
    assert((i >= 0) and (i < this->vector_size));
    return this->vector[i];
}

template <typename T>
void Vector<T>::push_back(T x)
{
    if (this->vector_size >= UPPER_BOUND * this->vector_capacity)
    {
        this->reallocate(this->vector_capacity * 2);
    }
    this->vector[vector_size] = x;
    this->vector_size++;
}

template <typename T>
void Vector<T>::pop_back()
{
    assert(this->vector_size > 0);
    if (this->vector_size <= LOWER_BOUND * this->vector_capacity)
    {
        this->reallocate(max(this->vector_capacity / 2, 1LL));
    }
    this->vector_size--;
}

template <typename T>
void Vector<T>::reallocate(lo n)
{
    lo *new_vector = new lo[n];
    if (new_vector == NULL)
    {
        throw "Memory allocation failed";
    }
    for (int i = 0; i < this->vector_size; i++)
    {
        new_vector[i] = this->vector[i];
    }
    delete this->vector;
    this->vector = new_vector;
    this->vector_capacity = n;
}

namespace math
{
vector<bool> prime;
vl primes = {2};
lo curr_n = 2;
void sieve(lo n)
{
    n = n * 1.7;
    prime.resize(n, true);
    derr2(primes, prime);
    TRV(primes)
    {
        lo start = curr_n + (it - curr_n % it) % it;
        for (lo i = start; i <= n; i += it)
            prime[i] = false;
    }
    REP(curr_n, n)
    if (prime[i])
    {
        primes.pb(i);
        for (lo j = 2 * i; j <= n; j += i)
            prime[j] = false;
    }
    //derr(prime);
    //derr(primes);
}
lo power(lo a, lo n, lo m)
{
    lo res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        n <<= 1;
    }
    return res;
}
lo next_prime(lo no)
{
    if (primes.back() < no)
    {
        sieve(no);
    }
    return *upper_bound(all(primes), no);
}
} // namespace math
template <typename T, typename U>
struct Entry
{
    T key;
    U value;
    Entry(T k, U v) : key(k), value(v) {}
};
template <typename T, typename U>
struct Bucket
{
    vector<Entry<T, U>> list;
    lo inside_modulo;
    Bucket()
    {
        this->inside_modulo = 2;
    }
};
template <typename T, typename U>
struct Unordered_map
{
    lo size;
    lo modulo;
    vector<Bucket<T, U>> buckets;
    lo Hash(string str);
    void Rehash();

  public:
    Unordered_map()
    {
        this->modulo = math::next_prime(5);
        this->size = 0;
        buckets.resize(modulo);
    }
    Unordered_map(lo x)
    {
        this->size = 0;
        this->modulo = math::next_prime(lo((ld(10.5) / ld(7)) * x));
        buckets.resize(modulo);
    }
    void Insert(T key, U value);
    U Search(T);
    void Erase(T);
};
template <typename T, typename U>
lo Unordered_map<T, U>::Hash(string str)
{
    lo res = 0;
    REP(0, str.length())
    {
        res = (res + str[i] * math::power(257, i, this->modulo)) % this->modulo;
    }
    return res;
}
template <typename T, typename U>
void Unordered_map<T, U>::Insert(T key, U value)
{
    stringstream ss;
    ss << key;
    string str = ss.str();
    lo hashed_index = Hash(str);
    this->buckets[hashed_index].list.push_back(Entry<T, U>({key, value}));
    this->size++;
    if (this->size > this->modulo * UPPER_BOUND)
    {
        Rehash();
    }
    return;
}

template <typename T, typename U>
U Unordered_map<T, U>::Search(T search_key)
{
    stringstream ss;
    ss << search_key;
    string str = ss.str();
    lo hashed_index = Hash(str);
    TRV(buckets[hashed_index].list)
    {
        if (it.key == search_key)
        {
            return it.value;
        }
    }
    return NULL;
}

template <typename T, typename U>
void Unordered_map<T, U>::Erase(T del_key)
{
    string del_value = Search(del_key);
    if (del_value == NULL)
    {
        cout << "NO found";
        return;
    }
    stringstream ss;
    ss << del_key;
    string str = ss.str();
    lo hashed_index = Hash(str);
    debug(hashed_index);
    auto to_delete = buckets[hashed_index].list.begin();
    while (to_delete != buckets[hashed_index].list.end())
    {
        debug2(to_delete->key, to_delete->value);
        if (to_delete->key == del_key and to_delete->value == del_value)
        {
            break;
        }
        to_delete++;
    }
    buckets[hashed_index].list.erase(to_delete);
}

template <typename T, typename U>
void Unordered_map<T, U>::Rehash()
{
    vector<Entry<T, U>> all_entries;
    TRV(this->buckets)
    {
        for (auto entry : it.list)
            all_entries.push_back(Entry<T, U>(entry));
    }
    this->buckets.clear();
    this->modulo = math::next_prime(this->modulo * 2 + 1);
    buckets.resize(this->modulo);
    this->size = 0;
    TRV(all_entries)
    {
        Insert(it.key, it.value);
    }
}
int main(int argc, char *argv[])
{
    //std::ios::sync_with_stdio(false);
    //cin.tie(0);cout.tie(0);cout.precision(20);
    Unordered_map<int, string> hash_table;
    while (1)
    {
        lo choice;
        // cin>>choice;
        cout << "Enter 1 for Insertion" << endl;
        cout << "Enter 2 for Deletion" << endl;
        cout << "Enter 3 for Searching" << endl;
        cin >> choice;
        ;
        if (choice == 1)
        {
            cout << "Enter a number: ";
            int x;
            string y;
            cin >> x >> y;
            hash_table.Insert(x, y);
        }
        else if (choice == 2)
        {
            cout << "Enter a number ";
            int x;
            cin >> x;
            hash_table.Erase(x);
        }
        else if (choice == 3)
        {
            cout << "Enter element to be Searched: ";
            int x;
            cin >> x;
            auto key = hash_table.Search(x);
            cout << key << endl;
            // }
            // else cout<<"Element Not Found"<<endl;
        }
        cout << hash_table.modulo << endl;
    }
    return 0;
}
