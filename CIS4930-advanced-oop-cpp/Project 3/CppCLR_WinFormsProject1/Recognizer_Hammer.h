#pragma once
#include "Recognizer.h"
ref class Recognizer_Hammer : public Recognizer
{
public:
	//Constructor
	Recognizer_Hammer();
	//override method Recognize
	bool Recognize(List<SmartCandlestick^>^ scList, int index) override;
};

