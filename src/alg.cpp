// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len-1; i++) {
    for (int j = i+1; j < len; j++) {
      if (arr[i] + arr[j] == value)
        count++;
    }
  }
  return count;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0, l = 0, r = len - 1;
  while (l < r - 1) {
    int middle = (l + r) / 2;
    if (arr[middle] <= value)
      l = middle;
    else
      r = middle;
  }
  len = r-1;
  for (int i = len; i >=0; i--) {
    for (int j = 0; j < i; j++) {
      if (arr[i] + arr[j] == value)
        count++;
      if (arr[i] + arr[j] > value)
        break;
    }
  }
  return count;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0, l = 0, r = len - 1;
  while (l < r - 1) {
    int middle = (l + r) / 2;
    if (arr[middle] <= value)
      l = middle;
    else
      r = middle;
  }
  len = r - 1;
  for (int i = 0; i <len; i++) {
    l = i+1, r = len-1;
    int counttwo = 0;
    while (l < r) {
      int mid = (l + r) / 2;
      if (arr[mid] < (value-arr[i]))
        l = mid + 1;
      else
        r = mid;
    }
    while (arr[l] == (value - arr[i])) {
      counttwo++;
      l++;
    }
    count += counttwo;
}
  return count;
}
