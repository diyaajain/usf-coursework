#pragma once
#include "Recognizer.h"
ref class Recognizer_BearishEngulfing : public Recognizer
{
public:
	//Constructor
	Recognizer_BearishEngulfing();
	//override method Recognize
	bool Recognize(List<SmartCandlestick^>^ scList, int index) override;
};
