// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    queue<char>q;
		    int freq[26]={0};
		    
		    string ans="";
		    
		    for(int i=0;i<A.length();i++)
		    {
		        q.push(A[i]);
		        
		        freq[A[i]-97]++; // ascii value of 'a' is 97 so to convert it into int form we had to - 97 , so increment freq of each char
		        
		        while(q.size()>0 && freq[q.front()-97]!=1)
		            q.pop();
		            
		        if(q.size()!=0)
		            ans+=q.front();
		        else
		            ans+='#';
		    }
		    
		    return ans;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends