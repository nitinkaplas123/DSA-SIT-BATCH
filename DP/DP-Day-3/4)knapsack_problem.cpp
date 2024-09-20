https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1


Solution 1-:
Steps-:
1)Using recursion

Code-:
int helper(int N, int W, int val[], int wt[])
{
        if(W==0 || N==0) 
        return 0;
        
        if(W>=wt[N-1])
        return max(val[N-1]+helper(N,W-wt[N-1],val,wt),helper(N-1,W,val,wt));
        else
        return helper(N-1,W,val,wt);
}

int knapSack(int N, int W, int val[], int wt[])
{
       return helper(N,W,val,wt);
}



Solution 2-:
int helper(int memo[1001][1001],int N, int W, int val[], int wt[])
{
        if(W==0 || N==0) 
        return 0;
        if(memo[N][W]!=-1) return memo[N][W];
        
        int res;
        if(W>=wt[N-1])
        res=max(val[N-1]+helper(memo,N,W-wt[N-1],val,wt),
                            helper(memo,N-1,W,val,wt));
        else
        res= helper(memo,N-1,W,val,wt);
        return memo[N][W]=res;
}

int knapSack(int N, int W, int val[], int wt[])
{
       int memo[1001][1001];
       memset(memo,-1,sizeof(memo));
       return helper(memo,N,W,val,wt);
}