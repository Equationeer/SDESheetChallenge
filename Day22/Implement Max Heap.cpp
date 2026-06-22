class Solution {
public:
    vector<int> heap;

    void initializeHeap() {
        heap.clear();
    }

    void insert(int key) {

        heap.push_back(key);

        int i = heap.size() - 1;

        while (i > 0) {

            int parent = (i - 1) / 2;

            if (heap[parent] < heap[i]) {
                swap(heap[parent], heap[i]);
                i = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int i) {

        int n = heap.size();

        while (true) {

            int largest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < n && heap[left] > heap[largest])
                largest = left;

            if (right < n && heap[right] > heap[largest])
                largest = right;

            if (left < n && right < n &&
                heap[left] == heap[right] &&
                heap[left] > heap[i]) {
                largest = left;
            }

            if (largest == i)
                break;

            swap(heap[i], heap[largest]);
            i = largest;
        }
    }

    void changeKey(int index, int new_val) {

        int old_val = heap[index];

        heap[index] = new_val;

        if (new_val > old_val) {

            while (index > 0) {

                int parent = (index - 1) / 2;

                if (heap[parent] < heap[index]) {
                    swap(heap[parent], heap[index]);
                    index = parent;
                } else {
                    break;
                }
            }

        } else {

            heapifyDown(index);
        }
    }

    void extractMax() {

        int n = heap.size();

        if (n == 0)
            return;

        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty())
            heapifyDown(0);
    }

    bool isEmpty() {
        return heap.empty();
    }

    int getMax() {
        return heap[0];
    }

    int heapSize() {
        return heap.size();
    }
};