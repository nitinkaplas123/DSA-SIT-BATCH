 https://www.geeksforgeeks.org/problems/sub-array-sum-divisible-by-k2617/1
 
 Solution 1 -: Time ->O(n2)   Space ->O(1)

TestCase -:
arr[]={2,3,5,4,5,3,4}
k=7
o/p -> 4


TestCase for -ve
17 2
235 -415 -838 -122 -172 224 282 -125 -90 -428 -758 -215 -821 -476 -639 -56 -769

Code-:
long long subCount(long long arr[], int N, long long K)
{
	    long long count=0;
	    for(int i=0;i<N;i++)
	    {
	        long long sum=0;
	        for(int j=i;j<N;j++)
	        {
	            sum+=arr[j];
	            if(sum%K==0)
	            count++;
	        }
	    }
	    return count;
}

Solution 2-:

Steps-:
1) we make map here for storing rem and frequency of it .
2) we also use prefix sum and to get rem of it by (sum%k) 
3) If rem is -ve make it positive by adding k in it because 
   7n-3 -> 7n-3 +7-7 
        -> 7(n-1)+4  
        here our rem is 4 

        initial rem is -> -3
        now rem is -> -3+7 -> 4 which is same as above.
4) if the rem is already present in map then ans+=m[rem] (means adding its freq) and then increase it freq by 1
5) At last just return the ans.


Diagram refer to nootebbok 1 page no. 27

Code-:
long long subCount(long long arr[], int N, long long K)
	{
	    long long count=0;
	    unordered_map<int,int>m;
	    m[0]=1;
	    
	    int sum=0;
	    int rem=0;
	    int ans=0;
	    for(int i=0;i<N;i++)
	    {
	        sum+=arr[i];
	        rem=sum%K;
	        if(rem<0)
	        rem+=K;
	        if(m.find(rem)!=m.end())
	        {
	            ans+=m[rem];
	            m[rem]++;
	        }
	        else
	        m[rem]=1;
	    }
	    return ans;
	}


In java -:
long subCount(long arr[] ,int n,int k)
{
        long count=0;
        HashMap<Long,Long>m=new HashMap<>();
        m.put(0L,1L);
        long sum=0;
        long rem=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            rem=sum%k;
            if(rem<0)
            rem+=k;
            
            if(m.containsKey(rem))
            {
                count+=m.get(rem);
                m.put(rem,m.get(rem)+1);
            }
            else
            m.put(rem,1L);
        }
        return count;
}



In Java, the correct syntax for the HashMap declaration should be HashMap<Long, Long> instead of 
HashMap<long, long>.

Here's why:

Capitalization: 
Java is case-sensitive, so long and Long are different types. long is a primitive data type,
while Long is a wrapper class for that primitive type.

Generics: 
When using generics in Java, you should use object types (Long), not primitive types (long). 
Generics in Java don't work with primitive types; they only work with objects. Therefore, if 
you want to use a primitive long as the key or value in a HashMap, you need to use its 
corresponding wrapper class Long.