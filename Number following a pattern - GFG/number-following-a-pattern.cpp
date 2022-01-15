// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
       
        string ans="";
        stack<int>s;
        int num=1;
        for(int i=0;i<S.length();i++)
        {
            char ch=S[i];
            
            if(ch=='D')
            {
                s.push(num);
                num++;
            }
            else
            {
                s.push(num);
                num++;
                while(!s.empty())
                {
                    char c=s.top()+'0';
                    ans+=c;
                    s.pop();
                }
            }
        }
        s.push(num);
        while(!s.empty())
        {
            char c=s.top()+'0';
            ans+=c;
            s.pop();        
        }
        return ans;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends