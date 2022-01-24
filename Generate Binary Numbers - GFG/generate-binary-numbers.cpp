// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

//Function to generate binary numbers from 1 to N using a queue.
vector<string> generate(int N)
{
	queue<string>nums;
	vector<string>ans;
	
	nums.push("1");
	
	for(int i=1;i<=N;i++){
	    string temp=nums.front();
	    ans.push_back(temp);
	    nums.pop();
	    nums.push(temp+"0");
	    nums.push(temp+"1");
	}
	return ans;
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends