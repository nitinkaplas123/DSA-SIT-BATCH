Question link-:
https://practice.geeksforgeeks.org/problems/maximum-width-of-tree/1

Solution 1-:
Steps-:
1)Using level order traversal


Code-: Time->O(N) Space->O(N)
 int getMaxWidth(Node* root) {
      if(root==NULL)
      return 0;
      queue<Node*>q;
      q.push(root);
      int maxi=0;
      while(q.empty()==false)
      {
         int size=q.size();
        
         for(int i=0;i<size;i++)
         {
             Node* curr=q.front();
             q.pop();
             if(curr->left)
             q.push(curr->left);
             if(curr->right)
             q.push(curr->right);
         }
         maxi=max(maxi,size);
      }
      return maxi;
    }



Solution 2-:
