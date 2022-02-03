// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    void solve(string str , int n, int k, string& ans,int index)
    {
        if(k==0)
            return;
        
        char maxchar=str[index];
        for(int i=index+1;i<n;i++)
        {
            if(maxchar<str[i])
                maxchar=str[i];
        }
        
        if(maxchar!=str[index])
            k--;
        
        for(int i=n-1;i>=index;i--)
        {
            if(str[i]==maxchar)
            {
                swap(str[i],str[index]);
               
                
                if(ans<str)
                    ans=str;
                
                solve(str,n,k,ans,index+1);
                
                swap(str[i],str[index]);
            }
        }
    }
    string findMaximumNum(string str, int k)
    {
       string ans=str;
       solve(str,str.length(),k,ans,0);
       return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends