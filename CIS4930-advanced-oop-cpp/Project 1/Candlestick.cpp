#include "Candlestick.h"

namespace CppCLRWinFormsProject
{
	//constructor that constructs a candlestick from a string
	Candlestick::Candlestick(String^ csvLine)
	{
		array<wchar_t>^ separators = { L',', L'"' }; // define array of characters to be used as seperators

		// split the csv line into indiviual values using the defined separators and remove empty entries
		array<String^>^ values = csvLine->Split(separators, StringSplitOptions::RemoveEmptyEntries); 

		if (values->Length >= 7) // checking to see if there are enough values to create a candlestick object
		{
			// parsing each value and assigning it to the corresponding candlestick property
			Date = DateTime::ParseExact(values[0], "yyyy-MM-dd", CultureInfo::InvariantCulture);
			Open = Double::Parse(values[1], CultureInfo::InvariantCulture);
			High = Double::Parse(values[2], CultureInfo::InvariantCulture);
			Low = Double::Parse(values[3], CultureInfo::InvariantCulture);
			Close = Double::Parse(values[4], CultureInfo::InvariantCulture);
			AdjClose = Double::Parse(values[5], CultureInfo::InvariantCulture);
			Volume = UInt64::Parse(values[6]); //parsing volume as an unsigned long
		}
		else
		{
			// handle the case where there are less than 7 vaues in the csv line
			Console::WriteLine("Values in the file are more than 7");
		}
	}
}
