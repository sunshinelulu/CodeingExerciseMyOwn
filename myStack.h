/*
 * myStack.h
 *
 *  Created on: 2016Äê12ÔÂ30ÈÕ
 *      Author: lujuan
 */

#ifndef MYSTACK_H_
#define MYSTACK_H_
struct TreeNode {
 int val;
 struct TreeNode *left;
 struct TreeNode *right;
};
typedef struct stack{
    struct TreeNode * element;
    struct stack *next;
    int isVisited;
}stack;
int isEmpty(stack * topStack);
stack * Push(stack * topStack, struct TreeNode * element);
stack * Pop(stack * topStack);
int * addArray(int *array, int *len, int val);
#endif /* MYSTACK_H_ */
