#pragma once
#include "SmartCandleStick.h"
#include "Recognizer.h"
using namespace System;
using namespace System::Globalization;
using namespace System::Collections::Generic;
ref class Recognizer_Bearish : public Recognizer
{
public:
	//Constructor
	Recognizer_Bearish();
	//override method Recognize
	bool Recognize(List<SmartCandlestick^>^ scList, int index) override;
};

