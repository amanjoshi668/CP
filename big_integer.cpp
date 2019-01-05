#define INF 1000
#include <bits/stdc++.h>
#define debug(x) cout<<#x<<"="<<x<<endl
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define debug2(x,y) cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#define debug3(x,y,z) cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;
#define debug4(x,y,z,w) cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<" "<<#w<<"="<<w<<endl;
#define debug5(x,y,z,w,t) cout<<#x<<"="<<x <<" ";debug4(y,z,w,t);
#define debug6(p,x,y,z,w,t) cout<<#p<<" "<<p<<" "<<#x<<"="<<x <<" ";debug4(y,z,w,t);
#define debug7(o,p,x,y,z,w,t) cout<<#o<<" "<<o<<" ";debug6(p,x,y,z,w,t);
#define print_matrix(a,n,m) REPE(0,n,0,m){cout<<(a)[i][j]<<((j==m-1)?'\n':' ');}
#define endl "\n"
#define wait int x;cin>>x;
#define derr(x) cerr<<#x<<"="<<x<<endl;
#define derr2(x,y) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#define derr3(x,y,z) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;
#define derr4(x,y,z,w) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<" "<<#w<<"="<<w<<endl;
#define derr5(x,y,z,w,t) cerr<<#x<<"="<<x <<" ";derr4(y,z,w,t);
#define derr6(p,x,y,z,w,t) cerr<<#p<<" "<<p<<" "<<#x<<"="<<x <<" ";derr4(y,z,w,t);
#define derr7(o,p,x,y,z,w,t) cerr<<#o<<" "<<o<<" ";derr6(p,x,y,z,w,t);
#define present(container, element) (container.find(element) != container.end())
using namespace std;
typedef long long lo;
struct bigint {
    string a;
    int len;
    bool neg;
    bigint();
    bigint(string );
    bigint(int);
    bigint(long long);
    bigint(long);
    bigint add (bigint &a, bigint &b);
    bigint subtract(bigint &a, bigint &b);
    bigint multiply(bigint a, bigint b);
    bigint scale(bigint a, int n);
    bigint divide(bigint a, bigint b, bigint &rem);
    bool operator<(bigint &a);
    ostream& operator<< ( ostream &o) ;
};

bigint bigint :: divide(bigint a, bigint b, bigint &rem){
    bigint res(0);
    bool res_neg = a.neg ^ b.neg;
    a.neg = b.neg = false;
    int diff = max(0, int(a.a.length() - b.a.length() - 1));
    bigint pw10("1" + string(diff, '0'));
    b = multiply(b,pw10);
    //debug2(b.a,a.a);
    while (!(a<b)) {
        bigint nb = b;
        nb.a = b.a + "0";
        if (a<nb){
            //cout<<"breakimng";
            break;
        }
        b = nb;
        pw10.a = pw10.a + "0";
    }
    //debug3(pw10.a,b.a,a.a);
    while (!((pw10.a.length()==1 and pw10.a[0] == '0') or pw10.a.empty())){
        //debug4(res.a,a.a,b.a,pw10.a);
        //cout<<(b<a)<<endl;
        while (!(a<b)) {
            a = subtract(a,b);
            res = add(res, pw10);
            //cout<<a.a<<"    "<<b.a<<endl;
            wait;
        }
        b.a.pop_back();
        pw10.a.pop_back();
    }
    res.neg = res_neg;
    rem = a;
    return res;
} 

bigint bigint :: scale(bigint a, int n){
    for(int i = 0;i<n;i++){
        a.a = a.a + "0";
    }
    return a;
}

bigint bigint :: multiply(bigint a, bigint b){
    //derr2(a.a,b.a);
    if(b<a){
        swap(a,b);
    }
    if(a.a.length()<=1){
        bigint res;
        int carry = 0;
        for(int i = b.a.length()-1 ; i>=0 ; i--){
            int x = b.a[i] - '0';
            //derr(x);
            carry = x * (a.a[0]-'0') + carry;
            res.a = to_string(carry%10) + res.a;
            //derr(carry);
            carry/=10;
        }
        while(carry>0){
            res.a = to_string(carry%10) + res.a;
            carry /= 10;
        }
        res.neg = a.neg ^ b.neg;
        return res;
    }
    int m = max(a.a.length(), b.a.length());
    m = m/2;
    //derr4(a.a.length(), m, m+1, a.a.length()-m);
    //derr4(b.a.length(), m, m+1, b.a.length()-m);
    bigint high1(a.a.substr(0,m));
    bigint low1(a.a.substr(m+1,a.a.length()-m));
    bigint high2(b.a.substr(0,m));
    bigint low2(b.a.substr(m+1,b.a.length()-m));
    high1.neg = low1.neg = false;
    high2.neg = low2.neg = false;
    bigint z0 = this->multiply(low1, low2);
    bigint z1 = this->multiply( add( low1, high1), add(low2, high2) );
    bigint z2 = this->multiply(high1, high2);
    bigint term1 = this->scale(z2, m*2);
    bigint term2 = this->subtract(z1,z2);
    //derr3(z0.a,z1.a,z2.a);
    term2 = this->subtract(term2, z0);
    term2 = this->scale(term2, m);
    term1 = this->add(term1, term2);
    //derr2(term1.a, term2.a);
    term1 = add(term1, z0);
    term1.neg = a.neg ^ b.neg;
    return term1;
}

bigint bigint :: subtract(bigint &a, bigint &b){
    if(a.neg == true  and b.neg == false){
        b.neg = true;
        return add(a,b);
    }
    else if(a.neg == false and b.neg == true){
        b.neg = false;
        return add(a,b);
    }
    else if(a.neg == true and b.neg == true){
        b.neg = false;
        a.neg = false;
        return subtract(b,a);
    }
    bigint res;
    if( a < b ){
        res.neg = true;
        swap(a,b);
    }
    bool carry = false;
    int i = a.a.length() - 1;
    int j = b.a.length() - 1;
    while(i>=0){
        if(j >= 0){
            int x = a.a[i] - '0' - carry;
            int y = b.a[j] - '0';
            if(x<y){
                carry = true;
                x += 10;
                res.a = to_string(x-y) + res.a;
            }
            else{
                carry = false;
                res.a = to_string(x-y) + res.a;
            }
        }
        else {
            if(carry){
                if(a.a[i] == '0'){
                    res.a = "9" + res.a;
                }
                else{
                    res.a = to_string (a.a[i] - '0' - 1) + res.a;
                    carry = false;
                }
            }
            else{
                res.a = a.a[i] + res.a;
            }
        }
        i--;
        j--;
    }
    int k=0;
    for(k=0;k<res.a.length();k++){
        //debug(res.a[k]);
        if(res.a[k]!='0'){
            break;
        }
    }//debug2(res.a,k);
    res.a = res.a.substr(k,res.a.length()-k);
    if(res.a.length()==1 and res.a[0]=='0')res.neg = false;
    return res;
}

bool bigint :: operator<(bigint &a){
    if(this->a.length() < a.a.length()){
        return true;        
    }
    else if(this->a.length() > a.a.length()){
        return false;
    }
    else {
        for(int i = 0 ; i<this->a.length() ; i++){
            if(this->a[i] < a.a[i]){
                return true;
            }
            else if(this->a[i] > a.a[i]){
                return false;
            }
        }
    }
    return false;
}
bigint bigint :: add(bigint &a, bigint &b){
    if(b.neg == true and a.neg == false){
        b.neg = false;
        return this->subtract(a,b);
    }
    if(b.neg == false and a.neg == true){
        a.neg = false;
        return this->subtract(b,a);
    }
    bigint res;
    res.neg = a.neg and b.neg;
    int i = a.a.length() - 1;
    int j = b.a.length() - 1;
    int carry = 0;
    while(i>=0 or j>=0){
        int x=0,y=0;
        if(i>=0){
            x = a.a[i] - '0';
            i--;
        }
        if(j>=0){
            y = b.a[j] - '0';
            j--;
        }
        carry = carry + x + y;
        //derr5(x,y,i,j,carry);
        res.a = to_string(carry%10) + res.a;
        carry /= 10;
    }
    while(carry>0){
        res.a = to_string(carry%10) + res.a;
        carry /= 10;
    }
    return res;
}

bigint :: bigint(){
    this->a = "";
    this->neg = false;
}

bigint :: bigint(string s){
    if(s[0] == '-'){
        this->a = s.substr(1,s.length()-1);
        this->neg = true;
    }
    else{
        this->neg = false;
        this->a = s;
    }
}

bigint :: bigint(int n){
    this->a = "";
    if(n<0){
        this->neg = true;
        n = -n;
    }
    else{
        this->neg = false;
    }
    while(n>0){
        this->a = to_string(n%10) + this->a;
        n/=10;
    }
}

bigint :: bigint(long long n){
    this->a = "";
    if(n<0){
        this->neg = true;
        n = -n;
    }
    else{
        this->neg = false;
    }
    while(n>0){
        this->a = to_string(n%10) + this->a;
        n/=10;
    }
}

bigint :: bigint(long n){
    this->a = "";
    if(n<0){
        this->neg = true;
        n = -n;
    }
    else{
        this->neg = false;
    }
    while(n>0){
        this->a += to_string(n%10) + this->a;
        n/=10;
    }
}

int main(){
    //std::ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);cout.precision(20);
    freopen("/home/aman/Documents/Competitive Programming/error.txt","w",stderr);
    bigint a("56568"),b("498515");swap(a,b);
    bigint t(20),r(36);
    cerr<<"working";
    cout<<a.a<<""<<b.a<<endl;
    cout<<endl;
    bigint rem;
    bigint res = res.divide(a,b,rem);
    cout<<res.a<<endl<<rem.a<<endl;
    return 0;
}