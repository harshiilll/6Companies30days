class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& prerequisites) {
        vector <int> adj[N]; 
        vector<int>ans;
        for(auto i : prerequisites) 
        {
           adj[i[0]].push_back(i[1]);
        }
         vector<int> indegree(N, 0);
        for(int i = 0; i < N; ++i)
        {
          for(auto it : adj[i]) 
          {
            indegree[it]++;
          }
        }
        
        queue<int> q;
        for(int i = 0; i < N; ++i) 
        {
         if(indegree[i] == 0) {
             q.push(i);
           }
        }
        int count = 0;
        while(!q.empty()) {
            int node = q.front();
            count += 1;
            ans.push_back(node);
            q.pop();
         
        for(auto i : adj[node]) {
             indegree[i]--;
             if(indegree[i] == 0) {
                 q.push(i);
             }
         }
        }
    reverse(ans.begin(),ans.end());
     if(count == N) return ans;
    ans.clear();
     return ans;
    }
};