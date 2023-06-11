// https://www.youtube.com/watch?v=pLzOp2_Y9Vk&ab_channel=CodewithAlisha

// We will use set to get the time complexity constant O(n)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for(auto x: nums){
            s.insert(x);
        }
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            int current_element = nums[i];
            int previous_element = current_element-1;
            int count = 0;
            if(s.find(previous_element)==s.end())
            {
                while(s.find(current_element)!=s.end())
                {
                    current_element++;
                    count++;
                }
            }
            ans = max(ans,count);
        }
        return ans;
    }
};