
















Solution 1-:
Steps-:
1)Using recursion.
2)Comparing from the end of both the string.

Code-:
int helper(string text1,string text2,int n,int m)
{
       if(n==0 || m==0)
       return 0;
       else if(text1[n-1]==text2[m-1])
       return 1+helper(text1,text2,n-1,m-1);
       else
       {
           int val1=helper(text1,text2,n-1,m);
           int val2=helper(text1,text2,n,m-1);
           return max(val1,val2);
       }
}

int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        return helper(text1,text2,n,m);
}


Solution 2-:
Steps-:
1)Using memoization 

Code-: Time->O(n*m) Space->O(n*m)
int helper(int memo[1001][1001],string &text1,string &text2,int n,int m)
{
       int res;
       if(n==0 || m==0) return 0;
       if(memo[n][m]!=-1) return memo[n][m];

       if(text1[n-1]==text2[m-1])
       res=1+helper(memo,text1,text2,n-1,m-1);
       else
       res=max(helper(memo,text1,text2,n-1,m),helper(memo,text1,text2,n,m-1));
       return memo[n][m]=res;
}

int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.length();
        int n2=text2.length();
        int memo[1001][1001];
        memset(memo,-1,sizeof(memo));
        return helper(memo,text1,text2,n1,n2);
}


Solution 3-:
Steps-:
1)Using tabulation 


Code-: Time->O(n1*n2) Space->O(n1*n2)
int lcs(int n, int m, string s1, string s2)
{
      
      int dp[n+1][m+1];
      for(int i=0;i<=n;i++)
      {
          for(int j=0;j<=m;j++)
          {
              if(i==0 || j==0)
              dp[i][j]=0;
              else if(s1[i-1]==s2[j-1])
              dp[i][j]=1+dp[i-1][j-1];
              else
              dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
          }
      }
      return dp[n][m];
}



Solution 4-: Time->O(N*M) Space=>
Steps-:
1)Here in previous tabulation solution if we clearly see-:
  to filling the current row we are using previous row 
2)So we make 2 array of size m+1 where m is the no. of charcaters in text2.
  vector<int>prev(m+1,0)
  vector<int>curr(m+1,0)
3)There is 2 cases-: 
  1) When text1[i-1]==text2[j-1] which means -> 1+dp[i-1][j-1]
     -:
     curr[j]=1+prev[j-1] as we need digaonal value which is in prev 
  2)When text1[i-1]!=text2[j-1] which means  -> max(dp[i-1][j],dp[i][j-1])
    -:
    curr[j]=max(curr[j-1],prev[j]) -> max(curr elements->left,prev_element->up)


Code-: Time->O(N*M) Space->O(N+M)
int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.length();
        int n2=text2.length();
        vector<int>prev(n2+1,0);
        vector<int>curr(n2+1,0);
       
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(text1[i-1]==text2[j-1])
                curr[j]=1+prev[j-1];
                else
                curr[j]=max(curr[j-1],prev[j]);
            }
            prev=curr;
        }
        return curr[n2];
}
     


Java -:
static int helper(int [][]memo,String s1,String s2,int n1,int n2)
    {
        if(n1==0 || n2==0) return 0;
        if(memo[n1][n2]!=-1)
        return memo[n1][n2];
        
        int res;
        if(s1.charAt(n1-1)==s2.charAt(n2-1))
        res= 1+helper(memo,s1,s2,n1-1,n2-1);
        else
        res= Math.max(helper(memo,s1,s2,n1,n2-1),helper(memo,s1,s2,n1-1,n2));
        return memo[n1][n2]=res;
    }
    static int lcs(int x, int y, String s1, String s2)
    {
        int [][]memo=new int[x+1][y+1];
        for(int i=0;i<=x;i++)
        {
            for(int j=0;j<=y;j++)
            {
                memo[i][j]=-1;
            }
        }
        return helper(memo,s1,s2,x,y);
    }