#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define int long long 
#define pb push_back
int M=1e9+7;
int gcd(int a,int b){if(b==0)return a;return gcd(b,a%b);}
const int inf=1e18;
const int N=1e6+10;

int dp[N];  // dp[i] is the number of ways to make a sum i using the given coins .coins are unlimited.
// transition dp[i]=dp[i-coins(j)]+1;
void solve(){
int n,x;cin>>n>>x;
vector<int>coins(n);
memset(dp, 0, sizeof(dp));
for(auto &a:coins)cin>>a;
    dp[0]=1;
for(int i=1;i<=x;i++){
    for(int j=0;j<n;j++){
    if(i-coins[j]>=0){
        dp[i]=(dp[i]+dp[i-coins[j]])%M;
    }
    }
}
cout<<dp[x];
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
