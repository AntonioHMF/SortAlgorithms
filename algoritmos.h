//Funções Auxiliares
int *gerarArrayAleatorio(int qtdeElementos);

void embaralha(int *vetor, int qtdeElementos);

void apagarArray(int *vetor);

int maxValor(int arr[], int n);

void troca(int *x, int *y);

//Setor - Bubble Sort

void bubbleSort(int *arr, int n);

//Setor - Selection Sort

void selectionSort(int *arr, int n);

//Setor - Insertion Sort

void insertionSort(int *arr, int n);

//Setor - Merge Sort

void mergeSort(int *arr, int inicio, int fim);

void merge(int *arr, int inicio, int meio, int fim);

//Setor - Quick Sort

void quickSort(int *arr, int inicio, int fim);

int particiona(int *arr, int inicio, int fim);

//Setor - Shell Sort

void shellSort(int *arr, int n);

//Setor - Heap Sort

void heapSort(int *arr, int n);

void criaHeap(int *arr, int i, int f);

//Setor - Bucket Sort

void bucketSort(int *arr, int n);

//Setor - Radix Sort
void placeCountingSort(int *arr, int n, int exp);

void radixSort(int *arr, int n);


