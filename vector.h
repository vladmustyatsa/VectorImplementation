#ifndef VECTOR_H
#define VECTOR_H
#include<iostream>

template<typename T>
class Vector {
    public:
      public:
      class ConstIterator;
      class Iterator;
      using value_type = T;
      using size_type = std::size_t;
      using difference_type = std::ptrdiff_t;
      using reference = value_type&;
      using const_reference = const value_type&;
      using pointer = value_type*;
      using const_pointer = const value_type*;
      using iterator = Vector::Iterator;
      using const_iterator = Vector::ConstIterator;
    private:
      size_type sz;
      size_type max_sz;
  		
  		pointer values;

		public:
				Vector() {
					sz = 0;
					max_sz = 0;
					values = nullptr;
				}
				Vector(const Vector& v) {
          
					sz = v.sz;
					max_sz = v.max_sz;
          
					values = max_sz ? new value_type[max_sz] : nullptr;
					for (size_type i = 0; i < sz; i++)
						values[i] = v.values[i];
				}

        Vector& operator=(const Vector& v) {
          
          sz = v.sz;
          max_sz = v.max_sz;
          if (values)
            delete[] values;
          values = max_sz ? new value_type[max_sz] : nullptr;
          for (size_type i = 0; i < sz; i++)
            values[i] = v.values[i];
          return *this;
        }

				Vector(size_type n) {
					max_sz = n;
					sz = 0;
					values = max_sz ? new value_type[max_sz] : nullptr;
				}
				Vector(std::initializer_list<value_type> l) {
					sz = l.size();
					max_sz = l.size();
					values = max_sz ? new value_type[max_sz] : nullptr;
					for (size_type i = 0; i < sz; i++) 
						values[i] = *(l.begin()+i);
					
				}

        size_type size() const {
					return sz;
				}

				bool empty() const {
					return (sz == 0);
				}

				void clear() {
					sz = 0;
				}

        void reserve(size_type n) {
          if (max_sz < n) {
            if(sz != 0) {
              pointer tmp = new value_type[n];
              for (size_type i = 0; i < sz; i++)
                tmp[i] = values[i];
              delete[] values;
              values = tmp;
            } else {
              if(values)
                delete[] values;
              values = new value_type[n];
            }
            max_sz = n;
          }
        }

        void shrink_to_fit() {
          if (sz < max_sz) {
            pointer tmp = sz ? new value_type[sz] : nullptr;
            for (size_type i = 0; i < sz; i++)
              tmp[i] = values[i];
            if(values)
              delete[] values;
            values = tmp;
            max_sz = sz;
          }
        }

        void push_back(value_type x) {
          reserve(sz+1);
          values[sz] = x;
          ++sz;
        }

        void pop_back() {
          if(sz == 0) 
            throw std::runtime_error("Vector is empty!");
          --sz;
        }

        reference operator[](size_type index) {
          if (index < 0 || index >= sz)
            throw std::runtime_error("Index out of range");
          return values[index];
        }

        const_reference operator[](size_type index) const {
          if (index < 0 || index >= sz)
            throw std::runtime_error("Index out of range");
          return values[index];
        }

        size_type capacity() const {
					return max_sz;
				}

        iterator begin() {
          return iterator(values);
        }

        iterator end() {
          if(values)
            return iterator(values+sz);
          return iterator();
        }

        const_iterator begin() const {
          return const_iterator(values);
        }

        const_iterator end() const {
          if(values)
            return const_iterator(values+sz);
          return const_iterator();
        }

        
        iterator insert(const_iterator pos, const_reference val) {
          auto diff = pos - begin();
          if (diff < 0 || static_cast<size_type>(diff) > sz)
            throw std::runtime_error("Iterator out of bounds");
          size_type current{static_cast<size_type>(diff)};
          if (sz >= max_sz) {
            if(max_sz == 0) {
              values = new value_type[1];
              max_sz = 1;
              
            } else {
            reserve(max_sz * 2); // Achtung Sonderfall, wenn keine Mindestgroesze definiert ist
            }
          }
          for (auto i{sz}; i-- > current;)
            values[i + 1] = values[i];
          values[current] = val;
          ++sz;
          return iterator{values + current};
        }

        iterator erase(const_iterator pos) {
          auto diff = pos - begin();
          if (diff < 0 || static_cast<size_type>(diff) >= sz)
            throw std::runtime_error("Iterator out of bounds");
          size_type current{static_cast<size_type>(diff)};
          for (auto i{current}; i < sz - 1; ++i)
            values[i] = values[i + 1];
          --sz;
          return iterator{values + current};
        }
								
				~Vector() {
					if (values){
						delete[] values;  
						//cout << "del" << endl;
					}
				}
    class Iterator {
      
      public:
        using value_type = Vector::value_type;
        using reference = Vector::reference;
        using pointer = Vector::pointer;
        using difference_type = Vector::difference_type;
        using iterator_category = std::forward_iterator_tag;
      private:
        pointer ptr;
      public:
        Iterator() : ptr{nullptr} {};
        Iterator(pointer ptr) : ptr{ptr} {};
        
    
        reference operator*() const {
          if(ptr == nullptr)
            throw std::runtime_error("ptr is nullptr");
          return *ptr;
        }
        pointer operator->() const {
          if(ptr == nullptr)
            throw std::runtime_error("ptr is nullptr");
          return ptr;
        }

        bool operator==(const const_iterator& it) const {
          return (it == *this);
        }

        bool operator!=(const const_iterator& it) const {
          
          return (it != *this);
        }

        iterator& operator++() {
          if(ptr)
            ++ptr;
          return *this;
        }

        iterator operator++(int) {
          if(ptr)
            return Iterator(ptr++);
          return *this;
        }

        operator const_iterator() const {
          return Vector::const_iterator(ptr);
        }

    };
    
    class ConstIterator {
        friend  Vector::difference_type operator-(const Vector::ConstIterator& lop , const Vector::ConstIterator& rop) {
          return lop.ptr - rop.ptr; 
        }
      public:
        using value_type = Vector::value_type;
        using reference = Vector::const_reference;
        using pointer = Vector::const_pointer;
        using difference_type = Vector::difference_type;
        using iterator_category = std::forward_iterator_tag;
      private:
        pointer ptr;
      public:
        ConstIterator() : ptr{nullptr} {};
        ConstIterator(pointer ptr) : ptr{ptr} {};
        reference operator*() const {
          if(ptr == nullptr)
            throw std::runtime_error("ptr is nullptr");
          return *ptr;
        }
        pointer operator->() const {
          if(ptr == nullptr)
            throw std::runtime_error("ptr is nullptr");
          return ptr;
        }

        bool operator==(const const_iterator& it) const {
          return (ptr == it.ptr);
        }
        
        bool operator!=(const const_iterator& it) const {
          return (ptr != it.ptr);
        }

        const_iterator& operator++() {
          if(ptr)
            ++ptr;
          return *this;
        }

        const_iterator operator++(int) {
          if(ptr)
            return ConstIterator(ptr++);
          return *this;
        }
    };
};


template<typename T>
std::ostream& operator<<(std::ostream& o, const Vector<T>& v) {
  o << "[";
  bool first = true;
  for(typename Vector<T>::size_type i=0; i<v.size(); ++i)
    if (first) {
      first = false;
      o << v[0];
    } else {
      o << ", " << v[i];
    }
  o << "]";
  return o;
}
#endif