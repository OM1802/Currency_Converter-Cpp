#include <iostream>
using namespace std;

class CurrencyConverter {
  private:
    double rates[8]; // Array of exchange rates as of December 17, 2022
  public:
    CurrencyConverter() { // Constructor to initialize exchange rates
      rates[0] = 1.0;
      rates[1] = 0.86;
      rates[2] = 0.72;
      rates[3] = 0.62;
      rates[4] = 0.82;
      rates[5] = 0.0091;
      rates[6] = 0.019;
      rates[7] = 0.012;
    }
    double convert(double amount, int fromCurrency, int toCurrency) { // Function to convert currency
      double convertedAmount = amount / rates[fromCurrency-1]; // Convert amount to USD
      convertedAmount *= rates[toCurrency-1]; // Convert amount from USD to selected currency
      return convertedAmount;
    }
};

int main() {
  CurrencyConverter converter;
  double amount, convertedAmount;
  int fromCurrency, toCurrency;

  cout << "Enter the amount to be converted: ";
  cin >> amount;

  cout << "Select the currency to convert from: " << endl;
  cout << "1. USD\n2. EUR\n3. GBP\n4. AUD\n5. CAD\n6. JPY\n7. SGD\n8. CNY" << endl;
  cin >> fromCurrency;

  cout << "Select the currency to convert to: " << endl;
  cout << "1. USD\n2. EUR\n3. GBP\n4. AUD\n5. CAD\n6. JPY\n7. SGD\n8. CNY" << endl;
  cin >> toCurrency;

  // Convert the amount to the selected currency
  convertedAmount = converter.convert(amount, fromCurrency, toCurrency);

  // Display the result
  cout << "Converted amount: " << convertedAmount << endl;
  return 0;
}
