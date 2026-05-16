
class Solution {
  public:
    int helpaterp(vector<vector<int>> hospital) {
        // code here
        int r=hospital.size();
        int c=hospital[0].size();
        queue<pair<int,int>>q;
        
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
              if(hospital[i][j]==2) q.push(make_pair(i,j));
            }
        }
        int timer=0;
        
        
        while(!q.empty())
        {
            timer++;
            int curr_pat=q.size();
            while(curr_pat--)
            {
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                
                if(i-1>-1 && hospital[i-1][j]==1)
                {
                hospital[i-1][j]=2;
                q.push(make_pair(i-1,j));
                }
                
                if(i+1<r && hospital[i+1][j]==1)
                {
                hospital[i+1][j]=2;
                q.push(make_pair(i+1,j));
                }
                
                if(j-1>-1 && hospital[i][j-1]==1)
                {
                hospital[i][j-1]=2;
                q.push(make_pair(i,j-1));
                }
                
                if(j+1<c && hospital[i][j+1]==1)
                {
                hospital[i][j+1]=2;
                q.push(make_pair(i,j+1));
                }
            }
        }
        
        
        int n=0;
         for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
              if(hospital[i][j]==0) n++;
            }
        }
        if(n==r*c) return 0;
        
        
         for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
              if(hospital[i][j]==1) return -1;
            }
        }
        return timer-1;
        
        
        
       
    }
};
