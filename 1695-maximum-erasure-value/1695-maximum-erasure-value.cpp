// https://www.youtube.com/watch?v=WG6Kok6tIyg&ab_channel=CodewithAlisha
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int start,end,ans,sum=0;
        set<int>s;
        while(end<nums.size())
        {
            while(start<end && s.find(nums[end])!=s.end())
            {
                s.erase(nums[start]);
                sum-=nums[start];
                start++;
            }
            s.insert(nums[end]);
            sum+=nums[end];
            end++;
            ans=max(ans,sum);
        }
        return ans;
    }
};