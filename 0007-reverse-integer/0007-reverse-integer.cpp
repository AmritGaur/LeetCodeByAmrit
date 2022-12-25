class Solution {
public:
    int reverse(int x) {
         int digit;
         int rev = 0;
        while(x != 0)
        {
            if((rev > INT_MAX/10 ) || (rev < INT_MIN/10 ))
             return 0;
            digit = x % 10;
            rev = rev * 10 + digit;
            x /= 10;
        }
        return rev;
    }
};