class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int sum = 0;
        int limit = tickets[k];
        int idx = 0;

        while (idx != k + 1)
            sum += min(tickets[idx++], limit);

        limit--;

        while (idx != tickets.size())
            sum += min(tickets[idx++], limit);

        return sum;
    }
};