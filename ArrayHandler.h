#include <cstdlib>
#include <limits>
#include <cstring>
#include <cstddef>


template<typename T>
class ArrayHandler {
private:
    size_t _size;
    T* _array[100000];
    T _Max;
    T _Min;
public:
    ArrayHandler() : _size(0),  _Min(std::numeric_limits<T>::max()), _Max(std::numeric_limits<T>::min()) {

    }


    

    void AppendElem(T elem) {
        _array[_size++] = elem;
        _Min = (elem < _Min) ? elem : _Min;
        _Max = (elem > _Max) ? elem : _Max;
        }

    bool IsContains(const T* elem) const {
        const T* konec = _array + _size;
        const T* nach = _array;
        while(nach < konec){
            if(*nach == *konec) return true;
            ++nach;
        }
        
        return false;
    }

    T GetMax() {
        return _Max;
    }

    T GetMin() {
        return _Min;
    }

    ~ArrayHandler() {

    }

};