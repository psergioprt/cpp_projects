template<typename T>
void swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}
template<typename T>
int bigger(T &a, T &b)
{
	if (a > b)
		return a;
	return b;
}

template<typename T>
int lower(T &a, T &b)
{
	if (a < b)
		return a;
	return b;
}

template<typename T>


template <typename T>
class BitcoinET
{
	private:
		T _number;

	public:
		BitcoinET() : _number(0){}
		BitcoinET(const T number) : _number(number){}
		BitcoinET(const BitcoinET& other) : _number(other._number){}
		BitcoinET& operator=(const BitcoinET& other)
		{
			if (this != &other)
				this->_number = other._number;
			return *this;
		}
		~BitcoinET(){}

		T print()
		{
			return this->_number;
		}
};

template <typename T>
class Array
{
	private:
		unsigned int _size;
		T* _data;
	public:
		Array() : _size(0), _data(NULL);
		Array(unsigned int size) : _size(size), _data(new T[n]());
		


}
