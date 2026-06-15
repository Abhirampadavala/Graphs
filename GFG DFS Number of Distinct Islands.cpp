// User function Template for C++

class Solution {
  public:
  
  int rows[4]={-1,0,1,0};
  int cols[4]={0,1,0,-1};
  
  bool valid(int p, int q, int m, int n)
  {
      if(p>-1 && p<m && q>-1 && q<n) return 1;
      else return 0;
  }
  
  void DFS(int i,int j,int p,int q,vector<vector<int>>& grid,vector<pair<int,int>>&current,vector<vector<int>>&vis)
  {
      vis[i][j]=1;
      current.push_back(make_pair(i-p,j-q));
      for(int x=0;x<4;x++)
      {
          if (valid(i+rows[x],j+cols[x],grid.size(),grid[0].size()) && !vis[i+rows[x]][j+cols[x]] && grid[i+rows[x]][j+cols[x]] == 1)
          DFS(i+rows[x],j+cols[x],p,q,grid,current,vis);
      }
  }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        //getting the size of rows and columns
        int m=grid.size();
        if(m==0) return 0;
        int n=grid[0].size();
        //using a set since it stores only unique values, so duplicate values will be not stored
        //each set will store the vector of pair of integers which are relative coordinates of an island
        set<vector<pair<int,int>>>s;
        //vis 2D matrix to check 
        vector<vector<int>>vis(m,vector<int>(n,0));
        
        
        //traverse along the 2D vector
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
             if(!vis[i][j] && grid[i][j]==1)
             {
                 vector<pair<int,int>>current;
                 DFS(i,j,i,j,grid,current,vis);
                 s.insert(current);
             }
            }   
        }
        
        return s.size();
    }
};
