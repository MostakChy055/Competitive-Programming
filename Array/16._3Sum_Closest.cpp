#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 5;

void solve(){
    sort(nums.begin(), nums.end());
    int closest_sum = INT_MAX / 2;  
        
    for (int i = 0; i < nums.size() - 2; ++i) {
        int left = i + 1, right = nums.size() - 1;
        while (left < right) {
            int current_sum = nums[i] + nums[left] + nums[right];
            if (abs(current_sum - target) < abs(closest_sum - target)) {
                closest_sum = current_sum;
            }
            if (current_sum < target) {
                ++left;
            } else if (current_sum > target) {
                --right;
            } else {
                return current_sum;
            }
        }
    }
        
    return closest_sum;
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