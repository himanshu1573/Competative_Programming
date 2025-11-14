#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
// #define int long long 
#define pb push_back
int mod=1e9+7;
int gcd(int a,int b){if(b==0)return a;return gcd(b,a%b);}
// const int inf=1e18;
const int N=1e6+10;

vector<vector<int>>dp(N,vector<int>(2));

void solve(){
int n;cin>>n;

//dp[i][0] is the number of ways to fill the grid from ith row to n-1 th row such that an vertical block is 
// trying to extend from i-1 th row 

//dp[i][1] is the number of ways to fill the grid from ith row to n-1 th row such that an horizontal block 
// is trying to extend from i-1 row 

//base case is dp[n][1]=1 and dp[n][0]=1 ;this is where our row end .
// final subproblem dp[1][0]+dp[1][1];
dp[n][0]=1;
dp[n][1]=1;


for(int i=n-1;i>=0;i--){
	dp[i][0]=(4ll*dp[i+1][0]+dp[i+1][1])%mod;
	dp[i][1]=(2ll*dp[i+1][1]+dp[i+1][0])%mod;
}
cout<<(dp[1][0]+dp[1][1])%mod<<nl;	
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0); 
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
