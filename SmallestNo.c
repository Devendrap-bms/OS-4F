#include<stdio.h>
int main(){
int a;
printf("Enter the Size of array:");
scanf("%d",&a);
int arr[a];
for (int i=0;i<a;i++){
        scanf("%d",&arr[i]);
}
int min=arr[0];
int j;
int position=0;
for(j=0;j<a;j++){
        if(min>arr[j]){
                min=arr[j];
                position=j;

        }
}
printf("The smallest element is :%d\n",min);
printf("The position of the element is : %d\n",position);




}
