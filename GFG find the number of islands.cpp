class Solution {
  public:
  int rows[8]={-1,0,1,-1,1,-1,0,1};
  int cols[8]={1,1,1,0,0,-1,-1,-1};
  
  bool valid(int p,int q,int n,int m)
  {
      if(p>-1 && p<n && q>-1 && q<m)
      {
          return 1;
      }
      else return 0;
  }
  
  void DFS(int i,int j,int n,int m,vector<vector<char>>& grid)
  {
      for(int k=0;k<8;k++)
      {
         if(valid(i+rows[k],j+cols[k],n,m) && grid[i+rows[k]][j+cols[k]]=='L') 
         {
             grid[i+rows[k]][j+cols[k]]='P';
             DFS(i+rows[k],j+cols[k],n,m,grid);
         }
      }
  }
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='L')
                {
                    grid[i][j]='P';
                    count++;
                    DFS(i,j,n,m,grid);
                }
            }
        }
        return count;
    }
};
