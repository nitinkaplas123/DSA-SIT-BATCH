Solution 1-:
Steps-:
1) using recursion


Code-:
int climbStairs(int n) {
        if(n==0) return 1;
        if(n<0) return 0;

        return climbStairs(n-1) + climbStairs(n-2);
}



Solution 2-:
Steps-:
1)using memoization 


Code-: Time->O(N) Space->O(N)
int helper(int memo[46],int n)
{
        if(n==0) return 1;
        if(n<0) return 0;

        if(memo[n]!=-1) return memo[n];

        int val1=helper(memo,n-1);
        int val2=helper(memo,n-2);
        return memo[n]=val1+val2;
}

int climbStairs(int n) {
        int memo[46];
        memset(memo,-1,sizeof(memo));
        return helper(memo,n);
}


Solution 3-:
Steps-:
1)using tabulation method 


int countWays(int n)
{
        int f[n+1];
        f[0]=1;
        f[1]=1;
        
        for(int i=2;i<=n;i++)
        {
            f[i]=f[i-1]%mod + f[i-2]%mod;
        }
        return f[n]%mod;
}

Solution 4-:
Steps-:
1) Using a,b,c


Code-:
int countWays(int n)
{
        if(n<=1) return 1;
        int a=1;
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



Java -:
int mod=1000000007;
    int helper(int []memo,int n)
    {
       if(n<0) return 0;
       if(n==0) return 1;
       
       if(memo[n]!=-1) return memo[n];
       
       int res;
       res=helper(memo,n-1)%mod + helper(memo,n-2)%mod;
       return memo[n]=res%mod;
    }
    int countWays(int n)
    {
       int []memo=new int[n+1];
       for(int i=0;i<=n;i++)
       {
           memo[i]=-1;
       }
       return helper(memo,n);
    }