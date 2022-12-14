std::vector<int> twoSum(std::vector<int>& nums, int target)
{
    std::vector<int> result;

    std::unordered_map<int,int> uMap;

    for (int i = 0; i < nums.size(); ++i)
    {
        if (uMap.count(target - nums[i]))
        {
            result.push_back(i);
            result.push_back(uMap[target-nums[i]]);
            break;
        }
        uMap[nums[i]] = i;
    }

    return result;
}
