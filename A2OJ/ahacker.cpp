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
#define CHECK_BIT(var, pos) ((var) & (1 << (pos)))
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
enum COLOR
{
    BLACK = 1,
    RED = 0
};
struct Node
{
    lo data;
    bool leaf;
    lo black_height;
    COLOR color;
    Node *par;
    Node *left;
    Node *right;
    Node(lo);
};
Node ::Node(lo d)
{
    this->data = d;
    this->leaf = true;
    this->color = RED;
    this->black_height = 1;
    this->par = this->left = this->right = NULL;
}
struct red_black_tree
{
    Node *root;
    Node *LEAF;
    Node *parent(Node *);
    Node *grandparent(Node *);
    Node *sibling(Node *);
    Node *uncle(Node *);
    void rotate_left(Node *);
    void rotate_right(Node *);
    Node *insert(Node *, Node *);
    void insert_recurse(Node *, Node *);
    void insert_repair_tree(Node *);
    void insert_case1(Node *);
    void insert_case2(Node *);
    void insert_case3(Node *);
    void insert_case4(Node *);
    void Insert(lo n);
    red_black_tree();
    void replace_node(Node *node, Node *child);
    void delete_one_child(Node *node);
    void delete_case1(Node *node);
    void delete_case2(Node *node);
    void delete_case3(Node *node);
    void delete_case4(Node *node);
    void delete_case5(Node *node);
    void delete_case6(Node *node);
    lo extract_min();
    lo min_elem(Node *node);
    lo predecessor(Node *node);
    void erase(Node *node, lo n);
    void Erase(lo n);
    void traverse(Node *node);
    bool empty();
    lo max_elem(Node *node);
    lo successor(Node* node);
};

bool red_black_tree ::empty()
{
    return this->root == NULL or this->root == this->LEAF;
}
lo red_black_tree ::predecessor(Node *node)
{
    return this->min_elem(node->right);
}
lo red_black_tree ::successor(Node* node){
    return this->max_elem(node->left);
}
void red_black_tree ::Erase(lo x)
{
    this->erase(this->root, x);
}
void red_black_tree ::erase(Node *node, lo n)
{
    if (node->left == this->LEAF and node->right == this->LEAF)
    {
        this->delete_one_child(node);
    }
    else if (node->data == n and node->right!=this->LEAF)
    {
        node->data = predecessor(node);
        erase(node->right, node->data);
    }
    else if(node->data == n){
        node->data = this->successor(node);
        erase(node->left, node->data);
    }
    else if (node->data > n)
    {
        erase(node->left, n);
    }
    else if (node->data < n)
    {
        erase(node->right, n);
    }
    // return node;
}
lo red_black_tree ::min_elem(Node *node)
{
    if (node == NULL)
        return -1;
    if (node->left == this->LEAF)
        return node->data;
    return min_elem(node->left);
}
lo red_black_tree ::max_elem(Node *node)
{
    if (node == NULL)
        return -1;
    if (node->right == this->LEAF)
        return node->data;
    return max_elem(node->right);
}

lo red_black_tree ::extract_min()
{
    lo x = min_elem(this->root);
    this->Erase(x);
    return x;
}
void red_black_tree ::replace_node(Node *node, Node *child)
{
    child->par = node->par;
    if (node == node->par->left)
    {
        node->par->left = child;
    }
    else
    {
        node->par->right = child;
    }
}
void red_black_tree ::delete_one_child(Node *node)
{
    debug(node);
    if(node == this->root){
        delete node;
        this->root = NULL;
        return;
    }
    Node *child;
    if (node->right == this->LEAF)
        child = node->left;
    else
        child = node->right;
    this->replace_node(node, child);
    if (node->color == BLACK)
    {
        if (child->color == RED)
        {
            child->color = BLACK;
        }
        else{
            debug("in delete one child");
            this->traverse(this->root);
            this->delete_case1(child);
        }
    }
    delete node;
    // return child;
}
void red_black_tree ::delete_case1(Node *node)
{
    debug4("In delete 1", node->data, node->par->data, (node->par == this->LEAF));
    if (node->par != NULL and node!=this->root)
    {
        debug3(node->par->data,  node->left->data , node->right->data);
        this->delete_case2(node);
    }
}
void red_black_tree ::delete_case2(Node *node)
{
    debug(node->data);
    auto sibling = this->sibling(node);
    if (sibling->color == RED)
    {
        node->par->color = RED;
        sibling->color = BLACK;
        if (node == node->par->left)
        {
            rotate_left(node->par);
        }
        else
        {
            rotate_right(node->par);
        }
    }
    debug("in delete case 2");
    this->traverse(this->root);
    delete_case3(node);
}
void red_black_tree ::delete_case3(Node *node)
{
    auto sibling = this->sibling(node);
    debug4(node->data,node->color,sibling->data, sibling->color);
    if (node->par->color == BLACK and sibling->color == BLACK and sibling->left->color == BLACK and sibling->right->color == BLACK)
    {
        debug("case 3 sibling coloring 3");
        sibling->color = RED;
        this->traverse(this->root);
        this->delete_case1(node->par);
    }
    else
    {
        this->delete_case4(node);
    }
}
void red_black_tree ::delete_case4(Node *node)
{
    auto sibling = this->sibling(node);
    if (node->par->color == RED and sibling->color == BLACK and sibling->left->color == BLACK and sibling->right->color == BLACK)
    {
        sibling->color = RED;
        node->par->color = BLACK;
        // this->delete_case1(node->par);
    }
    else
    {
        this->delete_case5(node);
    }
}
void red_black_tree ::delete_case5(Node *node)
{
    if(node->par == this->LEAF){
        return;
    }
    auto sibling = this->sibling(node);
    if (sibling->color == BLACK)
    {
        if (node == node->par->left and sibling->right->color == BLACK and sibling->left->color == RED)
        {
            sibling->color = RED;
            sibling->left->color = BLACK;
            this->rotate_right(sibling);
        }
        else if (node == node->par->right and sibling->left->color == BLACK and sibling->right->color == RED)
        {
            sibling->color = RED;
            sibling->right->color = BLACK;
            this->rotate_left(sibling);
        }
    }
    this->delete_case6(node);
}
void red_black_tree ::delete_case6(Node *node)
{
    auto sibling = this->sibling(node);
    sibling->color = node->par->color;
    node->par->color = BLACK;
    if (node == node->par->left)
    {
        sibling->right->color = BLACK;
        rotate_left(node->par);
    }
    else
    {
        sibling->left->color = BLACK;
        rotate_right(node->par);
    }
}
red_black_tree ::red_black_tree()
{
    this->LEAF = new Node(-1);
    this->root = NULL;
    this->LEAF->color = BLACK;
    this->LEAF->par = this->LEAF->left = this->LEAF->right = this->LEAF;
}
Node *red_black_tree ::parent(Node *node)
{
    return node->par;
}
Node *red_black_tree ::grandparent(Node *node)
{
    return this->parent(node->par);
}
Node *red_black_tree ::sibling(Node *node)
{
    // debug("I am in sibling");
    // debug2(node->data, node->color);
    // debug2(node->par->data, node->par->color);
    if (node->par == this->LEAF)
    {
        return this->LEAF;
    }
    // debug("also");
    if (node == this->parent(node)->left)
    {
        // debug("here");
        return this->parent(node)->right;
    }
    return this->parent(node)->left;
}
Node *red_black_tree ::uncle(Node *node)
{
    auto grand_par = this->grandparent(node);
    debug3("fdfsdfsdfdsfdsfsdf", grand_par->data, grand_par->color);
    if (grand_par == this->LEAF)
    {
        return this->LEAF;
    }
    auto parent = this->parent(node);
    debug2(node->data, node->color);
    auto sibling = this->sibling(parent);
    // debug2(sibling->data, sibling->color);
    return sibling;
}
void red_black_tree ::rotate_left(Node *node)
{
    assert(node != NULL);
    auto new_node = node->right;
    auto p = this->parent(node);
    assert(new_node != this->LEAF);
    node->right = new_node->left;
    new_node->left = node;
    node->par = new_node;
    if (node->right != this->LEAF)
    {
        node->right->par = node;
    }
    if (p != this->LEAF)
    {
        if (node == p->left)
        {
            p->left = new_node;
        }
        else if (node == p->right)
        {
            p->right = new_node;
        }
        new_node->par = p;
    }
    else
    {
        this->root = new_node;
        new_node->par = p;
    }
}
void red_black_tree ::rotate_right(Node *node)
{
    assert(node != this->LEAF);
    auto new_node = node->left;
    auto p = parent(node);
    assert(new_node != this->LEAF);
    node->left = new_node->right;
    new_node->right = node;
    node->par = new_node;
    if (node->left != this->LEAF)
    {
        node->left->par = node;
    }
    if (p != this->LEAF)
    {
        if (node == p->left)
        {
            p->left = new_node;
        }
        else if (node == p->right)
        {
            p->right = new_node;
        }
        new_node->par = p;
    }
    else
    {
        this->root = new_node;
        new_node->par = p;
    }
}
Node *red_black_tree ::insert(Node *root, Node *node)
{
    insert_recurse(root, node);
    insert_repair_tree(node);
    root = node;
    while (parent(root) != this->LEAF)
    {
        root = parent(root);
    }
    return root;
}
void red_black_tree ::insert_recurse(Node *root, Node *node)
{
    if (root != NULL and node->data < root->data)
    {
        if (root->left != this->LEAF)
        {
            insert_recurse(root->left, node);
            return;
        }
        else
            root->left = node;
    }
    else if (root != NULL)
    {
        if (root->right != this->LEAF)
        {
            insert_recurse(root->right, node);
            return;
        }
        else
            root->right = node;
    }
    node->par = root;
    if (!node->par)
        node->par = this->LEAF;
    node->leaf = true;
    node->color = RED;
    node->left = node->right = this->LEAF;
}
void red_black_tree ::insert_repair_tree(Node *node)
{
    // this->traverse(this->root);
    if (parent(node) == this->LEAF)
    {
        debug(1);
        insert_case1(node);
    }
    else if (parent(node)->color == BLACK)
    {
        debug(2);
        insert_case2(node);
    }
    else if (uncle(node)->color == RED)
    {
        debug(3);
        insert_case3(node);
    }
    else
    {
        debug(4);
        insert_case4(node);
    }
}
void red_black_tree ::insert_case1(Node *node)
{
    assert(parent(node) == this->LEAF);
    node->color = BLACK;
    return;
}
void red_black_tree ::insert_case2(Node *node)
{
    return;
}
void red_black_tree ::insert_case3(Node *node)
{
    parent(node)->color = BLACK;
    uncle(node)->color = BLACK;
    grandparent(node)->color = RED;
    insert_repair_tree(grandparent(node));
}
void red_black_tree ::insert_case4(Node *node)
{
    auto p = this->parent(node);
    auto g = this->grandparent(node);
    if (node == g->left->right)
    {
        rotate_left(p);
        node = node->left;
    }
    else if (node == g->right->left)
    {
        rotate_right(p);
        node = node->right;
    }
    p = this->parent(node);
    g = this->grandparent(node);
    if (node == p->left)
    {
        rotate_right(g);
    }
    else
    {
        rotate_left(g);
    }
    p->color = BLACK;
    g->color = RED;
}
void red_black_tree ::Insert(lo n)
{
    auto node = new Node(n);
    node->left = node->right = node->par = this->LEAF;
    this->root = this->insert(this->root, node);
}
void red_black_tree ::traverse(Node *node)
{
    // return;
    if (!node)
        return;
    debug5(node->data, node->color, node->left->data, node->right->data, node->par->data);
    cout<<"data = "<<node->data<<"\tleft = "<<node->left->data<<"\tright = "<<node->right->data;
    cout<<"\tcolor = "<<node->color<<endl;
    if (node->left != this->LEAF)
    {
        traverse(node->left);
    }
    if (node->right != this->LEAF)
    {
        traverse(node->right);
    }
}
vl pset; // 1000 is just an initial number, it is user-adjustable.
void init_set(lo _size)
{
    pset.resize(_size);
    REP(0, _size - 1)
    pset[i] = i;
}
lo find_set(lo i) { debug(i);return (pset[i] == i) ? i : (pset[i] = find_set(pset[i])); }
void union_set(lo i, lo j) { pset[find_set(i)] = find_set(j); }
bool is_sameSet(lo i, lo j) { return find_set(i) == find_set(j); }
lo const N = 262144;
// Node *root = new Node(lo(N * N));
int main(int argc, char *argv[])
{
    // std::ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    // cout.precision(20);

    // while(1){
    //     cout<<"Enter 1 for insertion"<<endl;
    //     cout<<"Enter 2 for deletion"<<endl;
    //     lo c;
    //     cin>>c;
    //     if(c==1){
    //         cout<<"Enter Element to be inserted: ";
    //         lo x;
    //         cin>>x;
    //         if(root == NULL)root = new Node(256);
    //         root = vEB_tree_insert(root, x, 1);
    //     }
    //     else if(c==2){
    //         cout<<"Enter Element to be deleted: ";
    //         lo x;
    //         cin>>x;
    //         root = vEB_tree_delete(root, x, 1);
    //     }
    //     lo x;
    //     REP(0,16)if((x=vEB_tree_member(root, i)) != -1 )debug2(i,x);
    //     debug2(vEB_tree_max(root), vEB_tree_min(root));
    //     debug2(vEB_tree_max_cnt(root), vEB_tree_min_cnt(root));
    // }

    red_black_tree tree;
    // REP(1,11)tree.Insert(i);
    // while(true){

    //     cout<<"Enter 1 for Insertion ";
    //     cout<<"Enter 2 for deletion "<<endl;
    //     lo choice;
    //     cin>>choice;
    //     if(choice == 1){
    //         lo x;
    //         cin>>x;
    //         tree.Insert(x);
    //     }
    //     else{
    //         lo x;
    //         cin>>x;
    //         tree.Erase(x);
    //     }
    //     debug("##################################");
    //     tree.traverse(tree.root);
    // }
    vector<vll> a(N);
    lo n, m;
    cin >> n >> m;
    init_set(n + 10);
    debug(pset.size());
    REP(0, m)
    {
        lo x, y, z;
        cin >> x >> y >> z;
        a[z].pb(mp(x, y));
        debug(i);
        tree.Insert(z);
        // tree.traverse(tree.root);
    }
    //derr("I am here");
    debug("I am here here");
    lo ans = 0;
    while (!tree.empty())
    {
        lo x = tree.extract_min();
        auto t = a[x].back();
        a[x].pop_back();
        derr(t);
        // cout<<x<< " "<<t<<endl;
        if (!is_sameSet(t.X, t.Y))
        {
            // cout<<"!same"<<endl;
            ans += x;
            union_set(t.X, t.Y);
            debug(x);
        }
        // tree.traverse(tree.root);
    }
    // assert(root == NULL);
    cout << ans;
    return 0;
}
