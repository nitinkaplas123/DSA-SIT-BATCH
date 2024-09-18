Question -> https://www.geeksforgeeks.org/problems/nth-fibonacci-number1335/1




Solution 1-:
Steps-:
1)using recusrion 
2)adding previous two values is current values.

int nthFibonacci(int n)
{
        if(n==1 || n==0)
        return n;
        return nthFibonacci(n-1)+nthFibonacci(n-2);
}


Solution 2-:
Steps-:

Code-:
int mod=1000000007;
    int nthFibonacci(int n)
    {
        if(n==0 || n==1) return n;
        int a=0;
        int b=1;
        int c;
        for(int i=2;i<=n;i++)
        {
            c=(a+b)%mod;
            a=b;
            b=c;
        }
        return c;
    }


Solution 3-:
Steps-:
1)using DP. tabulation.

Code-:
int mod=1000000007;
int nthFibonacci(int n)
{
       int f[n+1];
       f[0]=0;
       f[1]=1;
       for(int i=2;i<=n;i++)
       {
           f[i]=(f[i-1]+f[i-2])%mod;
       }
       return f[n];
}

Solution 4-:
Steps-:
1)Using memoization 

Code-:
int mod=1000000007;
int helper(int memo[],int n)
{
       if(memo[n]==-1)
       {
           int res;
           if(n==0 || n==1)
           res=n;
           else
           res=helper(memo,n-1)%mod+helper(memo,n-2)%mod;
           memo[n]=res;
       }
       return memo[n]%mod;
}

int nthFibonacci(int n)
{
       int memo[n+1];
       memset(memo,-1,sizeof(memo));
       return helper(memo,n);
}


