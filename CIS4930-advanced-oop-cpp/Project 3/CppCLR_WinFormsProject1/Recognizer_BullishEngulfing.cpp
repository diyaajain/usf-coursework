#include "pch.h"
#include "Recognizer_BullishEngulfing.h"

/// <summary>
/// Recognize_Doji constructor
/// </summary>
Recognizer_BullishEngulfing::Recognizer_BullishEngulfing() : Recognizer()
{
    //assign value for patern name
    this->Pattern_Name = "Bullish Engulfing";
    //assign value for pattern length
    this->Pattern_Length = 2;
}

/// <summary>
/// recognizing bullish engulfing pattern method
/// </summary>
/// <param name="scList">list of smart candlesticks</param>
/// <param name="index">index of the element</param>
/// <returns></returns>
bool Recognizer_BullishEngulfing::Recognize(List<SmartCandlestick^>^ scList, int index) {

    //create first smart candlestick
    SmartCandlestick^ sc1 = scList[index];

    //check condition if not out of bound
    if (index < scList->Count - 1)
    {
        //create second smart candlestick
        SmartCandlestick^ sc2 = scList[index + 1];
        //check condition 
        bool bullishEngulfing = (sc2->Close > sc2->Open) && (sc1->Close < sc1->Open) && (sc2->Close > sc1->Open) && (sc2->Open < sc1->Close);
        //add to dictionary
        sc1->candleStick_Patterns[this->Pattern_Name] = bullishEngulfing;
        //return value
        return bullishEngulfing;

    }
    //check if out of bound
    else
    {
        //add to dictionary
        sc1->candleStick_Patterns[this->Pattern_Name] = false;
        //return value
        return false;
    }
}




