// For reference:
// https://www.youtube.com/watch?v=77KQifr--ek&ab_channel=AyushiSharma
class Solution {
    void helper(int index,int sum,int n,vector<vector<int>> &ans,vector<int> &ans2,int k){
        //base case
        if(sum==n && k==0){
            ans.push_back(ans2);
            return;
        }
            if(sum>n){
                return;
            }
            for(int i=index;i<=9;i++){//Here we started i with index so that we can follow the at most one conditions
            if(i>n){
                break;
            }
            ans2.push_back(i);
            helper(i+1,sum+i,n,ans,ans2,k-1);
            ans2.pop_back(); //Backtracking in the case of false cases
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ans2;
        vector<vector<int>> ans;
        helper(1,0,n,ans,ans2,k);
        return ans;
    }
};