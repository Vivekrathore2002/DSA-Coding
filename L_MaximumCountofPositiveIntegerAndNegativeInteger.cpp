// class Solution {
// public:
//     int maximumCount(vector<int>& nums) {
//         int cnt1=0;
//         int cnt2=0;
//         int ans;
//         int n = nums.size();
//         for(int i=0;i<n;i++){
//             if(nums[i]<0){
//                 cnt2++;
//             }
//             else if(nums[i]>0){
//                 cnt1++;
//             }
//             else{
//             }
//         }
//         ans=max(cnt1,cnt2);
//         return ans;
//     }
// };