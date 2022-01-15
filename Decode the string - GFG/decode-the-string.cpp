// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            
            if (s[i] == ']') {
                string temp;
                while (!st.empty() && st.top() != '[') {
                    temp = st.top()+temp;
                    st.pop();
                }
                
                st.pop();
                
                string num;
                while (!st.empty() && isdigit(st.top())) {
                    num = st.top()+num;
                    st.pop();
                }
                int number = stoi(num);
                string repeat;
                for (int j = 0; j < number; j++)
                    repeat += temp;
                for (char c : repeat)
                    st.push(c);
            }
            else
                st.push(s[i]);
        }
        string res;
        while (!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends