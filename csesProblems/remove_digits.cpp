#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define int long long 
#define pb push_back
int mod=1e9+7;
int gcd(int a,int b){if(b==0)return a;return gcd(b,a%b);}
const int inf=1e18;
const int N=1e5+10;

//dp[i] is the minimun number of step required to make i to 0;
void solve(){
int n;cin>>n;
vector<int>dp(n+1,inf);
dp[0]=0;
for(int i=1;i<=n;i++){
	int digit=i;
	while(digit>0){
		int temp=digit%10;
		digit=digit/10;
		if(temp!=0)
			dp[i]=min(dp[i],1+dp[i-temp]);
	}
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
