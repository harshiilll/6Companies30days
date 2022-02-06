class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1,right=0;
        for(int i=0;i<piles.size();i++)
            right=max(right,piles[i]);
        
        int ans=right;
        while(left<=right)
        {
            int mid=(left+right)/2;
            
            int hours=0;
            for(int i=0;i<piles.size();i++)
                hours+=ceil(1.0 *piles[i]/mid);
            if(hours<=h)
            {
                ans=min(ans,mid);
                right=mid-1;
            }
            else
                left=mid+1;
        }
        return ans;
    }
};