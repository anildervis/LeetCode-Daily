class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        vector<int> ans(deck.size());
        queue<int> q;
        for (int i = 0; i < deck.size(); i++)
            q.push(i);

        int idx = 0;
        while (!q.empty())
        {
            ans[q.front()] = deck[idx++]; 
            q.pop();
            if (!q.empty())
            {
                q.push(q.front());
                q.pop();
            }
        }

        return ans;
    }
};