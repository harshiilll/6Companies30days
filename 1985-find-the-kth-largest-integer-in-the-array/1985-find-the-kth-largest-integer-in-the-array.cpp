class Solution {
public:
  string kthLargestNumber(vector<string>& nums, int k) {    
    nth_element(begin(nums), begin(nums) + k - 1, end(nums), [](const auto& a, const auto& b) {
      return a.length() == b.length() ? a > b : a.length() > b.length();      
    });
    return nums[k - 1];
  }
};