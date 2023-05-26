class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        deque<int> q;
        for(int i: asteroids)
        {
            if(i > 0)
            {
                q.push_back(i);
            }
            else
            {
                while(q.size() && q.back() > 0 && q.back() < abs(i))
                {
                    q.pop_back();
                }
                if(q.empty())
                {
                    q.push_back(i);
                }
                else
                {
                    if(q.back() > 0 && q.back() == abs(i))
                    q.pop_back();
                    else if(q.back() < 0)
                    q.push_back(i);
                }
            }
        }
        vector<int> ans;
        while(q.size())
        {
            int t = q.front();
            q.pop_front();
            ans.push_back(t);
        }
        return ans;
    }
};