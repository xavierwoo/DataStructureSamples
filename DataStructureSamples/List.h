//
//  List.h
//  DataStructureSamples
//
//  Created by 吴 歆韵 on 2018/11/28.
//  Copyright © 2018 Xavier Woo. All rights reserved.
//

#ifndef List_h
#define List_h

template <class T>
class List {
private:
    struct Node{
        T data;
        Node *prev, *next;
        Node(const T &d, Node *p, Node *n):data(d), prev(p), next(n){};
    };
    int m_size;
    Node *head;
    Node *tail;
public:
    class Iterator{
        friend class List<T>;
    private:
        Node *current;
        
        Iterator(Node *p):current(p){}
    public:
        T& get_data();
        Iterator next();
        Iterator prev();
        
        bool operator!=(Iterator itr);
    };
    
    List();
    
    Iterator begin();
    Iterator end();
    Iterator insert(Iterator itr, const T& item);
    Iterator erase(Iterator itr);
    int size(){return m_size;}
    
    //////////////////////////////////////////////////////////
    //TODO:实现以下函数功能
    void push_back(const T& item); //在List尾部添加数据item
    /////////////////////////////////////////////////////////
};

template <class T>
List<T>::List() {
    m_size = 0;
    head = new Node(T(), NULL, NULL);
    tail = new Node(T(), NULL, NULL);
    head->next = tail;
    tail->prev = head;
}

/***
 返回头节点迭代器
*/
template <class T>
typename List<T>::Iterator List<T>::begin() {
    return List<T>::Iterator(head->next);
}

/***
 返回尾节点迭代器
 */
template <class T>
typename List<T>::Iterator List<T>::end() {
    return List<T>::Iterator(tail);
}

/***
 在迭代器itr位置之前插入item
*/
template <class T>
typename List<T>::Iterator List<T>::insert(Iterator itr, const T &item) {
    Node *p = itr.current;
    p->prev->next = new Node(item, p->prev, p);
    p->prev = p->prev->next;
    ++m_size;
    return Iterator(p->prev);
}

/***
 获取后继迭代器
*/
template <class T>
typename List<T>::Iterator List<T>::Iterator::next() {
    return List<T>::Iterator(current->next);
}

/***
 迭代器的不等判断
*/
template <class T>
bool List<T>::Iterator::operator!=(Iterator itr) {
    return current != itr.current;
}

/***
 获取迭代器当前指向元素
*/
template <class T>
T& List<T>::Iterator::get_data() {
    return current->data;
}

/***
 删除迭代器指向的节点
*/
template <class T>
typename List<T>::Iterator List<T>::erase(List<T>::Iterator itr) {
    Node *p = itr.current;
    Iterator re(p->next);
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
    m_size--;
    return re;
}

#endif /* List_h */
