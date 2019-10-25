#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){
		std::vector<int> res;	//结果数组
		std::vector<int> idx(nums.size(), 0);  //位置数组

		int val = 0;
		std::for_each(idx.begin(), idx.end(), [&val](int &v){
			v = val++;
		}); //位置数组初始化

		std::sort(idx.begin(), idx.end(), [&nums](int l, int r){
			return nums[l]  < nums[r];
		});	//根据nums数组大小对位置数组进行排序

		//std::for_each(idx.begin(),idx.end(),[&nums](int id){     cout << nums[id]<< " "; });
		for (int i = 0, j = nums.size()-1; i < j;){
			int sum = nums[idx[i]] + nums[idx[j]];
			if (sum == target){
				res.push_back(idx[i]);
				res.push_back(idx[j]);
				++i;
				--j;
			}else if( sum < target){
				++i;
			}else{
				--j;
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