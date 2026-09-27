#include <stdlib.h>

#define MIN_RUN 32

int min(int a, int b) {
    return (a < b) ? a : b;
}

void reverse(int *arr, int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void auxInsertionSort(int *arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int temp = arr[i];
        int j = i - 1;

        while (j >= left && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void auxMerge(int *arr, int l, int m, int r) {
    int len1 = m - l + 1;
    int len2 = r - m;

    int *left = (int *)malloc(len1 * sizeof(int));
    int *right = (int *)malloc(len2 * sizeof(int));

    for (int i = 0; i < len1; i++) left[i] = arr[l + i];
    for (int i = 0; i < len2; i++) right[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;

    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    while (i < len1) arr[k++] = left[i++];
    while (j < len2) arr[k++] = right[j++];

    free(left);
    free(right);
}

void timSort(int arr[], int n) {
    int i = 0;

    while (i < n) {
        int runStart = i;
        int runEnd = i;

        if (i + 1 < n) {
            if (arr[i] <= arr[i + 1]) {
                while (runEnd + 1 < n && arr[runEnd] <= arr[runEnd + 1]) runEnd++;
            } else {
                while (runEnd + 1 < n && arr[runEnd] > arr[runEnd + 1]) runEnd++;
                reverse(arr, runStart, runEnd);
            }
        }
        int currentRunLength = runEnd - runStart + 1;
        if (currentRunLength < MIN_RUN) {
            int targetEnd = min(runStart + MIN_RUN - 1, n - 1);
            insertionSort(arr, runStart, targetEnd);
            i = targetEnd + 1;
        } else {
            i = runEnd + 1;
        }
    }
    for (int size = MIN_RUN; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = min((left + 2 * size - 1), (n - 1));

            if (mid < right) {
                merge(arr, left, mid, right);
            }
        }
    }
}
