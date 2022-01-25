// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        vector<vector<int>>ans;
        
        if(arr.size()==0)
            return ans;
        
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<arr.size();i++)
        {
            for(int j=i+1;j<arr.size();j++)
            {
                int target=k-arr[i]-arr[j];
                int front=j+1;
                int end=arr.size()-1;
                
                while(front<end)
                {
                    int two_sum=arr[front]+arr[end];
                    
                    if(two_sum<target)
                        front++;
                    else if(two_sum>target)
                        end--;
                    else
                    {
                        vector<int>v;
                        v.push_back(arr[i]);
                        v.push_back(arr[j]);
                        v.push_back(arr[front]);
                        v.push_back(arr[end]);
                        ans.push_back(v);
                        
                        // processing duplicates
                        while(front<end && arr[front]==v[2])
                            front++;
                        
                        while(front<end && arr[front]==v[3])
                            end--;
                    }
                }
                
                while(j+1<arr.size() && arr[j+1]==arr[j])
                    j++;
            }
            
            while(i+1<arr.size() && arr[i+1]==arr[i])
                    i++;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends