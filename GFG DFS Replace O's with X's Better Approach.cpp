//In this approach , first we will traverse along the boundary of the 2D matrix
//then if we find any block grid[i][j]=='O' then do a graph traversal on it and change all the components of graph to 'V'
//Now all the boundary 'O's are eliminated and insider 'O's are left
//Now do a double for loop on 2D matrix and change all the 'O's to 'X's and all the 'V's to 'O's
class Solution {
  public:
  
  int row[4]={0,0,1,-1};
  int col[4]={1,-1,0,0};
  
  bool valid(int i, int j, int m, int n)
  {
      if(i>-1 && i<m && j>-1 && j<n) return 1;
      else return 0;
  }
  
   void DFS(int i,int j,vector<vector<char>>& grid,int m,int n)
   {
       for(int k=0;k<4;k++)
       {
         if(valid(i+row[k],j+col[k],m,n) && (grid[i+row[k]][j+col[k]]=='O'))
         {
             grid[i+row[k]][j+col[k]]='V';
             DFS(i+row[k],j+col[k],grid,m,n);
         }
       }
       
   }
  
    void fill(vector<vector<char>>& grid) {
        // Code here
        int m=grid.size();
        int n=grid[0].size();
        
        
            for(int j=0;j<n;j++)
            {
                if(grid[0][j]=='O')
                {
                 grid[0][j]='V';
                 DFS(0,j,grid,m,n);
                }
                
                if(grid[m-1][j]=='O')
                {
                  grid[m-1][j]='V';
                 DFS(m-1,j,grid,m,n); 
                }
            }
            
            for(int i=0;i<m;i++)
            {
                if(grid[i][0]=='O')
                {
                 grid[i][0]='V';
                 DFS(i,0,grid,m,n);
                }
                
                if(grid[i][n-1]=='O')
                {
                  grid[i][n-1]='V';
                 DFS(i,n-1,grid,m,n); 
                }
            }
              
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='O')  grid[i][j]='X';
            }
        }
        
         for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='V')  grid[i][j]='O';
            }
        }
        
        
    
        
    }
};
