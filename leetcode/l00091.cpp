class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return 0;
        char a[16];
        int i = 0, j = 0;
        while(x){
            a[j++] = x%10;
            x /= 10;
        }
        for(j--;i < j; i++,j--){
            if(a[i] != a[j]) return false;  
        }
        return true;
    }
};
