// //Striver Solution
// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         vector<vector<int>> mergedIntervals;
//         if(intervals.size() == 0) {
//             return mergedIntervals; 
//         }
//         sort(intervals.begin(), intervals.end());
//         vector<int> tempInterval = intervals[0]; 
        
//         for(auto it : intervals) {
//             if(it[0] <= tempInterval[1]) {
//                 tempInterval[1] = max(it[1], tempInterval[1]); 
//             } else {
//                 mergedIntervals.push_back(tempInterval); 
//                 tempInterval = it; 
//             }
//         }
//         mergedIntervals.push_back(tempInterval);
//         return mergedIntervals; 
//     }
// };



class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int n=intervals.size();
        for(int i=0;i<n;i++){
            if(ans.empty()){
                ans.push_back(intervals[i]); //[1,4]       [3,6] == [1,6]
            }
            else{
                vector<int>&v=ans.back();
                int y=v[1];
                //Overlapping
                if(intervals[i][0]<=y){
                    v[1]=max(y,intervals[i][1]);
                }
                //notOverlapping
                else{
                    ans.push_back(intervals[i]);
                }
            }
        }
        return ans;

    }
};