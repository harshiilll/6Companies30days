// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends

#include <unordered_map>
/*You are required to complete this function */

string encode(string src)
{     
     string ans="";
    int c=1;
    for(int i=0;i<src.length();i++)
    {
        if(src[i]==src[i+1])
            c++;
        else
        {
            ans+=src[i];
            ans+='0'+c;
            c=1;
        }
    }
  return ans;

}     
 
