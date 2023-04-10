// class Solution {
// public:
//     vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
//         int m = mat.size() , n= mat[0].size();
//         vector<vector<int>>v(r,vector<int>(c));
//         queue<int>q;
//         if(m*n == r*c){
//             for(int i=0;i<m;i++){
//                 for(int j=0;j<n;j++){
//                     q.push(mat[i][j]);
//                 }
//             }
//             for(int i=0;i<r;i++){
//                 for(int j=0;j<c;j++){
//                     v[i][j] = q.front();
//                     q.pop();
//                 }
//             }
//             return v;
//         }
//         return mat;
//     }
// };
// 

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int n = nums.size(), m = nums[0].size();
        if (n * m != r * c) return nums;
        vector<vector<int>> ans(r, vector<int>(c));
        for (int i = 0; i < r * c; i++) 
        ans[i/c][i%c] = nums[i/m][i%m];
        return ans;
    }
};