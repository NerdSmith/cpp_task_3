#include <iostream>

void read_arr(int** arr, int size) 
{   
    std::cout << "Enter array elements: " << std::endl;
    for (int i = 0; i < size; i++) {
        std::cin >> *(*arr + i);
    }
}

int* get_every_third_element(int** default_arr, int size, int* new_size) 
{
    int* new_arr = new int[size];
    for (int i = 1; (i - 1) < size; i++) {
        if (i % 3 == 0) {
            *(new_arr + *new_size) = *(*default_arr + i - 1);
            (*new_size)++;
        }
    }
    return new_arr;
}

void print_arr(int** arr, int size) 
{
    for (int i = 0; i < size; i++) {
        std::cout << *(*arr + i) << ' ';
    }
}

int main()
{
    int size;
    std::cout << "Enter array size: ";
    std::cin >> size;
    int* arr = new int[size];
    read_arr(&arr, size);

    int new_size = 0;
    int* new_arr = get_every_third_element(&arr, size, &new_size);

    std::cout << "Result: ";
    print_arr(&new_arr, new_size);

    delete[] arr, new_arr;

    return 0;
}
