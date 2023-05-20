// https://www.youtube.com/watch?v=nztc9MKaask&ab_channel=CodewithAlisha
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int i;
        priority_queue<int,vector<int>> pq;
        for(int i=0;i<heights.size()-1;i++)
        {
            int difference = heights[i+1]-heights[i];
            if(difference>0){
                //have to use a brick or ladder now
                bricks-=difference;
                pq.push(difference);
                if(bricks<0)
                {
                    if(ladders<=0)return i;
                    int getbackbricks=pq.top(); //Highest element till now who took bricks previously will choose some ladder and give back the bricks it took previously
                    bricks+=getbackbricks=pq.top();
                    ladders--;
                    pq.pop();
                }
            }
        }
        return i; //reached all the values even before getting to the end;
    }
};