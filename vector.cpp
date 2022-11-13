template <class T>
class Vector {
  
private:
    T* data;
    size_t size;
    size_t capacity;

public:
    Vector (): size(0), capacity(16) {                                                                          // 0 and 16 are default values for size and capacity
        data = new T[capacity];
    }
  
    Vector (size_t capacity): size(0), capacity(capacity), data(new T[capacity]) {}                             // constructor with default capacity

    Vector(const Vector<T>& other): size(other.size), capacity(other.capacity), data(new T[other.capacity]) {   // copy constructor
        for (size_t i = 0; i < other.size; ++ i) {
            data[i] = other.data[i];
        }
    }

    Vector& operator=(const Vector<T>& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            capacity = other.capacity;
            data = new T[capacity];
            for (size_t i = 0; i < other.size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    ~Vector () {
        delete[] data;
    }

    bool empty() const {
        return size == 0;
    }
  
    size_t get_size() const {
        return size;
    }
  
    size_t get_capacity() const {
        return capacity;
    }

     void push_back(const T& element) {                
        if (size == capacity) {
            resize();
        }
        data[size++] = element;
    }

    T& at(const size_t idx) {                                            // no checks for valid indexes
        return data[idx];
    }

    const T& at(const size_t idx) const {                                
        return data[idx];
    }

    T& operator[](int i) {
        return data[i];
    }

    const T& operator[](int i) const {
        return data[i];
    }

    T& front() {
        return data[0];
    }

    const T& front() const {
        return data[0];
    }

    T& back() {
        return data[size - 1];
    }

    const T& back() const {
        return data[size - 1];
    }

    void pop_back() {
        -- size;
    }

private:
    void resize() {
        if (size > 0) {
            size_t newCapacity = capacity * 2;
            T* newData = new(nothrow) T[newCapacity];
            if (!newData) {
                return;
            }
            for (size_t i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity = newCapacity;
        }
    }
};
