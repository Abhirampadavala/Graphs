class Solution {
  public:
  int rows[4]={0,0,1,-1};
  int cols[4]={-1,1,0,0};
  
  bool valid(int i, int j,int n)
  {
      if(i<n && i>-1 && j<n && j>-1) 
      {
          return 1;
      }
       return 0;
  }
  
  bool DFS(int i, int j,int n,vector<vector<int>>&path,vector<vector<int>>& mat)
  {
      path[i][j]=1;
      for(int x=0;x<4;x++)
      {
         if(valid(i+rows[x],j+cols[x],n) && !path[i+rows[x]][j+cols[x]])
         {
            if(mat[i+rows[x]][j+cols[x]]==2) return 1;
            
            if(mat[i+rows[x]][j+cols[x]]==3)
            {
                //here instead of writing return DFS(i+rows[x], j+cols[x], n, path, mat)
                //you have to write the below line
                //because below line tells me that if I found 2 and am returning 1
                //if it doent find it will stay silent and go for next
                //but if there is no 2 , then return DFS(...) statement will give me false and stop
                //and will not try others
                if(DFS(i+rows[x], j+cols[x], n, path, mat) == 1) return 1;
    
            }
         }
      }
      //path[i][j]=0;
      //no need of above since i will not go in the path which is already visited 
       return 0;
  }
    bool isPathPossible(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        vector<vector<int>>path(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==1) 
                {
                    return DFS(i,j,n,path,mat);
                }
            }
        }
        return 0;
    }
};
