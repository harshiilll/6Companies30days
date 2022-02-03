/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int length=mountainArr.length();
        
        // find the peak
        int left=0,right=length-1,peak=0;
        while(left<right)
        {
            int mid=(right+left)/2;
            if (mountainArr.get(mid)<mountainArr.get(mid+1))
            {
                left=mid+1;
                peak=mid+1;
            }
            else
                right=mid;
        }
        
        // search left side of array:
        left=0;
        right=peak;
        while(left<=right)
        {
            int midInd=(right+left)/2;
            int midNum=mountainArr.get(midInd);
            if(midNum==target)
                return midInd;
            else if(midNum<target)
                left=midInd+1;
            else if(midNum>target)
                right=midInd-1;
        }
        
        // search right side of array
        left=peak+1;
        right=length-1;
        while(left<=right)
        {
            int midInd=(right+left)/2;
            int midNum=mountainArr.get(midInd);
            if(midNum==target)
                return midInd;
            else if(midNum<target)
                right=midInd-1;
            else if(midNum>target)
                left=midInd+1;
        }
        
        // if not found
        return -1;
    }
};