// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
    for (int i = 0; i < len - 1; i++) {
      for (int j = len - 1; j > i; j--) {
        if (arr[i] + arr[j] == value) {
          count++;
      }
    }
  }
    return count;
}

int countPairs2(int* arr, int len, int cr, int value) {
  int count = 0, left = cr, right = len-1, mid = 0;
  while (left<=right) {
    mid = 1 + (right - left) / 2;
    if (arr[mid] == value && mid != cr) {
      count++;
      int m1 = mid, m2 = mid;
      while (arr[--m1] == value && m1 > cr) {
        count++;
      }
      while(arr[++m2]=value){
        count++;
      }
      return count;
    } else if (arr[mid] > value) {
      right = mid - 1;
    } else {
      left = mid + 1;
      }
    }
    return 0;
}

int countPairs3(int* arr, int len, int cr, int value) {
  int res = 0;
  for (int i = 0; i < len; i++) {
    if (arr[i] <= value - arr[i]) { 
       res += countPairs2(arr, len, i, value - arr[i]); 
     }
   }
   return res;
}
