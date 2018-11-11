int BinarySearch(const int A[], int X, int N) {
    int Low, Mid, High;

    Low = 0;
    High = N - 1;

    while (Low <= High) {
        Mid = (Low + High) / 2;
        if (A[Mid] < X) {
            Low = Mid + 1;
        } else if (A[Mid] > X){
            High = Mid - 1;
        } else {
            return Mid;
        }
    }
    return -1;
}
