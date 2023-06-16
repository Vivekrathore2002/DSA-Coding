// Code taken as it is from
// with a little change only
// Max Consecutive Ones III
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
    int ans = 0;
    int flip = 0;
    int i = 0;
    int j = 0;
    int n = nums.size();
    while (i < n) {
        if (nums[i] == 0) {
            flip++;
        }
        while (flip > 1) {
            if (nums[j] == 0)
                flip--;
            j++;
        }
        ans = max(ans, i - j + 1);
        i++;
    }
    return ans-1;  
    }
};