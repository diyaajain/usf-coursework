#pragma once
#include "Recognizer.h"
ref class Recognizer_Marubozu : public Recognizer
{
public:
	//Constructor
	Recognizer_Marubozu();
	//override method Recognize
	bool Recognize(List<SmartCandlestick^>^ scList, int index) override;
};

