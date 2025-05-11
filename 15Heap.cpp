#include<iostream>
using namespace std;
#include<queue>

class heap{
    public:

    int arr[100];
    int size;

    heap(){

         arr[1] = -1;
         size = 0;
    }

    void insert(int val){
        size = size + 1;
        int index = size;
        arr[index] = val;

        while(index > 1){

            int parent = index/2;

            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }

    }

    void print(){
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        } cout << endl;
        
    }

    void deletefromHeap(){

        if(size == 0){
            cout << "nothing to delete" ;
            return;
        }
        //step1: put last element in first
        arr[1] = arr[size];
        //step2: remove last element
        size--;
        
        //step3: take root node to its correct position
        int i = 1;

        while(i < size){
            int leftindex = 2*i;
            int rightindex = 2*i+1;

            if(leftindex < size && arr[i] < arr[leftindex]){
                swap(arr[i], arr[leftindex]);
                i = leftindex;
            }
            else if(rightindex < size && arr[i] < arr[rightindex]){
                swap(arr[i], arr[rightindex]);
                i = rightindex;
            }
            else{
                return;
            }
        }

        
    }

    void heapify(int arr[], int n, int i){
        int largest = i;
        // 1 base indexing logic if 0 base indexing then for left = 2*i+1 amd right = 2*i+2
        int left = 2*i;
        int right = 2*i+1;
        //no need of <=
        if(left <= n && arr[largest] < arr[left]){
            largest = left;
        }
          //no need of <= 
        if(right <= n && arr[largest] < arr[right]){
            largest = right;
        }
        if(largest != i){
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }

    void heapSort(int arr[], int n){
        int size = n;
        while(size > 1){
            //step1: swap 
            swap(arr[size], arr[1]);
            size--;
            
            //step2
            heapify(arr, size, 1);
        }
    }
};

int main(){

    heap h;

    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deletefromHeap();
    h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    // if 1 base indexing so below i = n/2 or if 0 base indexing then i = n/2-1
    for (int i = n/2; i > 0; i--){

        h.heapify(arr, n, i);
    }
    cout << "printing the array now: " << endl ;

    for (int i = 1; i <= n; i++)
        {
            cout << arr[i] << " " ;
        }cout << endl;

        h.heapSort(arr, n);
         cout << "printing the Sorted array now: " << endl ;

    for (int i = 1; i <= n; i++)
        {
            cout << arr[i] << " " ;
        }

    cout << endl;

    cout << " Max heapusing Priority Queue " << endl;

    priority_queue<int> pq;

    pq.push(5);
    pq.pop();
    pq.push(4);
    pq.push(2);
    pq.push(9);
    cout << "Top :" << pq.top() << endl;
    cout << "size :" << pq.size() << endl;
    string ans = (pq.empty()) ? "empty" : "Notempty";
    cout << ans ;

    cout << endl;
    cout << "Using Min heap " << endl;

    priority_queue<int, vector<int>, greater<int>> minheap;

    minheap.push(5);
    minheap.pop();
    minheap.push(4);
    minheap.push(2);
    minheap.push(9);
    cout << "Top :" << minheap.top() << endl;
    cout << "size :" << minheap.size() << endl;
    string res = (minheap.empty()) ? "empty" : "Notempty";
    cout << res ;

    
        
    

    return 0;
}