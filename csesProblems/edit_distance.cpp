#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define int long long 
#define pb push_back
int mod=1e9+7;
int gcd(int a,int b){if(b==0)return a;return gcd(b,a%b);}
const int inf=1e18;
// dp[i][j] is the edit distance between first i characters of string A and j is the edit distance 
// b/w first j characters of string B;
// transition is when A[i]==B[i] dp[i][j]=dp[i-1][j-1]
// if last characters are not equal then three cases 
// 1.replace dp[i][j]=dp[i-1][j-1]+1;/
// 2. remove from  string A then dp[i][j]=dp[i-1][j];
// 3. remove from  string b then dp[i][j]=dp[i][j-1];
// 4. base is dp[i][0] =i or dp[0][i]=i and dp[0][0]=0;


void solve(){
	string s,t;
	cin>>s>>t;
    int n=s.size();
    int m=t.size();
	vector<vector<int>>dp(n+1,vector<int>(m+1));
    
    for(int i=0;i<=n;i++){
        dp[i][0]=i;
    }
    for(int i=0;i<=m;i++){
        dp[0][i]=i;
    }
    dp[0][0]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char a=s[i-1];
            char b=t[j-1];
            if(a==b)dp[i][j]=dp[i-1][j-1];
            else {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            // skipping from string 1
            int x=dp[i-1][j]+1;
            dp[i][j]=min(x,dp[i][j]);

            // skipping from string 2;
            dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
        }
    }
    cout<<dp[n][m];
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
