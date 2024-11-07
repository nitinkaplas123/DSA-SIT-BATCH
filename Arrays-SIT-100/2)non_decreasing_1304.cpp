https://leetcode.com/problems/non-decreasing-array/description/

Code-:
bool checkPossibility(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        for(int i=1;i<n;i++)
        {
           if(nums[i-1]>nums[i])
           {
               if(i>1)
               {
                 if(nums[i-2]>nums[i])
                 nums[i]=nums[i-1];
                 else 
                 nums[i-1]=nums[i];
               }
               else
               nums[i-1]=nums[i];

               count++;
           }
        }
        return (count>1)?0:1;
    }
