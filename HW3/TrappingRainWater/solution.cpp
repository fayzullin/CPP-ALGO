class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty())  { return 0; }
        
        int leftInd = 0, rightInd = height.size() - 1;
        int trappedVolume = 0;
        int leftMaxBorder = 0, rightMaxBorder = 0;
        
        while (leftInd < rightInd)
        {
            if (height[leftInd] < height[rightInd])
            {
                if (height[leftInd] > leftMaxBorder)
                {
                    leftMaxBorder = height[leftInd];
                }
                else
                {
                    trappedVolume += leftMaxBorder - height[leftInd];
                }
                ++leftInd;
            }
            else
            {
                if (height[rightInd] > rightMaxBorder)
                {
                    rightMaxBorder = height[rightInd];
                }
                else
                {
                    trappedVolume += rightMaxBorder - height[rightInd];
                }
                --rightInd;
            }
        }
        
        return trappedVolume;
    }
};