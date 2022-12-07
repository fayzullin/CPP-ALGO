class Solution {
public:

    Solution() : result(1) {}

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        generateSubset(nums, 0, 0, false);
        return result;
    }

private:
    void generateSubset(const vector<int>& nums, size_t currSubsetInd, size_t currPos, bool skippedPrev)
    {
        if (currPos == nums.size())
        {
            return;
        }

        generateSubset(nums, currSubsetInd, currPos + 1, true);

        if (currPos != 0 && nums[currPos] == nums[currPos - 1] && skippedPrev)
        {
            return;
        }

        result.push_back(result[currSubsetInd]);
        result.back().push_back(nums[currPos]);
        generateSubset(nums, result.size() - 1, currPos + 1, false);
    }

private:
    vector<vector<int>> result;
};
