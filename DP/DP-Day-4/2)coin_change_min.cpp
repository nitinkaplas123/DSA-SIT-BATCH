https://leetcode.com/problems/coin-change/


[1,2,3] Sum=5 

o/p -> 2

Solution 1-:
Code-:
int helper(vector<int> &coins, int M, int V)
	{
	    if(M==0)
	    {
	        if(V==0) return 0;
	        else return 1e9;
	    }
	    if(V>=coins[M-1])
	    return min(1+helper(coins,M,V-coins[M-1]),helper(coins,M-1,V));
	    else
	    return helper(coins,M-1,V);
	}
	int minCoins(vector<int> &coins, int M, int V) 
	{ 
	    int res=helper(coins,M,V);
	    if(res==1e9)
	    return -1;
	    else
	    return res;
	} 


Solution 2-:
Code-:
int helper(int memo[13][10001],vector<int> &coins, int M, int V)
	{
	    if(M==0)
	    {
	        if(V==0) return 0;
	        else return 1e9;
	    }
	    if(memo[M][V]!=-1) return memo[M][V];
	    
	    int res;
	    if(V>=coins[M-1])
	    res= min(1+helper(memo,coins,M,V-coins[M-1]),
	                 helper(memo,coins,M-1,V));
	    else
	    res=helper(memo,coins,M-1,V);
	    return memo[M][V]=res;
	}
    int coinChange(vector<int>& coins, int V) {
         int memo[13][10001];
         int M=coins.size();
	     memset(memo,-1,sizeof(memo));
	    
	    int res=helper(memo,coins,M,V);
	    if(res==1e9)
	    return -1;
	    else
	    return res;
    }


