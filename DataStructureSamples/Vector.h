//
//  Vector.h
//  DataStructureSamples
//
//  Created by 吴 歆韵 on 2018/11/23.
//  Copyright © 2018 Xavier Woo. All rights reserved.
//

#ifndef Vector_h
#define Vector_h

template <class T>
class Vector {
private:
    T *m_data;
    int m_size;
    int m_capacity;
    
    void reserve(int newCapacity);
    
public:
    Vector();
    ~Vector();
    T& at(int index);
    void insert(int index, const T& item);
    void erase(int index);
    int size();
    
    //////////////////////////////////////////////////////////
    //TODO:实现以下函数功能
    void push_back(const T& item); //在Vector尾部添加数据item
    /////////////////////////////////////////////////////////
};

/***
 获取容器中当前元素的个数
*/
template <class T>
int Vector<T>::size() {
    return m_size;
}

template <class T>
Vector<T>::Vector() {
    m_size = 0;
    m_capacity = 4;
    m_data = new T[m_capacity];
}

template <class T>
Vector<T>::~Vector() {
    delete[] m_data;
}

/***
 获取容器中第index号位置的元素
 */
template <class T>
T& Vector<T>::at(int index) {
    return m_data[index];
}


//TODO: 思考，若index大于当前Vector中数据个数，会出现怎样的情况？应该怎样修改代码？
/***
 在index号位置后插入item
*/
template <class T>
void Vector<T>::insert(int index, const T& item){
    if(m_size == m_capacity)reserve(m_capacity *2 +1);
    for(int i=m_size; i > index; ++i){
        m_data[i] = m_data[i-1];
    }
    m_data[index] = item;
    ++m_size;
}

/***
 为容器扩容
*/
template <class T>
void Vector<T>::reserve(int newCapacity) {
    T* old = m_data;
    m_data = new T[newCapacity];
    for (int i=0; i<m_size; i++) {
        m_data[i] = old[i];
    }
    m_capacity = newCapacity;
    delete [] old;
}

/***
 删除第index号位置的元素
*/
template <class T>
void Vector<T>::erase(int index) {
    for (int i = index; i < m_size-1; ++i) {
        m_data[i] = m_data[i+1];
    }
    --m_size;
}

#endif /* Vector_h */
