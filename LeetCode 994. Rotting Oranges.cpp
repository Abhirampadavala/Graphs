class Solution {
public:
    int rows[4]={0,1,-1,0};
    int cols[4]={1,0,0,-1};
    bool valid(int i,int j,int n,int m)
    {
        if(i<n && i>=0 && j>=0 && j<m)
       {
        return 1;
       }
        return 0;
    }

    

    int orangesRotting(vector<vector<int>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        int timer=0;
        int fresh=0;
      
      //traversing along the grid , if i find rot orange put its coord in q
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++)
        {
          if(grid[i][j]==2)
          {
             q.push({i,j});
          } 
          if(grid[i][j]==1) fresh++;
        }
      } 
      
     //also counting number of fresh oranges in the grid, if initially zero then return -1
      if(fresh==0) return 0;
      
      while(!q.empty())
      {
        int curr_path=q.size();
        while(curr_path--)
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int k=0;k<4;k++ )
            {
             if(valid(x+rows[k],y+cols[k],n,m) && grid[x+rows[k]][y+cols[k]]==1)
             {
                 grid[x+rows[k]][y+cols[k]]=2;
                 q.push({x+rows[k],y+cols[k]});
             }
            }
        }
        timer++;
      }

     //After BFS now checking whether any fresh ornage left, if present return -1
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==1)
            return -1;
        }
      }

      return timer-1; 
    }
};
