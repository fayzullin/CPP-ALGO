class Solution {
public:
    vector<string> generateParenthesis(int n) {
        generateParenthesisImpl(n, 0, 0, string{});
        return result;
    }

private:
    void generateParenthesisImpl(int n, int currPos, int left_minus_right, string currComb)
    {
        if (currPos == 2 * n && left_minus_right == 0)
        {
            result.push_back(std::move(currComb));
        }

        if (left_minus_right < 2 * n - currPos)
        {
            generateParenthesisImpl(n, currPos + 1, left_minus_right + 1, currComb + '(');
        }

        if (left_minus_right > 0)
        {
            generateParenthesisImpl(n, currPos + 1, left_minus_right - 1, currComb + ')');
        }
    }

private:
    vector<string> result;
};