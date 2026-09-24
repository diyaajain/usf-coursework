#include "pch.h"
#include "Recognizer_Gravestone_Doji.h"


/// <summary>
/// Recognize_Gravestone_Doji constructor
/// </summary>
Recognizer_Gravestone_Doji::Recognizer_Gravestone_Doji() : Recognizer()
{
    //assign value for patern name
    this->Pattern_Name = "Gravestone Doji";
    //assign value for pattern length
    this->Pattern_Length = 1;
}

/// <summary>
/// recognizing gravestone doji pattern method
/// </summary>
/// <param name="scList">list of smart candlesticks</param>
/// <param name="index">index of the element</param>
/// <returns></returns>
bool Recognizer_Gravestone_Doji::Recognize(List<SmartCandlestick^>^ scList, int index) {
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
        //check condition for dragonfly doji smart candlesticks
        bool gravestoneDoji = (sc->bodyRange <= (sc->range * 0.03)) && (sc->upperTail >= (0.7 * sc->range));
        //add to the dictionary
        scList[index]->candleStick_Patterns->Add(Pattern_Name, gravestoneDoji);
        //return value
        return gravestoneDoji;
    }
}




