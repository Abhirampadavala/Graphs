//DFS of Graph        GFG

class Solution {
  public:
  
  void DFS(int p,int V,vector<vector<int>>& adj,vector<bool>&visited,vector<int>&ans)
        {
        
        ans.push_back(p);
        visited[p]=1;
        
        for(int j=0;j<adj[p].size();j++)
        {
            if(!visited[adj[p][j]])
            {
            DFS(adj[p][j],V,adj,visited,ans);
            }
        }
       
        }
        
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int V=adj.size();
        vector<bool>visited(V,0);
        vector<int>ans;
        int p=0;
        
        DFS(p,V,adj,visited,ans);
         return ans;
        
    }
};
