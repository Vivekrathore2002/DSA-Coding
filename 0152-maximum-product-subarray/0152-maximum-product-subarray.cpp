class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int ans=nums[0], maxp = nums[0], minp = nums[0];
        for(int i=1;i<nums.size();i++){
            int temp = max({nums[i],maxp*nums[i],minp*nums[i]});
            minp = min({nums[i],maxp*nums[i],minp*nums[i]});
            maxp = temp;
            ans = max(maxp,ans);
        }
        return ans;
    }
};