class Solution {
public:
    vector<vector<int>> permuteUnique(const vector<int>& nums) {
        permutationSize = nums.size();
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        return permuteUniqueImpl(sortedNums);
    }
private:
    int permutationSize;

    // `sortedNums` MUST be sorted. Actually it is enough that
    // all repeated elements go one after another, but sorting is easier to achieve.
    vector<vector<int>> permuteUniqueImpl(const vector<int>& sortedNums)
    {
        vector<vector<int>> permutations;

        if (sortedNums.size() == 1 )
        {
            permutations.push_back(sortedNums);
            permutations.back().reserve(permutationSize);
            return permutations;
        }

        for (int i = 0; i < sortedNums.size(); ++i)
        {
            if (i != 0 && sortedNums[i] == sortedNums[i - 1])
            {
                continue;
            }

            vector<int> less_nums = copy_and_erase(sortedNums, i);
            vector<vector<int>> less_nums_permutations = permuteUniqueImpl(less_nums);

            for (auto& less_nums_permutation : less_nums_permutations)
            {
                less_nums_permutation.push_back(sortedNums[i]);
                permutations.push_back(std::move(less_nums_permutation));
            }
        }

        return permutations;
    }

    vector<int> copy_and_erase(const vector<int>& nums, int pos)
    {
        vector<int> result = nums;
        result.erase(result.begin() + pos);
        return result;
    }
};