#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    vector<int>nums{1, 3};
    int n = nums.size(), target = 3;
    int left = 0, right = n - 1, index = - 2;
    bool first = 0;
    if(nums[0] < nums[n - 1] || target < nums[n - 1]) first = 1;
    while(left <= right){
        int mid = (left + right) >> 1;
        if(nums[mid] <= nums[n - 1]){
            if(!first || nums[mid] > target) right = mid - 1;
            else left = mid + 1;
            if(nums[mid] == target) index = mid;
        }
        else{
            if(first || nums[mid] < target) left = mid + 1;
            else right = mid - 1;
            if(nums[mid] == target) index = mid;
        }
    }
    cout << index << '\n';
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