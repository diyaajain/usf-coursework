#pragma once
#include "Recognizer.h"
ref class Recognizer_Gravestone_Doji : public Recognizer
{
public:
	//Constructor
	Recognizer_Gravestone_Doji();
	//override method Recognize
	bool Recognize(List<SmartCandlestick^>^ scList, int index) override;

};

