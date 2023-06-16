//With the help of chatgpt
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count the frequency of each number using a map
        unordered_map<int, int> map;
        for (int num : nums) {
            map[num]++;
        }
        // Step 2: Create a priority queue to store the top k frequent numbers
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto it : map) {
            pq.push(make_pair(it.second, it.first));
            // Keep the size of the priority queue <= k
            if (pq.size() > k) {
                pq.pop();
            }
        }
        // Step 3: Retrieve the top k frequent numbers from the priority queue
        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        // Step 4: Reverse the result to get the numbers in descending order of frequency
        reverse(result.begin(), result.end());
        return result;
    }
};

