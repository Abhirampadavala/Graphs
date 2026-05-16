class Solution {
  public:
  
  vector<pair<int,int>>store;
  int row[4]={0,0,1,-1};
  int col[4]={1,-1,0,0};
  
  bool outsider(int i,int j,int m, int n)
  {
    if((i==0 && j>-1 && j<n)||(i==m-1 && j>-1 && j<n)|| (j==0 && i>-1 && i<m)||(j==n-1 && i>-1 && i<m))  return 1;
    else return 0;
  }
  
  bool valid(int i, int j, int m, int n)
  {
      if(i>-1 && i<m && j>-1 && j<n) return 1;
      else return 0;
  }
  
   void DFS(int i,int j,vector<vector<char>>& grid,int m,int n,int &count)
   {
         store.push_back(make_pair(i,j)); 
             
       for(int k=0;k<4;k++)
       {
         if(valid(i+row[k],j+col[k],m,n) && (grid[i+row[k]][j+col[k]]=='O'))
         {
             grid[i+row[k]][j+col[k]]='V';
             if(outsider(i+row[k],j+col[k],m,n)) count++;
             DFS(i+row[k],j+col[k],grid,m,n,count);

         }
       }
       
   }
  
    void fill(vector<vector<char>>& grid) {
        // Code here
        int m=grid.size();
        int n=grid[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='O')
                {
                    int count=0;
                    if(outsider(i,j,m,n)) count++;
                    store.clear();
                     grid[i][j]='V';
                    DFS(i,j,grid,m,n,count);
                    
                     if(!count) 
                     {
                      for(int k=0;k<store.size();k++)
                      grid[store[k].first][store[k].second]='X';
                     }
                }
            }
        }
        
       
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='V')
                {
                    grid[i][j]='O';
                }
            }
        }
        
    }
};
