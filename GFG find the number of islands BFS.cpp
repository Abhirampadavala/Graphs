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
  

    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        queue<pair<int,int>>q;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='L')
                {
                    grid[i][j]='P';
                    count++;
                    q.push(make_pair(i,j));
                    
                    while(!q.empty())
                    {
                        int x=q.front().first;
                        int y=q.front().second;
                        q.pop();
                        
            for(int k=0;k<8;k++)
      {
         if(valid(x+rows[k],y+cols[k],n,m) && grid[x+rows[k]][y+cols[k]]=='L') 
         {
             grid[x+rows[k]][y+cols[k]]='P';
             q.push(make_pair(x+rows[k],y+cols[k]));
         }
      }
                        
                    }
                }
            }
        }
        return count;
    }
};
