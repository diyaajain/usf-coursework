#pragma once
#include "Recognizer.h"
ref class Recognizer_Valley : public Recognizer
{
public:
	//Constructor
	Recognizer_Valley();
	//override method Recognize
	bool Recognize(List<SmartCandlestick^>^ scList, int index) override;
};

