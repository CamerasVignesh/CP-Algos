#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<algorithm>
#include<unordered_map>
#include <set>

using namespace std;

class HeapSort
{

    vector<int> vec{ 12, 11, 13, 5, 6, 7 };;
    public:

        void Swap(vector<int>& vec, int index, int largestIndex)
        {
            int temp = vec[index];
            vec[index] = vec[largestIndex];
            vec[largestIndex] = temp;
        }

        void MaxHeapify(vector<int>& vec, int index, int heapSizeParameter)
        {
            int heapSize = heapSizeParameter;
            while (index < heapSize)
            {
                int left = 2 * index + 1;
                int right = 2 * index + 2;
                int largestIndex = index;
                if (left < heapSize && vec[left] > vec[index])
                {
                    largestIndex = left;
                }
                if (right < heapSize && vec[right] > vec[largestIndex])
                {
                    largestIndex = right;
                }
                if (largestIndex != index)
                {
                    Swap(vec, index, largestIndex);
                    index = largestIndex;
                }
                else
                {
                    break;
                }
            }
        }

        void BuildMaxHeap(vector<int>& vec)
        {
            int start = vec.size() / 2 - 1;
            while (start >= 0)
            {
                MaxHeapify(vec, start, vec.size());
                start--;
            }
        }

        HeapSort()
        {
            
            BuildMaxHeap(vec);
            int heapSize = vec.size() - 1;
            for (int i = heapSize; i >= 1; i--)
            {
                Swap(vec, i, 0);
                MaxHeapify(vec, 0, i);
            }
        }
};

class MaxPriorityQueueUsingHeap : HeapSort
{
    vector<int> vec{ 15, 13, 9, 5, 12, 8, 7, 4, 0, 6, 2, 1 };//Heap Vector
public:
    
    int HeapExtractMax()
    {
        int mx = vec[0];
        vec[0] = vec[vec.size() - 1];
        vec.pop_back();
        MaxHeapify(vec, 0, vec.size());
        return mx;
    }

    void HeapIncreaseKey(int index, int key)
    {
        if (key < vec[index])
        {
            throw new invalid_argument("Invalid value for Max Heap Key");
        }
        vec[index] = key;        
        while (index >= 0)
        {
            int parentIndex = (index - 1) / 2;
            if (vec[parentIndex] < vec[index])
            {
                Swap(vec, index, parentIndex);
                index = parentIndex;
            }
            else
            {
                break;
            }
        }
    }

    void MaxHeapInsert(int val)
    {
        vec.push_back(INT_MIN);
        HeapIncreaseKey(vec.size() - 1, val);
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << " ";
        }
    }
};
