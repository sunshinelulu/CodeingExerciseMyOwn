#include<vector>
#include<iostream>
#include<queue>
using namespace std;
//关于剑值offer中的入栈序列和出栈序列的一道问题解法
class PushAndPopVector {
public:
	bool IsPopOrder(vector<int> pushV,vector<int> popV){
		if(pushV.size() == 0) return false;
		vector<int> stack;
		int len = popV.size();
		for(int i = 0,j = 0 ;i < len;){
			stack.push_back(pushV[i++]);
			while(j <  len && stack.back() == popV[j]){
				stack.pop_back();
				j++;
			}
		}
		return stack.empty();
	}
};
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
//从上到下，从左到由遍历二叉树
class PrintTreeUpDownLeftRight {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
    	vector<int> result;
    	if(root != NULL){
    		queue<TreeNode*>TreeNodes;
    		TreeNodes.push(root);
    		while(! TreeNodes.empty()){
    			TreeNode* node =  TreeNodes.front();
    			TreeNodes.pop();
    			if(node->left != NULL)TreeNodes.push(node->left);
    			if(node->right != NULL)TreeNodes.push(node->right);
    			result.push_back(node->val);
    		}
    	}
    	return result;

    }
};
//验证某一序列是否为，二叉搜索数的合法序列
class VerifySquence {
public:
	bool AssistVerifySquenceOfBST(vector<int>& sequence, int left, int right){
		if(left >= right)return true;
		else{
			int root = sequence[right];
			int lessIndex;
			for(lessIndex = left; lessIndex < right; lessIndex++){
				if(sequence[lessIndex] > root)break;
			}
			int moreIndex;
			for(moreIndex = right-1; moreIndex >= left; moreIndex--){
					if(sequence[moreIndex] < root)break;
			}
			if(lessIndex == moreIndex +1){
				bool leftChild = AssistVerifySquenceOfBST(sequence, left, moreIndex);
				bool rightChild = AssistVerifySquenceOfBST(sequence, lessIndex, right-1);
				return  leftChild && rightChild;
			}else{
				return false;
			}
		}
	}
    bool VerifySquenceOfBST(vector<int> sequence) {
    	int len = sequence.size();
    	bool result = true;
    	if(len > 0){
    		return AssistVerifySquenceOfBST(sequence, 0, len -1);
    	}
    	return result;
    }
};
//找出二叉树中和为某一值的所有路径
class allPathInBinaryTree{
private:
	vector<int> singlePath;
	vector<vector<int>> result;
public:
	void AssistFindPath(TreeNode* root,int expectNumber, vector<int>& singlePath, int sum){
		if(root == NULL)return;
		if(root->left == NULL && root->right == NULL){
			if(sum + root->val == expectNumber){
				singlePath.push_back(root->val);
				vector<int> newPath = vector<int>(singlePath);
				result.push_back(newPath);
				singlePath.pop_back();
			}
			return;
		}else{
			singlePath.push_back(root->val);//将非叶子节点放入栈中
			AssistFindPath(root->left, expectNumber, singlePath, sum + root->val);
			AssistFindPath(root->right, expectNumber, singlePath, sum + root->val);
			singlePath.pop_back();//遍历完该子树后需要将根节点从中pop出来，以便回退到上一层节点进行下一个子树的遍历
		}

	}
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
    	AssistFindPath(root, expectNumber, singlePath, 0);
    	return result;
    }
};

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
//这是一道关于复杂链表的复制题目，看起来以及做起来都挺难的，要特别注意。
class RandomListClone {
public:
	RandomListNode* Clone(RandomListNode* pHead){
		if(!pHead) return NULL;
		RandomListNode *currNode = pHead;
		//第一步：先对链表节点进行复制
		while(currNode){
			RandomListNode *node = new RandomListNode(currNode->label);
			node->next = currNode->next;
			currNode->next = node;
			currNode = node->next;
		}
		//第二步：对其的random进行修改
		currNode = pHead;
		while(currNode){
			RandomListNode *node = currNode->next;
			if(currNode->random){
				node->random = currNode->random->next;
			}
			currNode = node->next;
		}
		//拆分，恢复原来的数组的样子     
		RandomListNode *pCloneHead = pHead->next;
		RandomListNode *tmp;
		currNode = pHead;
		while(currNode->next){
			tmp = currNode->next;
			currNode->next =tmp->next;
			currNode = tmp;
		}
		return pCloneHead;
	}
};
//将一棵二叉排序树转换为一个双向链表
//这道题目的思路其实是在中序遍历过程中进行一些操作的记录，因此，属于很取巧的做法。
class SortTree2List {
private:
	TreeNode *leftHead = NULL; //只要设置两个全局变量就可以啦
	TreeNode *rightHead = NULL;//需要设置两个全局变量来解决问题。
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if(pRootOfTree == NULL)return NULL;
		Convert(pRootOfTree->left);
		if(rightHead == NULL){ //表明当前的链表中什么都没有，需要进行初始化
			leftHead = rightHead = pRootOfTree;
		}else{
			rightHead->right = pRootOfTree; //需要增加新的节点到队列中去
			pRootOfTree->left = rightHead;
			rightHead = pRootOfTree;
		}
		Convert(pRootOfTree->right);
		return leftHead;
	}


};
//字符串的全排列问题
