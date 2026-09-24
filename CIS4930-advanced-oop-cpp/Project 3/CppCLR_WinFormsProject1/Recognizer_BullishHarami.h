#pragma once
#include "Recognizer.h"
ref class Recognizer_BullishHarami : public Recognizer
{
public:
	//Constructor
	Recognizer_BullishHarami();
	//override method Recognize
	bool Recognize(List<SmartCandlestick^>^ scList, int index) override;
};

