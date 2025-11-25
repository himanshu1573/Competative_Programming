#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define int long long 
#define pb push_back
int mod=1e9+7;
int gcd(int a,int b){if(b==0)return a;return gcd(b,a%b);}
const int inf=1e18;
const int N=1e5+10;

int dp[505][505];
int recursive_solve(int a,int b){
    if(a==b)return 0;
    if(a==0 || b==0)return 0;
    if(a<b)swap(a,b);

if(dp[a][b]!=-1)return dp[a][b];

int minCuts=INT_MAX;
for(int i=1;i<a;i++){
    minCuts=min(minCuts,1+recursive_solve(i,b)+recursive_solve(a-i,b));
}
dp[a][b]=minCuts;
return dp[a][b];
}
void solve(){
int n,m;cin>>n>>m;
// dp[i][j] is the minimum number of cuts  required to convert i*j into squres .
memset(dp,-1,sizeof(dp));
int ans=recursive_solve(n,m);
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
