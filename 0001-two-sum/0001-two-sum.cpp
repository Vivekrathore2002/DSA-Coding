class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> elements;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    elements.push_back(i);
                    elements.push_back(j);
                }
            }
        }
        return elements;
    }
};