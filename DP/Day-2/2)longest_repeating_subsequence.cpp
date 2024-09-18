
int lcs(int n, int m, string s1, string s2)
    {
       vector<int>prev(m+1,0);
       vector<int>curr(m+1,0);
       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=m;j++)
           {
               if(s1[i-1]==s2[j-1] and i!=j)
               curr[j]=1+prev[j-1];
               else
               curr[j]=max(prev[j],curr[j-1]);
           }
           prev=curr;
       }
       return curr[m];
    }
    
	int LongestRepeatingSubsequence(string str)
	{
		    int n=str.length();
		    return lcs(n,n,str,str);
	}