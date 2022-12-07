class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if ((s1.size() + s2.size() != s3.size())) { return false; }
        
        // add dummy elements to the start of strings to get numeration from 1 not 0
        s1 = " " + s1;
        s2 = " " + s2;
        s3 = " " + s3;
        
        vector<vector<bool>> interleaveMatrix(s1.size(), vector<bool>(s2.size(), false));
        
        for (int i = 0; i < s1.size(); ++i)
        {
            for (int j = 0; j < s2.size(); ++j)
            {
                if (i == 0 && j == 0)
                {
                    interleaveMatrix[0][0] = true;
                    continue;
                }
                else if (i == 0)
                {
                    interleaveMatrix[i][j] = interleaveMatrix[i][j - 1] && s3[i + j] == s2[j];
                }
                else if (j == 0)
                {
                    interleaveMatrix[i][j] = interleaveMatrix[i - 1][j] && s3[i + j] == s1[i];
                }
                else
                {
                    interleaveMatrix[i][j] = (interleaveMatrix[i][j - 1] && s3[i + j] == s2[j]) ||
                                             (interleaveMatrix[i - 1][j] && s3[i + j] == s1[i]);
                }
            }
        }
        
        return interleaveMatrix[s1.size() - 1][s2.size() - 1];
    }
};