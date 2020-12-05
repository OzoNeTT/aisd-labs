template <typename TElement>
class stackInArray {
private:
    unsigned int sizeOfStack;
    TElement *array;

public:
    stackInArray(const unsigned int maxSize) {
        sizeOfStack = 0;
        array = new TElement [maxSize];
    }

    ~stackInArray() {
        delete[] array;
    }

    void push(const TElement newElement) {
        array[sizeOfStack] = newElement;
        sizeOfStack++;
    }

    void pop() {
        sizeOfStack--;
    }

    TElement top() {
        return array[sizeOfStack-1];
    }

    unsigned int size() {
        return sizeOfStack;
    }
};