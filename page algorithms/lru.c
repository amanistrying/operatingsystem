#include <stdio.h>
#define MAX_FRAMES 4
int findLRU(int frames[], int lastIndex[]) {
    int i, min = lastIndex[0], index = 0;

    for (i = 1; i < MAX_FRAMES; i++) {
        if (lastIndex[i] < min) {
            min = lastIndex[i];
            index = i;
        }
    }
    return index;
}
int main() {
    int pages[100];
    int referenceStringLength;
    int frames[MAX_FRAMES];
    int lastIndex[MAX_FRAMES] = {-1, -1, -1, -1};
    int pageFaults = 0;
    int pageHits = 0;
    int i, j;
    printf("Enter the length of the reference string: ");
    scanf("%d", &referenceStringLength);
    printf("Enter the reference string: ");
    for (i = 0; i < referenceStringLength; i++) {
        scanf("%d", &pages[i]);
    }
    for (i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
    
    printf("\nIncoming\t");
    for (i = 0; i < MAX_FRAMES; i++) {
        printf("Frame %d\t", i + 1);
    }
    printf("\n");
    for (i = 0; i < referenceStringLength; i++) {
        int page = pages[i];
        int isPageFault = 1;

        for (j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == page) {
                isPageFault = 0; // Page hit
                pageHits++;
                lastIndex[j] = i;
                break;
            }
        }
        if (isPageFault) {
            int replaceIndex = findLRU(frames, lastIndex);
            frames[replaceIndex] = page;
            lastIndex[replaceIndex] = i;
            pageFaults++;
        }
        printf("%d\t\t", page);
        for (j = 0; j < MAX_FRAMES; j++) {
            printf("%d\t\t", frames[j]);
        }
        printf("\n");
    }
    printf("\nPage Faults: %d\n", pageFaults);
    printf("Page Hits: %d\n", pageHits);
    return 0;
}
