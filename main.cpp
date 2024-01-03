#include <iostream>
#include <vector>

//InsertionSort which saves each step in a 2D vector
std::vector<std::vector<unsigned int>> InsertionSort(std::vector<unsigned int> v)
{
    std::vector<std::vector<unsigned int>> steps;
    steps.push_back(v);
    for (unsigned int i = 1; i < v.size(); i++)
    {
        unsigned int j = i;
        while (j > 0 && v[j - 1] > v[j])
        {
            std::swap(v[j], v[j - 1]);
            j--;
        }
        steps.push_back(v);
    }
    return steps;
}

//SelectionSort which saves each step in a 2D vector
std::vector<std::vector<unsigned int>> SelectionSort(std::vector<unsigned int> v)
{
    std::vector<std::vector<unsigned int>> steps;
    steps.push_back(v);
    for (unsigned int i = 0; i < v.size() - 1; i++)
    {
        unsigned int min = i;
        for (unsigned int j = i + 1; j < v.size(); j++)
            if (v[j] < v[min])
                min = j;
        std::swap(v[i], v[min]);
        steps.push_back(v);
    }
    return steps;
}

//BubbleSort which saves each step in a 2D vector
std::vector<std::vector<unsigned int>> BubbleSort(std::vector<unsigned int> v)
{
    std::vector<std::vector<unsigned int>> steps;
    steps.push_back(v);
    for (unsigned int i = 0; i < v.size() - 1; i++){
        for (unsigned int j = 0; j < v.size() - i - 1; j++){
            if (v[j] > v[j + 1])
                std::swap(v[j], v[j + 1]);
        }
        steps.push_back(v);
    }
    return steps;
}

//partition function for QuickSort which saves every step in a 2D vector
int partition(std::vector<unsigned int>& vec, int start, int end)
{
    int pivot = vec[end];
    int i = (start - 1);

    for (int j = start; j <= end - 1; j++)
    {
        if (vec[j] < pivot)
        {
            i++;
            std::swap(vec[i], vec[j]);
        }
    }
    std::swap(vec[i + 1], vec[end]);
    return (i + 1);
}


//QuickSort which saves each step in a 2D vector
std::vector<std::vector<unsigned int>> QuickSort(std::vector<unsigned int>& vec, int start, int end)
{
    static std::vector<std::vector<unsigned int>> steps;
    if (start < end)
    {
        steps.push_back(vec);
        int pi = partition(vec, start, end);
        QuickSort(vec, start, pi - 1);
        QuickSort(vec, pi + 1, end);
    }

    return steps;
}


//merge function for MergeSort which saves every step in a 2D vector
void merge(std::vector<unsigned int>& v, int start, int mid, int end)
{
    std::vector<unsigned int> left;
    std::vector<unsigned int> right;

    for (int i = start; i <= mid; i++)
        left.push_back(v[i]);
    for (int i = mid + 1; i <= end; i++)
        right.push_back(v[i]);

    int i = 0, j = 0, k = start;
    while (i < left.size() && j < right.size())
    {
        if (left[i] <= right[j])
        {
            v[k] = left[i];
            i++;
        }
        else
        {
            v[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left.size())
    {
        v[k] = left[i];
        i++;
        k++;
    }

    while (j < right.size())
    {
        v[k] = right[j];
        j++;
        k++;
    }
}


//MergeSort which saves each step in a 2D vector
std::vector<std::vector<unsigned int>> MergeSort(std::vector<unsigned int>& v, int start, int end)
{
    static std::vector<std::vector<unsigned int>> steps;

    if (start < end) {
        int mid = start + (end - start) / 2;
        // Sort first and second alves
        steps.push_back(v);
        MergeSort(v, start, mid);
        merge(v, start, mid, end);
        MergeSort(v, mid + 1, end);

    }

    return steps;
}

//HeapSort helper function
void heapify(std::vector<unsigned int>& v, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && v[l] > v[largest])
        largest = l;

    if (r < n && v[r] > v[largest])
        largest = r;

    if (largest != i) {
        std::swap(v[i], v[largest]);
        heapify(v, n, largest);
    }
}


//HeapSort which saves each step in a 2D vector
std::vector<std::vector<unsigned int>> HeapSort(std::vector<unsigned int>& v, int n)
{
    static std::vector<std::vector<unsigned int>> steps;
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(v, n, i);

    for (int i = n - 1; i > 0; i--) {
        std::swap(v[0], v[i]);
        heapify(v, i, 0);
        steps.push_back(v);
    }
    return steps;
}


template <typename T>
void printVector(std::vector<std::vector<T>> v)
{
    for (auto i : v[0])
        std::cout << "----";
    std::cout << "-" << std::endl;

    for (auto i1 : v)
    {
        std::cout << "|";
        for (auto i2 : i1)
            std::cout << " " << i2 << " |";
        std::cout << std::endl;
        for (auto i2 : i1)
            std::cout << "----";
        std::cout << "-" << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    std::vector<unsigned int> v1 = { 5, 2, 4, 6, 1, 3, 7 };
    std::vector <std::vector<unsigned int>> result;

    std::cout << "InsertionSort:" << std::endl;
    result = InsertionSort(v1);
    printVector<unsigned int>(result);

    std::cout << "SelectionSort:" << std::endl;
    result.clear();
    result = SelectionSort(v1);
    printVector<unsigned int>(result);

    std::cout << "ExchangeSort/BubbleSort:" << std::endl;
    result.clear();
    result = BubbleSort(v1);
    printVector<unsigned int>(result);

    std::cout << "QuickSort:" << std::endl;
    result.clear();
    auto v2 = v1;
    result = QuickSort(v2, 0, v1.size() - 1);
    printVector<unsigned int>(result);

    std::cout << "MergeSort:" << std::endl;
    result.clear();
    v2 = v1;
    result = MergeSort(v2, 0, v1.size() - 1);
    printVector<unsigned int>(result);

    std::cout << "HeapSort:" << std::endl;
    result.clear();
    v2 = v1;
    result = HeapSort(v2, v2.size());
    printVector<unsigned int>(result);


    return 0;
}
