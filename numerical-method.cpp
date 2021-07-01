
//=============================================
// Add two int, check for overflow
// doesn't mod result if it does overflow
// return -1: overflow
// return 0; no overflow

int addOvf(int* result, int a, int b) 
{ 
    // INT_MAX - b provides us maximum that 'a' can be if there is no overflow
    if( a > INT_MAX - b)
        return -1; 
    else
    { 
        *result = a + b; 
        return 0; 
    } 
}


//===============================================
// Add two int, check for overflow
// Will mod result even when there is overflow
//
//
int addOvf(int* result, int a, int b) 
{ 
    *result = a + b;
    // when both `a` and `b` are positive, there is no way result will be negative
    if(a > 0 && b > 0 && *result < 0) 
        return -1; 
    // vice versa
    if(a < 0 && b < 0 && *result > 0) 
        return -1; 
    return 0; 
} 

//================================================
// return reversed of input integer
    int reverse(int x) {
        int ans = 0;
        while (x) {
            int temp = ans * 10 + x % 10;
            if (temp / 10 != ans)
                return 0;
            ans = temp;
            x /= 10;
        }
        return ans;
    }

//=======================================================================================================================
//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//You can return the answer in any order.
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Output: Because nums[0] + nums[1] == 9, we return [0, 1].
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // map of target - nums : index
        // [7,2,3,4] 9
        // map 7:0, 2:1, 3:2, 4:3
        
        // look for 9-7 = 2;
        // map.find(2)->second -> 1;
       
        vector<int> v;
        map<int,int> index;
        for(int i=0; i<nums.size(); i++) {
            index[nums[i]] = i;
        }
        
        for(int i=0; i<nums.size(); i++) {
            auto iter = index.find(target - nums[i]);
            if(iter != index.end()) {
                if ( i != iter->second ) {
                  v.push_back(i);
                  v.push_back(iter->second);
                  return v;
                }
            }
        }
        return v;
    }
};
