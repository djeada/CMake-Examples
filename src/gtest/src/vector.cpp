#ifndef VECTOR_CPP
#define VECTOR_CPP

template <class T> Vector<T>::Vector() : capacity(0), n(0), data(nullptr) {}

template <class T> Vector<T>::Vector(const Vector<T> &v) {
    n = v.n;
    capacity = v.capacity;
    if (capacity > 0) {
        data = new T[capacity];
        for (int i = 0; i < n; i++)
            data[i] = v.data[i];
    } else {
        data = nullptr;
    }
}

template <class T> Vector<T> &Vector<T>::operator=(const Vector<T> &v) {
    if (this != &v) {
        delete[] data;
        n = v.n;
        capacity = v.capacity;
        if (capacity > 0) {
            data = new T[capacity];
            for (int i = 0; i < n; i++)
                data[i] = v.data[i];
        } else {
            data = nullptr;
        }
    }
    return *this;
}

template <class T> Vector<T>::~Vector() {
    delete[] data;
}

template <class T> typename Vector<T>::iterator Vector<T>::begin() {
    return data;
}

template <class T> typename Vector<T>::iterator Vector<T>::end() {
    return data + size();
}

template <class T> T &Vector<T>::front() {
    return data[0];
}

template <class T> T &Vector<T>::back() {
    return data[n - 1];
}

template <class T> const T &Vector<T>::front() const {
    return data[0];
}

template <class T> const T &Vector<T>::back() const {
    return data[n - 1];
}

template <class T> void Vector<T>::push_back(const T &v) {
    if (n >= capacity) {
        unsigned int newCapacity = (capacity == 0) ? 1 : capacity * 2;
        reserve(newCapacity);
    }
    data[n++] = v;
}

template <class T> T Vector<T>::pop_back() {
    if (n > 0) {
        return data[--n]; // Fix: decrement first, then return
    }
    // Should throw exception in real implementation
    return T();
}

template <class T> void Vector<T>::reserve(unsigned int newCapacity) {
    if (newCapacity > capacity) {
        T *newData = new T[newCapacity];

        for (int i = 0; i < n; i++)
            newData[i] = data[i];

        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
}

template <class T> int Vector<T>::size() const {
    return n;
}

template <class T> bool Vector<T>::empty() const {
    return n == 0;
}

template <class T> void Vector<T>::resize(unsigned int newSize) {
    if (newSize > capacity)
        reserve(newSize);
    n = newSize;
}

template <class T> T &Vector<T>::operator[](unsigned int index) {
    return data[index];
}

template <class T> const T &Vector<T>::operator[](unsigned int index) const {
    return data[index];
}

template <class T> void Vector<T>::clear() {
    n = 0;
    // Don't deallocate capacity - this is standard behavior
}

#endif // VECTOR_CPP
