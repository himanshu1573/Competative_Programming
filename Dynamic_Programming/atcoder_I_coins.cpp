#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define int long long 
#define pb push_back
int mod=1e9+7;
int gcd(int a,int b){if(b==0)return a;return gcd(b,a%b);}
const int inf=1e18;
const int N=1e5+10;

// dp[i][j] is having exactly j heads in tossing coin using 0 to ... i
void solve(){
int n;cin>>n;                       
vector<double>pHeads(n);
for(auto &a:pHeads)cin>>a;

vector<vector<double>>dp(n+1,vector<double>(n+1));
dp[0][0]=1;

for(int i=1;i<=n;i++){
	for(int j=0;j<=i;j++){
		double p=pHeads[i-1];
		// if(j>0)
			dp[i][j]=p*dp[i-1][j-1]+(1-p)*dp[i-1][j];
	}
}
double ans=0;
for(int head=(n+1)/2;head<=n;head++){
	ans+=dp[n][head];
}
cout<<fixed<<setprecision(10)<<ans<<endl;
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