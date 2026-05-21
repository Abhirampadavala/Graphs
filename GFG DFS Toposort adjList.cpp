class Solution {
  public:
  
    void DFS(int node,vector<vector<int>>& edges,vector<int>&visited,stack<int>&s)
    {
        visited[node]=1;
        for(int j=0;j<edges[node].size();j++)
        {
            if(!visited[adj[node][j]])
            DFS(edges[node][j],edges,visited,s);
        }
        s.push(node); 
    }
  
  
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>visited(V,0);
        stack<int>s;
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            DFS(i,edges,visited,s);
        }
        
        vector<int>ans;
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        
        return ans;
        
    }
};
