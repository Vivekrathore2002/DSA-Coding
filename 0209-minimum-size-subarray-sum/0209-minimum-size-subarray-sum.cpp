//https://www.youtube.com/watch?v=b7wMv62Y1l4&ab_channel=ApnaCollege
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
         int ans = INT_MAX,n = nums.size(),start = 0,sum = 0;
        for(int i = 0;i < n;i++)
        {
            sum += nums[i];
            if(sum >= target)
            {
                ans = min(ans,i - start + 1);
            }
            while(sum > target && start < i)
            {
                sum -= nums[start++];
                if(sum >= target)
                {
                    ans = min(ans,i - start + 1);
                }
            }
        }
        if(ans == INT_MAX)
        {
            return 0;
        }
        return ans;
    }
};