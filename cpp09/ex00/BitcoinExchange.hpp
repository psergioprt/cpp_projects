#include <string>

class BitcoinExchange
{
	private:
		std::map<std::string date, double value> _exchangeRates;
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
