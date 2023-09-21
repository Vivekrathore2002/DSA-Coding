// 1st method
// class Solution {
// public:
//     bool isNStraightHand(vector<int>& hand, int groupSize) {
//         int n = hand.size();

//         // Check if it's possible to divide the hand into groups of size groupSize
//         if (n % groupSize != 0) {
//             return false;
//         }

//         // Sort the hand in ascending order
//         sort(hand.begin(), hand.end());

//         unordered_map<int, int> mp;

//         for (int card : hand) {
//             mp[card]++;
//         }

//         for (int i = 0; i < n; i++) {
//             if (mp[hand[i]] > 0) 
//             {
//                 for (int j = hand[i]; j < hand[i] + groupSize; j++)
//                 {
//                     if (mp.find(j) == mp.end() || mp[j] == 0)
//                     {
//                         return false;
//                     }
//                     mp[j]--;
//                 }
//             }
//         }

//         return true;
//     }
// };


// 2nd method
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        map<int,int> mp;
        for(auto x: hand){
            mp[x]++;
        }
        int num = -1;
        while(true){
            num=mp.begin()->first;
            int c = 0;
            while(c<groupSize){
                if(mp[num]==0){
                    return false;
                }
                mp[num]--;
                if(mp[num]==0) mp.erase(num);
                num++;
                c++;
            }
            if(mp.size()==0) break;
        }
        return true;
    }
};
