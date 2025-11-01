#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define int long long 
#define pb push_back
int mod=1e9+7;
int gcd(int a,int b){if(b==0)return a;return gcd(b,a%b);}
const int inf=1e18;
const int N=1e5+10;

// dp[i][j] is the max possible values that can be achieved using first i values weights not exceding W;
void solve(){
int n,W;cin>>n>>W;
vector<int>values(n+1),weights(n+1);
for(int i=1;i<=n;i++){
	cin>>weights[i]>>values[i];
}
vector<vector<int>>dp(n+1,vector<int>(W+1,0));

for(int i=1;i<=n;i++){
	for(int j=0;j<=W;j++){
		// exclude the ith item ;
		dp[i][j]=dp[i-1][j];

		//include the ith item 
		if(j>=weights[i])
		dp[i][j]=max(dp[i][j],dp[i-1][j-weights[i]]+values[i]);
	}
}
cout<<dp[n][W];
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
