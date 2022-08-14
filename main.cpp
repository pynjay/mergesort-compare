
#include <iostream>
#include <time.h>
#include <chrono>
using namespace std;

void merge2(int *arr, int l, int m, int r){
    int i, j, k;
    int nl = m - l + 1;
    int nr = r - m;
    int arr1[nl], arr2[nr];
    for(i = 0; i<nl; i++){
      arr1[i] = arr[l+i];
    }
    for(j = 0; j<nr; j++){
      arr2[j] = arr[m+1+j];
    }
    i = 0;
    j = 0;
    k = l;
    while(i < nl && j<nr) {
      if(arr1[i] <= arr2[j]) {
         arr[k] = arr1[i];
         i++;
      }else{
         arr[k] = arr2[j];
         j++;
      }
      k++;
   }
    while(i<nl) {       
      arr[k] = arr1[i];
      i++; k++;
    }
     while(j<nr) {    
      arr[k] = arr2[j];
      j++; k++;
    }
}

void mergeSort(int *arr, int l, int r){
    int m;
    if(l < r) {
        m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge2(arr, l, m, r);
    }
}

void merge3(int *arr, int l, int m1, int m2, int r){
    int i, j, o, k;
    int nl = m1 - l + 1;
    int nr = r - m2;
    int nm = m2 - m1;
    int arr1[nl], arr2[nr], arr3[nm];
    for(i = 0; i<nl; i++){
      arr1[i] = arr[l+i];
    }
    for(j = 0; j<nr; j++){
      arr2[j] = arr[m2+1+j];
    }
    for(o = 0; o<nm; o++){
      arr3[o] = arr[m1+1+o];
    }
    i = 0;
    j = 0;
    o = 0;
    k = l;
    while(i < nl && j<nr && o < nm) {
      if(arr1[i] < arr2[j]) {
         if(arr1[i] < arr3[o]){
            arr[k] = arr1[i];
            i++;
         } else {
            arr[k] = arr3[o];
            o++;
         }
      }else{
         if(arr2[j] < arr3[o]){
            arr[k] = arr2[j];
            j++;
         } else {
            arr[k] = arr3[o];
            o++;
         }
      }
      k++;
   }

   while(i < nl && j<nr) {
      if(arr1[i] <= arr2[j]) {
         arr[k] = arr1[i];
         i++;
      }else{
         arr[k] = arr2[j];
         j++;
      }
      k++;
   }

   while(i < nl && o < nm) {
      if(arr1[i] <= arr3[o]) {
         arr[k] = arr1[i];
         i++;
      }else{
         arr[k] = arr3[o];
         o++;
      }
      k++;
   }

   while(o < nm && j<nr) {
      if(arr3[o] <= arr2[j]) {
         arr[k] = arr3[o];
         o++;
      }else{
         arr[k] = arr2[j];
         j++;
      }
      k++;
   }


   while(i<nl) {       
      arr[k] = arr1[i];
      i++; k++;
   }
   while(o<nm) {    
      arr[k] = arr3[o];
      o++; k++;
   }
   while(j<nr) {    
      arr[k] = arr2[j];
      j++; k++;
   }
}

void mergeSort3(int *arr, int l, int r){
    int m1, m2;
    if((r-l) >= 2) {
        m1 = l+(r-l+1)/3-1;
        m2 = l+2*((r-l+1)/3)-1;
        mergeSort3(arr, l, m1);
        mergeSort3(arr, m1+1, m2);
        mergeSort3(arr, m2+1, r);
        merge3(arr, l, m1, m2, r);
    } else if((r-l) == 1){
      merge3(arr, l, l, l, r);
    }
}




int main(){
    //int d[] = {1, 3, 2, 9, 21, 12, 9, 1, 8, 4, 5, 7, 11}; /// 13

    srand( (unsigned)time(NULL));

    const int max = 1000;

    int d[max];

    int c[max];

    int a[max];

    int no1;

    for(int s = 0; s < max; s++){
        no1 = rand() % 100;
        d[s] = no1;
    }

    int num = rand()%100;


    cout << num << endl;


    for(int i = 0; i < max; i++){
        cout << d[i] << ' ';
    }

    cout << endl;


    auto start = std::chrono::high_resolution_clock::now();


    for(int i = 0; i < 1000; i++){

        for(int s = 0; s < max; s++){
            c[s] = d[s];
        }

        mergeSort(c, 0, max-1);

    }

    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start);

    cout << duration.count() << endl;

    /// start of the mess

      auto start1 = std::chrono::high_resolution_clock::now();
    
    for(int i = 0; i < 1000; i++){

            for(int s = 0; s < max; s++){
                a[s] = d[s];
            }

            mergeSort3(a, 0, max-1);


    }

    auto stop1 = std::chrono::high_resolution_clock::now();

    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(stop1-start1);

    cout << duration1.count() << endl;

    for(int i = 0; i < max; i++){
        if(a[i]!=c[i]){
            cout << "FALSE" << endl;
        }
    }
   
   
}