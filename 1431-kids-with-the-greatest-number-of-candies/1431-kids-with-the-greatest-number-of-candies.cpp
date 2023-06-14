class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx=INT_MIN;
        for(int i=0;i<candies.size();i++){
            mx=max(candies[i],mx);
        }
        //mx have maximum value here
        vector<bool> ans;
        for(int i=0;i<candies.size();i++){
            if((candies[i]+extraCandies)>=mx){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};