//#include <iostream>
//using namespace std;
//void growArray(int*& arr, int& capacity, int size)
//{
//    capacity = capacity * 2;
//    int* temp = new int[capacity];
//
//    for (int i = 0; i < size; i++)
//    {
//        temp[i] = arr[i];
//    }
//    delete[] arr;
//    arr = temp;
//}
//
//void shrinkArray(int*& arr, int& capacity, int size)
//{
//    if (capacity > 1 && size <= capacity / 2)
//    {
//        int newCapacity = capacity / 2;
//
//        if (newCapacity < 1)
//        {
//            newCapacity = 1;
//        }
//        int* temp = new int[newCapacity];
//        for (int i = 0; i < size; i++)
//        {
//            temp[i] = arr[i];
//        }
//        delete[] arr;
//        arr = temp;
//        capacity = newCapacity;
//    }
//}
//
//void display(int* arr, int size)
//{
//    cout << "Current roll numbers: ";
//
//    for (int i = 0; i < size; i++)
//    {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//}
//
//int main()
//{
//    int capacity;
//    cout << "Enter initial capacity: ";
//    cin >> capacity;
//    int* arr = new int[capacity];
//    int size = 0;
//    int choice;
//    int rollNumber;
//    do
//    {
//        cout << "\n1. Insert roll number" << endl;
//        cout << "2. Remove roll number" << endl;
//        cout << "3. Exit" << endl;
//        cout << "Enter your choice: ";
//        cin >> choice;
//        if (choice == 1)
//        {
//            cout << "Enter roll number: ";
//            cin >> rollNumber;
//            if (size == capacity)
//            {
//                growArray(arr, capacity, size);
//            }
//            arr[size] = rollNumber;
//            size++;
//
//            display(arr, size);
//        }
//        else if (choice == 2)
//        {
//            cout << "Enter roll number to remove: ";
//            cin >> rollNumber;
//            int index = -1;
//            for (int i = 0; i < size; i++)
//            {
//                if (arr[i] == rollNumber)
//                {
//                    index = i;
//                    break;
//                }
//            }
//            if (index != -1)
//            {
//                for (int i = index; i < size - 1; i++)
//                {
//                    arr[i] = arr[i + 1];
//                }
//                size--;
//
//                shrinkArray(arr, capacity, size);
//
//                display(arr, size);
//            }
//            else
//            {
//                cout << "Roll number not found." << endl;
//            }
//        }
//        else if (choice == 3)
//        {
//            cout << "Program ended." << endl;
//        }
//        else
//        {
//            cout << "Invalid choice." << endl;
//        }
//
//    } while (choice != 3);
//
//    delete[] arr;
//
//    return 0;
//}