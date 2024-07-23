class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 1) return true;
       else if(n%2 == 0 && n/2 >= 1) return isPowerOfTwo(n/2);
       else return false;
    }
};