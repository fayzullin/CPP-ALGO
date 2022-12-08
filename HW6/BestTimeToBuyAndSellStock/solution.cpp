#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prefixMin = MAX_VALUE;
        int prefixProfit = 0;

        for (auto todayPrice : prices)
        {
            if (todayPrice < prefixMin)
            {
                prefixMin = todayPrice;
                continue;
            }

            int possibleProfit = todayPrice - prefixMin;
            if (possibleProfit > prefixProfit)
            {
                prefixProfit = possibleProfit;
            }
        }

        return prefixProfit;
    }

private:
    const int MAX_VALUE = 100'000;
};
