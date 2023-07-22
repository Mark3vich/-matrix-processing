#include <stdio.h> 
#include <malloc.h>
#include <stdbool.h> 
#include <stdlib.h> 
#include <math.h>

void memoryAllocation(int ** array, const int N, const int M) { 
    for(size_t i = 0; i < N; i++) {
        array[i] = (int*)calloc(M, sizeof(int*));
    }
}

void memoryCleansing(int ** array, const int N) { 
    for(size_t i = 0; i < N; i++) {
        free(array[i]);
    }
    free(array);
}

void Input(int ** array, const int N, const int M) {
    for(size_t i = 0; i < N; i++) { 
        for(size_t j = 0; j < M; j++) { 
            scanf("%d", &array[i][j]);
        }
    }
}

void Output(int ** array, const int N, const int M) { 
    for(size_t i = 0; i < N; i++) { 
        for(size_t j = 0;  j < M; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    } 
}

// Information 
int searchMaxElement(int ** array, const int N, const int M) { 
    int maxElement = array[0][0];
    for(size_t i = 0; i < N; i++) {
        for(size_t j = 0; j < M; j++) {
            if(maxElement < array[i][j]) { 
                maxElement = array[i][j];
            }
        }
    }
    return maxElement;
}

int searchMinElement(int ** array, const int N, const int M) { 
    int minElement = array[0][0];
    for(size_t i = 0; i < N; i++) {
        for(size_t j = 0; j < M; j++) {
            if(minElement > array[i][j]) { 
                minElement = array[i][j];
            }
        }
    }
    return minElement;
}

bool theMatrixIsCalledUnit(int ** array, const int N, const int M) { 
    for(size_t i = 0; i < N; i++) {
        for(size_t j = 0; j < M; j++) {
            if(i == j && array[i][j] != 1) { 
                return false;
            }
            if(i != j && array[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

bool theMatrixIsCalledDiagonal(int ** array, const int N, const int M) { 
    for(size_t i = 0; i < N; i++) {
        for(size_t j = 0; j < M; j++) {
            if(i == j && array[i][j] != 0) { 
                return false;
            }
            if(i != j && array[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

bool theMatrixIsCalledZero(int ** array, const int N, const int M) { 
    for(size_t i = 0; i < N; i++) {
        for(size_t j = 0; j < M; j++) {
            if(array[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

bool theMatrixIsCalledUpperTriangular(int ** array, const int N, const int M) { 
    for(size_t i = 0; i < N; i++) {
        for(size_t j = 0; j < M; j++) {
            if(i > j && array[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

bool theMatrixIsCalledLowerTriangular(int ** array, const int N, const int M) { 
    for(size_t i = 0; i < N; i++) {
        for(size_t j = 0; j < M; j++) {
            if(i < j && array[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

bool theMatrixIsCalledLowerSymmetrical(int ** array, const int N, const int M) { 
    for(size_t i = 0; i < N; i++) {
        for(size_t j = 0; j < M; j++) {
            if (array[i][j] != array[j][i]) {
                return false;
            }
        }
    }
    return true;
}

char* outputOfAFunctionByItsValue(bool isFlag) {
    return isFlag ? "is" : "is not";
}

void displayInfo(int ** array, const int N, const int M) { 
    printf("Max element of the matrix %d\n", searchMaxElement(array, N, M));
    printf("Min element of the matrix %d\n", searchMinElement(array, N, M));
    printf("The matrix %s singular\n", outputOfAFunctionByItsValue(theMatrixIsCalledUnit(array, N, M)));
    printf("The matrix %s diagonal\n", outputOfAFunctionByItsValue(theMatrixIsCalledDiagonal(array, N, M)));
    printf("The matrix %s zero\n", outputOfAFunctionByItsValue(theMatrixIsCalledZero(array, N, M)));
    printf("The matrix %s upper triangular\n", outputOfAFunctionByItsValue(theMatrixIsCalledUpperTriangular(array, N, M)));
    printf("The matrix %s lower triangular\n", outputOfAFunctionByItsValue(theMatrixIsCalledLowerTriangular(array, N, M)));
    printf("The matrix %s lower symmetrical\n", outputOfAFunctionByItsValue(theMatrixIsCalledLowerSymmetrical(array, N, M)));
}

// Operations 
typedef struct _indexOfTheMaxOrMinElement {
    int x; 
    int y;
} indexOfTheMaxOrMinElement;

void swap(int *a, int *b) {
    if(*a == *b) { 
        return;
    }
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void searchMaxElementIndex(int ** array, const int N, const int M, indexOfTheMaxOrMinElement * max) {
    int maxElement = array[0][0];
    max->x = 0;
    max->y = 0;
    for(size_t i = 0; i < N; i++) {
        for(size_t j = 0; j < M; j++) {
            if(maxElement < array[i][j]) { 
                maxElement = array[i][j];
                max->x = i;
                max->y = j;
            }
        }
    }
}

void searchMinElementIndex(int ** array, const int N, const int M, indexOfTheMaxOrMinElement * min) {
    int minElement = array[0][0];
    min->x = 0;
    min->y = 0;
    for(size_t i = 0; i < N; i++) {
        for(size_t j = 0; j < M; j++) {
            if(minElement > array[i][j]) { 
                minElement = array[i][j];
                min->x = i;
                min->y = j;
            }
        }
    }
}

void exchangeTheMaximumAndMinimumElementInTheMatrix(int ** array, const int N, const int M) {
    indexOfTheMaxOrMinElement max;
    indexOfTheMaxOrMinElement min;
    searchMaxElementIndex(array, N, M, &max);
    searchMinElementIndex(array, N, M, &min);
    swap(&array[min.x][min.y], &array[max.x][max.y]);
    Output(array, N, M);
}

typedef struct _arrayIndex {
    int N;
    int M;
} arrayIndex;

void getIndexArray(int ** array, const int N, const int M, const int indexOneElement, arrayIndex * Number) {
    int buf1 = indexOneElement;
    int buf2 = indexOneElement;
    if(M > indexOneElement - 1) {
        Number->N = 0;
        Number->M = indexOneElement - 1;
        return;
    } 

    while(buf1 > M) {
        buf1 -= M;
    }

    while(buf2 > N) {
        buf2 = (buf2 - 1) / N;
    }

    Number->N = buf2;
    Number->M = buf1 - 1;
}

void swapElementsByIndex(int ** array, const int N, const int M, const int indexOneElement, const int indexTwoElement) {
    arrayIndex Number1;
    arrayIndex Number2;

    getIndexArray(array, N, M, indexOneElement, &Number1);
    getIndexArray(array, N, M, indexTwoElement, &Number2);

    swap(&array[Number1.N][Number1.M], &array[Number2.N][Number2.M]);
    
    Output(array,N,M);
}

void interfaceForExchangingElements(int ** array, const int N, const int M) {
    int indexOneElement, indexTwoElement;
    printf("Enter two indexes\n");
    scanf("%d %d", &indexOneElement, &indexTwoElement);
    printf("\n");
    swapElementsByIndex(array, N, M, indexOneElement, indexTwoElement);
}

int compare(const void * x1, const void * x2) {
    return ( *(int*)x1 - *(int*)x2 );             
}

void sortTheArrayInAscendingOrder(int ** array, const int N, const int M) {
    int *oneDimensionalArray = (int*)calloc(N*M, sizeof(int)); 
    int t = 0;
    for(size_t i = 0; i < N; i++) {
        for(size_t j = 0; j < M; j++) {
            oneDimensionalArray[t] = array[i][j];
            t++;
        }
    }
    qsort(oneDimensionalArray, N * M, sizeof(int), compare);
    t = 0;
    for(size_t i = 0; i < N; i++) {
        for(size_t j = 0; j < M; j++) {
            array[i][j] = oneDimensionalArray[t];
            t++;
        }
    }
    Output(array, N, M);
    free(oneDimensionalArray);
}

bool searchingForAnElementInAnUnsortedArray(int ** array, const int N, const int M, const int element) { 
    for(size_t i = 0; i < N; i++) { 
        for(size_t j = 0; j < M; j++) {
            if(array[i][j] == element) { 
                printf("Its index {%d %d}\n", i++, j++);
                return true;
            }
        }
    }
    return false;
}

bool searchingForAnElementInAnSortedArray(int ** array, const int N, const int M, const int element) { 
    int i = 0;
    int j = M - 1;
    while(i < N * M && j >= 0) { 
        if(array[i][j] == element) { 
            printf("Its index {%d %d}\n", i++, j++);
            return true;
        } else if(array[i][j] > element) { 
            j--;
        } else {
            i++;
        }
    }
    return false;
}

void displayBool(bool value) { 
    if(value) { 
        printf("This element is assigned in the array");
    } else { 
        printf("This element does not belong in the array");
    }
}

void searchController(int ** array, const int N, const int M, const int element, const int point) {
    switch (point) {
        case 1:
            displayBool(searchingForAnElementInAnSortedArray(array, N, M, element));
            break;
        case 2: 
            displayBool(searchingForAnElementInAnUnsortedArray(array, N, M, element));
            break;
        default:
            printf("oops, something went wrong");
            break;
    }
}

void searchingDisplay(int ** array, const int N, const int M) {
    int point;
    int element;
    printf("Enter the element that we will be looking for\n");
    scanf("%d", &element);
    printf("The array is sorted?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    scanf("%d", &point);
    searchController(array, N, M, element, point);
}

void informationAboutTheMatrix() {
    int N1, M1; 
    printf("Size matrix: ");
    scanf("%d %d", &N1, &M1);
    printf("\n");
    int **array1 = (int**)calloc(N1, sizeof(int*)); 
    memoryAllocation(array1, N1, M1);  

    printf("Input array: \n");
    Input(array1, N1, M1);
    printf("\n");

    displayInfo(array1, N1, M1);

    printf("============\n");
    Output(array1, N1, M1);

    memoryCleansing(array1, N1);
}

// + - * 
void addition(int ** array1, const int N1, const int M1, 
              int ** array2, const int N2, const int M2, 
              int ** array3, const int N3, const int M3) { 
    for(size_t i = 0; i < N3; i++) {
        for(size_t j = 0; j < M3; j++) { 
            array3[i][j] = array1[i][j] + array2[i][j];
        }
    }
    Output(array3, N3, M3);
} 

void subtraction(int ** array1, const int N1, const int M1, 
                 int ** array2, const int N2, const int M2, 
                 int ** array3, const int N3, const int M3) {
    for(size_t i = 0; i < N3; i++) {
        for(size_t j = 0; j < M3; j++) { 
            array3[i][j] = array1[i][j] - array2[i][j];
        }
    }
    Output(array3, N3, M3);
}

void multiplication(int ** array1, const int N1, const int M1, 
                    int ** array2, const int N2, const int M2, 
                    int ** array3, const int N3, const int M3) {
    for(size_t i = 0; i < N1; i++) {
        for(size_t j = 0; j < M2; j++){
            array3[i][j] = 0;
            for(size_t k = 0; k < N2; k++) {
                array3[i][j] += array1[i][k] * array2[k][j];
            }
        }
    }
    Output(array3, N3, M3);
}

void controllerOfMatrixOperations(int ** array1, const int N1, const int M1, 
                                  int ** array2, const int N2, const int M2, 
                                  int ** array3, const int N3, const int M3, 
                                  const int point) { 
    switch (point) {
        case 1:
            addition(array1, N1, M1, array2, N2, M2, array3, N3, M3);
            break;
        case 2:
            subtraction(array1, N1, M1, array2, N2, M2, array3, N3, M3);
            break;
        case 3:
            multiplication(array1, N1, M1, array2, N2, M2, array3, N3, M3);
            break;
        default:
            break;
    }
}

int max(const int a, const int b) { 
    return a > b ? a : b;
}

void operationsOnMatrices() {
    int N1, M1; 
    int N2, M2; 
    int point;
    printf("Matrices must necessarily be square!!!\n");
    printf("Size first matrix: ");
    scanf("%d %d", &N1, &M1);
    printf("\n");
    printf("Size second matrix: ");
    scanf("%d %d", &N2, &M2);
    if(N1 != M1 || N2 != M2) {
        printf("Try to keep the matrix size correct");
        return;
    }

    int N3 = max(N1, N2);
    int M3 = max(M1, M2);

    int **array1 = (int**)calloc(N1, sizeof(int*)); 
    int **array2 = (int**)calloc(N2, sizeof(int*));
    int **array3 = (int**)calloc(N3, sizeof(int*));

    memoryAllocation(array1, N1, M1);  
    memoryAllocation(array2, N2, M2); 
    memoryAllocation(array3, N3, M3);

    printf("Input array1: \n");
    Input(array1, N1, M1);
    printf("\n");
    printf("Input array2: \n");
    Input(array2, N2, M2);
    printf("\n");

    printf("Enter the type of operation\n");
    printf("1. Adds\n");
    printf("2. Multiplies\n");
    printf("3. Subtracts\n");
    scanf("%d", &point);
    
    controllerOfMatrixOperations(array1, N1, M1, array2, N2, M2, array3, N3, M3, point);

    memoryCleansing(array1, N1);
    memoryCleansing(array2, N2);
}

void minDisplay(int **array, const int N, const int M) {
    indexOfTheMaxOrMinElement min;
    searchMinElementIndex(array,N, M, &min);
    printf("%d %d", min.x, min.y);
}

void maxDisplay(int **array, const int N, const int M) {
    indexOfTheMaxOrMinElement max;
    searchMaxElementIndex(array,N, M, &max);
    printf("%d %d", max.x, max.y);
}

void controlOverTheChoiceOfOperationsOnTheMatrix(const int point, int **array, const int N, const int M) { 
    switch (point) {
        case 1:
            interfaceForExchangingElements(array, N, M);
            break;
        case 2: 
            exchangeTheMaximumAndMinimumElementInTheMatrix(array, N, M);
            break;
        case 3:
            sortTheArrayInAscendingOrder(array, N, M);
            break;
        case 4:    
            searchingDisplay(array, N, M);
            break;
        case 5:
            minDisplay(array, N, M);
            break;
        case 6:
            maxDisplay(array, N, M);
            break;
        default:
            printf("Unfortunately this option is not available :(");
            break;
    }
}

void operationsOnMatrice() {
    int N1, M1; 
    int options;

    printf("Size matrix: ");
    scanf("%d %d", &N1, &M1);
    printf("\n");
    int **array1 = (int**)calloc(N1, sizeof(int*)); 
    memoryAllocation(array1, N1, M1);  

    printf("Input array: \n");
    Input(array1, N1, M1);

    printf("Enter the option number\n");
    printf("1. Swap elements in an array (specify the index as in normal life)\n");
    printf("2. Exchange the maximum and minimum values\n");
    printf("3. Sort the array in ascending order\n");
    printf("4. Searching for an element in an array\n");
    printf("5. Finding the smallest index of an element in an array\n"); // min 
    printf("6. Finding the largest index of an element in the array\n"); // max
    scanf("%d", &options);

    controlOverTheChoiceOfOperationsOnTheMatrix(options, array1, N1, M1);

    printf("\n");
}

void controllerOfUserActions(int point) {
    switch(point) {
        case 1: 
            informationAboutTheMatrix();
            break;
        case 2: 
            operationsOnMatrices();
            break; 
        case 3: 
            operationsOnMatrice();
            break;
        default: 
            printf("Unfortunately this option is not available :(");
            break;
    }
}

int main() { 
    int number;
    printf("Enter the option number\n");
    printf("1. Learns information about the matrix\n");
    printf("2. Operations on matrices\n");
    printf("3. Operations on the matrix\n");
    scanf("%d", &number);

    controllerOfUserActions(number);

    return 0;
}
