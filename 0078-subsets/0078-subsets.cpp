// https://youtu.be/rYkfBRtMJr8?si=Yf4eD8-hu2oWwzE6
class Solution {
public:
    void func(int ind,vector<int> sum,vector<int> &arr,int n,vector<vector<int>> &sumSubset){
        if(ind==n){
            sumSubset.push_back(sum);
            return;
        }
        sum.push_back(arr[ind]);
        //pick the element
        func(ind+1,sum,arr,n,sumSubset);
        sum.pop_back();
        //do not pich the element
        func(ind+1,sum,arr,n,sumSubset);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sumSubset;
        vector<int> sum;
        int n=nums.size();
        func(0,sum,nums,n,sumSubset);
        // sort(sumSubset.begin(),sumSubset.end());
        return sumSubset;
    }
};