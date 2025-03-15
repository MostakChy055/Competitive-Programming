#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    vector<int>vc{1, 2, 5, 4};
    vector<int>khela(vc.begin(), vc.end());
    for(int i: khela) cout << i << " ";
    cout << endl;
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i += 1)
        solve();

    return 0;
}