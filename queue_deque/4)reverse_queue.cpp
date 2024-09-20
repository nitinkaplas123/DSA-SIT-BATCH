Question -> https://www.geeksforgeeks.org/problems/queue-reversal/1

























Solution 1-:
Steps-:
1)create a stack and push all the elements of queue into stack.
2)Now create a queue and push all the elements of stack into queue and return the new queue.

queue<int> rev(queue<int> q)
{
       stack<int>st;
       while(q.empty()==false)
       {
           int val=q.front();
           q.pop();
           st.push(val);
       }
       
       queue<int>q1;
       while(st.empty()==false)
       {
           int val=st.top();
           st.pop();
           q1.push(val);
       }
       return q1;
}

In java -:
 public Queue<Integer> rev(Queue<Integer> q){
        Stack<Integer>st=new Stack<>();
        
        while(q.isEmpty()==false)
        {
            int val=q.remove();
            st.add(val);
        }
        
        Queue<Integer>q1=new LinkedList<>();
        while(st.isEmpty()==false)
        {
            int val=st.pop();
            q1.add(val);
        }
        return q1;
}


Solution 2-:
Steps-:
1)Using recursion 

Code-:
void helper(queue<int>&q)
{
        if(q.size()==0) return;
        int x=q.front();
        q.pop();
        
        helper(q);
        q.push(x);   
}
queue<int> rev(queue<int> q)
{
      helper(q);
      return q;
}


In Java -:
void helper(Queue<Integer>q)
{
        if(q.size()==0) return ;
        
        int x=q.remove();
        helper(q);
        q.add(x);
}
public Queue<Integer> rev(Queue<Integer> q){
      helper(q);
      return q;
}


The difference in behavior between the Java and C++ versions of the recursive solution may be due to 
differences in the runtime environments and memory management.

Java has a fixed stack size for each thread, which limits the depth of recursion. This limitation can 
cause a StackOverflowError if the recursion depth exceeds the stack size.
In the provided Java code, the recursion is not tail-recursive, meaning that each recursive call adds 
a new stack frame until it reaches the base case, potentially causing a stack overflow if the queue is large.

On the other hand, C++ does not have a fixed stack size, and compilers may optimize tail-recursive
calls by reusing the same stack frame, effectively eliminating the risk of a stack overflow.
This behavior allows the C++ code to handle larger input sizes without encountering runtime errors.

