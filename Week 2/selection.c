# include <stdio.h>
# define n 10
int main() {
int arr[n]={5,3,8,1,2,7,9,4,6,0};
for (int i=0;i<n-1;i++){
int min=i;
for (int j=i+1;j<n;j++){
if (arr[min]>arr[j]){
min=j;
}
}
if (min!=i){
int temp=arr[i];
arr[i]=arr[min];
arr[min]=temp;
}
}
for (int i=0;i<n;i++){
printf("%d ",arr[i]);
}
}

