class Solution {
public:
    int findTheWinner(int n, int k)
    {
        queue<int> numbers;
    
    	for(int i = 1; i <= n; ++i)
            numbers.push(i);

        while(numbers.size() != 1)
        {
            for(int i = 1; i < k; ++i)
	    {
                numbers.push(numbers.front());
                numbers.pop();
            }
            numbers.pop();
        }

        return numbers.front();
    }
};
