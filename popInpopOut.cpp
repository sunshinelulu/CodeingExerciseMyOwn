#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>
#include<set>
#include<string.h>
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
//验证某一序列是否为，二叉搜索数的后续遍历的合法序列
//这道题目好像印象不太深刻了，但是似乎就是要找到是否是合法的后续遍历序列。
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
//字符串的全排列问题，是我的死区问题。
//感觉这道题目真的很难，真的没有完全理解清楚到底是什么意思，千万不要出这种个题目呀
//不知道这种题目是不是真的只有记住答案了现在的时间真的是泰紧急了。
class StrPermutation {
public:
	void Permutation(vector<string>& array, string str, int begin){
		int len = str.length();
		if(begin == len-1){
			array.push_back(str);
			return;
		}else{
			for(int i = begin; i < len; ++i){
				//为了解决字符串中共有重复字符的问题，在交换之前还要检查是否重复
				if(i != begin && str[i] == str[begin] )
					continue;
				swap(str[i], str[begin]); //原来c++中真的有这么个东西，真是无法理解呀
				Permutation(array, str, begin + 1);
				swap(str[i], str[begin]);//原来c++中真的有这么个东西，真是无法理解呀
			}
		}
	}
    vector<string> Permutation(string str) {
    	vector<string> array;
    	if(str.length() > 0){
    		Permutation(array, str, 0);
    	}
    	//好麻烦还要对结果进行排序真是的。
    	sort(array.begin(), array.end());
    	return array;
    }
};
//找到出现次数大于一半的数字，若没有则返回0；例如9的一半为4，出现5次即是合法的。
class FinkCountUpHalf {
    public:
        int MoreThanHalfNum_Solution(vector<int> numbers) {
        	int len = numbers.size();
        	map<int, int> count;
        	for(int i = 0; i < len; i++){
        		if(count.find(numbers[i]) != count.end()){
        			count[numbers[i]] ++;
        		}else{
        			count[numbers[i]] = 1;
        		}
        	}
        	for(map<int, int>::iterator i = count.begin(); i != count.end(); ++i){
        		if(i->second > (len/2))
        			return i->first;
        	}
        	return 0;
        }
        //第二种别人家的巧妙的解法，利用num，对num进行计数目，如果与num相同，则count加一，如果不同规则减一，如果等于0则需要重新选择num的值并
        //并进行计数，这样如果存在大于一半的数，则回事最后让count大于0的num
        int MoreThanHalfNum_Solution2(vector<int> numbers) {
        	int n = numbers.size();
        	if (n == 0) return 0;
        	int num = numbers[0], count = 1;
        	for (int i = 1; i < n; i++) {
        		if (numbers[i] == num) count++;
        		else count--;
        		if (count == 0) {
        			num = numbers[i];
        			count = 1;
        		}}
        	// Verifying ，之所以要进行检查是因为2,2,3,3,4,4最后num为4但却不是题目所要求的值。   
        	count = 0;
        	for (int i = 0; i < n; i++) {
        		if (numbers[i] == num) count++;
        	}
        	if (count * 2 > n) return num;
        	return 0;
        }
    };
struct pririty_queue_compare{ //优先队列所需要使用的比较函数的结构特征。
public:
	bool operator()(int a, int b){
		return a < b;
	}
};
//找出数组中最小的k个数目，我想用一个优先队列来做这道题目，顺便练习一下c++中的优先队列的使用方法，这样再出到类似题目的编程题目的时候就可以很好的使用优先队列了。
class FindKmin {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    	priority_queue<int, vector<int>, pririty_queue_compare> kMin;//原来如果要使用自己写的比较函数，要用三个参数对其进行初始化呀。
    	vector<int> result(k);
    	int len = input.size();
    	if(k >= len){
    		sort(input.begin(), input.end());
    		vector<int> temp = vector<int>(input);
    		return temp;
    	}else{
    		for(int i = 0; i < k; ++i){
    			kMin.push(input[i]);
    		}
    		for(int i = k; i < len; ++i){
    			int top = kMin.top();
    			if(input[i] < top){
    				kMin.pop();
    				kMin.push(input[i]);
    			}
			}
    		for(int i = k-1; i >= 0; --i){
				int top = kMin.top();
				result[i] = top;
				kMin.pop();
			}
    	}
    	return result;
    }
    vector<int> GetLeastNumbers_Solution2(vector<int> input, int k) {
    	int len = input.size();
    	int actualK = (len < k)?(len):(k);
    	vector<int>result(actualK);
    	if(k > 0 && len >0){
    		for(int i = 1; i < actualK; i++){
				int j = i-1;
				int temp = input[i];
				while(j >= 0 && input[j] > temp){input[j+1] = input[j] ;j--;}
				input[j+1] = temp;
			}
			for(int i = k; i < len; i++){
				if(input[k-1] > input[i]){
					int temp = input[i];
					input[i] = input[k-1];
					input[k-1] = temp;
					if(k-1 > 0){
						int j = k-2;
						int temp2 = input[k-1];
						while(j >= 0 && input[j] > temp2){input[j+1] = input[j] ;j--;}
						input[j+1] = temp2;
					}
				}
			}
			for(int i = 0; i < actualK; i++)
				result[i] = input[i];
    	}

    	return result;
    }
};
//找出一个数组中的最大子数组的和，其实动态规划的问题应该从一个最小的问题开始分析，这样慢慢的就会有思路了。
class FindMaxSumOfSubArray {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
    	int len = array.size();
    	int maxSum = 0;
    	if(len > 0){
    		int f = array[0];
    		maxSum = f;
    		for(int i = 1; i < len; i++){
    			f = (f + array[i] > array[i])?(f + array[i]):(array[i]);
    			if(f > maxSum)maxSum = f;
    		}
    	}
    	return maxSum;
    }
};
//找到一个区间中的数组中包含的1的个数。
class Find1nums {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
    	int sum = 0;
    	for(int i = 1; i <= n; i++){
    		int temp = i;
    		while(temp){
    			int mod = temp%10;
    			if(mod == 1)sum++;
    			temp = temp/10;
    		}
    	}
    	return sum;
    }
};
//牛客网的模拟练习题目,找出被抹掉的整数数字。这中间我犯过的错误是，忽略数组中有重复数组的情况，导致结果出错。
class FindmissInteger{
public:
	void FindmissIntegerSolution(){
		int num;
		cin>>num;
		int min = 1000000000;int max = 1;int i=0;
		int *array = (int *)malloc(num*sizeof(int));
		int count = num;
		while(num--){
			int temp;
			scanf("%d", &temp);
			if(temp > max)max = temp;
			if(temp < min)min= temp;
			array[i++] = temp;
		}
		if(count+1<(max - min +1)){
			cout<<"mistake";
		}
		else{
			int *array2 = (int *)calloc((max - min +1), sizeof(int));
			for(int i= 0; i < count; ++i){
				array2[array[i] - min]++;
			}
			vector<int>temp;
			for(int i= 0; i < (max - min +1); ++i){
				if(array2[i] == 0)
					temp.push_back(i);
			}
			//如4 4 6 7,按照之前的算法是一定通不过的，所以就需要新写一遍。
			int len = temp.size();
			if(len == 0){
				if(min -1 > 0)cout<<min-1<<' ';
				cout<< max + 1;
			}else{
				if(len == 1){
					cout<<min+temp[0];
				}else{
					cout<<"mistake";
				}
			}
			free(array2);
		}
		free(array);
	}

};
//找出1-num中的0-9出现的次数。但是这个做法时间复杂度很高。
class cout09Sum{
public:
	void solution(){
		int num;
		cin>>num;
		int result[10] = {0};
		for(int i = 1; i <= num; i++){
			int temp = i;
			while(temp){
				int mod = temp%10;
				temp = temp/10;
				result[mod]++;
			}
		}
		for(int i= 0; i < 10; i++){
			if(i == 9)cout<<result[i];
			else
				cout<<result[i]<<' ';
		}

	}
};
//找出字符数组中第一个不重复的字符
class FirstNotRepeatingCharSolution {
public:
    int FirstNotRepeatingChar(string str) {
    	struct cell{
    		int num;
    		int index;
    		cell():num(0),index(-1){}
    		cell(int numIn, int indexIn):num(numIn),index(indexIn){}
    	};
    	cell count[26];
    	int len = str.length();
    	for(int i = 0; i < len; ++i){
    		count[str[i]-'A'].num++;
    		count[str[i]-'A'].index = i;
    	}
    	int index = len;
    	for(int i = 0; i < 26; ++i){
			if(count[i].num == 1){
				if(count[i].index > -1 && index > count[i].index)
					index = count[i].index;
			}
		}
    	if(index < len && index > -1)return index;
    	else
    		return -1;

    }
};
//将二叉树序列化和反序列化,这道题目真是太麻烦了，一点都不想写这个东西，还要需要列不是麻烦了吗。
class SerializeDeserialize {
public:
	void assistSerialize(TreeNode *root, vector<char>& c){
		//if(root->left)
	}
    char* Serialize(TreeNode *root) {
//    	if(root = NULL)return NULL;
//    	vector<char> c;
//    	queue<TreeNode *> q;
//    	q.push(root);
//    	while(!q.empty()){
//    		//TreeNode * head = q.front();
//    		q.pop();
//    		if(!q.empty()){
//
//    		}
//
//    	}
    	return NULL;

    }
    TreeNode* Deserialize(char *str) {
    	return NULL;
    }
};
//查找一个数字在排序数组中出现的次数。
class GetNumberOfKSolution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int len  = data.size();
        int count = 0;
        for(int i = 0; i < len; i++){
        	if(data[i] == k)count++;
        	else{
        		if(data[i] < k)
        			continue;
        		else
        			break;
        	}
        }
        return count;
    }
};
//数组中找出两个仅出现一次的的数字，其余的都出现过两次。这其实jianzhioffer中比较考脑力的题目。所以你懂的。
class FindNumsAppearOnceSolution {
	public:
	void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
		set<int> save;
		set<int>::iterator iter;
		int len = data.size();
		for (int i = 0; i < len; i++){
			if (save.find(data[i]) == save.end())
				save.insert(data[i]);
			else{
				iter = save.find(data[i]);
				save.erase(iter);
			}
		}
		iter = save.begin();
		*num1 = *iter;
		*num2 = *(++iter);
	}
	void FindNumsAppearOnce2(vector<int> data,int* num1,int *num2) {
		if(data.size() < 2) return ;
		int myxor = 0;
		int flag = 1;
		int len = data.size();
		for(int i = 0 ; i < len; ++ i )
			myxor ^= data[i];
		while((myxor & flag) == 0) flag <<= 1;
		*num1 = myxor;
		*num2 = myxor;
		for(int i = 0; i < len; ++ i ){
			if((flag & data[i]) == 0) *num2 ^= data[i];
			else *num1 ^= data[i];
		}
	}
};
//左旋转字符串，虽然是一道很简单的题目。但是却也挺需要动脑的。abc defg左移动3，则可以先 cba gfe在进行一次反转则有
class LeftRotateStringSolution {
public:
    string LeftRotateString(string str, int n) {
    	string temp = str;
    	int len = str.length();
    	n = n%len;
    	for(int i = 0; i < len; ++i){
    		temp[(i-n+len)%len] = str[i];
    	}
    	return temp;
    }
    void reverse(string & str, int start, int end){
    	while(start < end){
    		char temp = str[start];
    		str[start] = str[end];
    		str[end] = temp;
    		start++;
    		end--;
    	}
    }
    string LeftRotateString2(string str, int n) {
    	if(str.length() < 2)return str;
    	int len = str.length();
    	n = n%len;
    	reverse(str, 0, n-1);
    	reverse(str, n, len-1);
    	reverse(str, 0, len-1);
    	 return str;
       }
};
//最长回文子序列
class longPalidromSequence{
public:
	int assist(char *s, int len){
		int *array = (int *)calloc(len*len, sizeof(int));
		for(int i = 0; i < len; i++)array[i*len+i] = 1;
		for(int l = 1; l < len; l++){
			for(int j = 0; j + l < len; j++){
				int temp;
				if(s[j] == s[j+l]){
					temp = 2 + array[(j+1)*len+j+l-1];
				}else{
					//原来c++语言中，真的有max这样的函数呀，我还以为别人写错了呢，看来是真的有。
					temp = max(array[(j)*len+j+l-1], array[(j+1)*len+j+l]);
				}
				array[(j)*len + j+l] = temp;
			}
		}
		return len - array[(0)*len+len-1];
	}
	void solution(){
		char s[1001] = {0};
		vector<int>result;
		gets(s);
		while(strlen(s) > 0){
			int len = strlen(s);
			//cout<<assist(s, len)<<endl;
			result.push_back(assist(s, len));
			gets(s);
		}
		int len = result.size();
		for(int i =0; i < len; ++i){
			cout<<result[i]<<endl;
		}

	}
};
