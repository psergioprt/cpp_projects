class BitcoinExchange
{
	private:
		int _value;

	public:
		BitcoinExchange();
		BitcoinExchange(const int value);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		int output() const;
		int multiply_by_rate() const;
		void open_file() const;
};
