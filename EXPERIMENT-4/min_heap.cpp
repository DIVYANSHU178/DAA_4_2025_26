#include<bits/stdc++.h>
using namespace std;

#define MAX 100

  if(right < heapSize && heap[smallest] > heap[right]) smallest = right;
  
  if(smallest !=i) {
    swap(heap[smallest] , heap[i]);
    heapifyDown(smallest);
    swap(heap[(i-1)/2] , heap[i]);
    i = (i-1)/2;
}

}

void insert(int val) {

if(heapSize == MAX) {

  cout<<"overflow"<<endl;
  return ;

}
  
  heap[heapSize] = val;
    heapSize++;
  heapifyUp(heapSize-1);
}

void deleteRoot()
{
  if(heapSize ==0) {
cout<<"underflow ";
  
  return;
  }
  heap[0] = heap[heapSize-1];
  heapSize--;
  heapifyDown(0);

}
int main() {
  insert(10);
  insert(20);
  insert(30);
  insert(1);
  deleteRoot();
  deleteRoot();
  
  for(int i =0;i<heapSize;i++) cout<<heap[i]<< " ";

}