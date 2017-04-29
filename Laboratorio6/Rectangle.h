#pragma once
# include <istream>
# include <ostream>

using namespace std;

template <typename T >
class Rectangle {
public:
	Rectangle() { initData(0, 0); };
	Rectangle(const T &w, const T & l) { initData(w, l); };
	Rectangle(const T & w_l) { initData(w_l, w_l); };
	Rectangle(const Rectangle & to_copy) {
		initData(to_copy.m_width, to_copy.m_length);
	};

	~Rectangle() {};

	void setW(const T &w);
	void setL(const T &l);

	T getW() const;
	T getL() const;

	T getArea() const;
	T getPerimeter() const;

	T getAll(T & perimenter) const;

	/* Overload + operator to add two Rectangles */
	Rectangle operator +(const Rectangle & to_be_added);

	/* Overload = operator to assign a Rectangle to another one */
	void operator =(const Rectangle & to_be_assigned);

	/* Overload prefix ++ operator */
	const Rectangle & operator ++();
	/* Overload postfix ++ operator */
	const Rectangle operator ++(int);

	/* Overload == and != operators to compare rectangles */
	bool operator ==(const Rectangle & to_be_compared);
	bool operator !=(const Rectangle & to_be_compared);

	/* Overload the << and >> operators*/
	friend istream & operator >> (istream & is, Rectangle & rect) {
		is >> rect.m_width >> rect.m_length;
		return is;
	};
	friend ostream & operator << (ostream & os, const Rectangle & rect) {
		os << rect.m_width << "x" << rect.m_length;
		return os;
	};

private:
	T m_width, m_length;

	void initData(const T &w, const T &l);
};

template <typename T >
void Rectangle <T >::setW(const T &w) {
	m_width = w;
}

template <typename T >
void Rectangle <T >::setL(const T &l) {
	m_length = l;
}

template <typename T >
T Rectangle <T >::getW() const {
	return m_width;
}

template <typename T >
T Rectangle <T >::getL() const {
	return m_length;
}

template <typename T >
T Rectangle <T >::getArea() const {
	return m_width * m_length;
}

template <typename T >
T Rectangle <T >::getPerimeter() const {
	return (m_width + m_length) * 2;
}

template <typename T >
T Rectangle <T >::getAll(T & perimenter) const {
	perimenter = getPerimeter();
	return getArea();
}

template <typename T >
void Rectangle <T >::initData(const T &w, const T &l) {
	m_width = w;
	m_length = l;
}

template <typename T >
Rectangle <T > Rectangle <T >:: operator +(const Rectangle & to_be_added) {
	Rectangle <T > output;

	output.m_width = this->m_width + to_be_added.m_width;
	output.m_length = this - > m_length + to_be_added.m_length;

	return output;
}

template <typename T >
void Rectangle <T >:: operator =(const Rectangle & to_be_assigned) {
	initData(to_be_assigned.m_width, to_be_assigned.m_length);
}

template <typename T >
const Rectangle <T >& Rectangle <T >:: operator ++() { // prefix version
	++m_width;
	++m_length;
	return *this;
}

template <typename T >
const Rectangle <T > Rectangle <T >:: operator ++(int) { // postfix version
														 // save the original value
	Rectangle <T > R(*this);
	// increment this object using the prefix version to do the work
	++(*this);
	// return the old value !
	return R;
}

template <typename T >
bool Rectangle <T >:: operator ==(const Rectangle & to_be_compared) {
	return ((m_width == to_be_compared.m_width) && (m_length == to_be_compared.m_length)
		);
}

template <typename T >
bool Rectangle <T >:: operator !=(const Rectangle & to_be_compared) {
	return !(*this == to_be_compared);
}
