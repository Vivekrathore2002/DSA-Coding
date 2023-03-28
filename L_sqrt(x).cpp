// class Solution {
// public:
//     int mySqrt(int x) {
//         int l=0;
//         int h=x;
//         int ans;
//         while(l<=h){
//             long int mid=l+(h-l)/2;
//             long int sq=mid*mid;
//             if(sq==x){
//                 // l=mid+1;
//                 ans=mid;
//                 return ans;
//                 // break;
//                 // mid=l+(h-l)/2;
//             }
//             else if(sq<x){
//                 l=mid+1;
//                 // mid=l+(h-l)/2;
//             }
//             else{
//                 h=mid-1;
//                 // break;
//             }
//         }
//         return ans;
//     }
// };