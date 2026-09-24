#pragma once
#include "Recognizer.h"
ref class Recognizer_DragonFly_Doji : public Recognizer
{
public:
	//Constructor
	Recognizer_DragonFly_Doji();
	//override method Recognize
	bool Recognize(List<SmartCandlestick^>^ scList, int index) override;
};

