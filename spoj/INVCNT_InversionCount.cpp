#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define int long long 
#define pb push_back
int mod=1e9+7;
int gcd(int a,int b){if(b==0)return a;return gcd(b,a%b);}
const int inf=1e18;
const int N=1e5+10;

int merge_and_count(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    int i = left;    
    int j = mid + 1; 
    int k = left;    
    int inversion_count = 0;
    while ((i <= mid) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inversion_count += (mid - i + 1);
        }
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
    return inversion_count;
}

int merge_sort_and_count(vector<int>& arr, vector<int>& temp, int left, int right) {
    int inversion_count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        inversion_count += merge_sort_and_count(arr, temp, left, mid);
        inversion_count += merge_sort_and_count(arr, temp, mid + 1, right);
        inversion_count += merge_and_count(arr, temp, left, mid, right);
    }
    return inversion_count;
}
void solve(){
    int n;
    cin >> n;
    if (n == 0) return; // Handle edge case or end of input
    
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    
    vector<int> temp(n);
    cout << merge_sort_and_count(A, temp, 0, n - 1) << nl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0); 
    
    int t;
    cin >> t;
    string blank;
    getline(cin, blank); 
    
    while(t--){
        solve();
        if (t > 0) {
            getline(cin, blank); 
        }
    }
    return 0;
}