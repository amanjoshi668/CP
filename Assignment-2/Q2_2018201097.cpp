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
struct Node
{
    lo base, number_of_entries;
    bool leaf;
    vl array;
    vector<Node *> link;
    Node();
    Node(lo t);
};
Node ::Node()
{
    this->number_of_entries = 0;
    this->base = 1;
    this->leaf = true;
    this->array.resize(2 * base - 1);
    this->link.resize(2 * base);
    fill(all(this->array), 0LL);
    //fill(all(this->link),NULL);
}
Node ::Node(lo t)
{
    this->number_of_entries = 0;
    this->base = t;
    this->leaf = true;
    this->array.resize(2 * t - 1);
    this->link.resize(2 * t);
    fill(all(this->array), 0LL);
    //fill(all(this->link),NULL);
}
struct Btree
{
    lo base;
    Node *root;
    Btree(lo base);
    bool search(Node *, lo k);
    void split_child(Node *, lo);
    void insert_non_full(Node *, lo k);
};
Btree ::Btree(lo t)
{
    this->base = t;
    this->root = new Node(t);
}
bool Btree ::search(Node *root, lo k)
{
    if (root == NULL)
        return false;
    if (binary_search(root->array.begin(), root->array.begin() + root->number_of_entries, k))
    {
        return true;
    }
    if (k < root->array[0])
        return search(root->link[0], k);
    auto it = upper_bound(root->array.begin(), root->array.begin() + root->number_of_entries, k);
    return search(root->link[it - root->array.begin()], k);
}
void Btree ::split_child(Node *x, lo index)
{
    auto z = new Node(this->base);
    auto y = x->link[index];
    //debug(y->number_of_entries);
    z->leaf = y->leaf;
    z->number_of_entries = y->number_of_entries = this->base - 1;
    REP(0, this->base - 1)
    {
        z->array[i] = y->array[i + this->base];
        z->link[i] = y->link[i + this->base];
    }
    z->link[this->base - 1] = y->link.back();
    IREP(x->number_of_entries - 1, index)
    {
        x->link[i + 1] = x->link[i];
    }
    x->link[index + 1] = z;
    IREP(x->number_of_entries - 1, index - 1)
    x->array[i + 1] = x->array[i];
    x->array[index] = y->array[this->base - 1];
    x->number_of_entries++;
}
void Insert(Btree &tree, lo k)
{
    auto old_root = tree.root;
    if (old_root->number_of_entries == 2 * tree.base - 1)
    {
        auto s = new Node(tree.base);
        tree.root = s;
        s->leaf = false;
        s->number_of_entries = 0;
        s->link[0] = old_root;
        tree.split_child(s, 0);
        tree.insert_non_full(s, k);
    }
    else
    {
        tree.insert_non_full(old_root, k);
    }
}
void Btree ::insert_non_full(Node *x, lo k)
{
    lo i = x->number_of_entries - 1;
    if (x->leaf)
    {
        while (i >= 0 and k < x->array[i])
        {
            x->array[i + 1] = x->array[i];
            i--;
        }
        x->array[i + 1] = k;
        x->number_of_entries++;
    }
    else
    {
        while (i >= 0 and k < x->array[i])
        {
            i--;
        }
        i++;
        auto y = x->link[i];
        if (y->number_of_entries == 2 * base - 1)
        {
            split_child(x, i);
            if (k > x->array[i])
                i++;
        }
        insert_non_full(x->link[i], k);
    }
}
void print_tree(Node *node)
{
    if (node == NULL)
        return;
    cerr << "Node"
         << " " << node->number_of_entries << endl;
    REP(0, node->number_of_entries)
        cerr << node->array[i] << " ";
    cerr << endl;
    REP(0, node->number_of_entries + 1)
    print_tree(node->link[i]);
}

lo successor(Node *node)
{
    if (node->leaf)
    {
        return node->array[0];
    }
    return successor(node->link[0]);
}

lo predecessor(Node *node)
{
    if (node->leaf)
    {
        return node->array[node->number_of_entries - 1];
    }
    return predecessor(node->link[node->number_of_entries]);
}

void Delete(Btree &tree, Node *node, lo k)
{
    //cerr<<"In Deleete"<<endl;
    //print_tree(node);
    if (node->leaf)
    {
        // debug("leaf");
        REP(0, node->number_of_entries)
        {
            if (node->array[i] == k)
            {
                node->array.erase(node->array.begin() + i);
                node->array.pb(0);
                node->number_of_entries--;
                //return;
            }
        }
        // derr(node->array);
        // print_tree(tree.root);
        return;
    }
    lo i = 0;
    while (node->array[i] < k and i < node->number_of_entries)
    {
        i++;
    }
    // derr3(i, node->array[i], k);
    if (i != node->number_of_entries and node->array[i] == k)
    {
        // debug("h0");
        if (node->link[i]->number_of_entries >= node->base)
        {
            //debug(1);
            auto k_new = predecessor(node->link[i]);
            node->array[i] = k_new;
            Delete(tree, node->link[i], k_new);
            return;
        }
        // debug("h1");
        if (i < node->base and node->link[i + 1]->number_of_entries >= node->base)
        {
            //debug(2);
            auto k_new = successor(node->link[i]);
            node->array[i] = k_new;
            Delete(tree, node->link[i + 1], k_new);
            return;
        }
        // debug("h2");
        // derr(i);
        auto y = node->link[i];
        auto z = node->link[i + 1];
        auto m = y->number_of_entries;
        auto p = z->number_of_entries;
        y->array[m] = k;
        for (lo j = 0; j < p; j++)
        {
            y->array[m + j + 1] = z->array[j];
        }
        for (lo j = 0; j <= p; j++)
        {
            y->link[m + j + 1] = z->link[j];
        }
        y->number_of_entries = m + p + 1;
        for (lo j = i; j < node->number_of_entries - 1; j++)
        {
            node->array[j] = node->array[j + 1];
        }
        for (lo j = i; j < node->number_of_entries; j++)
        {
            node->link[j] = node->link[j + 1];
        }
        node->number_of_entries = node->number_of_entries - 1;
        delete z;
        if (node->number_of_entries == 0)
        {
            delete node;
            tree.root = y;
        }
        // print_tree(y);
        //cerr<<"djfjkdfljsdjfjldsjlfkdsjlfjkldsjfsdjkfjklsdf"<<endl;
        // print_tree(tree.root);
        //cerr<<"I am here"<<endl;
        Delete(tree, y, k);
        return;
    }
    else
    {
        //derr(i);
        if (node->link[i]->number_of_entries >= node->base)
        {
            //debug("in else");
            Delete(tree, node->link[i], k);
            return;
        }
        else if (i == node->number_of_entries)
        {
            if (node->link[i - 1]->number_of_entries >= node->base)
            {
                // node->link[i]->array[node->base - 1] = node->array[i-1];
                IREPV(j, node->link[i]->number_of_entries - 1, 0)
                {
                    node->link[i]->array[j + 1] = node->link[i]->array[j];
                }
                IREPV(j, node->link[i]->number_of_entries, 0)
                {
                    node->link[i]->link[j + 1] = node->link[i]->link[j];
                }
                node->link[i]->array[0] = node->array[i - 1];
                node->link[i]->link[0] = node->link[i - 1]->link[node->link[i - 1]->number_of_entries];
                node->link[i]->number_of_entries++;
                node->array[i - 1] = node->link[i - 1]->array[node->link[i - 1]->number_of_entries - 1];
                //node->link[i]->link[node->base] = node->link[i-1]->link[node->link[i-1]->number_of_entries-1];
                //node->link[i]->number_of_entries = node->base;
                node->link[i - 1]->number_of_entries--;
                Delete(tree, node->link[i], k);
            }
            else
            {
                auto y = node->link[i - 1];
                auto z = node->link[i];
                auto m = y->number_of_entries;
                auto p = z->number_of_entries;
                y->array[m] = node->array[i - 1];
                for (lo j = 0; j < p; j++)
                {
                    y->array[m + j + 1] = z->array[j];
                }
                for (lo j = 0; j <= p; j++)
                {
                    y->link[m + j + 1] = z->link[j];
                }
                y->number_of_entries = m + p + 1;
                for (lo j = i - 1; j < node->number_of_entries - 1; j++)
                {
                    node->array[j] = node->array[j + 1];
                    node->link[j] = node->link[j + 1];
                }
                node->number_of_entries = node->number_of_entries - 1;
                node->link[node->number_of_entries] = node->link[node->number_of_entries - 1];
                delete z;
                if (node->number_of_entries == 0)
                {
                    delete node;
                    tree.root = y;
                }
                Delete(tree, y, k);
                return;
            }
        }
        else if (i < node->number_of_entries and node->link[i + 1]->number_of_entries >= node->base)
        {
            //debug("hh");
            node->link[i]->array[node->base - 1] = node->array[i];
            node->link[i]->number_of_entries++;
            node->array[i] = node->link[i + 1]->array[0];
            node->link[i]->link[node->base] = node->link[i + 1]->link[0];
            REPV(j, 0, node->link[i + 1]->number_of_entries)
            {
                node->link[i + 1]->array[j] = node->link[i + 1]->array[j + 1];
                node->link[i + 1]->link[j] = node->link[i + 1]->link[j + 1];
            }
            node->link[i + 1]->number_of_entries--;
            node->link[i + 1]->link[node->link[i + 1]->number_of_entries] = node->link[i + 1]->link[node->link[i + 1]->number_of_entries + 1];
            Delete(tree, node->link[i], k);
        }
        else
        {
            //derr("Merging");
            auto y = node->link[i];
            auto z = node->link[i + 1];
            auto m = y->number_of_entries;
            auto p = z->number_of_entries;
            y->array[m] = node->array[i];
            for (lo j = 0; j < p; j++)
            {
                y->array[m + j + 1] = z->array[j];
            }
            for (lo j = 0; j <= p; j++)
            {
                y->link[m + j + 1] = z->link[j];
            }
            y->number_of_entries = m + p + 1;
            for (lo j = i; j < node->number_of_entries - 1; j++)
            {
                node->array[j] = node->array[j + 1];
                node->link[j] = node->link[j + 1];
            }
            node->number_of_entries = node->number_of_entries - 1;
            node->link[node->number_of_entries] = node->link[node->number_of_entries - 1];
            delete z;
            if (node->number_of_entries == 0)
            {
                delete node;
                tree.root = y;
            }
            Delete(tree, y, k);
            return;
        }
    }
}

int main(int argc, char *argv[])
{
    //std::ios::sync_with_stdio(false);
    //cin.tie(0);cout.tie(0);cout.precision(20);
    //freopen("error.txt","w",stderr);
    lo base;
    cin >> base;
    Btree tree(base);
    while (1)
    {
        cout << "Enter 1 for Insertion" << endl;
        cout << "Enter 2 for Searching" << endl;
        cout << "Enter 3 for Deletion" << endl;
        lo x;
        cin >> x;
        if (x == 1)
        {
            cout << "Enter element to be inserted: ";
            cin >> x;
            Insert(tree, x);
        }
        else if (x == 2)
        {
            cout << "Enter element to be searched: ";
            cin >> x;
            cout << tree.search(tree.root, x) << endl;
        }
        else
        {
            cout << "Enter element to be deleted:";
            cin >> x;
            Delete(tree, tree.root, x);
        }
        //cerr<<"HHHJHFHJDHFJDHFJDHFDJHFJDHFJD"<<endl;
        ///cout<<tree.root->array<<endl;
        print_tree(tree.root);
        cout << endl;
        cerr << endl;
    }
    return 0;
}