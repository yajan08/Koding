#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void swap(T* a, T* b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}

template <typename T>
class bubble
{
    vector<T> arr;

public:

    void bubble_sort()
    {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (arr[j] > arr[j + 1])
                    swap(&arr[j], &arr[j + 1]);
    }

    void accept()
    {
        char cont;
        T elem;
        cout << endl
             << "Enter data for array:" << endl;
        do
        {
            cout << endl
                 << "Enter element: ";
            cin >> elem;
            arr.push_back(elem);
            cout << endl
                 << "Do you want to add another element? (Y/n): ";
            cin >> cont;
        } while (cont == 'Y' || cont == 'y');
    }

    void display()
    {
        for (int i = 0; i < arr.size(); i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main()
{
    int choice;
    bubble<int> a1;
    bubble<float> a2;

    while (1)
    {
        cout << endl
             << "Choose array data type:" << endl
             << "1 - int" << endl
             << "2 - float" << endl
             << "3 - Exit" << endl
             << endl
             << "Your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            a1.accept();

            cout << endl
                 << "Original int array: ";
            a1.display();

            a1.bubble_sort();

            cout << endl
                 << "Sorted int array: ";
            a1.display();
            break;

        case 2:
            a2.accept();

            cout << endl
                 << "Original float array: ";
            a2.display();

            a2.bubble_sort();

            cout << endl
                 << "Sorted float array: ";
            a2.display();
            break;

        case 3:
            cout << endl
                 << "You have chosen to exit. Bye bye." << endl;
            return 0;

        default:
            cout << endl
                 << "Invalid input! Try again." << endl;
        }
    }
}
