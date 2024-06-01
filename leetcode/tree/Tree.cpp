//
// Created by 陈远航 on 2023/11/24.
//


#include "BinaryTree.h"
using namespace std;

class Solution {
   public:
    /**
     * 中序遍历 非递归
     */
    static vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* p = root;
        while (p != nullptr || !st.empty()) {
            while (p != nullptr) {
                st.push(p);
                p = p->left;
            }
            if (!st.empty()) {
                p = st.top();
                st.pop();
                res.push_back(p->val);
                p = p->right;
            }
        }
        return res;
    }

    /**
     * 226 翻转二叉树
     * 给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
     */
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }
        // 采用先序遍历
        swap(root->left, root->right);
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
        return root;
    }

    /**
     * 101 对称二叉树： 给你一个二叉树的根节点 root，检查它是否轴对称。
     */
    bool isSymmetric(TreeNode* root) {
        // 采用后序遍历
        // 对左子树做 左右根 右子树 做右左根
        return compare(root->left, root->right);
    }

    bool compare(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right != nullptr) {
            return false;
        } else if (right == nullptr && left != nullptr) {
            return false;
        } else if (right == nullptr && left == nullptr) {
            return true;
        } else {
            if (left->val != right->val) {
                return false;
            }
            return compare(left->left, right->right) &&
                   compare(left->right, right->left);
        }
    }

    /**
     * 非递归实现判断是否是对称二叉树
     * @param root
     * @return
     */
    bool compareNonRecursion(TreeNode* root) {
        if (root == nullptr)
            return true;
        queue<TreeNode*> que;
        que.push(root->left);
        que.push(root->right);
        while (!que.empty()) {
            TreeNode* n1 = que.front();
            que.pop();
            TreeNode* n2 = que.front();
            que.pop();
            if (n1 == nullptr && n2 == nullptr) {
                continue;
            }
            if (n1 == nullptr || n2 == nullptr || n1->val != n2->val) {
                return false;
            }
            que.push(n1->left);
            que.push(n2->right);
            que.push(n2->left);
            que.push(n1->right);
        }
        return true;
    }

    /**
     * 104 最大深度
     * @param root
     * @return
     */
    int maxDepth(TreeNode* root) {
        // 采用后序遍历
        if (root == nullptr)
            return 0;
        return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

    /**
     * 非递归 层序遍历
     * @param root
     * @return
     */
    static int maxDepthNonRecursion(TreeNode* root) {
        // 采用后序遍历
        if (root == nullptr)
            return 0;
        queue<TreeNode*> que;
        int depth = 0;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();  // 必须在此处就记录size
                                    // 此时的size才是这一层的个数
            depth++;
            TreeNode* n;
            for (int i = 0; i < size; ++i) {
                n = que.front();
                que.pop();
                if (n->left != nullptr) {
                    que.push(n->left);
                }
                if (n->right != nullptr) {
                    que.push(n->right);
                }
            }
        }
        return depth;
    }

    /**
     * 求最小深度：最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
     * @param root
     * @return
     */
    int minDepth(TreeNode* root) {
        // 后序遍历
        if (root == nullptr) {
            return 0;
        }
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if (left == 0 && right != 0) {  // 左孩子为空 右孩子不空 则叶子在右子树
            return right + 1;
        } else if (left != 0 && right == 0) {
            return left + 1;
        }
        return min(left, right) + 1;
    }

    static int minDepthNonRecursion(TreeNode* root) {
        if (root == nullptr)
            return 0;
        queue<TreeNode*> que;
        int depth = 0;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();  // 必须在此处就记录size
                                    // 此时的size才是这一层的个数
            depth++;
            TreeNode* n;
            for (int i = 0; i < size; ++i) {
                n = que.front();
                que.pop();
                if (n->left == nullptr && n->right == nullptr) {
                    return depth;
                }
                if (n->left != nullptr) {
                    que.push(n->left);
                }
                if (n->right != nullptr) {
                    que.push(n->right);
                }
            }
        }
        return depth;
    }

    /**
     * 完全二叉树的节点个数 （当做普通二叉树即可）
     */
    int countNodes(TreeNode* root) {
        // 后序
        if (root == nullptr) {
            return 0;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }

    /**
     * 是否是平衡二叉树
     */
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        if (abs(getHeight(root->left) - getHeight(root->right)) <= 1) {
            return left && right;
        }
        return false;
    }

    int getHeight(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return std::max(getHeight(root->left), getHeight(root->right)) + 1;
    }

    /**
     * 257. 二叉树的所有路径：给你一个二叉树的根节点 root ，按任意顺序
     * ，返回所有从根节点到叶子节点的路径。
     */
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string path;
        if (root == nullptr)
            return result;
        traversal(root, path, result);
        return result;
    }

    void traversal(TreeNode* cur, string path, vector<string>& result) {
        path += to_string(cur->val);  // 中
        if (cur->left == nullptr && cur->right == nullptr) {
            result.push_back(path);
            return;
        }
        if (cur->left)
            traversal(cur->left, path + "->", result);  // 左
        if (cur->right)
            traversal(cur->right, path + "->", result);  // 右
    }

    /**
     * 左叶子之和：给定二叉树的根节点 root ，返回所有左叶子之和。
     */
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        reverse(root, sum);
        return sum;
    }

    void reverse(TreeNode* root, int& sum) {
        if (root == nullptr)
            return;

        // 判断为左叶子
        if (root->left != nullptr && root->left->left == nullptr &&
            root->left->right == nullptr) {
            sum += root->left->val;
        }
        reverse(root->left, sum);
        reverse(root->right, sum);
    }

    /**
     * 513.找树左下角的值：给定一个二叉树的 根节点 root，请找出
     * 该二叉树的 最底层 最左边 节点的值。假设二叉树中至少有一个节点。
     */
    int max = INT_MIN;
    int result;
    int findBottomLeftValue(TreeNode* root) {
        reverseFor513(root, 0);
        return result;
    }

    // 按照优先搜索左子树的顺序 然后一定要注意 最底层是第一个结果的条件
    // 故每一棵树都要搜
    void reverseFor513(TreeNode* root, int depth) {
        if (root->left == nullptr && root->right == nullptr) {
            if (depth > max) {
                max = depth;
                result = root->val;
            }
            return;
        }
        if (root->left != nullptr) {
            reverseFor513(root->left, depth + 1);
        }
        if (root->right != nullptr) {
            reverseFor513(root->right, depth + 1);
        }
    }

    /**
     * 112. 路径总和：给你二叉树的根节点 root 和一个表示目标和的整数
     * targetSum 。 判断该树中是否存在 根节点到叶子节点
     * 的路径，这条路径上所有节点值相加等于目标和 targetSum 。
     * 如果存在，返回 true ；否则，返回 false 。
     */
    int sum = 0;
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }
        sum += root->val;
        if (root->left == nullptr && root->right == nullptr) {
            if (sum == targetSum) {
                return true;
            }
        }
        bool left = hasPathSum(root->left, targetSum);
        bool right = hasPathSum(root->right, targetSum);
        sum -= root->val;
        return left || right;
    }

    /**
     * 106.从中序与后序遍历序列构造二叉树
     */
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return traversalForBuild(inorder, postorder, 0, inorder.size(), 0,
                                 postorder.size());
    }

    TreeNode* traversalForBuild(vector<int>& inorder,
                                vector<int>& postorder,
                                int inLeft,
                                int inRight,
                                int postLeft,
                                int postRight) {
        if (postLeft == postRight) {
            return nullptr;
        }
        // 1.先从post找root
        int root = postorder[postRight - 1];
        TreeNode* n = new TreeNode(root);
        // 为叶子结点
        if (inRight - inLeft == 1) {
            return n;
        }

        // 2.从in中找到当前的分割点
        int cut = 0;
        for (int i = inLeft; i < inRight; i++) {
            if (root == inorder[i]) {
                cut = i;
            }
        }
        // 3.分别做左子树和右子树的递归操作
        // 后序数组没有明确的切割元素来进行左右切割，不像中序数组有明确的切割点，切割点左右分开就可以了。
        // 此时有一个很重的点，就是中序数组大小一定是和后序数组的大小相同的（这是必然）。
        // 中序数组我们都切成了左中序数组和右中序数组了，那么后序数组就可以按照左中序数组的大小来切割，
        // 切成左后序数组和右后序数组。
        n->left = traversalForBuild(inorder, postorder, inLeft, cut, postLeft,
                                    postLeft + cut - inLeft);
        n->right = traversalForBuild(inorder, postorder, cut + 1, inRight,
                                     postLeft + cut - inLeft, postRight - 1);
        return n;
    }

    /**
     * 654. 最大二叉树:给定一个不重复的整数数组 nums 。 最大二叉树
     * 可以用下面的算法从 nums 递归地构建:
     * 1. 创建一个根节点，其值为 nums 中的最大值。
     * 2. 递归地在最大值 左边 的 子数组前缀上 构建左子树。
     * 3. 递归地在最大值 右边 的 子数组后缀上 构建右子树。
     * 4. 返回 nums 构建的 最大二叉树 。
     */
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return reverseForCons(nums, 0, nums.size());
    }

    TreeNode* reverseForCons(vector<int>& nums, int left, int right) {
        if (left == right) {
            return nullptr;
        }

        int max = -1, index = -1;
        for (int i = left; i < right; i++) {
            if (nums[i] > max) {
                max = nums[i];
                index = i;
            }
        }
        TreeNode* p = new TreeNode(max);
        p->left = reverseForCons(nums, left, index);
        p->right = reverseForCons(nums, index + 1, right);
        return p;
    }

    /**
     * 617. 合并二叉树:给你两棵二叉树： root1 和 root2 。
        当你将其中一棵覆盖到另一棵之上时，两棵树上的一些节点将会重叠（而另一些不会）。
        你需要将这两棵树合并成一棵新二叉树。
        合并的规则是：如果两个节点重叠，那么将这两个节点的值相加作为合并后节点的新值；
        否则，不为 null 的节点将直接作为新二叉树的节点。返回合并后的二叉树。
    */
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) {
            return nullptr;
        }
        TreeNode* p;
        if (root1 == nullptr) {
            p = new TreeNode(root2->val);
            p->left = mergeTrees(nullptr, root2->left);
            p->right = mergeTrees(nullptr, root2->right);
        } else if (root2 == nullptr) {
            p = new TreeNode(root1->val);
            p->left = mergeTrees(root1->left, nullptr);
            p->right = mergeTrees(root1->right, nullptr);
        } else {
            p = new TreeNode(root1->val + root2->val);
            p->left = mergeTrees(root1->left, root2->left);
            p->right = mergeTrees(root1->right, root2->right);
        }
        return p;
    }

    // 700. 二叉搜索树中的搜索:给定二叉搜索树（BST）的根节点 root
    // 和一个整数值 val。 你需要在 BST 中找到节点值等于 val 的节点。
    // 返回以该节点为根的子树。 如果节点不存在，则返回 null 。
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return nullptr;
        }
        if (val < root->val) {
            return searchBST(root->left, val);
        }
        if (root->val == val) {
            return root;
        }
        if (val > root->val) {
            return searchBST(root->right, val);
        }
        return nullptr;
    }

    // 98.验证BST：给你一个二叉树的根节点 root
    // ，判断其是否是一个有效的二叉搜索树。
    long pre = LONG_LONG_MIN;
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        bool left = isValidBST(root->left);
        if (root->val <= pre) {
            return false;
        }
        pre = root->val;
        bool right = isValidBST(root->right);
        return left && right;
    }

    // 530. 二叉搜索树的最小绝对差:给你一个二叉搜索树的根节点 root ，
    // 返回 树中任意两不同节点值之间的最小差值 。
    // 差值是一个正数，其数值等于两值之差的绝对值。
    // 0 <= Node.val <= 105
    vector<int> res;
    int getMinimumDifference(TreeNode* root) {
        int min = INT_MAX;
        reverseForMin(root);
        for (int i = 0; i < res.size() - 1; i++) {
            if (abs(res[i] - res[i + 1]) < min) {
                min = abs(res[i] - res[i + 1]);
            }
        }
        return min;
    }

    void reverseForMin(TreeNode* p) {
        if (p == nullptr) {
            return;
        }
        reverseForMin(p->left);
        res.push_back(p->val);
        reverseForMin(p->right);
    }

    // 501. 二叉搜索树中的众数:给你一个含重复值的二叉搜索树（BST）的根节点
    // root ， 找出并返回 BST 中的所有 众数（即，出现频率最高的元素）。
    vector<int> modeNums;
    int count = 0, preVal, maxCount = 1;
    vector<int> findMode(TreeNode* root) {
        preVal = getFirst(root);
        traversalForMode(root);
        return modeNums;
    }

    int getFirst(TreeNode* p) {
        while (p->left != nullptr) {
            p = p->left;
        }
        return p->val;
    }

    void traversalForMode(TreeNode* p) {
        if (p == nullptr) {
            return;
        }
        traversalForMode(p->left);
        if (p->val == preVal) {
            count++;
        } else {
            preVal = p->val;
            count = 1;
        }
        if (count == maxCount) {
            modeNums.push_back(p->val);
        }
        if (count > maxCount) {
            modeNums.clear();
            modeNums.push_back(p->val);
            maxCount = count;
        }
        traversalForMode(p->right);
    }

    // 236. 最近公共祖先 ⭐️
    // 1.要找的两个节点分别在左子树和右子树中
    // 2.要找的一个节点是另一个节点的子树
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 采用后序遍历
        if (root == nullptr || root == p || root == q) {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left == nullptr && right != nullptr) {
            return right;
        }

        if (right == nullptr && left != nullptr) {
            return left;
        }

        if (left != nullptr && right != nullptr) {
            return root;
        }
        return nullptr;
    }

    // 235.二叉搜索树的最近公共祖先：给定一个二叉搜索树,找到该树中两个指定节点的最近公共祖先。
    // 解法：即从上往下遍历，第一个位于 p q 之间的即是
    TreeNode* lowestCommonAncestorBSTNonRecursion(TreeNode* root,
                                                  TreeNode* p,
                                                  TreeNode* q) {
        queue<TreeNode*> que;
        que.push(root);
        int left = std::min(p->val, q->val);
        int right = std::max(p->val, q->val);
        while (!que.empty()) {
            TreeNode* n = que.front();
            que.pop();
            if (n->val == p->val || n->val == q->val ||
                (n->val > left && n->val < right)) {
                return n;
            }
            if (n->left != nullptr) {
                que.push(n->left);
            }
            if (n->right != nullptr) {
                que.push(n->right);
            }
        }
        return nullptr;
    }

    // 701. 二叉搜索树的插入
    // 给定二叉搜索树（BST）的根节点 root 和要插入树中的值 value
    // ，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            TreeNode* n = new TreeNode(val);
            return n;
        }

        if (val > root->val) {
            root->right = insertIntoBST(root->right, val);
        }

        if (val < root->val) {
            root->left = insertIntoBST(root->left, val);
        }
        return root;
    }

    // 450.删除二叉搜索树
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->val == key) {
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }
            if (root->left == nullptr) {
                auto tmp = root->right;
                delete root;
                return tmp;
            }
            if (root->right == nullptr) {
                auto tmp = root->left;
                delete root;
                return tmp;
            }
            // 第五种情况：左右孩子节点都不为空，则将删除节点的左子树头结点（左孩子）
            // 放到删除节点的右子树的最左面节点的左孩子上，返回删除节点右孩子为新的根节点。
            auto rightPre = root->right;
            while (rightPre->left != nullptr) {
                rightPre = rightPre->left;
            }
            rightPre->left = root->left;
            return root->right;
        }
        if (root->val > key)
            root->left = deleteNode(root->left, key);
        if (root->val < key)
            root->right = deleteNode(root->right, key);
        return root;
    }

    // 669. 修剪二叉搜索树
    // 给你二叉搜索树的根节点 root ，同时给定最小边界low 和最大边界
    // high。通过修剪二叉搜索树， 使得所有节点的值在[low, high]中。修剪树 不应该
    // 改变保留在树中的元素的相对结构
    //(即，如果没有被移除，原有的父代子代关系都应当保留)。 可以证明，存在
    // 唯一的答案 。 所以结果应当返回修剪好的二叉搜索树的新的根节点。
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->val < low) {
            return trimBST(root->right, low, high);
        }
        if (root->val > high) {
            return trimBST(root->left, low, high);
        }

        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }

    // 108.有序数组转换为二叉搜索树:附加条件 高度平衡
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return traversalForArraytoBST(nums, 0, nums.size());
    }

    TreeNode* traversalForArraytoBST(vector<int> nums, int left, int right) {
        if (left == right) {
            return nullptr;
        }
        int mid = (left + right) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = traversalForArraytoBST(nums, left, mid);
        node->right = traversalForArraytoBST(nums, mid + 1, right);
        return node;
    }

    // 538.二叉搜索树转累加树：累加树是使得每个节点的值是原来的节点值加上所有大于它的节点值之和。
    int preValue = 0;
    TreeNode* convertBST(TreeNode* root) {
        // BST中序遍历
        traversalForConBST(root);
        return root;
    }

    void traversalForConBST(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        traversalForConBST(root->right);
        root->val += preValue;
        preValue = root->val;
        traversalForConBST(root->left);
    }
};