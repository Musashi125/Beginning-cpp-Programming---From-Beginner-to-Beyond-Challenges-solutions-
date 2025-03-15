#include <iostream>

using namespace std;

void print (int* ptr,size_t count);
int* apply_all(int* arr1, size_t size1, int* arr2, size_t size2);


int main() {
    const size_t array1_size {5};
    const size_t array2_size {3};
    
    int array1[] {1,2,3,4,5};
    int array2[] {10,20,30};
    
    cout << "Array 1: " ;
    print(array1,array1_size);
    
    cout << "Array 2: " ;
    print(array2,array2_size);
    
    int *results = apply_all(array1, array1_size, array2, array2_size);
    constexpr size_t results_size {array1_size * array2_size};

    cout << "Result: " ;
    print(results, results_size);
    delete [] results;
    cout << endl;

    return 0;
}

void print (int* ptr,size_t count)
{
  cout << "[ ";
  for (size_t i{0}; i < count; i++)
    {
    if (i > 0) cout << " ";
    cout << *(ptr+i);
    }
  cout <<" ]" <<endl ;
}

int* apply_all(int* arr1, size_t size1, int* arr2, size_t size2)
{
int* ptr {new int[size1 * size2]};
int* temp {ptr};
for (size_t i {0}; i < size1 ; i++)
{
    for (size_t j {0}; j < size2; j++)
    {
        *ptr= arr1[i] * arr2[j];
         ptr++;
    }
}
return temp;
/*
int  position  {0};
for (size_t i {0}; i < size1 ; i++)
  {
    for (size_t j {0}; j < size2; j++)
      {     
        ptr[position] = arr1[i] * arr2 [j];
        position++;
      }
  }
  return ptr;
  */
}
