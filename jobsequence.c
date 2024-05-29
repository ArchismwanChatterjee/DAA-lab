#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum profit job sequence
void findJobSequence(char id[], int deadline[], int profit[], int n) {
    // Sort jobs based on their profit in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (profit[j] < profit[j + 1]) {
                // Swap profit
                int temp = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = temp;

                // Swap deadline
                temp = deadline[j];
                deadline[j] = deadline[j + 1];
                deadline[j + 1] = temp;

                // Swap id
                char tempId = id[j];
                id[j] = id[j + 1];
                id[j + 1] = tempId;
            }
        }
    }

    // Array to store the result job sequence
    char result[n];
    // Array to keep track of the time slots
    int slots[n];
    for (int i = 0; i < n; i++) {
        slots[i] = -1;
    }

    // Iterate through all the jobs
    for (int i = 0; i < n; i++) {
        // Find a time slot for the current job
        for (int j = deadline[i] - 1; j >= 0; j--) {
            if (slots[j] == -1) {
                slots[j] = i;
                result[i] = id[i];
                break;
            }
        }
    }

    // Print the job sequence
    printf("Job sequence: ");
    for (int i = 0; i < n; i++) {
        if (slots[i] != -1) {
            printf("%c ", result[slots[i]]);
        }
    }
}

int main() {
    // Number of jobs
    int n=5;

    // Arrays to store the job details
    char id[] = {'a', 'b', 'c', 'd', 'e'};
    int deadline[]={2, 1, 2, 1, 3};
    int profit[]={100, 19, 27, 25, 15};

    // Find the maximum profit job sequence
    findJobSequence(id, deadline, profit, n);

    return 0;
}

// Job sequence: c a e 