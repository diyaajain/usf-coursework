#include "pch.h"
#include "Recognizer_Bullish.h"

/// <summary>
/// Recognize_Bullish constructor
/// </summary>
Recognizer_Bullish::Recognizer_Bullish() : Recognizer()
{
    //assign value for patern name
	this->Pattern_Name = "Bullish";
    //assign value for pattern length
	this->Pattern_Length = 1;
}

/// <summary>
/// recognizing bullish pattern method
/// </summary>
/// <param name="scList">list of smart candlesticks</param>
/// <param name="index">index of the element</param>
/// <returns></returns>
bool Recognizer_Bullish::Recognize(List<SmartCandlestick^>^ scList, int index) {
    //create the smart candlestick at that index
    SmartCandlestick^ sc = scList[index];
    //check if key exist
    if (sc->candleStick_Patterns->ContainsKey(this->Pattern_Name))
    {
        //return existed value of the key
        return sc->candleStick_Patterns[this->Pattern_Name];
    }
    //if not exist in the dictionary
    else
    {
        //check condition for bullish smart candlesticks
        bool bullish = sc->Open < sc->Close;
        //add to the dictionary
        scList[index]->candleStick_Patterns->Add(Pattern_Name, bullish);
        //return value
        return bullish;
    }
}



