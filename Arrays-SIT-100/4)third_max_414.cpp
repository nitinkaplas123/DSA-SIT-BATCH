https://leetcode.com/problems/third-maximum-number/description/

Solution 1-:
Steps-:
1)sort the array.
2)traverse from end to start 
3)if from end find the 2 distinct element if count==2 means current element is third largest.


Code-:
int thirdMax(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int count=0;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]!=nums[i+1])
            count++;

            if(count==2)
            return nums[i];
        }
        return nums[n-1];
}


Solution 2-:
Steps-:
1)same concept as we use in find the second largest element.

Code-:
LONG_MIN is a constant representing the minimum representable value 
for a long integer type in C and C++ programming languages. It's 
defined in the <climits> (or <limits.h> in C) header file. The exact 
value of LONG_MIN depends on the platform and the specific system you are using.

In most systems, LONG_MIN is typically defined as -9223372036854775807 - 1, 
which is equivalent to the hexadecimal representation 0x8000000000000000 for
a 64-bit long (assuming two's complement representation for signed integers).
This value represents the smallest negative integer that can be stored in a long.



Code-:
int thirdMax(vector<int>& nums) {
        int n=nums.size();
        long long int first=LONG_MIN;
        long long int second=LONG_MIN;
        long long int third=LONG_MIN;

        for(int i=0;i<n;i++)
        {
            if(nums[i]>first)
            {
                third=second;
                second=first;
                first=nums[i];
            }
            else if(nums[i]>second and nums[i]!=first)
            {
                third=second;
                second=nums[i];
            }
            else if(nums[i]>third and nums[i]!=first and nums[i]!=second)
            third=nums[i];
            else
            continue;
        }
        return (third==LONG_MIN)?first:third;
}