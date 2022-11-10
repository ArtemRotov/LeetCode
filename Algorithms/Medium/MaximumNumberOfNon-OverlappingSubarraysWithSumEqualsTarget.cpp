int maxNonOverlapping(std::vector<int>& nums, int target)
{
    if (nums.empty())
        return 0;

    int result = 0;
    int sum = 0;
    int left = -1;      // Start of a new subarray
    int right = -1;     // End of last found subarray

    std::unordered_map<int,int> uMap;
    uMap[0] = -1;

    for(int i = 0; i < nums.size(); ++i)
    {
        sum += nums[i];

        if (uMap.count(sum-target))
        {
            left = uMap[sum-target] + 1;
            if (left > right)
            {
                right = i;
                result++;
            }
        }

        uMap[sum] = i;
    }

    return result;
}
