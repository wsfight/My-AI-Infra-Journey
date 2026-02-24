#ifndef VECTOR_H_
#define VECTOR_H_
#include <utility>
template <typename object>
/**
 * move函数:告诉编译器把一个左值变成右值. 无任何开销.实际调用的是移动构造函数或者是移动赋值运算符
 */
class Vector
{
public:
    typedef object *iterator;             // 定义iterator为object*类型,vector中迭代器就是一个指针
    typedef const object *const_iterator; // 定义cost_iterator 为object*类型 这个对象里面的值是常量.
    iterator begin()
    {
        return &objects_[0]; // 返回object[0]的地址
    }
    iterator end()
    {
        return &objects_[size()]; // 返回实际容量的下一个地址 会不会是一个无效地址的?
    }
    explicit Vector(int initSize = 0) : size_{initSize}, capacity_{initSize + SPARE_CAPACITY}
    {
        /**
         * explicit:显示转换,避免传参时的隐式转换
         */
        objects_ = new object[capacity_]; // c++中的new是object的数量大小
    }
    explicit Vector(const Vector &v1) : size_{v1.size_}, capacity_{v1.capacity_}
    {
        /**
         * 复制拷贝 深拷贝
         */
        objects_ = new object[capacity_]; // 开辟一个capacity_个object大小的空间
        for (int i = 0; i < v1.size_; ++i)
        {
            objects_[i] = v1.objects_[i];
        }
    }
    Vector &operator=(const Vector &v)
    {
        // 重载赋值运算符
        // this 指向对象本身的指针
        Vector copy = v;        // 拷贝构造
        std::swap(*this, copy); // 交换了堆区里的值
        return *this;
    }
    ~Vector()
    {
        // 析构函数
        delete[] objects_;
    }

    Vector(Vector &&v) : size_{v.size_}, capacity_{v.capacity_}, objects_{v.objects_}
    {
        // 清理原主,在v析构时 如果不清理,会把新的Vector给析构掉.
        // 用法Vector<T> v = std::move(v1);
        v.objects_ = nullptr;
        v.size_ = 0;
        v.capacity_ = 0;
    }
    void reserve(int newCapacity)
    {
        // vector扩容
        if (newCapacity < size_)
        {
            // 不用扩容
            return;
        }
        object *newArray = new object[newCapacity];
        for (int i = 0; i < size_; ++i)
        {
            newArray[i] = std::move(objects_[i]);
        }
        capacity_ = newCapacity;
        std::swap(objects_, newArray); // 交换了指针
        delete[] newArray;
    }
    void resize(int newSize)
    {
        if (newSize > capacity_)
        {
            reserve(newSize * 2);
        }
        size_ = newSize;
    }
    object &operator[](int index)
    {
        // 重载[]运算符 可读可写
        return objects_[index];
    }

    int capacity() const
    {
        // 返回容器的容量
        return capacity_;
    }
    int size() const
    {
        // 返回容器中元素个数
        return size_;
    }
    void clear()
    {
        // 删除容器中所有元素
        // TODO
        size_ = 0;
    }
    bool empty() const
    {
        return size_ == 0;
    }
    void push_back(const object &x)
    {
        // 参数const object&x 传参时不发生拷贝
        // objects_[size_++] = x 由于const object&x 所以这里只能是拷贝构造函数
        if (size_ == capacity_)
        {
            // 检查容量
            reserve(capacity_ * 2 + 1); // 扩容
        }
        objects_[size_++] = x;
    }
    void push_back(object &&x)
    {
        if (size_ == capacity_)
        {
            reserve(capacity_ * 2);
        }
        objects_[size_++] = std::move(x);
    }
    void pop_back()
    {
        --size_;
    }
    const object &back() const
    {
        return objects_[size_ - 1];
    }
    const object &front() const
    {
        return objects_[0];
    }

private:
    int size_;                            // 目前的大小
    int capacity_;                        // 容量
    object *objects_;                     // 一个指针
    static const int SPARE_CAPACITY = 16; // 预留的容量
};
#endif