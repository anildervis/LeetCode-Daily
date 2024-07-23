class Solution {
public:
    bool isPowerOfTwo(int n) {
        double result=powerTwo(n);
        

        if (result==1)
            return true;
        else if(result<1)
            return false;
        else
            return false;

        
    }
    double powerTwo(double n){
        double result=n;
        if (result==1)
            return result;
        else if(result<1)
            return result;
        else
            return powerTwo(result/2);

    }

};