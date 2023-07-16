#include<stdio.h>  
int main()  {
    int incomingStream[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5, 4, 2, 1, 5, 1, 2, 3, 5};  
    int pageFaults=0;  
    int frames=4;  
    int m,n,s,pages;   
    pages=20;  
    printf("Incoming\tFrame 1 \tFrame 2 \tFrame 3 \tFrame4");  
    int temp[frames];  
    for(m=0;m<frames;m++)  {
        temp[m]=-1;  
    }  
    for(m=0;m<pages;m++)  { 
        s=0;   
        for(n=0;n<frames;n++)  {
            if(incomingStream[m]==temp[n]){
                s++;  
                pageFaults--;  
            }  
        }  
        pageFaults++;  
        if((pageFaults<=frames) && (s==0)){
            temp[m]=incomingStream[m];  
        }  
        else if(s==0)  
        {  
            temp[(pageFaults-1)% frames]=incomingStream[m];  
        }  
        printf("\n");  
        printf("%d\t\t",incomingStream[m]);  
        for(n=0;n<frames;n++)  
        {  
            if(temp[n]!=-1)  
                printf("%d\t\t", temp[n]);  
            else  
                printf("-\t\t");  
        }  
    }  
    printf("\nTotal Page Faults: %d\n",pageFaults); 
    printf("Page hits: %d", pages - pageFaults);
    return 0;  
}
