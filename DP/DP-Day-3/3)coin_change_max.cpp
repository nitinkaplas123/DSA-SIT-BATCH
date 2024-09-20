https://www.geeksforgeeks.org/problems/coin-change2448/1

Solution 1-:
Steps-:
1)using recursion

Code-:
long long helper(int coins[], int N, int sum)
{
        if(N==0)
        {
            if(sum==0) return 1;
            else
            return 0;
        }
        if(sum>=coins[N-1])
        return helper(coins,N,sum-coins[N-1]) + helper(coins,N-1,sum);
        else
        return helper(coins,N-1,sum);
}
    
long long int count(int coins[], int N, int sum)
{
        return helper(coins,N,sum);
}

Solution 2-:
Steps-:
1)using memo


Code-:
long long helper(long long  memo[1001][1001],int coins[], int N, int sum)
{
        if(N==0)
        {
            if(sum==0) return 1;
            else
            return 0;
        }
        if(memo[N][sum]!=-1) return memo[N][sum];
        
        long long int res;
        if(sum>=coins[N-1])
        res= helper(memo,coins,N,sum-coins[N-1]) +
               helper(memo,coins,N-1,sum);
        else
        res= helper(memo,coins,N-1,sum);
        return memo[N][sum]=res;
}

long long int count(int coins[], int N, int sum)
{
        long long int memo[1001][1001];
        memset(memo,-1,sizeof(memo));
        return helper(memo,coins,N,sum);
}