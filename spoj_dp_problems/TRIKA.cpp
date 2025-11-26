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
int x,y;cin>>x>>y;
vector<vector<int>>grid(n+1,vector<int>(m+1));
for(int i=1;i<=n;i++){
	for(int j=1;j<=m;j++){
		cin>>grid[i][j];
	}
}
//dp[i][j] is the minimum power path from x,y to (i,j) while the allowed steps are right i,j+1 or down i+1,j
vector<vector<int>>dp(25,vector<int>(25,inf));
dp[x][y]=0;
for(int i=x;i<=n;i++){
	for(int j=y;j<=m;j++){
		if(i==x && j==y)continue;

		dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
	}
}
// cout<<grid[x][y]-dp[n][m];
if(grid[x][y]-dp[n][m]>=0)cout<<"Y "<<grid[x][y]-dp[n][m];
else cout<<"N";
// for(int i=1;i<=n;i++){
// 	for(int j=1;j<=m;j++){
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
