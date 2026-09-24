#pragma once
#include "Recognizer.h"
ref class Recognizer_BullishEngulfing : public Recognizer
{
public:
	//Constructor
	Recognizer_BullishEngulfing();
	//override method Recognize
	bool Recognize(List<SmartCandlestick^>^ scList, int index) override;
};

