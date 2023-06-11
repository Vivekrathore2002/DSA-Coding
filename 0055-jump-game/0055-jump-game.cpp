class Solution {
public:
    bool canJump(vector<int>& nums) {
        int curr = nums[0];
        for(int i=1;i<nums.size();i++){
            if(curr<=0) return false;
            curr--;
            curr = max(nums[i],curr);
        }
        return true;
    }
};