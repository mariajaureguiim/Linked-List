#include <iostream>
#include <vector>
using namespace std;
template <typename T> class LinkedList {
public:
    struct Node {
        T data;
        Node* next;
        Node* prev;
    };

    /*============ Construction/ Destruction ==================*/
    LinkedList();  // DEFAULT CONSTURCTOR
    ~LinkedList(); // DESTRUCTOR
    LinkedList(const LinkedList<T>& list);
    /*================ BEHAVIORS ==========================*/
    void PrintForward() const;

    void PrintReverse() const;
    void PrintForwardRecursive(const Node* node) const;
    void PrintReverseRecursive (const Node* node) const;
    /*================ Accessors ==========================*/
    unsigned int NodeCount() const;
    unsigned int size() const;
    Node* Head() const;

    Node* Head();

    Node* Tail() const;

    Node* Tail();
    void FindAll(vector<Node*>& outData, const T& value) const;
    const Node* Find(const T& data) const;
    Node* Find(const T& data);
    const Node* GetNode(unsigned int index) const;
    Node* GetNode(unsigned int index);
    /*================ Insertion ==========================*/
    void AddHead(const T& data);

    void AddTail(const T& data);

    void AddNodesHead(const T* data, unsigned int count);

    void AddNodesTail(const T* data, unsigned int count);
    void InsertAfter(Node* node, const T& data);
    void InsertBefore(Node* node, const T& data);
    void InsertAt(const T& data, unsigned int index);
    /*================ Insertion ==========================*/
    const T& operator[](unsigned int index) const;
    T& operator[](unsigned int index);
    bool operator== (const LinkedList<T>& rhs);
    LinkedList<T>& operator=(const LinkedList<T>& rhs);
/*===================Removal=======================*/
    bool RemoveHead();
    bool RemoveTail();
    unsigned int Remove(const T&data);
    bool RemoveAt (unsigned int index);
    void Clear();
private:
    unsigned int count;
    Node* _head;
    Node* _tail;
};
/* ====================================SOURCE FILL
 * =========================================*/

template <typename T> LinkedList<T>::LinkedList() {
    count = 0;
    _head = nullptr;
    _tail = nullptr;
}

template <typename T> LinkedList<T>::~LinkedList() {
    Node* clear = _head;
    while (clear != nullptr) {
        clear = clear->next;
        delete _head;
        _head = clear;
    }
    delete clear;
}
template <typename T> unsigned int LinkedList<T>::NodeCount() const {
    return count;
}
template <typename T> unsigned int LinkedList<T>::size() const { return count; }

template <typename T> void LinkedList<T>::AddHead(const T& data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    // if the LL is empty
    if (_head == nullptr && _tail == nullptr) {
        _head = newNode;
        _tail = newNode;
    }
        // else
    else {
        newNode->next = _head;
        _head->prev = newNode;
        _head = newNode;
    }

    count++;
}

template <typename T>
void LinkedList<T>::AddNodesHead(const T* data, unsigned int count) {
    for (int i = count - 1; i >= 0; i--) {
        this->AddHead(data[i]);
    }
}

template <typename T> void LinkedList<T>::AddTail(const T& data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    // if the LL is empty
    if (_head == nullptr && _tail == nullptr) {
        _head = newNode;
        _tail = newNode;
    }
        // else
    else {
        newNode->prev = _tail;
        _tail->next = newNode;
        _tail = newNode;
    }

    count++;
}

template <typename T>
void LinkedList<T>::AddNodesTail(const T* data, unsigned int count) {
    for (unsigned int i = 0; i < count; i++) {
        this->AddTail(data[i]);
    }
}

template <typename T> void LinkedList<T>::PrintForward() const {
    if (!_head)
        return;
    Node* nodesPrintF = _head;
    while (nodesPrintF != nullptr) {
        cout << nodesPrintF->data << endl;
        nodesPrintF = nodesPrintF->next;
    }
}

template <typename T> void LinkedList<T>::PrintReverse() const {
    if (!_tail)
        return;
    Node* nodesPrintR = _tail;
    while (nodesPrintR != nullptr) {
        cout << nodesPrintR->data << endl;
        nodesPrintR = nodesPrintR->prev;
    }
}
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Head() const {
    return _head;
}
template <typename T> typename LinkedList<T>::Node* LinkedList<T>::Head() {
    return _head;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Tail() const {
    return _tail;
}
template <typename T> typename LinkedList<T>::Node* LinkedList<T>::Tail() {
    return _tail;
}
template <typename T>
const typename LinkedList<T>::Node*
LinkedList<T>::GetNode(unsigned int index) const {
    if (index >= count)
        throw out_of_range("Index is greater than numbers of nodes");
    unsigned int count = 0;
    Node* currentNode = _head;
    while (currentNode != nullptr) {
        if (count == index)
            return currentNode;
        count++;
        currentNode = currentNode->next;
    }
    return nullptr;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) {
    if (index >= count)
        throw out_of_range("Index is greater than numbers of nodes");
    unsigned int count = 0;
    Node* currentNode = _head;
    while (currentNode != nullptr) {
        if (count == index)
            return currentNode;
        count++;
        currentNode = currentNode->next;
    }
    return nullptr;
}

template <typename T>
void LinkedList<T>::FindAll(vector<LinkedList::Node*>& outData,
                            const T& value) const {
    Node* currentNode = _head;
    while (currentNode != nullptr) {
        int i = 0;
        if (currentNode->data == value) {
            i++;
            outData.push_back(currentNode);
        }
        currentNode = currentNode->next;
    }
}
template <typename T>
const T& LinkedList<T>::operator[](unsigned int index) const {
    return GetNode(index)->data;
}

template <typename T> T& LinkedList<T>::operator[](unsigned int index) {
    return GetNode(index)->data;
}
template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data) const {
    Node* currentNode = _head;
    while (currentNode != nullptr) {
        if (currentNode->data == data)
            return currentNode;
        currentNode = currentNode->next;
    }

    return nullptr;
}
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data) {
    Node* currentNode = _head;
    while (currentNode != nullptr) {
        if (currentNode->data == data)
            return currentNode;
        currentNode = currentNode->next;
    }

    return nullptr;
}
template <typename T> LinkedList<T>::LinkedList(const LinkedList<T>& list) {
    _head = nullptr;
    _tail = nullptr;
    Node* currentNode = list.Head();
    while (currentNode != nullptr) {
        AddTail(currentNode->data);
        currentNode = currentNode->next;
    }
}
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs) {

    Clear();
    _head = nullptr;
    _tail = nullptr;
    Node* currentNode = rhs.Head();
    while (currentNode != nullptr) {
        AddTail(currentNode->data);
        currentNode = currentNode->next;
    }
    return *this;

}


template <typename T>
void LinkedList<T>::InsertAfter(Node* node, const T& data) {
    Node* currentNode = node;
    if (currentNode == _tail) {
        AddTail(data);
    }


    else {
        Node* newNode = new Node;

        newNode->data = data;
        newNode->next = currentNode->next;
        newNode->prev = currentNode;
        currentNode->next = newNode;
        newNode->next->prev = newNode;

        count++;
    }
}

template <typename T>
void LinkedList<T>::InsertBefore(Node* node, const T& data) {
    Node* currentNode = node;
    if (currentNode == _head) {
        AddHead(data);

    }
    else {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = currentNode;
        newNode->prev = currentNode->prev;
        currentNode->prev->next = newNode;
        currentNode->prev = newNode;

        count++;
    }
}

template <typename T>
void LinkedList<T>::InsertAt(const T& data, unsigned int index) {

    if (index > count)
        return;
    else if (index == count){
        AddTail(data);
        return;
    }


    else if (index == 0){

        AddHead(data);
        return;
    }
    else {


        unsigned int count = 0;
        Node* currentNode = _head;
        while (currentNode != nullptr) {
            if (count == index)
                break;
            count++;
            currentNode = currentNode->next;
        }
        InsertBefore(currentNode, data);
    }


}
template <typename T>
bool LinkedList<T>:: operator== (const LinkedList<T>& rhs){
    Node * A = _head;
    Node * B = rhs.Head();

    while(A!=nullptr && B!=nullptr){
        if(A->data != B->data)
            return false;

        A = A->next;
        B = B->next;
    }

    if(A!=nullptr || B!=nullptr)
        return false;

    return true;
}

template <typename T>
bool LinkedList<T>:: RemoveHead(){
    Node* nodeDelete= _head;

    if(nodeDelete == nullptr)
        return false;

    //only 1 node
    if(count == 1){
        _head = nullptr;
        _tail = nullptr;
        delete nodeDelete;
        count--;
        return true;
    }

    //more than 1 node
    _head = _head->next;
    _head->prev = nullptr;

    count--;
    delete nodeDelete;
    return true;


}
template <typename T>
bool LinkedList<T>:: RemoveTail(){
    Node* nodeDelete= _tail;

    if(nodeDelete == nullptr)
        return false;

    //only 1 node
    if(count == 1){
        _head = nullptr;
        _tail = nullptr;
        delete nodeDelete;
        count--;
        return true;
    }

    //more than 1 node
    _tail = _tail->prev;
    _tail->next = nullptr;

    count--;
    delete nodeDelete;
    return true;

}

template <typename T>
bool LinkedList<T>::RemoveAt (unsigned int index) {

    if(index >= count)
        return false;

    Node * temp = GetNode(index);

    if(temp!=nullptr){
        if(temp == _head){
            return RemoveHead();
        }
        else if(temp== _tail){
            return RemoveTail();
        }
            //remove from middle
        else{
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            count--;
            return true;
        }
    }
    else{
        return false;
    }


}
template <typename T>
unsigned int LinkedList<T>::Remove(const T&data){

    int totalRemoved = 0;

    Node * temp;

    do{
        temp = Find(data);
        if(temp!=nullptr){
            if(temp == _head){
                if(RemoveHead()){
                    totalRemoved++;
                }
            }
            else if(temp== _tail){
                if(RemoveTail()){
                    totalRemoved++;
                }
            }
                //remove from middle
            else{
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
                count--;
                totalRemoved++;
            }

        }
    }while(temp!=nullptr);

    return totalRemoved;

}
template<typename T>
void LinkedList<T>::Clear() {
    this->~LinkedList<T>();

    _head = nullptr;
    _tail = nullptr;
    count=0;
}

template <typename T>
void LinkedList<T>:: PrintForwardRecursive(const Node* node) const{
    if (node== nullptr)
        return;
    else
        cout<< node->data<< endl;
    PrintForwardRecursive(node->next);
}
template <typename T>
void LinkedList<T>:: PrintReverseRecursive (const Node* node) const{
    if (node== nullptr)
        return;
    else
        cout<< node->data<< endl;
    PrintReverseRecursive(node->prev);
}