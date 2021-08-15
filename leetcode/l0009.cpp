class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return 0;
        long long z= x, y = 0;
        while(x){
            y = y * 10 + x%10;
            x /= 10;
        }
        return z == y;
    }
};
