#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define int long long 
#define pb push_back
int mod=1e9+7;
int gcd(int a,int b){if(b==0)return a;return gcd(b,a%b);}
const int inf=1e18;
const int N=1e5+10;

bool valid(int x,int m){
	return x>=1 && x<=m;
}
void solve(){
int n,m;cin>>n>>m;
vector<int>a(n);
for(auto &i:a)cin>>i;

// dp[i][k] is the number of prefixes of length i that can be formed such that the last element
// of the prefix is k;
// baes case is dp[1][k]=1 if(a[0]=0 or a[0]=k)


vector<vector<int>>dp(n+1,vector<int>(m+1));

for(int i=1;i<=m;i++){
	if(a[0]==i || a[0]==0){
		dp[1][i]=1;
	}
}

for(int i=2;i<=n;i++){
	for(int k=1;k<=m;k++){
		if(a[i-1]!=0 && a[i-1]!=k){dp[i][k];continue;} // this case is where the current element is non zero .
        
        for(int prev=k-1;prev<=k+1;prev++){
        	if(!valid(prev,m)){
        		continue;
        	}
        	dp[i][k]=(dp[i][k]+dp[i-1][prev])%mod;
        }

	}	
}
int ans=0;
for(int i=1;i<=m;i++){
	ans=(ans+dp[n][i])%mod;
}
cout<<ans<<nl;

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
