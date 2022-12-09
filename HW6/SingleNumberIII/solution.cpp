#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_all = 0;
        for (auto num : nums)
        {
            xor_all ^= num;
        }

        // make mask containing single non-zero bit on the same position
        // where the first non-zero bit of `xor_all` is located
        size_t mask = 1;
        while (!(xor_all & 1u))
        {
            xor_all >>= 1u;
            mask <<= 1u;
        }

        // calculate result numbers
        int first = 0;
        int second = 0;
        for (auto num : nums)
        {
            if (num & mask)
            {
                first ^= num;
            }
            else
            {
                second ^= num;
            }
        }

        return {first, second};
    }
};
