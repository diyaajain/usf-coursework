#include "pch.h"
#include "candllestick.h"
Candlestick::Candlestick(String^ csvLine) {
	array<wchar_t>^ separators = {L',',L'"'};
	array<String^>^ values = csvLine->Split(separators, StringSplitOptions::RemoveEmptyEntries);
	if (values->Length >=  7) {
		Date = DateTime::ParseExact(values[0], "yyyy-MM-dd", CultureInfo::InvariantCulture);
		Open = Double::Parse(values[1], CultureInfo::InvariantCulture);
		High = Double::Parse(values[2], CultureInfo::InvariantCulture);
		Low = Double::Parse(values[3], CultureInfo::InvariantCulture);
		Close = Double::Parse(values[4], CultureInfo::InvariantCulture);
		Volume = Int64::Parse(values[6]);
	}
}