https://www.geeksforgeeks.org/problems/longest-common-substring1452/1

 
 
 Solution 1-:

 int longestCommonSubstr (string S1, string S2, int n, int m)
    {
       int dp[n+1][m+1];
       int maxx=0;
       for(int i=0;i<=n;i++)
       {
           for(int j=0;j<=m;j++)
           {
               if(i==0 || j==0) dp[i][j]=0;
               else if(S1[i-1]==S2[j-1])
               dp[i][j]=1+dp[i-1][j-1];
               else
               dp[i][j]=0;
               maxx=max(maxx,dp[i][j]);
           }
       }
       return maxx;
    }

Solution 2-:
Steps-:
1)using prev and curr vector.
Code-:
int longestCommonSubstr (string S1, string S2, int n, int m)
    {
       int maxx=0;
       vector<int>prev(m+1,0);
       vector<int>curr(m+1,0);
       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=m;j++)
           {
               if(S1[i-1]==S2[j-1])
               curr[j]=1+prev[j-1];
               else
               curr[j]=0;
               maxx=max(maxx,curr[j]);
           }
           prev=curr;
       }
       return maxx;
    }