class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> fewest_number(amount + 1, BIG_NUM);
        fewest_number[0] = 0;
        
        for (long long int curr_amount = 0; curr_amount <= amount; ++curr_amount)
        {
            for (auto coin : coins)
            {
                long long int curr_amount_plus_coin = curr_amount + coin;
                
                if (curr_amount_plus_coin > amount) 
                { 
                    continue; 
                }
                
                if (fewest_number[curr_amount] + 1 < fewest_number[curr_amount_plus_coin])
                {
                    fewest_number[curr_amount_plus_coin] = fewest_number[curr_amount] + 1;
                }
            }
        }
        
        return fewest_number[amount] == BIG_NUM ? -1 : fewest_number[amount];
    }
    
private:
    const int BIG_NUM = 10001;
};