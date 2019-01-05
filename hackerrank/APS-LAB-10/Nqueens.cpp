#include<bits/stdc++.h>
using namespace std;
typedef long long lo;
vector<vector<lo>> board;
set<vector<lo> > solution;
lo n;
bool is_safe(lo x,lo y){
    for(int i=0;i<x;i++)if(board[i][y]==1)return false;
    lo tx=x-1;lo ty=y-1;
    while(tx>=0 and ty>=0){
        if(board[tx][ty]==1)return false;
        tx--;ty--;
    }
    tx=x-1;
    ty=y+1;
    while(tx>=0 and ty<n){
        if(board[tx][ty]==1)return false;
        tx--;
        ty++;
    }
    return true;
}
void fun(lo index, vector<lo>cur){
    if(index==n){
        solution.insert(cur);
        return ;
    }
    for(int i=0;i<n;i++)if(is_safe(index,i)){
        board[index][i]=1;
        cur.push_back(i+1);
        fun(index+1,cur);
        cur.pop_back();
        board[index][i]=0;
    }
}
int main(){
    lo t;
    cin>>t;
    while(t--){
        cin>>n;
        board.resize(n,vector<lo>(n,0));
        solution.clear();
        vector<lo>cur;
        fun(0,cur);
        for(auto it: solution){
            cout<<"[";
            for(auto it2: it)cout<<it2<<" ";
            cout<<"]"<<" ";
        }
        cout<<endl;
    }
}