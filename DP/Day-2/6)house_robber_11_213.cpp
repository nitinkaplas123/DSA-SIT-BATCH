    Code-:
     // f()
    // {
    //     int dp[n+1];
    //     dp[0]=0;
    //     dp[1]=nums[0];

    //     for(int i=2;i<=n;i++)
    //     {
    //         int val1=nums[i-1] + dp[i-2];
    //         int val2=dp[i-1];
    //         dp[i]=max(val1,val2);
    //     }
    // }
    int helper(vector<int>nums,int n)
    {
        if(n==1)
        return nums[0];
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
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==1)
        return nums[0];
        if(n==2)
        return max(nums[0],nums[1]);

        vector<int>temp1,temp2;
        for(int i=0;i<n-1;i++)
        {
            temp1.push_back(nums[i]);
        }

        for(int i=1;i<n;i++)
        {
            temp2.push_back(nums[i]);
        }

        int res1=helper(temp1,n-1);
        int res2=helper(temp2,n-1);
        return max(res1,res2);
    }