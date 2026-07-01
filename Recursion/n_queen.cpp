#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define int long long
#define pb push_back

int mod=1e9+7;
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
// const int inf=1e18;
// const int N=1e5+10;

vector<vector<string>> ans;

bool isSafe(int row,int col,vector<string>&board,int n){
    int dupRow=row,dupCol=col;
    while(row>=0&&col>=0){
        if(board[row][col]=='Q')return false;
        row--;
        col--;
    }
    row=dupRow;
    col=dupCol;
    while(col>=0){
        if(board[row][col]=='Q')return false;
        col--;
    }
    row=dupRow;
    col=dupCol;
    while(row<n&&col>=0){
        if(board[row][col]=='Q')return false;
        row++;
        col--;
    }
    return true;
}

void solveQueen(int col,vector<string>&board,int n){
    if(col==n){
        ans.pb(board);
        return;
    }
    for(int row=0;row<n;row++){
        if(isSafe(row,col,board,n)){
            board[row][col]='Q';
            solveQueen(col+1,board,n);
            board[row][col]='*';
        }
    }
}

void solve(){
    int n;
    cin>>n;
    vector<string>board(n,string(n,'.'));
    solveQueen(0,board,n);
    cout<<ans.size()<<nl;
    for(auto &v:ans){
        for(auto &row:v)cout<<row<<nl;
        cout<<nl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--)solve();
    return 0;
}