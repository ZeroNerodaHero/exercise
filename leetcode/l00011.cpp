class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> v(2);
        int ar[n];
        for(int i = 0; i < n; i++) ar[i] = i;
        sort(ar,ar+n,[&](int a,int b){ return nums[a] < nums[b];});
        for(int i = 0, j = n-1; i < j;){
            if(nums[ar[i]] + nums[ar[j]] == target){
                v[0] = ar[i], v[1]= ar[j];
                break;
            }
            else if(nums[ar[i]] + nums[ar[j]] < target) i++;
            else j--;
        }
        return v;
    }
    
};
