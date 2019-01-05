#include<bits/stdc++.h>
using namespace std;
typedef long long lo;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lo t;
    cin>>t;
    while(t--){
        lo n,k;
        cin>>n>>k;
        vector<lo> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            a[i]%=k;
        }
        lo dp[n][k];
        memset(dp,0,sizeof(dp));
        dp[0][a[0]]=1;
        //dp[0][(-a[0]+k)%k]=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<k;j++){
                dp[i][j]+=dp[i-1][(j+a[i])%k];
                dp[i][j]+=dp[i-1][(j-a[i]+k)%k];
            }
        }
        /*for(int i=1;i<n;i++){
            for(int j=0;j<k;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }*/
        if(dp[n-1][0]!=0)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}