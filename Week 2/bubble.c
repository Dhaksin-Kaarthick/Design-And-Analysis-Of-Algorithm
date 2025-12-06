# include <stdio.h>
# define n 10
int main() {
int arr[n]={5,3,8,1,2,7,9,4,6,0};

for(int i=0;i<n-1;i++){
for(int j=i+1;j<n;j++){
if (arr[i]>arr[j]){
int temp=arr[i];
arr[i]=arr[j];
arr[j]=temp;
}
}

}


for (int i=0;i<n;i++){
printf("%d ",arr[i]);
}
}
