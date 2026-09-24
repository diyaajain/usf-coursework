#pragma once
//pragma once helps to avoid override
using namespace System;
using namespace System::Globalization;
public ref class Candlestick
{
public:
	// define Datetime Date
	property DateTime Date;
	// define open property
	property double Open;
	//define high property
	property double High;
	//define low property
	property double Low;
	//define close property
	property double Close;
	//degine volume propber
	property unsigned long long Volume;

	//Constructor that takes a CSV line as input
	Candlestick(String^ csvLine);

};

