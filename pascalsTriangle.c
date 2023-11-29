// pascals triangle
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    if (numRows == 0) {
        return NULL;
    }

    int **arr = (int**)malloc(numRows * sizeof(int*));
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));
    
    for (int i = 0; i < numRows; i++) {
        arr[i] = (int*)malloc((i + 1) * sizeof(int));
        (*returnColumnSizes)[i] = i + 1;
    }

    if (arr == NULL) {
        return NULL;
    }
    
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                arr[i][j] = 1;
            } else {
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
            }
        }
    }

    *returnSize = numRows;
    return arr;
}
