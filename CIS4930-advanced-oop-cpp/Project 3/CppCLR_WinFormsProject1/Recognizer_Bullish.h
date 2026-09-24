#pragma once
#include "SmartCandleStick.h"
#include "Recognizer.h"
using namespace System;
using namespace System::Globalization;
using namespace System::Collections::Generic;
ref class Recognizer_Bullish : public Recognizer
{
public:
	//Constructor
	Recognizer_Bullish();
	//override method Recognize
	bool Recognize(List<SmartCandlestick^>^ scList, int index) override;

};

