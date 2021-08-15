class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> v(2);
        for(int i = 0; i < nums.size(); i++){
            auto it = m.find(nums[i]);
            if(it != m.end()){
                v[0] = i;
                v[1] = it->second;
                return v;
            }
            m[target-nums[i]] = i;   
        }
        return v;
    }
    
};
