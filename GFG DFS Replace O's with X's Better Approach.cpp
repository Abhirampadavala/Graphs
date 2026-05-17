//In this approach , first we will traverse along the boundary of the 2D matrix
//then if we find any block grid[i][j]=='O' then do a graph traversal on it and change all the components of graph to 'V'
//Now all the boundary 'O's are eliminated and insider 'O's are left
//Now do a double for loop on 2D matrix and change all the 'O's to 'X's and all the 'V's to 'O's
