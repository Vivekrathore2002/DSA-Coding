// class Solution {
// public:
//     int findContentChildren(vector<int>& g, vector<int>& s) {
//         int n1=g.size();
//         sort(g.begin(),g.end());
//         sort(s.begin(),s.end());
//         int n2=s.size();
//         int i=0;
//         int j=0;
//         int count=0;
//         // int ans=0;
//         while(j<n1 && i<n2){
//             if((s[i])>=g[j]){
//                 g[j]=s[i]-g[j];
//                 count++;
//                 i++;
//                 j++;
//             }
//             else if(s[i]<g[j]){
//                 i++;
//                 // ans=0;
//                 // if(i==n2-1){
//                 //     j++;
//                 // }
//                 // else if(j==n1-1){
//                 //     i++;
//                 // }
//                 // else if(j==n1-1 && i==n2-1){
//                 //     i=0;
//                 // }
//             }
//         }
//         return count;
//     }
// };