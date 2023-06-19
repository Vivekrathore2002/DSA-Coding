class Solution
{
public:
    long long totalCost(vector<int> &costs, int k, int m)
    {
        long long ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;
        int n = costs.size();
        int i = 0, j = n - 1;
        while (i < n && i < m)//make prefix queue to get minimum element from prefix
        {
            pq1.push(costs[i++]);
        }
        while (j >= i && j >= n - m)//make suffix queue to get minimum element from suffix
        {
            pq2.push(costs[j--]);
        }
        // cout << pq1.size() << " " << pq2.size() << endl;
        // cout<<"#\n";
        while (k--)//repeat k time
        {
            if (!pq1.empty() && !pq2.empty())//both queue are not empty
            {
                if (pq1.top() < pq2.top())//pq1 have minimum cost so hire this employee add new emplyee's cost into prefix min heap
                {
                    ans += pq1.top();
                    // cout << pq1.top() << " ";
                    pq1.pop();
                    if (i <= j)
                    {
                        pq1.push(costs[i++]);
                    }
                }
                else if (pq1.top() > pq2.top())//pq2 have minimum cost so hire this employee add new emplyee's cost into suffix min heap
                {
                    ans += pq2.top();
                    // cout << pq2.top() << " ";
                    pq2.pop();
                    if (i <= j)
                    {
                        pq2.push(costs[j--]);
                    }
                }
                else//if pq1 and pq2 both have hiring cost same fo hire from pq1(given in question)
                {
                    ans += pq1.top();
                    // cout << pq1.top() << " ";
                    pq1.pop();
                    if (i <= j)
                    {
                        pq1.push(costs[i++]);
                    }
                }
            }
            else if (pq1.empty())//if we hired all employee from prefix than queue than hring is possible from pq2
            {
                ans += pq2.top();
                // cout << pq2.top() << " ";
                pq2.pop();
                if (i <= j)
                {
                    pq2.push(costs[j--]);
                }
            }
            else//if we hired all employee from suffix than queue than hring is possible from pq1
            {
                ans += pq1.top();
                // cout << pq1.top() << " ";
                pq1.pop();
                if (i <= j)
                {
                    pq1.push(costs[i++]);
                }
            }
        }
        // cout<<"#\n";
        return ans;
    }
};