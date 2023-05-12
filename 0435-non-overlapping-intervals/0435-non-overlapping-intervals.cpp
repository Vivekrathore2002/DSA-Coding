// https://www.youtube.com/watch?v=evA9Z5p16bI&ab_channel=CodewithAlisha
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // there are mainly three cases possible
        // example [1,5](prev) [8,9](current)
        // 1.NO overlappig - just increase prev and current
        // example [1,5](prev) [3,6](current) 
        // 2.(overlapping but one can not come into another)
        // exmaple [1,5](prev) [2,3](current)
        // 3.[2,3] coming into [1,5]
        // lets start with making prev integer as 0
        //first we have to sort the given vector so that we can compare index by index
        sort(intervals.begin(),intervals.end());
        int prev=0;
        int ans=0; //to store the number of minimised intervals 
        int n=intervals.size();
        for(int current=1;current<n;current++){
            if(intervals[current][0]<intervals[prev][1]){
                ans++;
                //here are both the cases such as [1,5],[3,6] & [1,5][2,3]
                //now for [1,5],[3,6] lets dlt 3,6 for that just increase the current variable which will be done automatically by the loop
                //now for [1,5],[2,3] lets dlt [1,5] for that increase prev and current both
                // so,
                if(intervals[current][1]<=intervals[prev][1]){
                    prev=current;
                }
            }
            //now for no overlapping which is our 3rd case,
            else{
                //just shift prev and current both to iterate the further cases 
                prev=current;
            }
        }
        return ans;
    }
};