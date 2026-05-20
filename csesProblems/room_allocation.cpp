
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
	int n;cin>>n;
	vector<tuple<int,int,int>>cust;
	for(int i=0;i<n;i++){
		int a,b;cin>>a>>b;
		cust.push_back({a,b,i});

	}
	sort(cust.begin(),cust.end());
	priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
	int rooms=0;
	vector<int>ans(n);
	for(int i=0;i<n;i++){
		auto [arrival,depart,idx]=cust[i];
		if(!pq.empty() && pq.top().first<arrival){
			auto [next_depart_time,available_room]=pq.top();
			pq.pop();
			ans[idx]=available_room;
			pq.push({depart,available_room});

		}else{
			rooms++;
			ans[idx]=rooms;
			pq.push({depart,rooms});
		}
	}
	cout << rooms << nl;
    for(int i=0; i<n; i++) cout << ans[i] << " ";
    cout << nl;
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


