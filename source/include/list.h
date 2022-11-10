#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>  // cout, endl
using std::cout;
using std::endl;

#include <iterator>  // bidirectional_iterator_tag
#include <cassert>   // assert()
#include <algorithm> // copy
using std::copy;
#include <cstddef>   // std::ptrdiff_t
#include <type_traits>

namespace sc { // linear sequence. Better name: sequence container (same as STL).
    /*!
     * A class representing a biderectional iterator defined over a linked list.
     *
     * \note
     * This iterator only works for traversing elements inside the same list.
     *
     * This class is incomplete and it is provided "as is".
     *
     * \date May, 2nd 2017.
     * \author Selan R. dos Santos
     */

    template < typename T >
    class list
    {
        private:
        //=== the data node.
        struct Node
        {
            T data; // Tipo de informação a ser armazenada no container.
            Node * next;
            Node * prev;

            Node( const T &d=T{} , Node * n=nullptr, Node * p=nullptr )
                : data {d}, next{n}, prev{p}
            { /* empty */ }
        };


        //=== The iterator classes.
        public:

        class const_iterator : public std::bidirectional_iterator_tag 
        {
            //=== Some aliases to help writing a clearer code.
            public:
                using value_type        = T;         //!< The type of the value stored in the list.
                using pointer           = T *;       //!< Pointer to the value.
                using reference         = T &;       //!< reference to the value.
                using const_reference   = const T &; //!< const reference to the value.
                using difference_type   = std::ptrdiff_t;
                using iterator_category = std::bidirectional_iterator_tag;

            private:
                Node * m_ptr; //!< The raw pointer.

            public:
                const_iterator( Node * ptr = nullptr ){
                    m_ptr = ptr;
                }
                
                ~const_iterator() = default;
                
                const_iterator( const const_iterator & itr){
                    m_ptr = itr.m_ptr;
                }
                
                const_iterator& operator=( const const_iterator & itr){
                    m_ptr = itr.m_ptr;
                }
                
                reference  operator*() {
                    return m_ptr->data;
                }
                
                const_reference  operator*() const {
                    return m_ptr->data;
                }
                
                const_iterator operator++() {
                    m_ptr = m_ptr->next;
                    return *this;
                }
                
                const_iterator operator++(int) {
                    auto cpy = *this;
	                m_ptr = m_ptr->next;
                    return cpy;
                }
                
                const_iterator operator--() {
                    m_ptr = m_ptr->prev;
                    return *this;
                }
                
                const_iterator operator--(int) {
                    auto cpy = *this;
	                m_ptr = m_ptr->prev;
                    return *this;
                }
                
                bool operator==( const const_iterator & rhs ) const {
                    return m_ptr == rhs.m_ptr;
                }
                
                bool operator!=( const const_iterator & rhs ) const {
                    return m_ptr != rhs.m_ptr;
                }


                //=== Other methods that you might want to implement.
                /// it += 3; // Go back  3 positions within the container. 
                const_iterator operator+=( difference_type step) { /* TODO */ return const_iterator{}; }
                
                /// it -= 3; // Go back  3 positions within the container. 
                const_iterator operator-=(  difference_type step ) { /* TODO */ return const_iterator{}; }
                
                /// it->method()
                //pointer operator->( void ) const{
                //
                //}
                
                /// it1 - it2
                difference_type operator-( const const_iterator & rhs ) const { /* TODO */ return 0; }

                // We need friendship so the list<T> class may access the m_ptr field.
                friend class list<T>;

                friend std::ostream & operator<< ( std::ostream & os_, const const_iterator & s_ )
                {
                    os_ << "[@"<< s_.m_ptr << ", val = " << s_.m_ptr->data << "]";
                    return os_;
                }
        };


        class iterator : public std::bidirectional_iterator_tag 
        {
            //=== Some aliases to help writing a clearer code.
            public:
                using value_type        = T; //!< The type of the value stored in the list.
                using pointer           = T *; //!< Pointer to the value.
                using reference         = T &; //!< reference to the value.
                using const_reference   = const T &; //!< const reference to the value.
                using difference_type   = std::ptrdiff_t;
                using iterator_category = std::bidirectional_iterator_tag;

            private:
                Node * m_ptr; //!< The raw pointer.

            public:
                iterator( Node * ptr = nullptr ){
                    m_ptr = ptr;
                }

                ~iterator() = default;

                iterator( const iterator & itr){
                    m_ptr = itr.m_ptr;
                }

                iterator& operator=( const iterator & itr){
                    m_ptr = itr.m_ptr;
                }

                reference  operator*() {
                    return m_ptr->data;
                }

                const_reference  operator*() const {
                    return m_ptr->data;
                }
                
                iterator operator++() {
                    m_ptr = m_ptr->next;
                    return *this;
                }
                
                iterator operator++(int) {
                    auto cpy = *this;
	                m_ptr = m_ptr->next;
                    return cpy;
                }
                
                iterator operator--() {
                    m_ptr = m_ptr->prev;
                    return *this;
                }
                
                iterator operator--(int) {
                    auto cpy = *this;
	                m_ptr = m_ptr->prev;
                    return *this;
                }
                
                bool operator==( const iterator & rhs ) const {
                    return m_ptr == rhs.m_ptr;
                }
                
                bool operator!=( const iterator & rhs ) const {
                    return m_ptr != rhs.m_ptr;
                }

                //=== Other methods that you might want to implement.
                
                /// it += 3; // Go back  3 positions within the container. 
                iterator operator+=( difference_type step) {
                     /* TODO */ return iterator{}; 
                }
                
                /// it -= 3; // Go back  3 positions within the container. 
                iterator operator-=(  difference_type step ) {
                     /* TODO */ return iterator{}; 
                }
                
                /// it->method()
                //pointer operator->( void ) const{
                //
                //}

                /// it1 - it2
                difference_type operator-( const iterator & rhs ) const {
                    return 0;
                    //FAZER AINDA
                }

                // We need friendship so the list<T> class may access the m_ptr field.
                friend class list<T>;

                friend std::ostream & operator<< ( std::ostream & os_, const iterator & s_ )
                {
                    os_ << "[@"<< s_.m_ptr << ", val = " << s_.m_ptr->data << "]";
                    return os_;
                }
        };

        //=== Private Function
        private:
            void initialize(){
                m_len = 0;
                //m_head = nullptr;
                //m_tail = nullptr;
                m_head = new Node;
                m_tail = new Node;
                m_head->next = m_tail;
                m_tail->prev = m_head;
            }

        //=== Private members.
        private:
            size_t m_len;    // comprimento da lista.
            Node * m_head; // nó cabeça.
            Node * m_tail; // nó calda.

        public:
        //=== Public interface
        
        friend std::ostream& operator <<(std::ostream& ostr, const list& rhs){
            Node* current = rhs.m_head->next;
            while(current != nullptr){
                std::cout << current->data << " ";
                current = current->next;
            }
            return ostr;
        }
        

        //=== [I] Special members
        list()
        { 
            /*  Head & tail nodes.
             *     +---+    +---+
             *     |   |--->|   |--+
             *     | H |    | T |  |
             *  +--|   |<---|   |  |
             *  |  +---+    +---+  |
             *  |                  |
             * ===                ===
             *  =                  =
             */
            initialize();
        }

        explicit list( size_t count ) {
            initialize();
            int index;
            for(index = 0; index < count; index++)
                push_back(count);
        }

        template< typename InputIt >
        list( InputIt first, InputIt last ) {
            initialize();
            for(auto itr= first; itr != last; ++itr)
                push_back( *itr ); 
        }
        
        list( const list & clone_ ) {

        }
        
        list( std::initializer_list<T> ilist_ ) {
            initialize();
            for(auto i: ilist_){
                push_back(i);
            }
        }
        
        ~list() {
            clear();
            delete m_head;
            delete m_tail;
        }

        list & operator=( const list & rhs ) {
            if(!empty()){
                clear();
            }
            Node* aux = rhs.m_head->next;             
            while (aux->next != nullptr){
                push_back(aux->data);
                aux = aux->next;
            }
            return *this;
        }
        
        list & operator=( std::initializer_list<T> ilist_ ) {
            
        }
        
        //=== [II] ITERATORS
        iterator begin() {
            if(!empty()){
                iterator itr{m_head->next};
                return itr;
            }else{
                return iterator{m_tail};
            }
        }

        const_iterator cbegin() const  {
            if(!empty()){
                const_iterator const_itr{m_head->next};
                return const_itr;
            }else{
                return const_iterator{m_tail};
            }
        }
        
        iterator end() {
            iterator itr{ m_tail };
	        return itr;
        }
        
        const_iterator cend() const  {
            const_iterator const_itr{m_tail};
        	return const_itr;
        }
        
        //=== [III] Capacity/Status
        bool empty ( void ) const {
            return size() == 0;
        }

        size_t size(void) const {
            return m_len;
        }
        
        //=== [IV] Modifiers
        void clear()  {
            while(!empty()){
        		pop_back();
            } 
        }

        T front( void ) {
            return *begin();
        }
        
        T front( void ) const  {
            return *cbegin();
        }
        
        T back( void ) {
            return *(--end());  
        }
        
        T back( void ) const  {
            return *(--cend());  
        }

        void push_front( const T & value_ ) {
            insert(begin(), value_);
        }

        void push_back( const T & value_ ) {
            insert(end(), value_);
        }

        void pop_front( ) {
            erase(begin());
        }

        void pop_back( ) {
            erase(--end());
        }

        //=== [IV-a] MODIFIERS W/ ITERATORS
        template < class InItr >
        void assign( InItr first_, InItr last_ )
        { /* TODO */ }

        void assign( std::initializer_list<T> ilist_ )
        { /* TODO */ }

        /*!
         *  Inserts a new value in the list before the iterator 'it'
         *  and returns an iterator to the new node.
         *
         *  \param pos_ An iterator to the position before which we want to insert the new data.
         *  \param value_ The value we want to insert in the list.
         *  \return An iterator to the new element in the list.
         */
        iterator insert( iterator pos_, const T & value_ )
        {
            auto* p = pos_.m_ptr;
            m_len++;
            auto* nptr = new Node{value_, p, p->prev};
            (p->prev)->next = nptr;
            p->prev = nptr;
            iterator iter{nptr};
            return iter;
        }

        template < typename InItr >
        iterator insert( iterator pos_, InItr first_, InItr last_ ) 
        {}
        
        iterator insert( iterator cpos_, std::initializer_list<T> ilist_ )
        {}

        /*!
         *  Erases the node pointed by 'it_' and returns an iterator
         *  to the node just past the deleted node.
         *
         *  \param it_ The node we wish to delete.
         *  \return An iterator to the node following the deleted node.
         */
        iterator erase( iterator it_ )
        {
            auto* aux = it_.m_ptr;
            iterator v{aux->next};
            aux->prev->next = aux->next;
            aux->next->prev = aux->prev; 
            delete aux;
            m_len--;
            return v;
        }
        
        // Erase items from [start; end) and return a iterator just past the deleted node.
        iterator erase( iterator start, iterator end )
        {
            for(auto itr = start; itr != end;){
                itr = erase(itr);
            }
            return end;
        }

        const_iterator find( const T & value_ ) const
        {}

        iterator find( const T & value_ )
        {}

        //=== [V] UTILITY METHODS
        void merge( list & other ){ return; }
        
        void splice( const_iterator pos, list & other ){ return; }
        
        void reverse( void ){
            if(!empty()){
                auto aux=m_head;
                while(aux != nullptr)
                {
                    std::swap(aux->next, aux->prev);
                    aux=aux->prev;
                }
            }
            std::swap(m_head, m_tail);
        }
        
        void unique( void ){ return; }
        
        void sort( void ){ return; }
    };

    //=== [VI] OPETARORS
    template < typename T >
    inline bool operator==( const sc::list<T> & l1_, const sc::list<T> & l2_ )
    {
        bool check = true;
        if(l1_.size() == l2_.size())
        {
            auto itr2 = l2_.cbegin();
            for(auto itr1=l1_.cbegin(); itr1 !=l1_.cend(); ++itr1)
            {
                if(*itr1 != *itr2){
                    check = false; 
                    break;
                }
                itr2++;
            }
            return check;
        }
        else{
            return false;
        }
    }

    template < typename T >
    inline bool operator!=( const sc::list<T> & l1_, const sc::list<T> & l2_ )
    {
        return !(l1_ == l2_);
    }
}
#endif

