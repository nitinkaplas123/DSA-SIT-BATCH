Solution 1-:
Steps-:
1)Here what we observe is we have to use queue and have to reverse the order after 1 level always.
2)For that we use flag 

Code-: Time->O(N) Space ->O(N)
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>v;
        if(root==NULL)
        return v;
        vector<int>v1;
        queue<TreeNode*>q;
        q.push(root);
        bool flag=true;
        while(q.empty()==false)
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
              TreeNode* curr=q.front();
              q.pop();
              v1.push_back(curr->val);
              
                 if(curr->left)
                 q.push(curr->left);
                 if(curr->right)
                 q.push(curr->right);
                 
            }
            if(!flag)
            reverse(v1.begin(),v1.end());
            v.push_back(v1);
            v1.clear();
            flag=!flag;
        }
        return v;
    }


Solution 2-:
Steps-:
1)here we use two stacks s1 nd s2
2)when we are in s1 push its left and right in s2 in order(left,right)
3)when we are in s2 push its left and right in s1 in order(right,left)
4)when both stacks empty then we return our ans.

Code-:
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>v;
        if(root==NULL)
        return v;
        vector<int>v1;
        stack<TreeNode*>s1;
        stack<TreeNode*>s2;
        s1.push(root);
        while(s1.empty()==false || s2.empty()==false)
        {
            if(s1.empty()==false)
            {
              while(s1.empty()==false)
              {
                TreeNode* curr=s1.top();
                s1.pop();
                v1.push_back(curr->val);
                if(curr->left)
                s2.push(curr->left);
                if(curr->right)
                s2.push(curr->right);
              }
            }

            else
            {
              while(s2.empty()==false)
              {
                TreeNode* curr=s2.top();
                s2.pop();
                v1.push_back(curr->val);
                if(curr->right)
                s1.push(curr->right);
                if(curr->left)
                s1.push(curr->left);
               }
            }
            v.push_back(v1);
            v1.clear();
        }
        return v;
    }