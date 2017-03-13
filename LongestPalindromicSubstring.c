/*
 * LongestPalindromicSubstring.c
 *
 *  Created on: 2017Äê2ÔÂ18ÈÕ
 *      Author: lujuan
 */
#include<string.h>
#include<stdlib.h>
extern void printStrArray(char v[], int n);
int left = 0;
int maxlen = 0;
void assistantFun(char *s, int len, int j, int k){
    while(j >= 0 && k < len && s[j] == s[k]){
        j--;
        k++;
    }
    if(maxlen < k-j-1){
        maxlen = k-j-1;
        left = j+1;
    }
}
char * copyStr(char *s, int left, int maxlen){
    char * temp = (char *)calloc(maxlen+1, sizeof(char));
    for(int i = 0; i < maxlen; i++){
        temp[i] = s[left+i];
    }
    temp[maxlen] = '\0';
    return temp;
}
char* longestPalindrome(char* s) {
    int len = strlen(s);
    if(len < 2)return s;
    for(int i =0; i < len-1; i++){
        assistantFun(s,len, i, i);
        assistantFun(s,len, i, i+1);
    }
    char * result = copyStr(s, left, maxlen);
    return result;

}
//int main(){
//	char s[] = "abcda";
//	char *temp = longestPalindrome(s);
//	printStrArray(temp, strlen(temp));
//	return 0;
//}

