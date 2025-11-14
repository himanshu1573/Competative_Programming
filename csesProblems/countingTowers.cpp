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

// dp[i][0]: Ways to build a tower of height i ending in two separate blocks ([ ][ ]).

// dp[i][1]: Ways to build a tower of height i ending in one joined block ([ ]).

//base case is dp[1][1]=1 and dp[1][0]=1 ;this is where our row  .
// final subproblem dp[n][0]+dp[n][1];
dp[1][0]=1;
dp[1][1]=1;


for(int i=2;i<N;i++){
	dp[i][0]=(4ll*dp[i-1][0]+dp[i-1][1])%mod;
	dp[i][1]=(2ll*dp[i-1][1]+dp[i-1][0])%mod;
}
	
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0); 
    solve();
    int t=1;
    cin>>t;
    while(t--){
    int n;cin>>n;
     cout<<(dp[n][0]+dp[n][1])%mod<<nl;
    }
    return 0;
}


