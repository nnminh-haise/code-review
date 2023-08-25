
class Array {
public:
    Array();

    ~Array();

    Array(int capacity);

    Array(int* arr, int length);

    int size();

    void append(int value);

    int get(int index);

    void set(int index, int value);

    void insert(int index, int value);

    void print();

private:
    int _capacity = 0;
    int _length = 0;
    int* _container = nullptr;
};
