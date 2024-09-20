int lcs(int n, int m, string s1, string s2)
    {
       vector<int>prev(m+1,0);
       vector<int>curr(m+1,0);
       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=m;j++)
           {
               if(s1[i-1]==s2[j-1])
               curr[j]=1+prev[j-1];
               else
               curr[j]=max(prev[j],curr[j-1]);
           }
           prev=curr;
       }
       return curr[m];
    }
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
       int LCS=lcs(m,n,X,Y);
       int n1=m-LCS;
       int n2=n-LCS;
       return LCS+n1+n2;
    }