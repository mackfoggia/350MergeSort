#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;



void mergeSort(int [], int, int);



int main(){
  srand(time(NULL));
  int size = rand() % 75 + 25;
  //int size = 8;
  int * array = new int[size];

  for(int i = 0; i < size; ++i){
    array[i] = rand() % 100 + 1;
    cout << array[i] << " ";
  }
  cout << endl;

  mergeSort(array, 0, size - 1);

  cout << "---------Sorted---------" << endl;
  for(int i = 0; i < size; ++i){
    cout << array[i] << " ";
  }
  cout << endl;

}


void mergeSort(int array[], int low, int high){
  if(low == high) return;
  int mid = (low + high) / 2;

  /*cout << "Before call low: " << low << ", high: " << high << " has: ";
  for(int i = low; i <= high; ++i){
    cout << array[i] << " ";
  }
  cout << endl;*/

  mergeSort(array, low, mid);
  mergeSort(array, mid + 1, high);

  /*cout << "After call: "; 
  for(int i = low; i <= high; ++i){
    cout << array[i] << " ";
  }
  cout << endl;*/

  int l = low;
  int r = mid + 1;

  int tempSize = high - low + 1;
  int index = 0;
  int * temp = new int[tempSize];
  while(index < tempSize){
    if(l == mid + 1) temp[index] = array[r++];
    else if(r == high + 1) temp[index] = array[l++];
    else{
      if(array[l] < array[r]) temp[index] = array[l++];
      else temp[index] = array[r++];
    }
    ++index;
  }
  
  /*cout << "Temp: "; 
  for(int i = 0; i < tempSize; ++i){
    cout << temp[i] << " ";
  }
  cout << endl << endl;*/

  for(int i = 0; i < tempSize; ++i){
    array[low++] = temp[i];
  }

  delete [] temp;
}
