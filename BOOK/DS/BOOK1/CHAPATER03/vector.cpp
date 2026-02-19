template <typename object>
class Vector
{
public:
    typedef object *iterator;             // 定义iterator为object*类型
    typedef const object *const_iterator; // 定义cost_iterator 为object*类型 这个对象里面的值是常量.
    iterator begin()
    {
        return &object[0]; // 返回object[0]的地址
    }
    iterator end()
    {
        return &object[size()]; // 返回实际容量的下一个地址 会不会是一个无效地址的?
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
         * 复制拷贝
         */
        objects_ = new object[capacity_]; // 开辟一个capacity_个object大小的空间
        for (int i = 0; i < v1.size_; ++i)
        {
            objects_[i] = v1.objects_[i];
        }
    }
    ~Vector()
    {
        delete[] objects_;
    }

private:
    int size_;                            // 目前的大小
    int capacity_;                        // 容量
    object *objects_;                     // 一个指针
    static const int SPARE_CAPACITY = 16; // 预留的容量
};