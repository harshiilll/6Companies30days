// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        
        vector<int> ans;
        int r_i=0;
        int r_t=r-1;
        int c_i=0;
        int c_t=c-1;
        
        int dir=0;
        while(r_i<=r_t && c_i<=c_t)
        {
            if(dir==0)
            {
                for(int i=c_i;i<=c_t;i++)
                    ans.push_back(matrix[r_i][i]);
                
                r_i++;
                dir=1;
            }
            
            else if(dir==1)
            {
                for(int i=r_i;i<=r_t;i++)
                    ans.push_back(matrix[i][c_t]);
                
                c_t--;
                dir=2;
            }
            
            else if(dir==2)
            {
                for(int i=c_t;i>=c_i;i--)
                    ans.push_back(matrix[r_t][i]);
                
                r_t--;
                dir=3;
            }
            
            else if(dir==3)
            {
                for(int i=r_t;i>=r_i;i--)
                    ans.push_back(matrix[i][c_i]);
                
                c_i++;
                dir=0;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends