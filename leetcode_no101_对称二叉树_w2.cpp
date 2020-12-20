/* ------------------------------------------------------------------|
给定一个二叉树，检查它是否是镜像对称的。

 

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3
 

进阶：

你可以运用递归和迭代两种方法解决这个问题吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/symmetric-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	迭代法
*
*	执行用时：4 ms, 在所有 C++ 提交中击败了86.06%的用户
*	内存消耗：12.9 MB, 在所有 C++ 提交中击败了11.71%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool check(TreeNode* u, TreeNode* v) {
    queue<TreeNode*> q;
    q.emplace(u);
    q.emplace(v);
    while (!q.empty()) {
        u = q.front();
        q.pop();
        v = q.front();
        q.pop();

        if (!u && !v) {
            continue;
        }
        if ((!u || !v) || (u->val != v->val)) {
            return false;
        }

        q.emplace(u->left);
        q.emplace(v->right);
        q.emplace(u->right);
        q.emplace(v->left);
    }
    return true;
}

bool isSymmetric(TreeNode* root) {
    return check(root, root);
}