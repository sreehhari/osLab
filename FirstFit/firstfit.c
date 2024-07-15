#include<stdio.h>
#include<string.h>


void firstFit(int blockSize[],int m,int processSize[],int n){
    int allocation[n];
    memset(allocation,-1,sizeof(allocation));

for (int i = 0; i < n; i++)
{
    for (int j = 0; i < m; j++)
    {
        if(blockSize[j]>=processSize[i]){
            allocation[i]=j;
            blockSize[j]-=processSize[i];
            break;
        }
    }
    
}
printf("\nProcess no \tProcessSize\tBlock no\n");
for (int i = 0; i < n; i++)
{
    printf("%d\t\t%d\t\t",i+1,processSize[i]);
    if (allocation[i]!=-1)
    {
        printf("%d",allocation[i]+1);

    }else{
        printf("not allocated");
        printf("\n");
    }

    printf("Free Blocks\n");
    for (int i = 0; i < m; i++)
    {
        printf("%d->",blockSize[i]);
    }
    
    
    
}



}


int main() {
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);
    firstFit(blockSize, m, processSize, n);
    return 0;
}
