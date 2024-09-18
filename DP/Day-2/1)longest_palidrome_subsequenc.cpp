 Solution 1-:
 Steps-:
 1)s1=A;
 2)s2=reverse(A.begin(),A.end())
 3)find lcs.

int helper(string s1,string s2)
    {
        int n=s1.length();
        int m=s2.length();
        
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
    int longestPalinSubseq(string A) 
    {
        string s=A;
        reverse(A.begin(),A.end());
        
        return helper(s,A);
    }