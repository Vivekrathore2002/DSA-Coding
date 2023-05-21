// https://www.youtube.com/watch?v=VEBbumHmps8&ab_channel=KnowledgeCenter
class Solution {
public:
int binary_search(vector<pair<pair<int,int>,int>>& sorted,int x)//& used to not make any copies
{
    int n=sorted.size();
    //The case where,[[1,6],[2,3],[3,4]] will be there in that,
    //for first pair only end(6) is greated already in the whole vector
    //so we return -1
    if(sorted[n-1].first.first<x) return -1;
    //now use binary search here
    int s=0;
    int e=n-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(sorted[mid].first.first>=x)
        e=mid-1; 
        else
        s=mid+1;
    }
    //since while loop executed till s=e, we can say s contains the final ans
    return sorted[s].second; //Gives the index of answer
}
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        //Let's take the example of [[3,4],[2,3],[1,2]]
        vector<pair<pair<int,int>,int>> sorted; //Will store elements like [{3,4},i] where the pair have there index with them so that even when we sort them there correct index will be stored along with them
        int n=intervals.size();
        for(int i=0;i<n;i++)
        {
            sorted.push_back({{intervals[i][0],intervals[i][1]},i});
        }
        //Now sort them
        sort(sorted.begin(),sorted.end());
        vector<int> result(n,-1);
        for(int i=0;i<n;i++){
            result[i]=binary_search(sorted,intervals[i][1]);
        }
        return result;
    }
};