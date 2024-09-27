class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), ans = 0;
        for(int l = 0, r = n - 1; l < r;){
            ans = max(ans, min(height[l], height[r]) * (r - l));
            if(height[l] < height[r]) l += 1;
            else r -= 1;
        }
        
        return ans;
    }
};