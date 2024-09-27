#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 5;

void solve(){
    vector<vector<int>>results;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for(int i = 0; i < n; i += 1){
        if(i && nums[i] == nums[i - 1]) continue;
        int l = i + 1, r = n - 1;
        while(l < r){
            int sum = nums[i] + nums[l] + nums[r];
            if(sum == 0){
                results.emplace_back(nums[i], nums[l], nums[r]);
                l += 1, r -= 1;
                while(l < r && nums[l] == nums[l - 1]) l += 1;
                while(r > l && nums[r] == nums[r + 1]) r -= 1;
            }
            else if(sum > 0) r -= 1;
            else l += 1;
        }
    }
    return results;
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