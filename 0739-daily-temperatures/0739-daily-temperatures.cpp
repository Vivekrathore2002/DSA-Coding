// https://www.youtube.com/watch?v=7MIXlgBfr_U&list=PLLT4EuYB4kIY2nfXL0sxzHbDHReuMw_sE&ab_channel=CodewithAlisha

// There can be two approaches mainly where 
//   1. 1st is using stack for storing the elements
//   2.
// 1st will be just start from the end of the tempreture and check towards the left side whether the small element have big element at right side or not
// this method will take extra space(o(n))


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        vector<int> ans(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++) {
            while (!s.empty() && temperatures[s.top()] < temperatures[i]) {
                int prevIndex = s.top();
                s.pop();
                ans[prevIndex] = i - prevIndex;
            }
            s.push(i);
        }
        return ans;
    }
};

