/*
1710. Maximum Units on a Truck
You are assigned to put some amount of boxes onto one truck. You are given
a 2D array boxTypes, where boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:

numberOfBoxesi is the number of boxes of type i.
numberOfUnitsPerBoxi is the number of units in each box of the type i.
You are also given an integer truckSize, which is the maximum number of boxes
that can be put on the truck. You can choose any boxes to put on the truck as
long as the number of boxes does not exceed truckSize.

Return the maximum total number of units that can be put on the truck.
*/

class Solution {
public:
    int maximumUnits(std::vector<std::vector<int>>& boxTypes, int truckSize) 
    {
        int result = 0;        
        
        std::sort(boxTypes.begin(), boxTypes.end(),[](auto &v1, auto &v2){
            return v1[1] > v2[1];
        });

        for (const auto &vec : boxTypes)
        {
            int cnt = std::min(vec[0], truckSize);
            truckSize -= cnt;
            result += vec[1] * cnt;
            if (!truckSize)
                break;
        }

        return result;   
    }
};
