class Solution {
public:
    double calculateEntropy(vector<int>& input) {
        if (input.empty()) return 0.0;
        unordered_map<int, int> mylist;
        unordered_map<int, int>::iterator it;
        int size = input.size();
        for (int i = 0; i<size; i++)
        {
            it = mylist.find(input[i]);            
            if (it != mylist.end())
                it->second++;            
            else
                mylist.insert(std::make_pair(input[i], 1));
                
        }
        
        double entropy = 0.0;
        it = mylist.begin();
        while (it != mylist.end())
        {
            double prob = (double)it->second/(double)size;
            entropy -= prob*log2(prob);
            it++;
        }
        return entropy;
    }
};