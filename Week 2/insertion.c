# include <stdio.h>
# define n 10
int main() {
int arr[n]={5,3,8,1,2,7,9,4,6,0};
for (int i=1;i<n;i++){
int j=i-1;
int key=arr[i];
while (j>=0 && arr[j]>key){
arr[j+1]=arr[j];
j--;
}
arr[j+1]=key;
}
for (int i=0;i<n;i++){
printf("%d ",arr[i]);
}
}

