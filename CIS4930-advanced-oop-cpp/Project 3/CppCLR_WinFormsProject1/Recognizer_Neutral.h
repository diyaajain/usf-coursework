#pragma once
#include "Recognizer.h"
ref class Recognizer_Neutral : public Recognizer
{
public:
	//Constructor
	Recognizer_Neutral();
	//override method Recognize
	bool Recognize(List<SmartCandlestick^>^ scList, int index) override;
};

