#include <cstring>

class DynamicArray {
public:

    DynamicArray(std::size_t capacity) 
        : size_{0uz}
        , capacity_{capacity}
    {
        std::allocator<int> alloc;
        data_ = alloc.allocate(capacity_);
    }

    ~DynamicArray() {
        std::allocator<int> alloc;
        alloc.deallocate(data_, capacity_);
    }

    int get(std::size_t i) {
        return data_[i];
    }

    void set(std::size_t i, int n) {
        data_[i] = n;
    }

    void pushback(int n) {
        if (size_ >= capacity_) this->resize();
        data_[size_] = n;
        ++size_;
    }

    int popback() {
        --size_;
        return data_[size_];
    }

    void resize() {
        int* oldData = data_;
        std::size_t oldCapacity = capacity_;

        capacity_ *= 2;

        std::allocator<int> alloc;
        data_ = alloc.allocate(capacity_);

        std::memcpy(data_, oldData, oldCapacity * sizeof(int));
        alloc.deallocate(oldData, oldCapacity);
    }

    std::size_t getSize() {
        return size_;
    }

    std::size_t getCapacity() {
        return capacity_;
    }

private:
    std::size_t size_;
    std::size_t capacity_;
    int* data_;
};
