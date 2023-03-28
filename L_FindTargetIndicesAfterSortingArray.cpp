// class Solution {
// public:
//     vector<int> targetIndices(vector<int>& nums, int target) {
//         sort(nums.begin(),nums.end());
//         vector<int> ans;
//         int i=0;
//         while(i<nums.size()){
//             if(nums[i]==target)
//             {
//             ans.push_back(i);
//             }
//             i++;
//         }
//         // sort(ans.begin(),ans.end());
//         return ans;
//     }
// };