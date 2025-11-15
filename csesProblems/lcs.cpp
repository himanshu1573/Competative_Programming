#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define nl endl
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define int long long
const int M = 1e9 + 7; 
const ll INF=1e18;
ll pow(ll a, ll b, ll c) { ll ans = 1; while (b) { if (b & 1) ans = (ans * a) % c; b >>= 1; a = (a * a) % c; } return ans; };

void solve(){
	 int n,m;cin>>n>>m;
	 vector<int>s(n),t(m);
	 for(auto &i:s)cin>>i;
	 for(auto &i:t)cin>>i;
	// dp[i][j] is the lcs of string1 from [0.....i]and string2 from [0....j];
vvi dp(n+1,vi(m+1,0));

for(int i=1;i<=n;i++){
	for(int j=1;j<=m;j++){
		dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		if(s[i-1]==t[j-1]) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
	}
}
vector<int> ans;
int i=n,j=m;
while(i && j){
if (s[i-1]==t[j-1]){
	ans.push_back(s[i-1]);
	i--,j--;
}else if(dp[i-1][j]>=dp[i][j-1])
i--;
else{
	j--;
}
}
reverse(ans.begin(),ans.end());
cout<<ans.size()<<nl;;
for(auto &i:ans)cout<<i<<" ";
// cout<<dp[n][m];
}
signed main(){
solve();
return 0;
}
