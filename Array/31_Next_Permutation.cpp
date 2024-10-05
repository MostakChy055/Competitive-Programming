#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    bool yes = 0;
    int n; cin >> n;
    vector<int>nums(n);
    // int n = nums.size();
    for(int i = 0; i < n; i += 1) cin >> nums[i];
    vector<int>ans;
    multiset<int>st; st.insert(nums[n - 1]);
    for(int i = n - 2; i >= 0; i -= 1){
        auto it = upper_bound(st.begin(), st.end(), nums[i]);
        if(it == st.end()) st.insert(nums[i]);
        else{
            int value = *it; st.erase(it); st.insert(nums[i]);
            nums[i] = value;
            int j = i + 1;
            for(int vl: st) nums[j++] = vl;
            yes = 1; 
            break;
        }
    }

    cout << st.size() << endl;
    if(yes) ans = nums;
    else{
        for(int i: st) ans.emplace_back(i);
        nums = ans;
    }
    for(int i: nums) cout << i << ' ';
    cout << '\n';
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