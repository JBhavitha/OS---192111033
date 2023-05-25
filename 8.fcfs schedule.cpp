#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int head, n, i, *arr, sum = 0;

    printf("Enter the number of tracks: ");
    scanf("%d", &n);

    arr = (int *) malloc(n * sizeof(int));

    printf("Enter the track positions: ");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("Sequence of head movement: ");

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
        sum += abs(head - arr[i]);
        head = arr[i];
    }

    printf("\nTotal head movement: %d\n", sum);
    printf("Average head movement: %d\n", sum/n);

    return 0;
}
Output : 
Enter the number of disk requests: 5
Enter the disk requests: 55
58
60
70
18
Total head movement: 122
Average head movement: 24.40
