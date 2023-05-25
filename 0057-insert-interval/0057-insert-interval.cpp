class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        vector<vector<int>> ans;
        intervals.push_back( newInterval );
        int size = intervals.size();
        sort( intervals.begin() , intervals.end() );
        for( int i = 0 ; i < size ; i++ )
        {
            if( ans.size() == 0 )
            {
                ans.push_back( intervals[i] );
            }
            else
            {
                vector<int> &prev = ans.back();
                int curr_first = intervals[i][0] , curr_second = intervals[i][1] ;
                int prev_first = prev[0] , prev_second = prev[1] ;
                if( prev_second >= curr_first )
                {
                    prev[1] = max( curr_second , prev_second );
                }
                else
                {
                    ans.push_back( intervals[i] );
                }
            }
        }
        return ans;
    }
};