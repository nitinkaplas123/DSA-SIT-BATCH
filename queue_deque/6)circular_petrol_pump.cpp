 https://www.geeksforgeeks.org/batch/dsa-5/track/DSASP-Queue/problem/circular-tour-1587115620

TestCase -:
Petrol []=  {4,8,7,4}
Distance[]= {6,5,3,5}

O/p -> 1


TestCase 2-:
Petrol []=  {8,9,4}
Distance[]= {5,10,12}

O/p -> -1

TetCase 3-:
Petrol[]={4,8}
Distance[]={5,6}

o/p -> 1


TetCase 4 -:
Petrol[]=[5,6,7,8,6,4]
Distance[]=[6,7,4,10,6,5]

o/p ->-1

Solution 1-:
Code-: Time->O(N^2) Space->O(1)
int tour(petrolPump p[],int n)
{
      for(int i=0;i<n;i++)
      {
          int curr_petrol=0;
          int j;
          for(j=i;j<n+i;j++)
          {
             int index=j%n;
             curr_petrol+=p[index].petrol;
             curr_petrol-=p[index].distance;
             if(curr_petrol<0)
             break;
          }
          if(j==n+i)
          return i;
      }
      return -1;
}


Solution 2-:

Idea -:
If curr_petrol becomes negative at pi, then non of the petrol pump from p0 to pi can be our valid solution.

p0 p1 p2 ....  pi-1 pi pi+1 .... pn 
means till (pi-1) we have +ve petrol in car.

suppose p2 is valid  point but its not 
lets see why its not valid-:



Code-:
int tour(petrolPump p[],int n)
{
       int start=0;
       int prev_petrol=0;
       int curr_petrol=0;
       
       for(int i=0;i<n;i++)
       {
           curr_petrol+=p[i].petrol-p[i].distance;
           if(curr_petrol<0)
           {
               start=i+1;
               prev_petrol+=curr_petrol;
               curr_petrol=0;
           }
       }
       return (curr_petrol+prev_petrol>=0?start:-1);
}

Java -:
 int tour(int petrol[], int distance[])
    {
       int n=petrol.length;
	   int start=0;
       int prev_petrol=0;
       int curr_petrol=0;
       
       for(int i=0;i<n;i++)
       {
           curr_petrol+=petrol[i]-distance[i];
           if(curr_petrol<0)
           {
               start=i+1;
               prev_petrol+=curr_petrol;
               curr_petrol=0;
           }
       }
       return (curr_petrol+prev_petrol>=0?start:-1);
    }