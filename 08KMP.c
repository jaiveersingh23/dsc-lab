#include <stdio.h>

#include<string.h>

int pmatch(char *string,char *pat,int *failure)

{

 int i=0,j=0;

 int lens=strlen(string);

 int lenp=strlen(pat);

 while(i<lens && j<lenp)

 {

 if(string[i]==pat[j])

 {

 i++;j++;

 }

 else if(j==0) i++;

 else j=failure[j-1]+1;

 }

 return ((j==lenp)?(i-lenp):-1);

}

void fail(char *pat,int *failure)

{

 int i,j,n=strlen(pat);

 failure[0]=-1;

 for(j=1;j<n;j++)

 {

 i=failure[j-1];

 while((pat[j]!=pat[i+1])&&(i>=0))

 i=failure[i];

 if(pat[j]==pat[i+1])

 failure[j]=i+1;

 else
   failure[j]=-1;

 }

}

void main(){

 char string[1000];

 printf("Enter a string\n");scanf("%s",string);

 char pat[1000];

 printf("Enter a pattern to check if its present in the entered string\n");scanf("%s",pat);

 int failure[1000];

 fail(pat,failure);

 int y=pmatch(string,pat,failure);

 printf("Pattern was found at index : %d",y);

}
