#include<stdio.h>

void binarysearch(int arr[],int b,int e,int item){

 int m;

 if(b>e){

 printf("The element isn't present in the array\n");

 return;

 }

 m=b+(e-b)/2;

 if(arr[m]==item)

 printf("%d was found at index: %d\n",item,m);

 else if(arr[m]>item)

 binarysearch(arr,b,m-1,item);

 else

 binarysearch(arr,m+1,e,item);

}

void main(){

 int n;

 printf("Enter Array size\n");

 scanf("%d",&n);

 int arr[n];

 printf("Enter the Array elements[in a sorted manner]\n");

 for(int i=0;i<n;i++)

 scanf("%d",&arr[i]);

 int item;

 printf("Enter the search element\n");

 scanf("%d",&item);

 binarysearch(arr,0,n-1,item);

}
