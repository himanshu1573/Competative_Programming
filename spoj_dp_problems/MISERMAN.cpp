#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define int long long 
#define pb push_back
int mod=1e9+7;
int gcd(int a,int b){if(b==0)return a;return gcd(b,a%b);}
const int inf=1e18;
const int N=1e5+10;

void solve(){
int n,m;cin>>n>>m;
vector<vector<int>>grid(n+1,vector<int>(m+1));
for(int i=1;i<=n;i++){
	for(int j=1;j<=m;j++){
		cin>>grid[i][j];
	}
}
//dp[i][j] is the min cost required to reach i using the bus j where bus j used is previous city bus .ie i-1;

vector<vector<int>>dp (105,vector<int>(105));
//base case is the first row dp[1][j]=grid[1][j];

// here we can go j,j-1,j+1 so we have to check if the current j is valid or not or it is out of bounds.
for(int i=1;i<=m;i++){
	dp[1][i]=grid[1][i];
}
for(int i=2;i<=n;i++){
	for(int j=1;j<=m;j++){
 		int pre_min_cost=INT_MAX;

 		if(j>1)pre_min_cost=min(pre_min_cost,dp[i-1][j-1]);
 		if(j<m)pre_min_cost=min(pre_min_cost,dp[i-1][j+1]);
 		pre_min_cost=min(pre_min_cost,dp[i-1][j]);

 		dp[i][j]=grid[i][j]+pre_min_cost;
	}
}

int ans=INT_MAX;
for(int i=1;i<=m;i++){
	ans=min(ans,dp[n][i]);
}
cout<<ans;

// for(int i=0;i<=n;i++){
// 	for(int j=0;j<=m;j++){
// 		cout<<dp[i][j]<<" ";
// 	}
// 	cout<<endl;
// }
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
