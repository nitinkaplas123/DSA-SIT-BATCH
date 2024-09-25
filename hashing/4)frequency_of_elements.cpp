Question -:
https://www.geeksforgeeks.org/problems/find-the-frequency/1






























Solution 1-: using hashing
Code-: Time ->O(N) Space->O(N)
int findFrequency(vector<int> Arr, int X)
{
    unordered_map<int,int>m;
    for(int i=0;i<Arr.size();i++)
    {
        m[Arr[i]]++;
    }
    
    return m[X];
}

In Java -:
int findFrequency(int Arr[], int X)
{
       HashMap<Integer,Integer>m=new HashMap<>();
       for(int i=0;i<Arr.length;i++)
       {
           m.put(Arr[i],m.getOrDefault(Arr[i],0)+1);
       }
       return m.containsKey(X)?m.get(X):0;
}




Solution 2-:
Steps-:
1)count the val of x in array and return it.

Code-:
int findFrequency(vector<int> Arr, int X)
{
    int count=0;
    for(int i=0;i<Arr.size();i++)
    {
        if(Arr[i]==X)
        count++;
    }
    return count;
}


In Java -:
int findFrequency(int Arr[], int X)
{
       int count=0;
       for(int i=0;i<Arr.length;i++)
       {
           if(Arr[i]==X)
           count++;
       }
       return count;
}