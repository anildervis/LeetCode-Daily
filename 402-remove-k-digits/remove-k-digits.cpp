class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.size() == k) return "0";
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        string res = "";
        int last = -1, end = k;

        for (int i = 0; i < k + 1 and i < num.size(); i++)
            pq.push({num[i], i});

        while (k >= 0 and last != num.size() - 1)
        {
            while (!pq.empty() and pq.top().second < last)
                pq.pop();
            res += num[pq.top().second];
            k -= pq.top().second - last - 1;
            last = pq.top().second;
            pq.pop();
            if (++end < num.size())
                pq.push({num[end], end});
        }

        if (end < num.size())
            res += num.substr(end, num.size() - end);

        int zero_count = -1;
        while (res[++zero_count] == '0');
        if (res.size() == zero_count) return "0";
        res = res.substr(zero_count, res.size() - zero_count);

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype([](pair<int, int>& a, pair<int, int>& b){return a.first == b.first ? a.second < b.second : a.first < b.first;})> pq2;

        for (int i = 0; i < res.size(); i++)
            pq2.push({res[i], i});

        while (k-- > 0)
        {
            res.erase(pq2.top().second, 1);
            pq2.pop();
        }

        return res.size() == 0 ? "0" : res;
    }
};