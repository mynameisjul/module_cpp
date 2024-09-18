#pragma once

#include <iterator>

template <typename Iterator>
class GroupIterator {
	private:
		Iterator	_it;
		size_t		_size;
	public:
		// PUBLLIC TYPES
		typedef std::random_access_iterator_tag	iterator_category;
		typedef Iterator						iterator_type;
		typedef typename std::iterator_traits<Iterator>::value_type			value_type;
		typedef typename std::iterator_traits<Iterator>::difference_type	difference_type;
		typedef typename std::iterator_traits<Iterator>::pointer			pointer;
		typedef typename std::iterator_traits<Iterator>::reference			reference;
		typedef typename std::iterator_traits<Iterator>::const_reference const_reference;

		// CANONICAL FORM
		GroupIterator() {}
		GroupIterator(Iterator it, size_t size) : _it(it), _size(size) {}
		GroupIterator(const GroupeIterator &other) {
			*this = other
		}
		GroupIterator &operator=(const GroupIterator &other) {
			if (this != &other) {
				_it = other._it;
				_size = other._size;
			}
			return *this;
		}
		~GroupIterator() {}

		// ACCESSER
		Iterator getIt() const {
			return _it;
		}

		size_t getSize() const {
			return _size;
		}

		reference getRef() const {
			return _it[_size - 1];
		}

		pointer getPtr() const {
			return &(_it[_size - 1]);
		}

		// INCREMENT AND DECREMENT
		GroupIterator &operator++() {
			_it += _size;
			return *this;
		}

		GroupIterator &operator++(int) {
			GroupIterator tmp = *this;
			++(*this);
			return tmp;
		}

		GroupIterator &operator--() {
			_it -= _size;
			return *this;
		}

		GroupIterator &operator--(int) {
			GroupIterator tmp = *this;
			--(*this);
			return tmp;
		}

		GroupIterator &operator+=(size_t increment) {
			_it += _size * increment;
			return *this;
		}

		GroupIterator &operator-=(size_t decrement) {
			_it -= _size * decrement;
			return *this;
		}

		reference operator[](size_t pos) {
			return _it[pos * _size + size - 1];
		}

		const_reference operator[](size_t pos) {
			return _it[pos * _size + _size - 1];
		}
};

