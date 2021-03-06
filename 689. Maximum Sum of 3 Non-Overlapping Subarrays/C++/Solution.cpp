class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k) {
        int length = nums.size();
        vector<int> leftSums(length + 1);
        leftSums[0] = 0;
        for (int i = 0; i < length; i++) {
            leftSums[i + 1] = leftSums[i] + nums[i];
        }
        vector<int> indexLeft(length, 0);
        int currentMax = 0;
        for (int i = k - 1; i < length; i++) {
            if (leftSums[i + 1] - leftSums[i + 1 - k] > currentMax) {
                indexLeft[i] = i + 1 - k;
                currentMax = leftSums[i + 1] - leftSums[i + 1 - k];
            } else {
                indexLeft[i] = indexLeft[i - 1];
            }
        }
        vector<int> indexRight(length, 0);
        currentMax = 0;
        for (int i = length - k; i >= 0; i--) {
            if (leftSums[i + k] - leftSums[i] >= currentMax) {
                indexRight[i] = i;
                currentMax = leftSums[i + k] - leftSums[i];
            } else {
                indexRight[i] = indexRight[i + 1];
            }
        }
        int theMax = 0;
        vector<int> result(3);
        for (int i = k; i <= length - 2 * k; i++) {
            int left = indexLeft[i - 1];
            int right = indexRight[i + k];
            currentMax = leftSums[left + k] - leftSums[left] + leftSums[i + k] - leftSums[i] + leftSums[right + k] -
                         leftSums[right];
            if (currentMax > theMax) {
                result[0] = left;
                result[1] = i;
                result[2] = right;
                theMax = currentMax;
            }
        }
        return result;
    }
};