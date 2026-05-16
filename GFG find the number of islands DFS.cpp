class Solution {
  public:
  int rows[8]={-1,0,1,-1,1,-1,0,1};
  int cols[8]={1,1,1,0,0,-1,-1,-1};

//This is to check whether the neighbouring coordinates for the land coordinate are valid or not 
 bool valid(int p,int q,int n,int m)
  {
      if(p>-1 && p<n && q>-1 && q<m)
      {
          return 1;
      }
      else return 0;
  }

//In this DFS function you are sending the coordinates of that land 
//piece found out 
//then size of the grid, grid itself

//Then using this nice method to check all the surrounding pieces of that land
  
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


//This is the only thing given in question,so here I have initialized all necessary things,
//then as usual for loop which will be of O(n*m) TC  as it was mentioned in expected complexities
//so if you find a land then DFS there, i.e send that coordinate (i,j) to DFS function
//The DFS function connects all land pieces attached to each other
//Now everytime you find an 'L',do count++ then you get to do a DFS completing that one island. 
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
