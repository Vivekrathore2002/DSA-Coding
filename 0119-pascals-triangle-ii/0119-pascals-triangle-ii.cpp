// // 1st code using chatgpt:
// class Solution {
// public:
//     vector<int> getRow(int rowIndex) {
//         vector<int> res(rowIndex+1, 1);
//         for(int i=2;i<=rowIndex;i++){
//             int prev = 1, curr;
//             for(int j=1;j<i;j++){
//                 curr = res[j];
//                 res[j] = prev + curr;
//                 prev = curr;
//             }
//         }
//         return res;
//     }
// };
//Some random youtuber 
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex+1, 1);
        for(int i = 1; i < rowIndex; ++i){
            for(int j = i; j > 0; --j)
                result[j] += result[j-1];
        }
        return result;
    }
};