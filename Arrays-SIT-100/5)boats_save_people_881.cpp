https://leetcode.com/problems/boats-to-save-people/description/


Solution 1-:
Steps-:
1)first we sort the array.
2)Now we use 2 pointer approach low at starting and high at end.

Code-:
int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        sort(people.begin(),people.end());

        int low=0;
        int high=n-1;
        int count=0;
        while(low<=high)
        {
            int sum=people[low]+people[high];
            if(sum<=limit)
            {
                count++;
                low++;
                high--;
            }
            else
            {
                count++;
                high--;
            }
        }
        return count;
}