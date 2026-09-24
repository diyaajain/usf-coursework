#include "pch.h"
#include "Recognizer_Marubozu.h"

/// <summary>
/// Recognize_Marubozu constructor
/// </summary>
Recognizer_Marubozu::Recognizer_Marubozu() : Recognizer()
{
    //assign value for patern name
    this->Pattern_Name = "Marubozu";
    //assign value for pattern length
    this->Pattern_Length = 1;
}

/// <summary>
/// recognizing marubozu pattern method
/// </summary>
/// <param name="scList">list of smart candlesticks</param>
/// <param name="index">index of the element</param>
/// <returns></returns>
bool Recognizer_Marubozu::Recognize(List<SmartCandlestick^>^ scList, int index) {
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
        //check condition for marubozu smart candlesticks
        bool marubozu = (sc->upperTail <= sc->bodyRange * 0.2) && (sc->lowerTail <= sc->bodyRange * 0.2);
        //add to the dictionary
        scList[index]->candleStick_Patterns->Add(Pattern_Name, marubozu);
        //return value
        return marubozu;
    }
}





