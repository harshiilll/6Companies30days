// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


 // } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
     #define pipi pair<int, pair<int, int>>
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
        
        priority_queue<pipi, vector<pipi>, greater<pipi>> minheap;
        
        int low = INT_MAX, high = INT_MIN;
        for(int i = 0; i < k; ++i) {
            int val = KSortedArray[i][0];
            low = min(low, val);
            high = max(high, val);
            minheap.push({val, {i, 0} });
        }

        int range = high - low;
        int max_value = high;
        int min_value = low;

        while(true) {
            pipi min_entry = minheap.top(); minheap.pop();

            int new_row = min_entry.second.first;
            int new_col = min_entry.second.second + 1;
            if(new_col >= n) break;

            int new_val = KSortedArray[new_row][new_col];
            minheap.push({new_val, {new_row, new_col}});

            min_value = minheap.top().first;
            max_value = max(max_value, new_val);

            if(max_value - min_value < range) {
                low = min_value;
                high = max_value;
                range = high - low;
            }
        }

        return {low, high};
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

  // } Driver Code Ends