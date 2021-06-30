// pre-order, top-down approach
val, left, right

// in-order
left, val, right

// post-order, bottom-up approach
left, right, val

// level order

//===================================================
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
//===================================================
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
class SolutionPostOrderRecur {
public:
    
    void postOrderRecur(TreeNode* n, vector<int>& v) {
        if(!n) return;
        postOrderRecur(n->left,v);
        postOrderRecur(n->right,v);
        v.push_back(n->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        postOrderRecur(root,v);
        return v;
    }
};

//=======================================================
// TODO: post-order iterative


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

//=======================================================
// pre-order
void maximum_depth(TreeNode* root, int depth) {
    if (!root) {
        return;
    }
    if (!root->left && !root->right) {
        answer = max(answer, depth);
    }
    maximum_depth(root->left, depth + 1);
    maximum_depth(root->right, depth + 1);
}
//=======================================================
// post-order
int maximum_depth(TreeNode* root) {
    if (!root) {
        return 0;                                 // return 0 for null node
    }
    int left_depth = maximum_depth(root->left);
    int right_depth = maximum_depth(root->right);
    return max(left_depth, right_depth) + 1;      // return depth of the subtree rooted at root
}

//========================================================
// mirror check (different from balance)
class Solution {
public:
    bool symRecur(TreeNode* r1, TreeNode* r2) {
        if(!r1 && !r2) return true;
        if(r1 && r2) {
            return (r1->val == r2->val) && 
                  symRecur(r1->right, r2->left) && 
                  symRecur(r1->left, r2->right);
        }
        
        return false;
        
    }
    
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return symRecur(root->left, root->right);
    }
};

//========================================================
// path sum
// Given the root of a binary tree and an integer targetSum, return true if the tree has 
// a root-to-leaf path such that adding up all the values along the path equals targetSum.
// A leaf is a node with no children.
class Solution {
public:
    bool recur(TreeNode* n, int sum, int targetSum){
        if(!n) return false;
        
        if(!n->left && !n->right) {
            if (sum + n->val == targetSum) return true;
        }
        
        return recur(n->left, sum+n->val, targetSum) || 
            recur(n->right, sum+n->val, targetSum);
        
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        return recur(root, 0, targetSum);
    }
};
