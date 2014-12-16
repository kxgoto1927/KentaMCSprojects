/*! \author  Kenta Goto
 *  \class  MCS 360
 *  \instructor Professor Lowman
 *  \assignment Project 1
 *  \file stack.cpp
 *  \brief Professor Lowman's Class Stack.  He uses a high level ADT to create a stack.
 */
/**
 * Construct the stack.
 */
template <class Object>
Stack<Object>::Stack(){
    topOfStack = NULL;
}

/**
 * Destructor.
 */
template <class Object>
Stack<Object>::~Stack(){
    makeEmpty();
}

/**
 * Test if the stack is logicaly full,
 * Return false always, in this implementation.
 */
template <class Object>
bool Stack<Object>::isFull() const{
    return false;
}

/**
 * Test if the stack is logically empty,
 * Return true if empty, false otherwise.
 */
template <class Object>
bool Stack<Object>::isEmpty() const{
    return topOfStack == NULL;
}

/**
 * Make the stack logically empty.
 */
template <class Object>
void Stack<Object>::makeEmpty(){
    while( !isEmpty())
        pop();
}

/**
 * Insert x into the stack.
 */
template <class Object>
void Stack<Object>::push( const Object & x ){
    topOfStack = new ListNode( x, topOfStack );
}

/**
 * Get the most recently inserted item in the stack.
 * return the most recently inserted item in the stack
 * or throw an exception if empty.
 */
template <class Object>
const Object & Stack<Object>::top() const{
    if( isEmpty() ){
        std::cout << "Underflow()" << std::endl;
        //inlcude code to handle exception
        //throw new Underflow();
    }
    return topOfStack->element;
}

/**
 * remove the most recently inserted item from the stack.
 * throw the Underflow exception if the stack is empty.
 */
template <class Object>
void Stack<Object>::pop(){
    if( isEmpty()){
        std::cout << "Underflow()" << std::endl;
        //inlcude code to handle exception
        //throw new Underflow();
    }

    ListNode *oldTop = topOfStack;
    topOfStack = topOfStack->next;
    delete oldTop;
}

/**
 * return and remove the most recently inserted item from the stack.
 * throw the Underflow exception if the stack is empty.
 */
template <class Object>
Object Stack<Object>::topAndPop(){
    Object topItem = top();
    pop();
    return topItem;
}

/**
 * Deep copy.
 */
template <class Object>
const Stack<Object> & Stack<Object>::
operator=( const Stack<Object> & rhs ){
    if( this != &rhs ){
        makeEmpty();
        if( rhs.isEmpty())
            return *this;

        ListNode *rptr = rhs.topOfStack;
        ListNode *ptr = new ListNode( rptr->element );
        topOfStack = ptr;

        for( rptr = rptr->next; rptr != NULL; rptr = rptr->next )
            ptr = ptr->next = new ListNode( rptr->element );
    }
    return *this;
}
/**
 * Copy Constructor
 */
template <class Object>
Stack<Object>::Stack( const Stack<Object> & rhs ){

    topOfStack = NULL;
    *this = rhs;
}
