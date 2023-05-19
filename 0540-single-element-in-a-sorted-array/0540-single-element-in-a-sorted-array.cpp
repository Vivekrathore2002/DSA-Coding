class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int,int> map;
        for(auto i:nums){
            map[i]++;
        }
        for(int i=0;i<nums.size();i++){
            if(map[nums[i]]==1){
                return nums[i];
            }
        }
        return -1;
    }
};