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
	for (lo j = (c); j < (lo)d; j++)					//no need to declare vaiables i,j
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
lo n;
bool check1fun(ll t)
{
	lo x = t.X;
	lo y = t.Y;
	if ((x == 0 or x == n) and (y == 0 or y == n))
		return true;
	return false;
}
bool check2fun(ll x, ll y)
{
	if (check1fun(x) or check1fun(y))
		return true;
	lo x1 = x.first;
	lo y1 = x.second;
	lo x2 = y.first;
	lo y2 = y.second;
	if ((x1 == n or x1 == 0) and (x2 == n or x2 == 0))
		return true;
	if ((y1 == n or y1 == 0) and (y2 == n or y2 == 0))
		return true;
	swap(x1,y1);
	swap(x2,y2);
	if ((x1 == n or x1 == 0) and (x2 == n or x2 == 0))
		return true;
	if ((y1 == n or y1 == 0) and (y2 == n or y2 == 0))
		return true;
	return false;
}
bool check3fun(ll x, ll y, ll z){
	lo x1 = x.first;
	lo y1 = x.second;
	lo x2 = y.first;
	lo y2 = y.second;
	lo x3 = z.first;
	lo y3 = z.second;
	if(x1 == 0 or x1 == n){
		if(y1<=y2 and y1<=y3)return true;
		if(y1>=y2 and y1>=y3)return true;
	}
	if((x1==0 or x1==n or y1==0 or y1 ==n) and (x2==0 or x2==n or y2==0 and y2==n))return true;
	// if(x1 == 0 and y2 == 0){
	// 	if(x3>=x2 or y3>=y1)return true;
	// }
	// if(x1 == 0 and y2 == n){
	// 	if(y3<=y1 or x3>=x2)return true;
	// }
	// if(x1 == n and y2 == 0){
	// 	if(y3>=y1 or x3<=x2)return true;
	// }
	// if(x1 == n and y2 == n){
	// 	if(y3<=y1 or x3<=x2)return true;
	// }
	swap(x1,y1);
	swap(x2,y2);
	swap(x3,y3);
	if(x1 == 0 or x1 == n){
		if(y1<=y2 and y1<=y3)return true;
		if(y1>=y2 and y1>=y3)return true;
	}
	// if(x1 == 0 and y2 == 0){
	// 	if(x3>=x2 or y3>=y1)return true;
	// }
	// if(x1 == 0 and y2 == n){
	// 	if(y3<=y1 or x3>=x2)return true;
	// }
	// if(x1 == n and y2 == 0){
	// 	if(y3>=y1 or x3<=x2)return true;
	// }
	// if(x1 == n and y2 == n){
	// 	if(y3<=y1 or x3<=x2)return true;
	// }
	return false;
}
int main(int argc, char *argv[])
{
	// std::ios::sync_with_stdio(false);
	// cin.tie(0);
	// cout.tie(0);
	// cout.precision(20);
	lo t;
	cin >> t;
	while (t--)
	{
		lo k;
		cin >> k >> n;
		n--;
		vll a(k);
		cin >> a;
		if (k >= 4)
		{
			cout << "yes" << endl;
			continue;
		}
		else if (k == 3)
		{
			bool ans = false;
			ans |= check2fun(a[0], a[1]);
			ans |= check2fun(a[1], a[2]);
			ans |= check2fun(a[2], a[0]);
			// debug(ans);
			ans |= check3fun(a[0],a[1],a[2]);
			// debug(ans);
			ans |= check3fun(a[0],a[2],a[1]);
			// debug(ans);
			ans |= check3fun(a[1],a[0],a[2]);
			// debug(ans);
			ans |= check3fun(a[1],a[2],a[0]);
			// debug(ans);
			ans |= check3fun(a[2],a[0],a[1]);
			// debug(ans);
			ans |= check3fun(a[2],a[1],a[0]);
			// debug(ans);
			if(ans)cout<<"yes"<<endl;
			else cout<<"no"<<endl;
		}
		else if(k==2){
			if(check2fun(a[0],a[1]))cout<<"yes"<<endl;
			else cout<<"no"<<endl;
		}
		else{
			if(check1fun(a[0]))cout<<"yes"<<endl;
			else cout<<"no"<<endl;
		}
	}
	return 0;
}
