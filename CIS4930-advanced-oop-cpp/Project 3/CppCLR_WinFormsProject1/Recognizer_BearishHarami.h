#pragma once
#include "Recognizer.h"
ref class Recognizer_BearishHarami : public Recognizer
{
public:
	//Constructor
	Recognizer_BearishHarami();
	//override method Recognize
	bool Recognize(List<SmartCandlestick^>^ scList, int index) override;
};

