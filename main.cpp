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


//QuickSort which saves each step in a 2D vector
std::vector<std::vector<unsigned int>> QuickSort(std::vector<unsigned int> v)
{
    std::vector<std::vector<unsigned int>> steps;
    steps.push_back(v);
    //TODO Implement QuickSort
    return steps;
}

//MergeSort which saves each step in a 2D vector
std::vector<std::vector<unsigned int>> MergeSort(std::vector<unsigned int> v)
{
    std::vector<std::vector<unsigned int>> steps;
    steps.push_back(v);
    //TODO Implement MergeSort
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
result = QuickSort(v1);
    printVector<unsigned int>(result);


    return 0;
}
