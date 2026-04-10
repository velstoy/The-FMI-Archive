#pragma once
#include <utility>
#include <functional>

template<class T>
class Optional {
private:
    T* value = nullptr;

    void copyFrom(const Optional<T>& other);
    void moveFrom(Optional<T>&& other);
    void free();
public:
    Optional() = default;
    Optional(const T& value);
    Optional(T&& value);
    Optional(const Optional<T>& other);
    Optional(Optional<T>&& other);

    Optional<T>& operator=(const Optional<T>& other);
    Optional<T>& operator=(Optional<T>&& other);

    const T& getOrDefault(const T& value) const;

    Optional<T> apply(const std::function<void(T& arg)>& func);

    void filterFirst(std::function<bool(const T& arg)> func, std::initializer_list<T>& args);
    void filterLast(std::function<bool(const T& arg)> func, std::initializer_list<T>& args);

    void clear();

    ~Optional();
};

template<class T>
inline void Optional<T>::copyFrom(const Optional<T>& other)
{
    this->value = new T(*other.value);
}

template<class T>
inline void Optional<T>::moveFrom(Optional<T>&& other)
{
    this->value = std::move(other.value);
    other.value = nullptr;
}

template<class T>
inline void Optional<T>::free()
{
    delete value;
}

template<class T>
inline Optional<T>::Optional(const T& value)
{
    *(this->value) = value;
}

template<class T>
inline Optional<T>::Optional(T&& value)
{
    *(this->value) = std::move(value);
    value = T{};
}

template<class T>
inline Optional<T>::Optional(const Optional<T>& other)
{
    copyFrom(other);
}

template<class T>
inline Optional<T>::Optional(Optional<T>&& other)
{
    moveFrom(other);
}

template<class T>
inline Optional<T>& Optional<T>::operator=(const Optional<T>& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }

    return *this;
}

template<class T>
inline Optional<T>& Optional<T>::operator=(Optional<T>&& other)
{
    if (this != &other)
    {
        free();
        moveFrom(other);
    }

    return *this;
}

template<class T>
inline const T& Optional<T>::getOrDefault(const T& value) const
{
    if (!this->value) 
    {
        return value;
    }

    return *(this->value);
}

template<class T>
inline Optional<T> Optional<T>::apply(const std::function<void(T& arg)>& func)
{
    if (value)
    {
        func(*value);
    }

    return *this;
}

template<class T>
inline void Optional<T>::filterFirst(std::function<bool(const T& arg)> func, std::initializer_list<T>& args)
{
    size_t size = args.size();
    for (size_t i = 0; i < size; i++)
    {
        if (func(args[i])) 
        {
            *(this->value) = args[i];
            return;
        }
    }
}

template<class T>
inline void Optional<T>::filterLast(std::function<bool(const T& arg)> func, std::initializer_list<T>& args)
{
    for (size_t i = args.size(); i > 0; i--)
    {
        if (func(args[i]))
        {
            *(this->value) = args[i];
            return;
        }
    }
}

template<class T>
inline void Optional<T>::clear()
{
    free();
    this->value = nullptr;
}

template<class T>
inline Optional<T>::~Optional()
{
    free();
}

