#pragma once
#include "Candlestick.h"

using namespace System;
using namespace System::IO;
using namespace System::Globalization;
using namespace System::Collections::Generic;

public ref class SmartCandlestick : Candlestick {
public:
	property double Range;
	property double bodyRange;
	property double topPrice;
	property double bottomPrice;
	property double upperTail;
	property double lowerTail;
	property Dictionary<String^, bool>^ patterns;


	/// <summary>
	/// Constructor for SmartCandlestick class that initializes a smart candlestick object using data from a Candlestick object.
	/// </summary>
	/// <param name="cs">The Candlestick object containing candlestick data to initialize the smart candlestick with.</param>
	SmartCandlestick(Candlestick^ cs) : Candlestick()
	{
		// Copy data from the provided Candlestick object to initialize the smart candlestick
		Date = cs->Date;
		Open = cs->Open;
		High = cs->High;
		Low = cs->Low;
		Close = cs->Close;
		Volume = cs->Volume;

		// Initialize the patterns dictionary
		patterns = gcnew Dictionary<String^, bool>;

		// Compute extra properties of the smart candlestick
		ComputeExtraProperties();

		// Compute candlestick patterns and update the pattern dictionary
		ComputePatternProperties();
	}


	/// <summary>
	/// Constructor for SmartCandlestick class that initializes a smart candlestick object using data from a CSV line.
	/// </summary>
	/// <param name="csvLine">The CSV line containing candlestick data.</param>
	SmartCandlestick(String^ csvLine) : Candlestick(csvLine)
	{
		// Initialize the patterns dictionary
		patterns = gcnew Dictionary<String^, bool>;

		// Compute extra properties of the smart candlestick
		ComputeExtraProperties();

		// Compute candlestick patterns and update the pattern dictionary
		ComputePatternProperties();
	}

	/// <summary>
	/// Computes additional properties of a SmartCandlestick object and updates its member variables.
	/// </summary>
	/// <returns>Void</returns>
	Void ComputeExtraProperties();

	/// <summary>
	/// Computes various candlestick patterns based on the properties of a SmartCandlestick object and updates its pattern dictionary.
	/// </summary>
	/// <returns>Void</returns>
	Void ComputePatternProperties();
 };

