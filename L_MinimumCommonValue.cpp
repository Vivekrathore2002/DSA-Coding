// class Solution {
// public:
//     int getCommon(vector<int>& nums1, vector<int>& nums2) {
//         // int n1=nums1.size();
//         // int n2=nums2.size();
//         //First method for two for loops concept that passed 34/40 test cases
//         // for(int i=0;i<n1;i++){
//         //     for(int j=0;j<n2;j++){
//         //         if(nums1[i]==nums2[j]){
//         //             return nums1[i];
//         //         }
//         //     }
//         // }
//         // return -1;

//         //Now binary search concept
//         // int s=nums2[0];
//         // int e=nums2[n2-1];
//         // int mid;
//         // if(n2==2){
//         //     mid=e;
//         // }
//         // else{
//         //     mid=s+(e-s)/2;
//         // }
//         // for(int i=0;i<n1;i++){
//             // if(n2==0 || n1==0){
//             //     return -1;
//             // }
//             // else if(n2==1){
//             //     if(nums1[i]!=nums2[n2-1]){
//             //         return nums1[i];
//             //     }
//             //     else{
//             //         return -1;
//             //     }
//             // }
//         //     if(mid<nums1[i]){
//         //         if(n2==2){
//         //             s=mid+1;
//         //             // mid=mid+1;
//         //             mid=s+(e-s)/2;

//         //         }
//         //         else{
//         //         s=mid+1;
//         //         mid=s+(e-s)/2;
//         //         }
//         //     }
//         //     else if(mid>nums1[i]){
//         //         e=mid-1;
//         //         mid=s+(e-s)/2;
//         //     }
//         //     else{
//         //         return nums1[i];
//         //     }
//         // }
//         // return -1;


//         int i=0;
//         int j=0;
//         int a=nums1.size();
//         int b=nums2.size();
//         int ans=-1;
//         while(i<a&&j<b){
//             if(nums1[i]<nums2[j]){
//                 i++;
//             }
//             else if(nums1[i]>nums2[j]){
//                 j++;
//             }
//             else{
//                 ans=nums1[i];
//                 return ans;
//             }
//         }
//         return ans;
//     }
// };