#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define int long long 
#define pb push_back
int mod=1e9+7;
int gcd(int a,int b){if(b==0)return a;return gcd(b,a%b);}
const int inf=1e18;
const int N=501;
int dp[N][N];
int solveRec(int a,int b){
    if(a>b){
        swap(a,b);
    }
    if(a==b){
        return 0;
    }
    if(dp[a][b]!=-1){
        return dp[a][b];
    }
    int min_cuts=1e9;
    for(int k=1;k<b;++k){
        min_cuts=min(min_cuts,1+solveRec(a,k)+solveRec(a,b-k));
    }
    for(int k=1;k<a;++k){
        min_cuts=min(min_cuts,1+solveRec(k,b)+solveRec(a-k,b));
    }
    dp[a][b]=min_cuts;
    return min_cuts;
}
void solve(){
    int a,b;
    cin>>a>>b;
    for(int i=0;i<=max(a,b);++i){
        for(int j=0;j<=max(a,b);++j){
            dp[i][j]=-1;
        }
    }
    cout<<solveRec(a,b)<<nl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0); 
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}