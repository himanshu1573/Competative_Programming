#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define int long long 
#define pb push_back
int mod=1e9+7;
int gcd(int a,int b){if(b==0)return a;return gcd(b,a%b);}
const int inf=1e18;
const int N=1e5+10;

int dp[N+10];
//dp[i] is the minimum possible  cost required to reach i from 0 using i-1 or i-2 cost  ;
// transition is dp[i]=min(dp[i-1],dp[i-2]);
void solve(){
int n;cin>>n;
vector<int>a(n);
for(int i=1;i<=n;i++)cin>>a[i];
dp[1]=0,dp[2]=dp[1]+abs(a[2]-a[1]);

for(int i=3;i<=n;i++){
	dp[i]=min(dp[i-1]+abs(a[i]-a[i-1]),dp[i-2]+abs(a[i-2]-a[i]));
}
cout<<dp[n];
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
