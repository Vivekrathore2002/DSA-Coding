// myself
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1;
        int last=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                first = i;
                break;
            }
        }
        for(int i=first;i<nums.size();i++){
            if(nums[i]==target){
                last = i;
                // break;
            }
        }
        vector<int> nums1;
        nums1.push_back(first);
        nums1.push_back(last);
        return nums1;
    }
};