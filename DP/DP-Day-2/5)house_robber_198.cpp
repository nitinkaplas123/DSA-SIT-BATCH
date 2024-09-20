Reference Diagram -> Notebook 1 (page 46) 

Solution 1-:
Steps-:
1)using recursion


Code-:
int helper(vector<int>&nums,int n)
{
        if(n<=0)
        return 0;

        int val1=nums[n-1]+helper(nums,n-2);
        int val2=helper(nums,n-1);

        return max(val1,val2);
}

int rob(vector<int>& nums) {
       int n=nums.size();
       return helper(nums,n);
}


Solution 2-:
Steps-:
1)using memoization 


Code-:
int helper(int memo[101],vector<int>&nums,int n)
{
        if(n<=0)  return 0;
        if(memo[n]!=-1) return memo[n];

        int val1=nums[n-1]+helper(memo,nums,n-2);
        int val2=helper(memo,nums,n-1);

        return memo[n]=max(val1,val2);
}

int rob(vector<int>& nums) {
       int n=nums.size();
       int memo[101];
       memset(memo,-1,sizeof(memo));
       return helper(memo,nums,n);
}




Solution 3-:
Steps-:
1)Using tabulation 
2)just use the code of memoization to make tabulation solution 


Code-: Time->O(N) Space->O(N)
int rob(vector<int>& nums) {
       int n=nums.size();
       int dp[n+1];

       dp[0]=0;
       dp[1]=nums[0];

       for(int i=2;i<=n;i++)
       {
           int val1=nums[i-1] +dp[i-2];
           int val2=dp[i-1];
           dp[i]=max(val1,val2);
       }
       return dp[n];
    }


Solution 4-:
Code-: Time->O(N) Space->O(1)
int rob(vector<int>& nums)
{
        int n=nums.size();
        if(n==1) return nums[0];
        
        int a=0;
        int b=nums[0];
        int c;
        for(int i=2;i<=n;i++)
        {
            int val1=nums[i-1] + a;
            int val2=b;
            c=max(val1,val2);
            a=b;
            b=c;
        }
        return c;
}