#include<stdio.h>
 int main(){
     int n;
     printf("enter the size of the array:");
     scanf("%d",&n);
     int arr[n];
     for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
     }
     int key;
     printf("enter the key to search:");
     scanf("%d",&key);
     int low=0;
     int high=n-1;
     int mid=(low+high)/2;
     int pos=-1;
     while(low<=high){
            int mid=(low+high)/2;
        if(arr[mid]==key){
                pos=mid;
             break;
        }
        else if(key<arr[mid]){
            high=mid-1;

        }
        else{
            low=mid+1;
        }


        }

     if(pos==-1){
        printf(" key not found");
     }
     else printf("key is found at position %d",pos);

 }
