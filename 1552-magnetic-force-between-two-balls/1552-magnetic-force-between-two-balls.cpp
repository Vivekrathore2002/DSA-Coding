class Solution {
public:
    int n, c;
    vector<int> a;

    bool check(int k)
    {
        int cows = 1;
        int lt = 0;
        for(int i=1; i<n; i++) {
            if(a[i] - a[lt] >= k) {
                lt = i;
                cows++;
                if(cows == c) return true;
            }
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        a = position;
        n = a.size();
        c = m;
        sort(a.begin(), a.end());
        int l = 0;
        int r = a[n-1] - a[0];

        while(l <= r) {
            int mid = (l + r) /2;
            if(check(mid)) l = mid + 1;
            else r = mid - 1;
        }
        return l - 1;
    }
};