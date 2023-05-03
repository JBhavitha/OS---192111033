#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 4
#define MAX_RESOURCES 3

int available[MAX_RESOURCES];
int maximum[MAX_PROCESSES][MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
int i,j;

bool isSafe() {
    int work[MAX_RESOURCES];
    bool finish[MAX_PROCESSES];

    // Initialize work and finish arrays
    for (i = 0; i < MAX_RESOURCES; i++) {
        work[i] = available[i];
    }
    for (i = 0; i < MAX_PROCESSES; i++) {
        finish[i] = false;
    }

    // Find an unmarked process whose needs can be satisfied
    bool found;
    do {
        found = false;
        for (i = 0; i < MAX_PROCESSES; i++) {
            if (!finish[i]) {
                bool canAllocate = true;
                for (j = 0; j < MAX_RESOURCES; j++) {
                    if (need[i][j] > work[j]) {
                        canAllocate = false;
                        break;
                    }
                }
                if (canAllocate) {
                    // Mark the process as finished and release its resources
                    finish[i] = true;
                    for (j = 0; j < MAX_RESOURCES; j++) {
                        work[j] += allocation[i][j];
                    }
                    found = true;
                }
            }
        }
    } while (found);

    // Check if all processes have finished
    for (i = 0; i < MAX_PROCESSES; i++) {
        if (!finish[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    // Initialize resource matrices and vectors
    int claim[MAX_PROCESSES][MAX_RESOURCES] = {
        {3, 2, 2},
        {6, 1, 3},
        {3, 1, 4},
        {4, 2, 2}
    };
    int allocation[MAX_PROCESSES][MAX_RESOURCES] = {
        {1, 0, 0},
        {6, 1, 2},
        {2, 1, 1},
        {0, 0, 2}
    };
    int available[MAX_RESOURCES] = {9, 3, 6};

    // Calculate need matrix
    for (i = 0; i < MAX_PROCESSES; i++) {
        for (j = 0; j < MAX_RESOURCES; j++) {
            need[i][j] = claim[i][j] - allocation[i][j];
        }
    }

    // Check if system is in a safe state
    if (isSafe()) {
        printf("System is in safe state.\n");
    } else {
        printf("System is in unsafe state.\n");
    }

    return 0;
}
