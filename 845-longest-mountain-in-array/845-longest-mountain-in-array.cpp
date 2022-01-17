class Solution {
public:

   int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int large = 0;
        
        for(int i = 1; i<=n-2;){
            
            if(arr[i] > arr[i+1] && arr[i] > arr[i-1]){
                int count = 1;
                int j = i;
                // move backward
                while(j>=1 && arr[j]>arr[j-1]){
                    j--;
                    count++;
                    
                }
                //move forward
                while(i<=n-2 && arr[i] > arr[i+1]){
                    i++;
                    count++;
                }
                large = max(large,count);
            }
            else{
                i++;
            }
            
        }
        return large;
        
    }
};