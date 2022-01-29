// { Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{
  public:
  
    vector<string> winner(string arr[],int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        vector<string>ans;
        
        
        string name="";
        int vote=0;
        
        map<string,int>m;
        for(int i=0;i<n;i++)
            m[arr[i]]++;
            
        int maxi=INT_MIN;
        for(auto x:m)
        {
            if(x.second>maxi)
            {
                maxi=x.second;
                name=x.first;
                vote=x.second;
            }
        }
       
        ans.push_back(name);
        ans.push_back(to_string(vote));
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}
  // } Driver Code Ends