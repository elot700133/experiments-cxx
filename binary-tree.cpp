// pre-order traversal - recursion
class SolutionPreOrderRecur {
public:
    void recur(TreeNode* n, vector<int>& v) {
        if(!n) return;
        v.push_back(n->val);
        recur(n->left,v);
        recur(n->right,v);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        recur(root,v);
        return v;
    }
};

// pre-order traversal - iterative
class SolutionPreOrderIter {
public:   
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        if(!root) return v;
        
        stack<TreeNode*> s;
        s.push(root);
        
        while(!s.empty()) {
            TreeNode* cur = s.top();
            s.pop();
            if(cur) {
                v.push_back(cur->val);
                s.push(cur->right);
                s.push(cur->left);
            }
        }
        return v;
    }
};

// in-order
class SolutionInOrderRecur {
public:
    void inOrderRecur(TreeNode* n, vector<int>& v) {
        if(!n) return;
        inOrderRecur(n->left,v);
        v.push_back(n->val);
        inOrderRecur(n->right,v);
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        inOrderRecur(root,v);
        return v;
    }
};

// in-order
class SolutionInOrderIter {
public:

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        if(!root) return v;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while(cur != nullptr || !s.empty()) {
            while(cur) {
                s.push(cur);
                cur = cur->left;
            }
            
            cur = s.top();
            s.pop();
            
            v.push_back(cur->val);
            
            cur = cur->right;
            
        }
        return v;
    }
};


//=======================================================
// level order traversal
class Solution {
public:
    void height(TreeNode* n, int d, int& max_d) {
        if(!n) return;
        
        max_d = max(d+1, max_d);
        
        height(n->left,d+1,max_d);
        height(n->right,d+1,max_d);
    }
    
    void level(TreeNode* n, int d, vector<vector<int>>& v) {
        if(!n) return;
        
        v[d].push_back(n->val);
        
        level(n->left, d+1, v);
        level(n->right, d+1, v);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return vector<vector<int>>();
        // find how deep tree is
        int max_d = -1;
        height(root, 0, max_d);
        //printf("max_d %d\n",max_d);
        
        vector<vector<int>> v(max_d);
        level(root, 0, v);
        return v;
        
        // traverse based on level
    }
};
