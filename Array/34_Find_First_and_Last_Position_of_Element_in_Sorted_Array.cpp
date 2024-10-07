#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    vector<int>nums{5, 7, 7, 8, 8, 10};
    int n = nums.size(), left = 0, right = n - 1, target = 5, indexL = - 1, indexU = - 1;
    while(left <= right){
        int mid = (left + right) >> 1;
        if(nums[mid] < target) left = mid + 1;
        else{
            if(nums[mid] == target) indexL = mid;
            right = mid - 1;
        }
    }
    left = 0, right = n - 1;
    while(left <= right){
        int mid = (left + right) >> 1;
        if(nums[mid] <= target){
            if(nums[mid] == target) indexU = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }
    cout << indexL << " " << indexU << '\n';
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