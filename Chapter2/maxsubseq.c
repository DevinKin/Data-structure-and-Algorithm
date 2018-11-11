int MaxSubsequenceSum1(const int A[], int N) {
    int ThisSum, MaxSum, i, j, k;

    /* 总开销: O(1*N*N*N)=O(3) */
    /* 赋值开销是O(1) */
    MaxSum = 0;
    /* N次的循环 */
    for (i = 0; i < N; i++) {
        /* N-i次循环 */
        for(j = i; j < N; j++) {
            ThisSum = 0;
            /* j-i+1次循环,假设为N次 */
            for (k = i; k <= j; k++) {
                ThisSum += A[k];
            }
            if (ThisSum > MaxSum) {
                MaxSum = ThisSum;
            }
        }
    }
    return MaxSum;
}

int MaxSubsequenceSum2(const int A[], int N) {
    int ThisSum, MaxSum, i, j;

    MaxSum = 0;
    /* N次循环 */
    for(i = 0; i < N; i++) {
        ThisSum = 0;
        /* N-i次循环 */
        for(j = i; j < N; j++) {
            ThisSum += A[j];

            if (ThisSum > MaxSum) {
                MaxSum = ThisSum;
            }
        }
    }
    return MaxSum;
}

static int Max3(int first, int second, int third) {
  return first > second ? (first > third ? first : third)
                        : (second > third ? second : third);
}

int MaxSubsequenceSum3(const int A[], int Left, int Right) {
    int MaxLeftSum, MaxRightSum;
    int MaxLeftBorderSum, MaxRightBorderSum;
    int LeftBorderSum, RightBorderSum;
    int Center, i;

    /* Base Case */
    if (Left == Right) {
        if (A[Left] > 0) {
            return A[Left];
        } else {
            return 0;
        }
    }

    Center = (Left + Right) / 2;
    MaxLeftSum = MaxSubsequenceSum3(A, Left, Center);
    MaxRightSum = MaxSubsequenceSum3(A, Center + 1, Right);

    MaxLeftBorderSum = 0;
    LeftBorderSum = 0;
    for (i = Center; i >= Left; i--) {
        LeftBorderSum += A[i];
        if (LeftBorderSum > MaxLeftBorderSum) {
            MaxLeftBorderSum = LeftBorderSum;
        }
    }

    MaxRightBorderSum = 0;
    RightBorderSum = 0;
    for (i = Center + 1; i <= Right; i++) {
        RightBorderSum += A[i];
        if (RightBorderSum > MaxRightBorderSum) {
            MaxRightBorderSum = RightBorderSum;
        }
    }

    return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}



int MaxSubsequenceSum4(const int A[], int N) {
    int ThisSum, MaxSum, j;
    ThisSum = MaxSum = 0;

    for (j = 0; j < N; j++) {
        ThisSum += A[j];

        if (ThisSum > MaxSum) {
            MaxSum = ThisSum;
        } else if (ThisSum < 0) {
            ThisSum = 0;
        }
    }
    return MaxSum;
}
