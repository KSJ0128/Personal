#include <iostream>
using namespace std;

int partition(int list[], int size)
{  
   int low = 1, high = size - 1;
   int pivot = list[0];
   int pivotIndex = 0;

   while(high > low)
   {
      while(low <= high && list[high] > pivot)
         high--;

      while(low <= high && list[low] <= pivot)
         low++;

      if(high > low) // 마지막에 low와 high가 역전되는데 해당 경우를 피하기 위해
      {
         int tmp = list[high];
         list[high] = list[low];
         list[low] = tmp;
      }
   }

   for(int i = 0, j = 1; i < size; i++, j++)
   {
      if(list[pivotIndex] > list[j])
      {
         int tmp = list[pivotIndex];
         list[pivotIndex] = list[j];
         list[j] = tmp;
      }
      else
         break;
      
      pivotIndex += 1;
   }
   return pivotIndex;
}

int main()
{
   int size, list[80];
   cin >> size;

   for(int i = 0; i < size; i++)
   {
      cin >>list[i];
   }

   cout << partition(list, size) << endl;

   for(int i = 0; i < size; i++)
   {
      cout << list[i] << " ";
   }
}