#include "pch.h"
#include "Recognizer_Bearish.h"


/// <summary>
/// Recognize_Bearish constructor
/// </summary>
Recognizer_Bearish::Recognizer_Bearish() : Recognizer()
{
    //assign value for patern name
    this->Pattern_Name = "Bearish";
    //assign value for pattern length
    this->Pattern_Length = 1;
}

/// <summary>
/// recognizing bearish pattern method
/// </summary>
/// <param name="scList">list of smart candlesticks</param>
/// <param name="index">index of the element</param>
/// <returns></returns>
bool Recognizer_Bearish::Recognize(List<SmartCandlestick^>^ scList, int index) {
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
        //check condition for bearish smart candlesticks
        bool bearish = sc->Open > sc->Close;
        //add to the dictionary
        scList[index]->candleStick_Patterns->Add(Pattern_Name, bearish);
        //return value
        return bearish;
    }
}




