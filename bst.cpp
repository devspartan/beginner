#include <bits/stdc++.h>
// kickStart
using namespace std;

struct Node {
    int data;
    int sum;
    struct Node *left;
    struct Node *right;
};

class BST {

  public:
    Node *root;
    int a;

    BST() { root = NULL; }

    Node *createNode(int data);
    Node *levelTree(Node *root, int arr[], int i, int size);
    Node *bt(int data);
    void inorderTraversal(Node *root, vector<int> &v, int lvl);
    void inorderWithoutRec();
    void levelOrderTraversal();
    void reverseLvelOrderTraversal();
    void preOrderWithoutRec();
    void mirrorTree(Node *temp);
    Node *levelTree(vector<int> arr, int size);
    int maxDepth(Node *temp);
    int minDepth(Node *temp);
    int maxWidth(Node *root);
    int findSum(Node *temp, int trueSum, int &count);
    int HighestTeamTenure(Node *childNode);
    int maxSumPath(Node *temp, int sum);
    int maxSumBetweenLeafNodes(Node *root, int *sum);
    int countLeafNodes(Node *temp);
    int countHalfNodes(Node *temp);
    Node *lca(int n1, int n2);
    Node *BTfromParentArray(int parent[], int n);
    Node *getNumberOfChildren(Node *tree, Node *countTree);
    Node *sortedArrayToBST(vector<int> arr, int st, int end);
    bool hasPathSum(Node *temp, int sum);
    void printRightView(Node *temp);
    Node *func(Node *temp, vector<int> &arr, int target, int idx);
    int rangeSumBST(Node *root, int l, int r);
    Node *mergeTrees(Node *r1, Node *r2);
    int sumRootToLeaf(Node *root, vector<int> &vt);
    Node *trimBst(Node *root, int low, int high);
    void rightSideView(Node *root);
    Node *convertBSTtoGT(Node *root);
    vector<double> averageOfLevels(Node *root);
    Node *addOneRow(Node *root, int v, int d);
    bool isValidBST(Node *root);
    bool isSymmetric(Node *root);
    Node *constructMaximumBinaryTree(vector<int> &nums);
    Node *constructMBTHelper(vector<int> &nums, int start, int end);
    int pseudoPalindromicPaths();
};

Node *BST::createNode(int data) {
    Node *newNode = new Node;
    // cout << sizeof(Node) << "size" << endl;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *BST::levelTree(Node *temp, int arr[], int i, int size) {
    if (i < size) {
        temp = createNode(arr[i]);
        temp->left = levelTree(temp->left, arr, 2 * i + 1, size);
        temp->right = levelTree(temp->right, arr, 2 * i + 2, size);
    } else {
        return temp;
    }

    return temp;
}

void BST::inorderTraversal(Node *root, vector<int> &v, int lvl) {
    Node *temp = root;
    if (temp == NULL) {
        return;
    }

    inorderTraversal(temp->left, v, lvl + 1);
    v.push_back(temp->data);
    cout << temp->data << " "
         << " LVL: " << lvl << endl;
    inorderTraversal(temp->right, v, lvl + 1);
}

void BST::inorderWithoutRec() {
    stack<Node *> st;
    Node *curr = root;
    bool check = true;
    while (check) {
        // cout << curr->data << endl;
        if (curr != NULL) {
            st.push(curr);
            // cout << "in left " << curr->data << endl;
            curr = curr->left;
        } else {
            if (st.size() != 0) {
                curr = st.top();
                st.pop();
                cout << curr->data << " ";
                curr = curr->right;
            } else {
                check = false;
            }
        }
    }
    cout << endl;
}

void BST::levelOrderTraversal() {
    queue<Node *> q;
    Node *temp = root;
    while (temp != NULL) {
        cout << temp->data << " ";
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
        temp = q.front();
        q.pop();
    }
    cout << " level order traversal " << endl;
}

void BST::preOrderWithoutRec() {
    stack<Node *> st;
    st.push(root);

    while (st.size()) {
        Node *temp = st.top();
        st.pop();
        cout << temp->data << " ";

        if (temp->right != NULL) {
            st.push(temp->right);
        }
        if (temp->left != NULL) {
            st.push(temp->left);
        }
    }
    cout << endl;
}

int BST::findSum(Node *temp, int trueSum, int &count) {

    if (temp == NULL) {
        return 0;
    }

    int tempSum = temp->data + findSum(temp->left, trueSum, count) +
                  findSum(temp->right, trueSum, count);
    cout << temp->data << "  " << tempSum << endl;
    if (tempSum == trueSum) {
        count++;
        cout << count << endl;
    }

    return tempSum;
}

Node *BST::bt(int data) {
    if (root == NULL) {
        root = createNode(data);
    } else {
        Node *newNode = createNode(data);
        Node *temp2 = root;
        while (true) {
            if (data > temp2->data && temp2->right == NULL) {
                temp2->right = newNode;
                break;
            } else if (data <= temp2->data && temp2->left == NULL) {
                temp2->left = newNode;
                break;
            } else if (data <= temp2->data && temp2->left != NULL) {
                temp2 = temp2->left;
            } else if (data > temp2->data && temp2->right != NULL) {
                temp2 = temp2->right;
            }
        }
    }

    return root;
}

Node *BST::BTfromParentArray(int parent[], int n) {

    int max = 0;
    for (int i = 0; i < n; i++) {
        if (parent[i] > max) {
            max = parent[i];
        }
    }

    Node *tree;
    Node *hashArr[max] = {0};
    for (int i = 0; i < n; i++) {
        if (parent[i] == -1) {
            tree = createNode(i);
            hashArr[i] = tree;
        } else {
            int num = parent[i];
            Node *pt = hashArr[num];

            if (pt->left == NULL) {
                pt->left = createNode(i);
                hashArr[i] = pt->left;
            } else {
                pt->right = createNode(i);
                hashArr[i] = pt->right;
            }
        }
    }

    return tree;
}

int BST::HighestTeamTenure(Node *childNode) {

    if (childNode->left == NULL && childNode->right == NULL) {
        // cout << childNode->data << " ";
        return childNode->data;

    }

    else if (childNode->left != NULL && childNode->right != NULL) {
        cout << childNode->data << "  " << childNode->left->data << "  "
             << childNode->right->data << endl;
        childNode->data = childNode->data + HighestTeamTenure(childNode->left) +
                          HighestTeamTenure(childNode->right);
        // cout << childNode->data << " ";
        return childNode->data;

    }

    else if (childNode->left == NULL && childNode->right != NULL) {
        childNode->data = childNode->data + HighestTeamTenure(childNode->right);
        // cout << childNode->data << " ";
        return childNode->data;
    }

    else if (childNode->left != NULL && childNode->right == NULL) {
        childNode->data = childNode->data + HighestTeamTenure(childNode->left);
        // cout << childNode->data << " ";
        return childNode->data;
    }
    return childNode->data;
}

int BST::maxSumPath(Node *temp, int sum) {

    if (temp->left == NULL && temp->right == NULL) {
        return temp->data;
    }

    else if (temp->right == NULL && temp->left != NULL) {
        int tempSum = temp->data + maxSumPath(temp->left, sum);
        return tempSum;
    } else if (temp->right != NULL && temp->left == NULL) {
        int tempSum = temp->data + maxSumPath(temp->right, sum);
        return tempSum;
    } else {
        int lt = temp->data + maxSumPath(temp->left, sum);
        int rt = temp->data + maxSumPath(temp->right, sum);
        cout << temp->data << " -->  ";
        return max(lt, rt);
    }
}

int BST::maxDepth(Node *temp) {
    // return no of nodes of longest path from root to leaf
    if (temp == NULL) {
        return 0;
    } else {
        int lt = maxDepth(temp->left);
        int rt = maxDepth(temp->right);
        int mxD = max(lt, rt);
        return mxD + 1;
    }
}

Node *BST::lca(int n1, int n2) {

    Node *temp = root;
    while (temp != NULL) {
        if (temp->data > n1 && temp->data > n2) {
            temp = temp->left;
        } else if (temp->data < n1 && temp->data < n2) {
            temp = temp->right;
        } else {
            return temp;
        }
    }

    cout << "NO COMMON ANCSTER";
    return root;
}

int BST::countLeafNodes(Node *temp) {
    if (temp == NULL) {
        return 0;
    }
    if (temp->left == NULL && temp->right == NULL) {
        return 1;
    }

    return countLeafNodes(temp->left) + countLeafNodes(temp->right);
}

void BST::reverseLvelOrderTraversal() {
    queue<Node *> q;
    stack<Node *> s;
    Node *temp = root;
    s.push(temp);
    q.push(temp->right);
    q.push(temp->left);
    while (q.size() != 0) {
        temp = q.front();
        q.pop();
        if (temp->right != NULL)
            q.push(temp->right);
        if (temp->left != NULL)
            q.push(temp->left);
        s.push(temp);
    }

    while (s.size() != 0) {
        cout << s.top()->data << " ";
        s.pop();
    }

    cout << endl;
}

void BST::mirrorTree(Node *temp) {

    if (temp == NULL) {
        return;
    }

    Node *swapNode = temp->left;
    temp->left = temp->right;
    temp->right = swapNode;
    mirrorTree(temp->left);
    mirrorTree(temp->right);
}

Node *BST::sortedArrayToBST(vector<int> arr, int st, int end) {
    cout << st << "  " << end << endl;

    if (st == end || st > end) {
        return NULL;
    }

    int mid = (st + end) / 2;
    Node *temp = createNode(arr[mid]);
    cout << temp->data << endl;
    temp->left = sortedArrayToBST(arr, st, mid);
    temp->right = sortedArrayToBST(arr, mid + 1, end);
    return temp;
}

int BST::countHalfNodes(Node *temp) {
    // nodes with one child

    if (temp == NULL) {
        return 0;
    } else if (temp->left == NULL && temp->right != NULL) {
        return countHalfNodes(temp->right) + 1;
    }

    else if (temp->right == NULL && temp->left != NULL) {
        return countHalfNodes(temp->left) + 1;
    }

    else if (temp->left != NULL && temp->right != NULL) {
        return countHalfNodes(temp->left) + countHalfNodes(temp->right);
    }

    return 0;
}

Node *BST::levelTree(vector<int> arr, int size) {

    int i = 0;
    queue<Node *> q;
    Node *head = createNode(arr[i]);
    cout << createNode(arr[i]) << " arr address" << endl;
    q.push(head);
    i++;
    while (i < size) {
        cout << arr[i] << " ";
        Node *parent = q.front();
        q.pop();

        Node *lft = createNode(arr[i]);
        Node *rght = NULL;

        i++;
        if (i < size) {
            rght = createNode(arr[i]);
        }

        q.push(lft);
        q.push(rght);
        parent->left = lft;
        parent->right = rght;
        i += 1;
    }
    cout << "level tree created" << endl;
    root = head;
    return head;
}

bool BST::hasPathSum(Node *temp, int sum) {
    // return true if there exits a path from root to leaf with sum == k else
    // false
    if (temp == NULL) {
        return (sum == 0);
    } else {
        int ans = 0;
        int subSum = sum - temp->data;

        if (subSum == 0 && temp->left == NULL && temp->right == NULL) {
            return 1;
        }

        if (temp->left != NULL) {
            ans = ans || hasPathSum(temp->left, subSum);
        }
        if (temp->right != NULL) {
            ans = ans || hasPathSum(temp->right, subSum);
        }

        return ans;
    }
}

void BST::printRightView(Node *temp) {

    if (temp == NULL) {
        return;
    }

    queue<Node *> q;
    int c1 = 1;
    int c2 = 0;
    q.push(temp);
    while (q.size() != 0) {
        Node *pt = q.front();
        q.pop();
        c1--;

        if (pt->left != NULL) {
            q.push(pt->left);
            c2++;
        }
        if (pt->right != NULL) {
            q.push(pt->right);
            c2++;
        }

        if (c1 == 0) {
            cout << pt->data << " ";
            c1 = c2;
            c2 = 0;
        }
    }
    cout << endl;
}

int BST::minDepth(Node *temp) {

    if (temp->left == NULL && temp->right == NULL) {
        return 1;
    }
    int lt = INT_MAX;
    int rt = INT_MAX;
    if (temp->left != NULL) {
        lt = minDepth(temp->left);
    }
    if (temp->right != NULL) {
        rt = minDepth(temp->right);
    }

    return min(lt, rt) + 1;
}

int BST::maxWidth(Node *root) {
    // maximum number of elements a certain level
    if (root == NULL) {
        return 0;
    }

    int result = 0;
    queue<Node *> q;

    q.push(root);
    // q.push(NULL);
    while (!q.empty()) {

        int count = q.size();

        result = max(count, result);

        // Node *currNode = q.front();
        // q.pop();
        while (count--) {

            Node *ft = q.front();
            q.pop();

            // currNode->next = ft;

            if (ft->left) {
                q.push(ft->left);
            }
            if (ft->right) {
                q.push(ft->right);
            }
        }
        // q.push(NULL);
    }
    return result;
}

int BST::maxSumBetweenLeafNodes(Node *root, int *sum) {
    // returns maximum sum possible between two leaf nodes;
    if (root == NULL) {
        return 0;
    }

    int lt = maxSumBetweenLeafNodes(root->left, sum);
    int rt = maxSumBetweenLeafNodes(root->right, sum);

    int subSum = max(max(lt, rt) + root->data, lt + rt + root->data);

    *sum = max(*sum, subSum);

    return max(lt, rt) + root->data;
}

int BST::rangeSumBST(Node *root, int l, int r) {
    // return sum having nodes data between l and r inclusive

    if (root == NULL) {
        return 0;
    }

    if (root->data == r) {
        // cout << "from 1 " << root->data << endl;;
        return root->data + rangeSumBST(root->left, l, r);
    } else if (root->data >= l && root->data < r) {
        // cout << "from 2 " << root->data << endl;;

        int t2 = rangeSumBST(root->left, l, r);
        int t1 = rangeSumBST(root->right, l, r);
        return t1 + t2 + root->data;
    } else if (root->data < l) {
        // cout << "from 3 " << root->data << endl;;

        int t2 = rangeSumBST(root->right, l, r);
        return t2;
    } else if (root->data >= r) {
        // cout << "from 4 " << root->data << endl;;

        int t1 = rangeSumBST(root->left, l, r);
        return t1;
    }

    return 0;
}

Node *BST::mergeTrees(Node *r1, Node *r2) {
    if (r1 == NULL && r2 == NULL) {
        return NULL;
    }

    if (r1 != NULL && r2 != NULL) {
        r1->data += r2->data;
    }

    if (r1 == NULL && r2 != NULL) {
        return r2;
    } else if (r1 != NULL && r2 == NULL) {
        return r1;
    } else {
        r1->left = mergeTrees(r1->left, r2->left);
        r1->right = mergeTrees(r1->right, r2->right);
        return r1;
    }
}

int BST::sumRootToLeaf(Node *root, vector<int> &vt) {
    // nodes have value 0 & 1 root to leaf convert binary to decimal and return
    // sum
    // of all paths;
    if (root->left == NULL && root->right == NULL) {
        vt.push_back(root->data);
        int size = vt.size();
        int num = 0;
        // cout << size << endl;
        for (int i = size - 1; i >= 0; i--) {
            num += pow(2, size - 1 - i) * vt[i];
            // cout << num  << "df" << endl;
        }
        vt.pop_back();
        return num;
    }

    int n1 = 0, n2 = 0;
    vt.push_back(root->data);
    // cout << vt.size() << " sd " << endl;
    if (root->left != NULL) {
        // cout << "from left";
        n1 = sumRootToLeaf(root->left, vt);
    }
    if (root->right != NULL) {
        // cout << "from right";
        n2 = sumRootToLeaf(root->right, vt);
    }
    vt.pop_back();
    return n1 + n2;
}

void levelOrderTemp(Node *root) {
    queue<Node *> q;
    Node *temp = root;
    while (temp != NULL) {
        cout << temp->data << " ";
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
        temp = q.front();
        q.pop();
    }
    cout << endl;
}

Node *BST::trimBst(Node *rt, int low, int high) {

    if (rt == NULL) {
        return rt;
    }
    if (rt->left == NULL && rt->right == NULL) {
        if (rt->data >= low && rt->data <= high) {
            cout << "in if " << rt->data << "  " << rt->left << " " << rt->right
                 << endl;
            return rt;
        } else {
            cout << "in else  " << rt->data << "  " << rt->left << " "
                 << rt->right << endl;
            return NULL;
        }
    }

    if (low <= rt->data && rt->data < high) {
        cout << "in first " << rt->data << endl;
        rt->left = trimBst(rt->left, low, high);
        rt->right = trimBst(rt->right, low, high);

    } else if (low <= rt->data && rt->data >= high) {
        cout << "in second " << rt->data << endl;

        if (rt->data == low || rt->data == high) {
            rt->right = NULL;
            rt->left = trimBst(rt->left, low, high);
        } else {
            rt = trimBst(rt->left, low, high);
        }

    } else if (low > rt->data && rt->data > high) {
        cout << "in third " << rt->data << endl;
        rt->left = NULL;
        if (rt->data == low || rt->data == high) {
            rt->right = trimBst(rt->right, low, high);
        } else {
            rt = trimBst(rt->right, low, high);
        }
    }

    return rt;
}

int convertBSTUtil(Node *root, int sum) {

    if (root == NULL) {
        return sum;
    }

    int temp = convertBSTUtil(root->right, sum);
    root->data += temp;
    temp = root->data;
    int temp2 = convertBSTUtil(root->left, temp);

    return temp2;
}

Node *BST::convertBSTtoGT(Node *root) {
    int sum = convertBSTUtil(root, 0);
    cout << sum << endl;
    // levelOrderTraversal();
    return root;
}
int MaxLevel = 0;

void rightSideView(Node *root, int level) {
    if (root == NULL) {
        return;
    }
    if (level > MaxLevel) {
        cout << root->data << " ";
        MaxLevel++;
    }
    level++;
    rightSideView(root->right, level);
    rightSideView(root->left, level);
}

vector<double> BST::averageOfLevels(Node *root) {
    // [2147483647,2147483647,2147483647]
    vector<double> res;
    Node *tt = root;

    queue<Node *> q;
    q.push(tt);
    long int c1 = 0;
    long int c2 = 1;
    long int sum = 0;
    long int count = 1;
    while (!q.empty()) {
        tt = q.front();
        q.pop();
        sum += tt->data;
        c2--;

        if (tt->left != NULL) {
            q.push(tt->left);
            c1++;
        }
        if (tt->right != NULL) {
            q.push(tt->right);
            c1++;
        }

        if (c2 == 0) {
            cout << count << " " << sum << endl;
            double temp = float(sum) / float(count);
            res.push_back(temp);
            c2 = c1;
            count = c1;
            c1 = 0;
            sum = 0;
        }
    }

    return res;
}

Node *BST::addOneRow(Node *root, int v, int d) {
    if (d == 1) {
        Node *g = createNode(v);
        g->left = root;
        root = g;
        return root;
    }
    Node *tt = root;
    queue<Node *> q;
    q.push(tt);
    int depth = 1;
    int c1 = 0;
    int c2 = 1;
    while (true) {
        if (d - 1 == depth) {
            while (!q.empty()) {
                Node *ak = q.front();
                q.pop();
                Node *newNode = createNode(v);
                newNode->left = ak->left;
                ak->left = newNode;
                newNode = createNode(v);
                newNode->right = ak->right;
                ak->right = newNode;
            }

            break;
        }
        tt = q.front();
        q.pop();
        c2--;

        if (tt->left != NULL) {
            q.push(tt->left);
            c1++;
        }
        if (tt->right != NULL) {
            q.push(tt->right);
            c1++;
        }

        if (c2 == 0) {
            c2 = c1;
            c1 = 0;
            depth++;
        }
    }
    return root;
}

bool isValidBSTUtil(Node *root, long long int l, long long int r) {
    if (root == NULL) {
        return true;
    }
    bool t1 = isValidBSTUtil(root->left, l, root->data);
    bool t2 = isValidBSTUtil(root->right, root->data, r);
    bool t3 = false;
    if (l < root->data && root->data < r) {
        t3 = true;
    }
    if (t1 == false || t2 == false || t3 == false) {
        return false;
    }
    return true;
}

bool BST::isValidBST(Node *root) {
    return isValidBSTUtil(root, INT64_MIN, INT64_MAX);
}

bool isSymmnetricUtil(Node *left, Node *right) {
    if (left == NULL && right == NULL) {
        return true;
    } else if (left == NULL || right == NULL) {
        return false;
    }

    return left->data == right->data &&
           isSymmnetricUtil(left->left, right->right) &&
           isSymmnetricUtil(left->right, right->left);
}

bool BST::isSymmetric(Node *root) {
    return isSymmnetricUtil(root->left, root->right);
}

Node *BST::constructMBTHelper(vector<int> &nums, int start, int end) {
    if (start > end || start < 0 || end >= nums.size()) {
        return NULL;
    }

    int max = -1;
    int maxIdx = -1;
    for (int i = start; i <= end; i++) {
        if (nums[i] > max) {
            max = nums[i];
            maxIdx = i;
        }
    }

    Node *res = createNode(nums[maxIdx]);
    res->left = constructMBTHelper(nums, start, maxIdx - 1);
    res->right = constructMBTHelper(nums, maxIdx + 1, end);
    return res;
}

Node *BST::constructMaximumBinaryTree(vector<int> &nums) {
    return constructMBTHelper(nums, 0, nums.size() - 1);
}

vector<vector<int>> levelOrder(Node *root) {
    vector<vector<int>> res;
    if (root == NULL) {
        return res;
    }

    queue<Node *> q;
    queue<Node *> q2;
    Node *temp = root;
    res.push_back(vector<int>(1, temp->data));
    q.push(temp);
    while (!q.empty()) {
        vector<int> rt;
        while (!q.empty()) {
            Node *tt = q.front();
            q.pop();

            if (tt->left != NULL) {
                rt.push_back(tt->left->data);
                q2.push(tt->left);
            }
            if (tt->right != NULL) {
                rt.push_back(tt->right->data);
                q2.push(tt->right);
            }
        }

        while (!q2.empty()) {
            q.push(q2.front());
            q2.pop();
        }

        res.push_back(rt);
    }

    // for (int i = 0; i < res.size(); i++) {
    //     for (int j = 0; j < res[i].size(); j++) {
    //         cout << res[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    return res;
}

int pseudoPalindromicPathsUtil(Node *root, unordered_map<int, int> &ump) {

    if (root == NULL) {
        return 0;
    }

    ump[root->data]++;

    if (root->left == NULL && root->right == NULL) {
        int count = 0;
        for (auto it : ump) {
            if (it.second % 2 == 1) {
                count++;
            }
        }
        ump[root->data]--;
        return count >= 2 ? 0 : 1;
    }

    int t1 = pseudoPalindromicPathsUtil(root->left, ump);
    int t2 = pseudoPalindromicPathsUtil(root->right, ump);
    ump[root->data]--;

    return t1 + t2;
}

int BST::pseudoPalindromicPaths() {
    unordered_map<int, int> ump;
    Node *temp = root;
    return pseudoPalindromicPathsUtil(temp, ump);
}

// Node *recoverFromPreorder(string t) {}

int main() {
    BST bt1;
    BST bt2;
    int size = 16;
    int size2 = 9;
    vector<int> arr = {2, 3, 1, 3, 2, 2, 4};
    int arr2[size2] = {4, 2, 7, 5, 6, 1, 3, 2, 4};
    Node *temp = NULL;
    // for (int i = 0; i < arr.size(); i++) {
    //     bt2.bt(arr2[i]);
    // }
    bt1.levelTree(arr, arr.size());
    bt1.levelOrderTraversal();
    // bt1.inorderWithoutRec();
    // levelOrder(bt1.root);
    // Node *tt = bt1.sortedArrayToBST(arr, 0, arr.size() - 1);

    vector<int> v1 = {5, 8, 7, 6, 15, 2, 4, 12, 5, 4};
    vector<int> v2;
    vector<int> v3;

    bt1.pseudoPalindromicPaths();
    // cout << bt1.isSymmetric(bt1.root) << endl;
    // bt1.addOneRow(bt1.root, -2, 5);
    // cout << bt1.isValidBST(bt1.root) << endl;
    // bt1.averageOfLevels(bt1.root);
    // rightSideView(bt1.root, 1);
    // bt1.convertBSTtoGT(bt1.root);

    // Node * asq = bt1.trimBst(bt1.root, 0, 3);
    // levelOrderTemp(asq);

    // temp = bt1.levelTree(arr, size2);
    // bt1.inorderTraversal(temp, v1, 0);
    // cout << bt1.sumRootToLeaf(temp, v1) << endl;
    // temp = bt1.mergeTrees(bt1.root, bt2.root);
    // int sum = bt1.rangeSumBST(bt1.root, 6, 10);
    // cout << "sum: " << sum  << endl;
    // cout << bt1.maxSumPath(bt1.root, 0) << endl;

    // bt1.inorderTraversal(bt1.root, v1, 1);
    // bt1.inorderWithoutRec();
    // bt1.mirrorTree(bt1.root);
    // bt1.inorderWithoutRec();
    // cout << "level order: ";
    // cout << "maxDepth: " << bt1.maxDepth(bt1.root) << endl;
    // cout << "minDepth: " << bt1.minDepth(bt1.root) << endl;
    // cout << "maxWidth: " << bt1.maxWidth(bt2.root) << endl;
    // bt1.preOrderWithoutRec();
    // cout << "leafNodeCount: " <<  bt1.countLeafNodes(bt1.root) << endl;
    // cout << "halhNodesCount: " << bt1.countHalfNodes(bt1.root) << endl <<
    // endl;
    //
    // cout << "lets print ";
    // bt2.printRightView(bt2.root) ;
    //
    // cout << bt1.hasPathSum(bt1.root, 13) << endl;
    // cout << "im out" << endl;
    // Node *lvlTree = NULL;
    // lvlTree = bt1.levelTree(arr2, size);
    // bt1.inorderTraversal(lvlTree, v1, 0);
    //
    // bt1.reverseLvelOrderTraversal();
    // 1337x.to
    // balalnced search tree from sorted array
    // Node *sortedTree;
    // int sortedArr[15] = {1, 2, 3, 4, 5, 6, 7, 8};
    // sortedTree = bt1.sortedArrayToBST(sortedArr, 0, 8);
    // bt1.inorderTraversal(sortedTree, v3, 1);

    // cout << endl << endl;
    // int minSum = INT_MIN;
    // cout << bt1.maxSumBetweenLeafNodes(bt1.root, &minSum);

    // bt2.inorderTraversal(bt2.root, v2);
    // int tempArr[5] = {-1, 0, 0, 2, 2};
    // Node *tree = bt1.BTfromParentArray(tempArr, 5);
    // bt1.inorderTraversal(tree, v3);

    // int dt = bt1.HighestTeamTenure(bt1.root);
    // cout << dt << endl;

    // vector<int> vt = {1, 2, 3, 5, 1, 4, 6, 7};
    // Node *countTree = bt1.createNode(0);
    // countTree->sum = 15;

    // cout << sizeof(Node) << " " << sizeof(BST) << endl;
    // bt1.inorderTraversal(bt1.root, v1);

    // temp = bt.levelTree(temp, arr, 0, 7);
    // int count = 0;
    // bt.findSum(temp, 7, count);

    // cout << count << endl;
}