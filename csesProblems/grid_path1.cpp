#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define int long long 
#define pb push_back
int mod=1e9+7;
int gcd(int a,int b){if(b==0)return a;return gcd(b,a%b);}
const int inf=1e18;
const int N=1e3+10;

//dp[i][j] is the number of ways to reach i,j from cell 0,0 by only using these step top i-1,j or right i,j-1;
vector<string>grid;
int dp[N][N];
int recursive_solve(int i,int j){
if(i<0 || j<0)return 0;    
if(grid[i][j]=='*')return 0;
if(i==0 && j==0)return 1;

if(dp[i][j]!=-1)return dp[i][j];
int top_way=recursive_solve(i-1,j);
int right_way=recursive_solve(i,j-1);

return dp[i][j]=(top_way+right_way)%mod;
}
void solve(){
int n;cin>>n;
grid.resize(n);
memset(dp, -1, sizeof(dp));
for(int i=0;i<n;i++)cin>>grid[i];

cout<<recursive_solve(n-1,n-1);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0); 
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
