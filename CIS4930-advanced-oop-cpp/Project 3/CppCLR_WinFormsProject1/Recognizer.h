#pragma once
#include "SmartCandleStick.h"
using namespace System;
using namespace System::Globalization;
using namespace System::Collections::Generic;
 ref class Recognizer abstract
{
	public:
		//define property pattern name
		property String^ Pattern_Name;

		//define property pattern length
		property int Pattern_Length;

		//define recognize method 
		virtual bool Recognize(List<SmartCandlestick^>^ scList, int index) = 0;

		//define recognizeAll method
		void Recognize_All(List<SmartCandlestick^>^ scList);

	protected:
		//constructor
		Recognizer();


};

