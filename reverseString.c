#include<stdio.h>
#include<string.h>
void reverseString(){
	char s[100];
	gets(s);
	int i =0;
	int j = 0;
	if(strlen(s) > 0){
		while(s[i++] != '\0'){
			if(s[i] != ' ')s[j++] = s[i];
			else{
				if(j-1 >= 0 && s[j-1] != ' ' && s[j] == ' ')
					s[j++] = ' ';
			}
		}
		s[j] = '\0';
	}
	for(int i = j-1; i >= 0; --i)
		printf("%c", s[i]);
}
