#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>
#include<set>
#include<string.h>
#include<stdio.h>
#include <limits.h> //INT_MAX INT_MIN
#include <unordered_map> //使用hash的map
using namespace std;

//关于剑值offer中的入栈序列和出栈序列的一道问题解法
//解决思路就是借助一个额外的栈空间
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
//剑指offer中的题目————从上到下，从左到由遍历二叉树
//解决思路就是借助一个队列进行遍历
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
		int longPalidrom = array[(0)*len+len-1];
		//之所以在之前的程序中报错，是因为我们calloc分配了内存但是却没有及时的用free进行释放，这种不好的
		//编程习惯导致，现在问题的出现。因此new delete malloc free千万要注意成对的进行使用不然后悔的是自己，我可以在这里练习一下如何判断是否存在内存泄漏。
		free(array);
		return len - longPalidrom;
	}
	void solution(){
		char s[1001] = {0};
		vector<int>result;
		while(scanf("%s", s) != EOF){
			int len = strlen(s);
			result.push_back(assist(s, len));
		}
		int len = result.size();
		for(int i =0; i < len; ++i){
			cout<<result[i]<<endl;
		}

	}
};
//将大写字母放在后面，并且不能改变字母之间的相对顺序。
class SetCapticalBack{
public:
	void assist(char *s, int len){
		for(int j = 0; j < len; j++){
			if(s[j] >= 'A' && s[j] <= 'Z'){
				continue;
			}else{
				char temp = s[j];
				int i = j-1;
				while(i >= 0 && s[i] >= 'A' && s[i] <= 'Z'){
					s[i+1] = s[i];
					i--;
				}
				s[i+1] = temp;
			}
		}
	}
	void solution(){
		char s[1001] = {0};
		vector<string>result;
		while(scanf("%s", s) != EOF){
			int len = strlen(s);
			assist(s, len);
			string temp = s;
			result.push_back(temp);
		}
		int len = result.size();
		for(int i =0; i < len; ++i){
			cout<<result[i]<<endl;
		}
		getchar();

	}
};
class diffTwoNUmber{
//	void solution(){
//		int N;
//		cin>>N;
//		int len = N; //关于这个输入输出的长度问题，我已经出现过好多次错误一定要注意，一定要注意。
//		vector<int> in(N);
//		int i = 0;
//		while(N--){
//			scanf("%d", &in[i]);
//			i++;
//		}
//		std::unordered_map<int, int> count;
//		int min = INT_MAX;
//		int max = 0;
//		for(i = 0; i < len; i++){
//			for(int j = i+1; j  < len; j++){
//
//				int diff = abs(in[j] - in[i]);
//				if(diff < min)min = diff;
//				if(diff > max)max = diff;
//
//				if(count.find(diff) != count.end())count[diff]++;
//				else
//					count[diff] = 1;
//			}
//		}
//		cout<<count[min]<<' '<<count[max];
//	}
};
//华为机试题目，将多组输入的十六进制字符串，转换为整数进行输出。
//如0xA，应该输出10。输入为字符串
class huawei0x2Int{
	int assist(char *s, int len){
		if(len <=2)return 0;
		int result = 0;
		for(int i = 2; i < len; ++i){
			if(s[i] >= '0' && s[i] <= '9'){
				result = result *16+s[i] - '0';
			}else{
				result = result *16+10+s[i] - 'A';
			}
		}
		return result;
	}
	void solution(){
		char s[1001] = {0};
		vector<int>result;
		while(scanf("%s", s) != EOF){
			int len = strlen(s);
			int temp = assist(s, len);
			result.push_back(temp);
		}
		int len = result.size();
		for(int i =0; i < len; ++i){
			cout<<result[i]<<endl;
		}

	}
};
//华为机试题目,将句子以单词为单位进行逆序排放。
class Boy_a_am_i{
	void solution(){
		char s[1001] = {0};
		gets(s);
		int len = strlen(s);
		vector<string> result;
		char word[1001] = {0};
		int index = 0;
		for(int i = 0; i < len; i++){
			if(s[i] == ' '){
				if(index > 0){
					word[index++] = 0;
					string temp = word;
					result.push_back(temp);
					index = 0;
				}
			}else{
				word[index++] = s[i];
			}
		}
		if(index > 0){//这个是最后拉下的空格没有，导致一部分单词没有被写入的原因。
			word[index++] = 0;
			string temp = word;
			result.push_back(temp);
			index = 0;
		}
		int slen = result.size();
		for(int i = slen-1; i >= 0; i--){
			cout<<result[i];
			if(i > 0)cout<<' ';
		}
	}
};
//华为机试题目，将输入的字符串按照字典序列进行排序
class paixuString{
	void solution(){
		int num;
		cin>>num;
		vector<string> result;
		while(num--){
			string temp;
			cin>>temp;
			result.push_back(temp);
		}
		sort(result.begin(), result.end());
		int len = result.size();
		for(int i = 0; i < len; ++i){
			cout<<result[i]<<endl;
		}
	}
};
//倒叙输出如入中的整数值，且数字不能出现重复的情况。
class reverseInt{
	void solution(){
		char s[1001] = {0};
		scanf("%s", s);
		int len  = strlen(s);
		int flag[10] = {0};
		for(int i= len-1; i >= 0; i--){
			int index = s[i] - '0';
			if(flag[index] == 0){
				flag[index] = 1;
				cout<<index;
			}
		}
	}
};
//剑指offer求两个链表的第一个公共节点。
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class SolutionPublicNodes {
public:
	//首先求出两个链表的长度
	int lenList( ListNode* pHead){
		int len = 0;
		while(pHead != NULL){
			len++;
			pHead = pHead->next;
		}
		return len;
	}
	//将较长的链表的开始指针向后挪动一定的距离
	ListNode* moveForwardHead(ListNode* pHead, int step){
		while(pHead != NULL && step--){
			pHead = pHead->next;
		}

	return pHead;
	}
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
    	int len1 = lenList(pHead1);
    	int len2 = lenList(pHead2);
    	if(len1 > 0 && len2 > 0){
    		int diff = 0;
    		if(len1 > len2){
    			diff = len1 - len2;
    			pHead1 = moveForwardHead(pHead1, diff);
    		}else{
    			diff = len2 - len1;
				pHead2 = moveForwardHead(pHead2, diff);
    		}
    		while(pHead1 != NULL && pHead2 != NULL){
    			if(pHead1 == pHead2)return pHead1;
    			else{
    				pHead1 = pHead1->next;
    				pHead2 = pHead2->next;
    			}
    		}
    		return NULL;
    	}
    	return NULL;
    }
};
//计算第index个丑数目问题。这是剑指OFFER中的题目，其实还是在了很多的坑的。
class SolutionUglyNumber {
public:
    int GetUglyNumber_Solution(int index) {
    	int result = 1;
    	queue<int> q2;q2.push(2);
    	queue<int> q3;q3.push(3);
    	queue<int> q5;q5.push(5);
    	while(--index > 0){//这里还是有坑的，因为0为假，而所有的非0的均为真，所以i--可以正常判断，而--i却会出错误，所以既然出现了
    		int h2 = q2.front();
    		int h3 = q3.front();
    		int h5 = q5.front();
    		if(h2 < h3 && h2 < h5){
    			result = h2;
    			q2.pop();
    			q2.push(2*result);
    			q3.push(3*result);
    			q5.push(5*result);
    		}
    		if(h3 < h2 && h3 < h5){
    			result = h3;
				q3.pop();
				q3.push(3*result);
				q5.push(5*result);
			}
    		if(h5 < h3 && h5 < h2){
    			result = h5;
				q5.pop();
				q5.push(5*result);
			}
    	}
    	return result;
    }
    int GetUglyNumber_Solution2(int index){
        if(index < 1)
            return 0;
        int minVal = 0;
        queue<int> q2, q3, q5;
        q2.push(1);
        for(int i = 0; i < index; i++){
            int val2 = q2.empty() ? INT_MAX : q2.front();
            int val3 = q3.empty() ? INT_MAX : q3.front();
            int val5 = q5.empty() ? INT_MAX : q5.front();
            minVal = min(val2, min(val3, val5));
            if(minVal == val2){
                q2.pop();
                q2.push(2 * minVal);
                q3.push(3 * minVal);
            }
            else if(minVal == val3){
                q3.pop();
                q3.push(3 * minVal);
            }
            else{
                q5.pop();
            }
            q5.push(5 * minVal);
        }
        return minVal;
    }
    int GetUglyNumber_Solution3(int index) {
        	int result = 1;
        	queue<int> q2;q2.push(2);
        	queue<int> q3;q3.push(3);
        	queue<int> q5;q5.push(5);
        	while(--index){
        		int h2 = q2.front();
        		int h3 = q3.front();
        		int h5 = q5.front();
        		if(h2 < h3 && h2 < h5){
        			result = h2;
        			q2.pop();
        			q2.push(2*result);
        			q3.push(3*result);
        			q5.push(5*result);
        		}
        		if(h3 < h2 && h3 < h5){
        			result = h3;
    				q3.pop();
    				q3.push(3*result);
    				q5.push(5*result);
    			}
        		if(h5 < h3 && h5 < h2){
        			result = h5;
    				q5.pop();
    				q5.push(5*result);
    			}
        	}
        	return result;
        }
};
//将句子中的单词反转之后进行排列。这个是加了空白格版本的东东。
class SolutionReverseSentence {
public:
    string ReverseSentence(string s) {
		int len = s.length();
		vector<string> result;
		char word[1001] = {0};
		int index = 0;
		for(int i = 0; i < len; i++){
			if(s[i] == ' '){
				if(index > 0){
					word[index++] = 0;
					string temp = word;
					result.push_back(temp);
					index = 0;
				}
				string temp = " ";
				result.push_back(temp);
			}else{
				word[index++] = s[i];
			}
		}
		if(index > 0){//这个是最后拉下的空格没有，导致一部分单词没有被写入的原因。
			word[index++] = 0;
			string temp = word;
			result.push_back(temp);
			index = 0;
		}
		int slen = result.size();
		string ss;
		for(int i = slen-1; i >= 0; i--){
			ss = ss + result[i];
		}
		return ss;
    }
};
//剑指offer：输入一个递增排序的数组和一个数字S，在数组中查找两个数，是的他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
//我感觉这道题目还是要看一下剑指offer中的解析的，因为这个问题和连续子序列和的问题，都被自己用这种hash表和map的技巧来解决感觉不是怎么一个好的办法。
//万一数组中有重复的数字要怎么办，所以刚决还是优点问题的。虽然通过了测试用例但是还是有问题的。
class SolutionFindNumbersWithSum {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int minProduct = INT_MAX;
        int len = array.size();
        int min = 0;
        int max = 0;
        unordered_map<int, int> mapAray;
        for(int i = 0; i < len; ++i){
        	mapAray[array[i]] = i;
        }
        for(int i = 0; i < len; ++i){
        	if(mapAray.find(sum - array[i]) != mapAray.end()){
        		if(minProduct > (sum - array[i])*(array[i])){
        			minProduct = (sum - array[i])*(array[i]);
        			min = i;
        			max = mapAray[sum - array[i]];
        		}
        	}
		}
        vector<int> result;
        if(minProduct < INT_MAX){
        	 if(min != max){
        		 if(min < max){
        			 result.push_back(array[min]);
					 result.push_back(array[max]);
        		 }else{
        			 result.push_back(array[max]);
					 result.push_back(array[min]);
        		 }
        	 }
        }
        return result;
    }
};
//牛牛在研究他自己独创的平衡数，平衡数的定义是：将一个数分成左右两部分，分别成为两个新的数。
//左右部分必须满足以下两点：
//1，左边和右边至少存在一位。2，左边的数每一位相乘如果等于右边的数每一位相乘，则这个数称为平衡数。
//例如：1221这个数，分成12和21的话，1*2=2*1，则称1221为平衡数，再例如：1236这个数，可以分成123和1*2*3=6，所以1236也是平衡数。而1234无论怎样分也不满足平衡数。
//输入描述:输入一个正整数（int范围内）。
//输出描述:如果该数是平衡数，输出 "YES", 否则输出 "NO"。
//输入例子:
//1221
//1234
//输出例子:
//YES
//NO
//这道题目是牛客网的练习试卷中判断一个数组是否为平衡数组的题目，其中一直不能通过的测试用例是0，1这样的含有0的用例，因此一定要小心要多测试自己的陈股
class solutionNikebiancheng{
public:
	bool assist(char *s, int len){
		if(len < 2)return false;
		unordered_map<int, int> mapA;
		vector<int> arrayProduct;
		int product = 1;
		for(int i = 0; i < len; i++){
			product = product *(s[i] - '0');
			mapA[product] = i;
			arrayProduct.push_back(product);
		}
		for(int i = 0; i < len; i++){
			int a1 = arrayProduct[i];
			if(a1 == 0){
				for(int j = i+1; j  < len; j++){
					if(s[j] == '0')return true;
				}
				return false;
			}
			if(mapA.find(a1*a1) != mapA.end()){
				int index = mapA[a1*a1];
				if(index != i && index == len-1)return true;
			}
		}
		return false;
	}
	void solution(){
		char s[2001] = {0};
		vector<string>result;
		while(scanf("%s", s) != EOF){
			int len = strlen(s);
			bool temp = assist(s, len);
			if(temp){
				string ss = "YES";
				result.push_back(ss);
			}else{
				string ss = "NO";
				result.push_back(ss);
			}

		}
		int len = result.size();
		for(int i =0; i < len; ++i){
			cout<<result[i]<<endl;
		}

	}
};
//牛牛手里有N根木棒,分别编号为1~N,现在他从N根里想取出三根木棒，使得三根木棒构成一个三角形,你能计算出牛牛有多少种取法吗?(考虑两种取法中使用的木棒编号有一个不一样就认为是不同的取法)。
//输入描述:首先输入一个正整数N，接下来的一行共有N个正整数表示每个木棒的长度。
//N ≤ 50, 木棒的长度 ≤ 10000.
//输出描述:输出一个整数表示方法数。输入例子:
//5
//1 2 3 4 5
//输出例子:3
class NiuKeSolution{
public:
	bool assist(int a, int b, int c){
		if(a>0 && b>0 && c>0){
			if(a+b <= c)return false;
			else{
				if(a+c <= b)return false;
				else{
					if(b+c <= a)return false;
					else return true;
				}
			}
		}
		return false;
	}
	void solution(){
		int num;
		cin>>num;
		int *input = (int*)malloc(sizeof(int)*num);
		int len = num;
		for(int i = 0; i < len; i++){
			scanf("%d", &input[i]);
		}
		int result = 0;
		for(int j = 0; j < len-2;j++){
			for(int k = j+1; k < len-1; k++){
				for(int l = k+1; l < len; l++){
					if(assist(input[j], input[k], input[l]))
						result = result +1;
				}
			}
		}
		cout<<result;
	}
};
//牛牛有两个字符串（可能包含空格）,牛牛想找出其中最长的公共连续子串,希望你能帮助他,并输出其长度。
//输入描述:输入为两行字符串（可能包含空格），长度均小于等于50.
//输出描述:输出为一个整数，表示最长公共连续子串的长度。
//输入例子:abcde  abgde
//输出例子:2
class solutionNiuKe2ZIChuan{
public:
	int assist(char*s1, int len1, char *s2, int len2){
		int result = 0;
		if(len1 > 0 && len2 > 0){
			int *temp = (int *)malloc(sizeof(int)*len1*len2);
			for(int i = 0; i < len1; i++){
				if(s2[len2-1] == s1[i])temp[i*len2+len2-1] = 1;
				else temp[i*len2+len2-1] = 0;
				if(temp[i*len2+len2-1]> result)
					result = temp[i*len2+len2-1];
			}
			for(int i = 0; i < len2; i++){
				if(s2[i] == s1[len1-1])temp[(len1-1)*len2+i] = 1;
				else temp[(len1-1)*len2+i] = 0;
				if(temp[(len1-1)*len2+i] > result)
					result = temp[(len1-1)*len2+i];
			}
			for(int i = len1 -2; i >= 0;i--){
				for(int j = len2 - 2; j >= 0; j--){
					if(s1[i] == s2[j])temp[i*len2+j] = 1+temp[(i+1)*len2+j+1];
					else temp[i*len2+j] = 0;
					if(temp[i*len2+j] > result)
						result = temp[i*len2+j];
				}
			}
		}
		return result;
	}
};
//牛牛想在[a, b]区间内找到一些数满足可以被一个整数c整除,现在你需要帮助牛牛统计区间内一共有多少个这样的数满足条件？
//输入描述:
//首先输入两个整数a,b,（-5*10^8 ≤ a ≤ b ≤ 5*10^8)
//接着是一个正整数c（1 <= c <= 1000）
class solutionCountNumber{
public:
	int solution(){
		int start;
		int end;
		int key;
		cin>>start>>end>>key;
		int count = 0;
		int m = start/key;
		int n = end/key;
		if(m*key >= start){
			count = n-m+1;
		}else
			count = n-m;
		return count;
	}
};
//牛牛在二维坐标系中画了N个点，且都是整点。现在牛牛想画出一个矩形，使得这N个点都在矩形内或者在矩形上。矩形的边均平行于坐标轴。牛牛希望矩形的面积最小。请你帮助牛牛计算下最小矩形的面积。
//输入描述:首先输入一个正整数N表示点的个数（2 <= N <= 50）接下来N行每行两个整数x, y，表示该点的坐标。绝对值均小于等于100.
//输出描述:
//一个整数表示最小矩形的面积。
//输入例子:
//2
//0 1
//1 0
//输出例子:1
class solutionMinRec{
	struct point{
		int x;
		int y;
		point(int xin, int yin){
			x = xin;
			y = yin;
		}
	};
public:
	int assist(vector<point>& input){
			int result = 0;
			int len = input.size();
			int xMin = INT_MAX;
			int xMax = INT_MIN;
			int yMin = INT_MAX;
			int yMax = INT_MIN;
			for(int i = 0; i < len; i++){
				if(input[i].x < xMin)xMin = input[i].x;
				if(input[i].x > xMax)xMax = input[i].x;
				if(input[i].y < yMin)yMin = input[i].y;
				if(input[i].y > yMax)yMax = input[i].y;
			}
			result = (xMax - xMin)*(yMax-yMin);
			return result;
	}
	void solution(){
		int num;
		cin>>num;
		vector<point> temp;
		int len = num;
		for(int i = 0; i < len; i++){
			int a,b;
			scanf("%d %d", &a, &b);
			temp.push_back(point(a,b));
		}
		int result = assist(temp);
		cout<<result;
	}
};
//众所周知计算机代码底层计算都是0和1的计算，牛牛知道这点之后就想使用0和1创造一个新世界！牛牛现在手里有n个0和m个1，
//给出牛牛可以创造的x种物品，每种物品都由一个01串表示。牛牛想知道当前手中的0和1可以最多创造出多少种物品。
//输入描述:输入数据包括x+1行：
//第一行包括三个整数x(2 ≤ x ≤ 20)，n(0 ≤ n ≤ 500)，m(0 ≤ m ≤ 500)，以空格分隔
//接下来的x行，每行一个01串item[i]，表示第i个物品。每个物品的长度length(1 ≤ length ≤ 50)
//输出描述:输出一个整数，表示牛牛最多能创造多少种物品
//输入例子:3 3 1
//1
//00
//100
//输出例子:2
class solution01ItemNum{
public:
	void find01(string& s, int& c0, int& c1){
		int len = s.length();
		for(int i = 0; i < len; ++i){
			if(s[i] == '0')c0++;
			else{
				if(s[i] == '1')c1++;
			}

		}
	}
	void solution(){
		int num, n, m;
		cin>>num>>n>>m;
		vector<string> input;
		for(int i= 0; i < num; i++){
			string temp;
			cin>>temp;
			input.push_back(temp);
		}
		//在C++中生成二维数组的方法。//在C++中生成二维数组的方法。//在C++中生成二维数组的方法。
		vector<vector<int>>flag(n+1);
		for(int i =0; i <= n; i++){
			flag[i].resize(m+1);
		}
		for(int start = num-1; start >= 0; start --){
			int c0 = 0;
			int c1 = 0;
			find01(input[start], c0,c1);
			if(start == num -1){
				for(int i=c0; i <= n; i++){
					for(int j = c1; j <= m; j++){
						flag[i][j] = 1;
					}
				}
			}else{
				for(int i = n; i>= c0; i--){
					for(int j = m; j >= c1; j--){
						int temp1 = 1+flag[i-c0][j-c1];
						int temp2 = flag[i][j];
						if(temp1 > temp2){
							flag[i][j] = temp1;
						}
					}
				}
			}
		}
		cout<<flag[n][m];

	}
};
//牛牛有N个字符串，他想将这些字符串分类，他认为两个字符串A和B属于同一类需要满足以下条件：
//A中交换任意位置的两个字符，最终可以得到B，交换的次数不限。比如：abc与bca就是同一类字符串。
//现在牛牛想知道这N个字符串可以分成几类。
//输入描述:首先输入一个正整数N（1 <= N <= 50），接下来输入N个字符串，每个字符串长度不超过50。
//输出描述:输出一个整数表示分类的个数。
//输入例子:
//4
//abcd
//abdc
//dabc
//bacd
//输出例子:
//1
class solutionFenLei{
	bool isNoneExist(vector<string>& input, string s){
		int len = input.size();
		for(int i = 0; i < len; i++){
			if(s.compare(input[i]) == 0)
				return false;
		}
		return true;
	}

	void solution(){
		int num;
		cin>>num;
		vector<string> input;
		for(int i= 0; i < num; i++){
			string temp;
			cin>>temp;
			sort(temp.begin(), temp.end());
			if(isNoneExist(input,temp)){
				input.push_back(temp);
			}
		}
		cout<<input.size();
	}
};
//牛牛在书上看到一种字符串叫做回文串,当一个字符串从左到右和从右到左读都是一样的,就称这个字符串为回文串。牛牛又从好朋友羊羊那里了解到一种被称为优美的回文串的字符串,考虑一个长度为N只包含大写字母的字符串,写出它所有长度为M的连续子串(包含所有可能的起始位置的子串,相同的子串也要计入),如果这个字符串至少有K个子串都是回文串,我们就叫这个字符串为优美的回文串。现在给出一个N,牛牛希望你能帮他计算出长度为N的字符串有多少个是优美的回文串(每个位置都可以是'A'~'Z'的一个。)
//输入描述:输入数据包括三个整数N, M, K(2 ≤ N ≤ 11, 2 ≤ M ≤ N, 0 ≤ K ≤ 11).
//输出描述:
//输出一个整数,表示所求的字符串个数.
//输入例子:
//2 2 1
//输出例子:
//26
//长度为2的字符串,它长度为2的子串只有它自身。长度为2的回文串有"AA","BB","CC"..."ZZ",一共26种。
class youMeiZiChuan{
	long long cnt[12];
	long long res = 0;
	int M, K, N;
	char s[12];
	void solve(int k, int p) {
	    if(k == 0) {
	        int tmp = 0;
	        for(int i = 0; i < N - M + 1; i++) {
	            bool ok = true;
	            for(int j = 0; j < M / 2; j++) {
	                if(s[i + j] != s[i + M - 1 - j]) {
	                    ok = false;
	                    break;
	                }
	            }
	            if(ok) tmp++;
	        }
	        if(tmp >= K) {
	            res += cnt[p];
	        }
	        return ;
	    }
	    for(int i = 0; i < p + 1; i++) {
	        s[k - 1] = 'a' + i;
	        solve(k - 1, max(p, i + 1));
	    }
	}
	int main() {
	    cin >> N >> M >> K;
	    cnt[0] = 0; cnt[1] = 26;
	    for(int i = 2; i <= N; i++) {
	        cnt[i] = cnt[i - 1] * (26 - i + 1);
	    }
	    solve(N, 0);
	    cout << res << endl;
	    return 0;
	}
};
//剑指offer中的题目：在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
//例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
class SolutionRemoveDuplicateList {
public:
	//这道题目自己还是做不太好的，因为会出现1，1，2没有。
    ListNode* deleteDuplication(ListNode* pHead)
    {
    	ListNode fakeHead(0);
		fakeHead.next = pHead;
		ListNode* pre = &fakeHead;
		ListNode* p = pre->next;
		while (p ) {
			ListNode* pn = p->next;

			if (pn && p->val == pn->val) {
				// move pn to next different value
				while (pn && p->val == pn->val) {
					pn = pn->next;
				}
				p = pn;
				pre->next = p;
			}
			else {
				pre = p;
				p = p->next;
			}
		}
		return fakeHead.next;
    }
};
//给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};
//给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
//出现错误的测试用例{8,6,10,5,7,9,11},7;{8,6,10,5,7,9,11},11
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
    	if(pNode == NULL)return NULL;
    	else{
    		if(pNode->right == NULL){
    			//这道题目其实还是有很多坑爹的题目的，因为如果不仔细考虑
    			TreeLinkNode* pNodeParent = pNode->next;
    			if(pNodeParent == NULL)return NULL;
    			if(pNodeParent != NULL&& pNodeParent->left == pNode)return pNodeParent;
    			else{
    				TreeLinkNode* pPP = pNodeParent->next;
    				while(pPP != NULL && pPP->right == pNodeParent){
    					pNodeParent = pPP;
    					pPP = pPP->next;
    				}
    				return pPP;
    			}
    		}
    		else{
    			TreeLinkNode* p = pNode->right;
    			while(p != NULL && p->left != NULL)p = p->left;
    			return p;
    		}
    	}
    }
};
//如果一个数字序列逆置之后跟原序列是一样的就称这样的数字序列为回文序列。例如：
//{1, 2, 1}, {15, 78, 78, 15} , {112} 是回文序列,
//{1, 2, 2}, {15, 78, 87, 51} ,{112, 2, 11} 不是回文序列。
//现在给出一个数字序列，允许使用一种转换操作：选择任意两个相邻的数，然后从序列移除这两个数，并用这两个数字的和插入到这两个数之前的位置(只插入一个和)。
//现在对于所给序列要求出最少需要多少次操作可以将其变成回文序列。
//输入描述:输入为两行，第一行为序列长度n ( 1 ≤ n ≤ 50)第二行为序列中的n个整数item[i]  (1 ≤ iteam[i] ≤ 1000)，以空格分隔。
//输出描述:输出一个数，表示最少需要的转换次数
//输入例子:
//4
//1 1 1 3
//输出例子:
//2
//看起来比较难的题目需要从比较简单的case出发来寻找解题的思路就是不错的选择。
class solutionHuiWen{
public:
	int assist(vector<int>&input){
		int len = input.size();
		if(len <= 1)return 0;
		if(input[0] == input[len-1]){
			if(len > 2){
				vector<int> newtemp(input.begin()+1, input.begin()+len-1);
				return assist(newtemp);
			}else return 0;

		}else{
			if(input[0] < input[len-1]){
				int newelement = input[0]+input[1];
				input[0] = newelement;
				input.erase(input.begin()+1);//学习到如何使用删除的功能了。
			}else{
				int newelement = input[len-2]+input[len-1];
				input[len-2] = newelement;
				input.erase(input.begin()+len-1);
			}
			return 1+assist(input);//使用递归有时候也是一个不错的选择。
		}
	}

	void solution(){
		int num;
		scanf("%d", &num);
		vector<int>input(num);
		for(int i = 0; i < num; i++){
			scanf("%d", &input[i]);
		}
		int result = num-1;
		result = assist(input);
		printf("%d", result);
	}
	int main()
	{
		solution();
	//	vector<int>a(4);a[0] =1;a[1] = 2;a[2] = 3;a[3] = 1;
	//	vector<int>b(a.begin()+1, a.begin()+3);//这里用迭代器来初始化向量，是一个[)前开后闭的这样的一个东西
	//	int len = b.size();
	//	for(int i = 0; i < len; ++i){
	//		cout<<b[i]<<' ';
	//	}

		return 0;
	}
};
//网易的第三道编程题目：题目的意思是说有n个人，然后有6项工作，需要安排若干个人手来做这六个工作，问总共有多少中不同的解法。其实这个是回溯思想的的
//应用，而我之前一直没有做对的原因在于，在每一个回溯的后面，忘记把之前安排的人给恢复原状，因此就彻底的错误了，一直得不到结果，所以如果再给我十分钟估计就做出来了，真是大意了呀。
//有点大意了实在是。
class WangYiBianCheng3{
public:
	bool canDoJobNum(string & temp, int num){
		int len = temp.length();
		for(int i =0 ; i < len ;i++){
			if(temp[i]-'0' == num)
				return true;
		}
		return false;
	}

	void solution(){
		int num;
		scanf("%d", &num);
		vector<string> input;
		vector<int>f0;
		vector<int>f1;
		vector<int>f2;
		vector<int>f3;
		vector<int>f4;
		vector<int>f5;
		for(int i = 0; i < num; i++){
			string temp;
			cin>>temp;
			if(canDoJobNum(temp, 0))f0.push_back(i);
			if(canDoJobNum(temp, 1))f1.push_back(i);
			if(canDoJobNum(temp, 2))f2.push_back(i);
			if(canDoJobNum(temp, 3))f3.push_back(i);
			if(canDoJobNum(temp, 4))f4.push_back(i);
			if(canDoJobNum(temp, 5))f5.push_back(i);
		}


		int count = 0;
		int len0 = f0.size();
		int len1 = f1.size();
		int len2 = f2.size();
		int len3 = f3.size();
		int len4 = f4.size();
		int len5 = f5.size();
		for(int i0 = 0; i0 < len0; i0++){
			vector<int>flag(num);
			if(flag[f0[i0]] == 0){flag[f0[i0]] = 1;}
			else continue;
			for(int i1 = 0; i1 < len1; i1++){
				if(flag[f1[i1]] == 0){flag[f1[i1]] = 1;}
				else continue;
				for(int i2 = 0; i2 < len2; i2++){
					if(flag[f2[i2]] == 0){flag[f2[i2]] = 1;}
					else continue;
					for(int i3 = 0; i3 < len3; i3++){
						if(flag[f3[i3]] == 0){flag[f3[i3]] = 1;}
						else continue;
						for(int i4 =0; i4 < len4; i4++){
							if(flag[f4[i4]] == 0){flag[f4[i4]] = 1;}
							else continue;
							for(int i5= 0; i5< len5;i5++){
								if(flag[f5[i5]] == 0){count++;flag[f5[i5]] = 0;}
								else continue;
							}
							flag[f4[i4]] = 0;//注意恢复为原始的初始状态才能得到所有的结果。
						}
						flag[f3[i3]] = 0;//注意恢复为原始的初始状态才能得到所有的结果。
					}
					flag[f2[i2]] = 0;//注意恢复为原始的初始状态才能得到所有的结果。
				}
				flag[f1[i1]] = 0;//注意恢复为原始的初始状态才能得到所有的结果。
			}
			flag[f0[i0]] = 0;//注意恢复为原始的初始状态才能得到所有的结果。
		}
		cout<<count;

	}

};
