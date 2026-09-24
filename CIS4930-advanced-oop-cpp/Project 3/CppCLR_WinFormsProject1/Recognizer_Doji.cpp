#include "pch.h"
#include "Recognizer_Doji.h"

/// <summary>
/// Recognize_Doji constructor
/// </summary>
Recognizer_Doji::Recognizer_Doji() : Recognizer()
{
    //assign value for patern name
    this->Pattern_Name = "Doji";
    //assign value for pattern length
    this->Pattern_Length = 1;
}

/// <summary>
/// recognizing doji pattern method
/// </summary>
/// <param name="scList">list of smart candlesticks</param>
/// <param name="index">index of the element</param>
/// <returns></returns>
bool Recognizer_Doji::Recognize(List<SmartCandlestick^>^ scList, int index) {
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
        //check condition for doji smart candlesticks
        bool doji = sc->bodyRange <= (sc->range * 0.03);
        //add to the dictionary
        scList[index]->candleStick_Patterns->Add(this->Pattern_Name, doji);
        //return value
        return doji;
    }
}



