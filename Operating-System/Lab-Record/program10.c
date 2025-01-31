#include <stdio.h>

#define MAX_FRAMES 10
#define MAX_PAGES 100

// Function to check if a page is in the frame
int isPageInFrame(int frames[], int n, int page) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == page) return i;
    }
    return -1;
}

// Function to find the Optimal page to replace
int findOptimal(int pages[], int n, int frames[], int frameCount, int currentIndex) {
    int farthest = -1, replaceIndex = -1;

    for (int i = 0; i < frameCount; i++) {
        int j;
        for (j = currentIndex + 1; j < n; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    replaceIndex = i;
                }
                break;
            }
        }
        // If a page is never used again, replace it immediately
        if (j == n) return i;
    }

    // If all pages in frames are found in the future, return the one that appears last
    return (replaceIndex == -1) ? 0 : replaceIndex;
}

// Function to implement Optimal Page Replacement
void optimalPageReplacement(int pages[], int n, int frameCount) {
    int frames[MAX_FRAMES], pageFaults = 0, index = 0;

    for (int i = 0; i < frameCount; i++) frames[i] = -1; // Initialize frames as empty

    for (int i = 0; i < n; i++) {
        int page = pages[i];

        int pos = isPageInFrame(frames, frameCount, page);

        if (pos == -1) {  // Page fault occurs
            pageFaults++;

            if (index < frameCount) { // If there's space, insert directly
                frames[index++] = page;
            } else { // Replace the optimal page
                int optimalIndex = findOptimal(pages, n, frames, frameCount, i);
                frames[optimalIndex] = page;
            }
        }

        // Display the current frame status
        printf("\nStep %d: ", i + 1);
        for (int j = 0; j < frameCount; j++) {
            if (frames[j] == -1)
                printf(" - ");
            else
                printf(" %d ", frames[j]);
        }
    }

    printf("\n\nTotal Page Faults: %d\n", pageFaults);
}

int main() {
    int n, frameCount, pages[MAX_PAGES];

    printf("Enter number of pages: ");
    scanf("%d", &n);
    
    printf("Enter page reference string: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &frameCount);

    optimalPageReplacement(pages, n, frameCount);

    return 0;
}
