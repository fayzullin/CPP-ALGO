class Solution {
public:
    
    Solution() : result(1) {}
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        generateSubset(nums, {}, 0, false);
        return result;
    }
    
private:
    void generateSubset(vector<int>& nums, vector<int> currSubset, int currPos, bool skippedPrev)
    {
        if (currPos == nums.size())
        {
            return;
        }
        
        vector<int> subsetWithNextElem = currSubset;
        subsetWithNextElem.push_back(nums[currPos]);
        
        generateSubset(nums, std::move(currSubset), currPos + 1, true);
        
        if (currPos != 0 && nums[currPos] == nums[currPos - 1] && skippedPrev)
        {
            return;
        }
        
        result.push_back(subsetWithNextElem);
        generateSubset(nums, std::move(subsetWithNextElem), currPos + 1, false);
    }
    
        
private:
    vector<vector<int>> result;
};