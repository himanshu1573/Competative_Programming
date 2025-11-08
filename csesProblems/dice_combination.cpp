#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define int long long 
#define pb push_back
int mod=1e9+7;
int gcd(int a,int b){if(b==0)return a;return gcd(b,a%b);}
const int inf=1e18;
const int N=1e6+10;

std::vector<int> dp;
int  recursive(int n){
if(n==0)return 1 ;
if(n<0)return 0;

if(dp[n]!=-1) return dp[n];
int ans=0;
for(int i=1;i<=6;i++){
ans=(ans+recursive(n-i))%mod;
}
dp[n]=ans;
return dp[n];
}

void solve(){
int n;cin>>n;
dp.assign(n+1,-1);
cout<<recursive(n)<<nl;
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
