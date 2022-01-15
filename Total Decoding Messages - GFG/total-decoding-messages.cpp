// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {

	public:
	int m=pow(10,9) + 7;
		int CountWays(string str){
		    // Code here
		  if(str.length()==0 || str[0]=='0' )
		    return 0;
		  if(str.length()==1)
		    return 1;
		    
		  int count1=1,count2=1;
		  for(int i=1;i<str.length();i++)
		  {
		      int d=str[i]-'0';
		      int dd=(str[i-1]-'0')*10+d;
		      
		      int count=0;
		      
		      if(d>0)
		        count+=count2; 
		      if(dd>=10 && dd<=26)
		        count+=count1;
		      
		      count1=count2%m; // prev to prev
		      count2=count%m; // count2 prev sol
		        
		  }
		  return count2%m;
		  
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends