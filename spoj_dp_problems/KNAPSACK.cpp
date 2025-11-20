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
int S,n;cin>>S>>n;
vector<int>size(n),values(n);
for(int i=0;i<n;i++){
	cin>>size[i]>>values[i];
}
//dp[i][j] is the maximum value achievalbe using weight i and total size not excedding S;
vector<vector<int>>dp(S+1,vector<int>(n+1));
dp[0][0]=0;
for(int s=0;s<=S;s++){
	for(int j=1;j<=n;j++){
		//exclude the value 
		dp[s][j]=dp[s][j-1];
		//include the values

		if(s>=size[j-1]){
			dp[s][j]=max(dp[s][j],dp[s-size[j-1]][j-1]+values[j-1]);
		}
	}
}
cout<<dp[S][n];
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
