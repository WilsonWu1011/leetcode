#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> hashmap;
        vector<int> res;
        for(size_t i = 0;i < nums.size();i++){
            hashmap.insert(pair<int,int>(nums[i],i));
        }
        for(size_t i = 0;i < nums.size();i++){
            int remain = target - nums[i];
            if((hashmap.find(remain) != hashmap.end()) &&(hashmap.find(remain)->second != i)){
                res.push_back(i);
                res.push_back(hashmap.find(remain)->second);
                break;
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums {2,7,11,15};
    //const int target = 9;
    const int target = 18;

    Solution solution;
    vector<int> resolution = solution.twoSum(nums,target);
    for(int i = 0;i < resolution.size();i++){
        cout << resolution[i] << " ";
    }
    cout << endl;
    return 0;
}
