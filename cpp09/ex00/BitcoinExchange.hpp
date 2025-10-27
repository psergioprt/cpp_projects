#include <string>

class BitcoinExchange
{
	private:
		double _value;

	public:
		BitcoinExchange();
		BitcoinExchange(const double value);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		double output() const;
		double multiply_by_rate() const;
		void openExchangeRateFile(std::string exchangeRateFile) const;
		void openFileToEvaluate(std::string fileToEvaluate) const;
};
