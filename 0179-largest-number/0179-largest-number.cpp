// https://www.youtube.com/watch?v=h1n-CYIyZ5k
class Solution {
public:
static bool check(string &s1,string &s2){
    return (s1+s2)>=(s2+s1);
}
    string largestNumber(vector<int>& nums) {
        //if all the elements are o then return o
        int x=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                x++;
            }
        }
        if(x==nums.size()) return "0";
        vector<string> s(nums.size(),"");
        for(int i=0;i<nums.size();i++){
            s[i]=to_string(nums[i]);
        }

        //now sort using custom comparator
        sort(s.begin(),s.end(),check);
        //append the ans of sorted array in an variable
        string ans = "";
        for(int i=0;i<s.size();i++){
            ans+=s[i];
        }
        return ans;
    }
};