case 
pattern -> [*,*,*,*]
str=       [""]

o/p -> 1

Solution 1-:
Steps-:


Code-:
int helper(string pat,string str,int n,int m)
{
        if(n==0 and m==0) return 1;
        
        if(n==0 || m==0)
        {
            if(m==0 and pat[n-1]=='*')
            return helper(pat,str,n-1,m);
            else
            return 0;
        }
        else if(pat[n-1]==str[m-1])
        return helper(pat,str,n-1,m-1);
        else
        {
            if(pat[n-1]=='?')
            return helper(pat,str,n-1,m-1);
            else if(pat[n-1]=='*')
            return helper(pat,str,n,m-1) || helper(pat,str,n-1,m);
            else
            return 0;
        }
}

int wildCard(string pattern, string str) {
        int n=pattern.length();
        int m=str.length();
        return helper(pattern,str,n,m);
}



Solution 2-:
Steps-:
1)using memo

Code-:
int helper(int memo[201][201],string pat,string str,int n,int m)
    {
        if(n==0 and m==0) return 1;
        
        if(memo[n][m]!=-1) return memo[n][m];
        int res;
        if(n==0 || m==0)
        {
            if(m==0 and pat[n-1]=='*')
            res= helper(memo,pat,str,n-1,m);
            else
            return 0;
        }
        else if(pat[n-1]==str[m-1])
        res= helper(memo,pat,str,n-1,m-1);
        else
        {
            if(pat[n-1]=='?')
            res= helper(memo,pat,str,n-1,m-1);
            else if(pat[n-1]=='*')
            res= helper(memo,pat,str,n,m-1) || helper(memo,pat,str,n-1,m);
            else
            return 0;
        }
        return memo[n][m]=res;
    }
    int wildCard(string pattern, string str) {
        int n=pattern.length();
        int m=str.length();
        int memo[201][201];
        memset(memo,-1,sizeof(memo));
        return helper(memo,pattern,str,n,m);
    }