#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    vector<int>a(n), b(m);
    int smlr = n & 1 ? n / 2: n / 2 - 1;
    int left = 0, right = n - 1;
    while(left <= right){
        int mid = (left + right) >> 1, leftsmlr = smlr - mid;
        if(leftsmlr >= m || b[leftsmlr] < a[mid] || (leftsmlr && b[leftsmlr - 1] <= a[mid])) left = mid + 1;
        else{
            if(n & 1) cout << 
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i += 1)
        solve();

    return 0;
}