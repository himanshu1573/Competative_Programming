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
int e,f;cin>>e>>f;
int W=f-e;
int n;cin>>n;
vector<int>values(n),weight(n);
for(int i=0;i<n;i++){
	cin>>values[i]>>weight[i];
}
// dp[i] is the min value possible using the weight i
vector<int>dp(W+5,inf);
dp[0]=0; // value  is zero if weigth having 0;
for(int i=1;i<=W;i++){
	for(int j=0;j<n;j++){
        if(i>=weight[j])
            if(dp[i-weight[j]]!=inf)
		      dp[i]=min(dp[i],dp[i-weight[j]]+values[j]);
	}
}
if (dp[W]==inf) {
        cout<<"This is impossible."<< "\n";
    } else {
        cout<<"The minimum amount of money in the piggy-bank is "<<dp[W]<<"."<<"\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0); 
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
