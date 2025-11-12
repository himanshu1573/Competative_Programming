#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
// #define int long long 
#define pb push_back
int mod=1e9+7;
int gcd(int a,int b){if(b==0)return a;return gcd(b,a%b);}
// const int inf=1e18;
const int N=1e5+10;

void solve(){
int n,X;cin>>n>>X;
vector<int>price(n),pages(n);
for(auto &i:price)cin>>i;
for(auto &i:pages)cin>>i;

//dp[i][x] it the max achievable pages i with price not exceding x;
vector<vector<int>>dp(n+1,vector<int>(X+1,0));
//base case is dp[0][any_thing] is 0;

for(int i=1;i<=n;i++){
	for(int x=0;x<=X;x++){
		//exclude the item
		int skip=dp[i-1][x];

		//include the item if still we have price left
		int take=0;
		if(x-price[i-1]>=0)
			 take=dp[i-1][x-price[i-1]]+pages[i-1];
		dp[i][x]=max(take,skip);	
	}
}
cout<<dp[n][X];	
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
