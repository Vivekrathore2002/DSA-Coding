//There can be two approached possible 
// 1.Binary search - which i know but it's already 1:25 am today(11/06/23) so imma just use 2nd approach with little more complexity



//Approach 2 - Lazy one - 
class Solution {
public:
    int findMin(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[0];
    }
};