std::vector<int> twoOutOfThree(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& nums3)
{
    std::vector<int> result;

    for (int i : nums1)
        if (std::find(nums2.begin(),nums2.end(),i) != nums2.end() ||
            std::find(nums3.begin(),nums3.end(),i) != nums3.end())
                result.push_back(i);

    for (int i : nums2)
        if (std::find(nums3.begin(),nums3.end(),i) != nums3.end())
            result.push_back(i);

    std::sort(result.begin(), result.end());
    result.erase(std::unique(result.begin(),result.end()),result.end());
    return result;
}
