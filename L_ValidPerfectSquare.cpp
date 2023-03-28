// class Solution {
// public:
//     bool isPerfectSquare(int num) {
//         int l=0;
//         int h=num;
//         while(l<=h){
//         long long int mid=l+(h-l)/2;
//         long long int sq=mid*mid;
//             if(sq==num){
//                 return true;
//             }
//             else if(sq<num){
//                 l=mid+1;
//             }
//             else{
//                 h=mid-1;
//             }
//         }
//         return false;
//     }
// };