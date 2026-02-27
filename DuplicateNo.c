#include<stdio.h>
int main(){
int n;
printf("Enter the Size of array:");
scanf("%d",&n);
int arr[n];
for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
}
for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if (arr[i]==arr[j]){
                printf("The duplicate element are present in the given array");
            }
        }
}
}
