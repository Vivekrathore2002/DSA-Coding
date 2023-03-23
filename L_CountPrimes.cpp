// class Solution {
// //     private:
// // bool isPrime(int n){
// //     if(n<=1){
// //         return false;
// //     }
// //     for(int i=2;i<n;i++){
// //         if(n%i==0){
// //             return false;
// //         }
// //     }
// //     return true;
// // }
// public:
//     int countPrimes(int n) {
//         // int cnt=0;
//         // for(int i=2;i<n;i++){
//         //     if(isPrime(i)){
//         //         cnt++;
//         //     }
//         // }
//         // return cnt;
//         //this is not the optimised way to do this problem
//         //so we will use stibe of eratost. theoram where basically all are prime at start and we de select them on the basis of their table 
//         //let's start
//         int cnt=0;
//         vector<bool> prime(n+1,true); //n+1 since we have to exclude last element so if we make it here n then we have to run the loop till n-1,so simply make vector till n+1 so that we dont need it to do that
//         prime[0] = prime[1] = false;
//         for(int i=2;i<n;i++){
//             if(prime[i]){
//                 cnt++;
//             for(int j=2*i;j<n;j=j+i){
//                 prime[j]=0;
//             }
//             }
//         }
//         return cnt;
//     }
// };