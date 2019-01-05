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
#define INF 500010
#define MOD 1000000007
#define M 1000000007
#define BLOCK 300
#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))
#define pb(a) push_back((a))
#define eps 1e-2
#define PI acos(-1.0)

#if _DEBUG
#define debug(x) cout<<#x<<"="<<x<<endl
#define debug2(x,y) cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#define debug3(x,y,z) cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;
#define debug4(x,y,z,w) cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<" "<<#w<<"="<<w<<endl;
#define debug5(x,y,z,w,t) cout<<#x<<"="<<x <<" ";debug4(y,z,w,t);
#define debug6(p,x,y,z,w,t) cout<<#p<<" "<<p<<" "<<#x<<"="<<x <<" ";debug4(y,z,w,t);
#define debug7(o,p,x,y,z,w,t) cout<<#o<<" "<<o<<" ";debug6(p,x,y,z,w,t);
#define wait int xxxx;cin>>xxxx;
#define derr(x) cerr<<#x<<"="<<x<<endl;
#define derr2(x,y) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#define derr3(x,y,z) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;
#define derr4(x,y,z,w) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<" "<<#w<<"="<<w<<endl;
#define derr5(x,y,z,w,t) cerr<<#x<<"="<<x <<" ";derr4(y,z,w,t);
#define derr6(p,x,y,z,w,t) cerr<<#p<<" "<<p<<" "<<#x<<"="<<x <<" ";derr4(y,z,w,t);
#define derr7(o,p,x,y,z,w,t) cerr<<#o<<" "<<o<<" ";derr6(p,x,y,z,w,t);

#else
#define debug(x) ;
#define debug2(x,y) ;
#define debug3(x,y,z) ;
#define debug4(x,y,z,q) ;
#define debug5(x,y,z,r,t) ;
#define debug6(x,y,z,r,t,s) ;
#define debug7(x,y,z,r,t,s,u) ;
#define wait ;
#define derr(x) ;
#define derr2(x,y) ;
#define derr3(x,y,z) ;
#define derr4(x,y,z,q) ;
#define derr5(x,y,z,r,t) ;
#define derr6(x,y,z,r,t,s) ;
#define derr7(x,y,z,r,t,f,u) ;
#endif


#define print_matrix(a,n,m) REPE(0,n,0,m){cout<<(a)[i][j]<<((j==m-1)?'\n':' ');}
#define present(container, element) (container.find(element) != container.end())
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
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
int main(int argc, char*argv[]){
    std::ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);cout.precision(20);
    // // freopen("error.txt", "w", stdout);
    lo T;
    cin>>T;
    REPV(t,1,T+1){
        lo n,q;
        cin>>n>>q;
        lo x1,x2,a1,b1,c1,m1;
        lo y1,y2,a2,b2,c2,m2;
        cin>>x1>>x2>>a1>>b1>>c1>>m1;
        cin>>y1>>y2>>a2>>b2>>c2>>m2;
        // debug("herer");
        vl l,r;
        l.pb(min(x1,y1));
        if(n>1)l.pb(min(x2,y2));
        r.pb(max(x1,y1));
        if(n>1)r.pb(max(x2,y2));
        REP(2,n){
            lo x3 = (a1*x2 + b1*x1 + c1)%m1;
            lo y3 = (a2*y2 + b2*y1 + c2)%m2;
            l.pb(min(x3,y3));
            r.pb(max(x3,y3));
            x1 = x2;
            y1 = y2;
            x2 = x3;
            y2 = y3;
        }
        vl query;
        lo z1,z2,a3,b3,c3,m3;
        cin>>z1>>z2>>a3>>b3>>c3>>m3;
        query.pb(z1+1);
        query.pb(z2+1);
        REP(2,q){
            lo z3 = (a3*z2 + b3*z1 + c3)%m3;
            query.pb(z3+1);
            z1 = z2;
            z2 = z3;
        }
        // debug("hrer");
        vll enter;
        REP(0,l.size()){
            l[i]++;
            r[i]++;
        }
        TRV(l)enter.pb(mp(it,0));
        TRV(r)enter.pb(mp(it,1));
        debug(enter.size());
        time_t start,end;
time (&start);
        sort(all(enter));
time (&end);
double dif = difftime (end,start);
printf ("Elasped time is %.2lf seconds.", dif );
        vl score(enter.size());
        vl cnt(enter.size());
        score[0]=1;
        cnt[0]=1;
        vl temp(enter.size());
        temp[0] = (enter[0].X);
        lo j=1;
        vl neg(enter.size());
        debug("input done");
        REP(1,enter.size()){
            lo num = enter[i].X;
            bool in = !enter[i].Y;
            if(enter[i].X==enter[i-1].X){
                if(in){
                    score[j-1]++;
                    cnt[j-1]++;
                }
                else {
                    cnt[j-1]--;
                    neg[j-1]++;
                }
                continue;
            }
            temp[j] = (enter[i].X);
            score[j] = score[j-1]+(num-temp[j-1])*cnt[j-1];
            if(in){
                score[j]++;
                cnt[j] = cnt[j-1]+1;
            }
            else{
                cnt[j] = cnt[j-1]-1;
            }
            j++;

        }
        debug("preprocessing done");
        lo ans=0;
        REP(0,q){
            // derr("fdfs");
            lo k = query[i];
            //lo last_ind;
            // derr("fdsfsdf");
            k = score[j-1]-k+1;
            lo l = 0;
            lo r = j-1;
            lo res=0;
            // debug(k);
            // debug3(k,l,r);
            if(k<=0)continue;
            else if(k==1)res = j-1;
            else while(l<=r){
                lo mid = (l+r)/2;
                lo num_of_elems = score[mid];
                if(num_of_elems>=k and k>num_of_elems-cnt[mid]-neg[mid]){
                    res=mid;
                    break;
                }
                else if(num_of_elems<k){
                    res = max(res,mid);
                    l = mid+1;
                }
                else{
                    r=mid-1;
                }
            }
            lo answer;
            if(score[res]>=k and k>=score[res]-cnt[res]-neg[res]){
                answer = temp[res];
            }
            else{
                lo rem = k-score[res];
                answer = temp[res];
                answer+=(rem+cnt[res]-1)/cnt[res];
            }
            ans+=answer*(i+1);
        }
        cout<<"Case #"<<t<<": "<<ans<<endl;
    }
    return 0;
}
