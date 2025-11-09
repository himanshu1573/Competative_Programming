#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define int long long 
#define pb push_back
int mod=1e9+7;
int gcd(int a,int b){if(b==0)return a;return gcd(b,a%b);}
const int inf=1e18;
const int N=1e5+10;
vector<int>coins;
vector<int>dp;
int  recursive_dp(int x){
if(x==0)return 0;
if(x<0)return inf;

if(dp[x]!=-1)return dp[x];
int totalCoins=inf;

for(auto &a:coins){
	int res=recursive_dp(x-a);
	if(res!=inf){
		totalCoins=min(totalCoins,res+1);
	}
}
dp[x]=totalCoins;
return dp[x];
}
void solve(){
int n,x;cin>>n>>x;
dp.resize(x+1,-1);
coins.resize(n);
for(auto &i:coins)cin>>i;

int result=recursive_dp(x);
if (result == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }
// cout<<ans<<nl;

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
