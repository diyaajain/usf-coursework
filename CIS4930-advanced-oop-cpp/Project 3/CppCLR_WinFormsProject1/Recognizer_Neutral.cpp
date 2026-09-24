#include "pch.h"
#include "Recognizer_Neutral.h"

/// <summary>
/// Recognize_Neutral constructor
/// </summary>
Recognizer_Neutral::Recognizer_Neutral() : Recognizer()
{
    //assign value for patern name
    this->Pattern_Name = "Neutral";
    //assign value for pattern length
    this->Pattern_Length = 1;
}

/// <summary>
/// recognizing neutral pattern method
/// </summary>
/// <param name="scList">list of smart candlesticks</param>
/// <param name="index">index of the element</param>
/// <returns></returns>
bool Recognizer_Neutral::Recognize(List<SmartCandlestick^>^ scList, int index) {
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
        //check condition for neutral smart candlesticks
        bool neutral = sc->bodyRange <= (sc->range * 0.2);;
        //add to the dictionary
        scList[index]->candleStick_Patterns->Add(Pattern_Name, neutral);
        //return value
        return neutral;
    }
}






