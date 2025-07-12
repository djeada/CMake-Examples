
template <class T> class Vector {

  public:
    Vector();
    Vector(const Vector<T> &v);
    ~Vector();

    typedef T *iterator;
    int size() const;
    bool empty() const;
    iterator begin();
    iterator end();
    T &front();
    T &back();
    const T &front() const;
    const T &back() const;
    void push_back(const T &value);
    T pop_back();

    void resize(unsigned int size);
    T &operator[](unsigned int index);
    const T &operator[](unsigned int index) const;
    Vector<T> &operator=(const Vector<T> &);
    void clear();

  private:
    int n;
    int capacity;
    void reserve(unsigned int size);
    T *data;
};

// Include implementation since this is a template
#include "vector.cpp"
