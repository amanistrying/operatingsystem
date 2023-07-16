#include <stdio.h>

int main() {
    int n;
    printf("Enter number of blocks:");
    scanf("%d",&n);
    printf("Enter size of blocks:\n");
    int block_size[n];
    int size_left[n];
   
    for(int i=0;i<n;i++){
        scanf("%d",&block_size[i]);
        size_left[i]=block_size[i];
    }
    int m;
    printf("Enter number of process:");
    scanf("%d",&m);
    printf("Enter size of process:\n");
    int process[m];
    int allocated_to[m];
    for(int j=0;j<m;j++)
    {
        scanf("%d",&process[j]);
        allocated_to[j]=-1;
    }
    
    for(int i=0;i<m;i++)
    {
        int min_block_size=29999999;
        int index=0;
        for(int j=0;j<n;j++)
        {
            if(process[i]<=size_left[j])
            {
                if(min_block_size>size_left[j]){
                    min_block_size=size_left[j];
                    index=j;
                }
            }
        }
        size_left[index]-=process[i];
        allocated_to[i]=index+1;
    }
    printf("Process no.     Process size      Allocated Bocks\n");
    for(int i=0;i<m;i++)
    {
        printf("%d\t\t\t%d\t\t\t%d\n",i+1,process[i],allocated_to[i]);
    }
    return 0;
}