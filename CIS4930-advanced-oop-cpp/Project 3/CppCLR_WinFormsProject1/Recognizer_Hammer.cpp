#include "pch.h"
#include "Recognizer_Hammer.h"

/// <summary>
/// Recognize_Hammer constructor
/// </summary>
Recognizer_Hammer::Recognizer_Hammer() : Recognizer()
{
    //assign value for patern name
    this->Pattern_Name = "Hammer";
    //assign value for pattern length
    this->Pattern_Length = 1;
}

/// <summary>
/// recognizing gravestone doji pattern method
/// </summary>
/// <param name="scList">list of smart candlesticks</param>
/// <param name="index">index of the element</param>
/// <returns></returns>
bool Recognizer_Hammer::Recognize(List<SmartCandlestick^>^ scList, int index) {
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
        //check condition for hammer smart candlesticks
        bool hammer = (sc->bodyRange < sc->range * 0.25) && (sc->lowerTail > (0.7 * sc->range));
        //add to the dictionary
        scList[index]->candleStick_Patterns->Add(Pattern_Name, hammer);
        //return value
        return hammer;
    }
}




