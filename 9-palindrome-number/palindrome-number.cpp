class Solution {
public:
    long long pali(int number, long long reverse)
    {
        return (!number ? reverse : pali(number / 10, reverse * 10 + number % 10));
    }
    bool isPalindrome(int x)
    {
        return (x == pali(x, 0) && x >= 0 ? true : false);
    }
};