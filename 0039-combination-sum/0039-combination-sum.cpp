class Solution {
public:
void  Sum(vector<int>& candidates,int target, vector<vector<int>> &result,vector<int> &r,int i){
    if(target==0){
        //if we got the exact answer
        result.push_back(r);
        return;
    }
    while(i <  candidates.size() && target - candidates[i] >= 0)
    {
        // Till every element in the array starting
        // from i which can contribute to the target
        r.push_back(candidates[i]);// add them to vector
        // recur for next numbers
        Sum(candidates,target - candidates[i],result,r,i);
        i++;
        // Remove number from vector (backtracking)
        r.pop_back();
    }

}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end()); // sort candidates array
        
        // remove duplicates
        candidates.erase(unique(candidates.begin(),candidates.end()),candidates.end());
        vector<int> r;
        vector<vector<int>> result;
        Sum(candidates,target,result,r,0);
        return result;
    }
};