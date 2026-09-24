#pragma once
#include "Recognizer.h"
ref class Recognizer_Peak : public Recognizer
{
public:
	//Constructor
	Recognizer_Peak();
	//override method Recognize
	bool Recognize(List<SmartCandlestick^>^ scList, int index) override;
};

