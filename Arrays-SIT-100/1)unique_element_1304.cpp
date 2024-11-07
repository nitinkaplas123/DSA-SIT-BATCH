https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/description/


Steps-:
Case-1 : If N is even 
Then run a loop as i=1 to i=n/2 where we add a value as i,-i.

Case-2 : If N is odd.
THen make n as n=n-1 and run a loop i=1 to i=n/2 and add 0 into it.


Solution -:
vector<int> sumZero(int n) {
        vector<int>v;
        for(int i=1;i<=n/2;i++)
        {
            v.push_back(i);
            v.push_back(-i);
        }
        if(n%2!=0)
        v.push_back(0);
        return v; 
    }

Time Complexity -O(N)