#include "pch.h"
#include "Recognizer_BearishEngulfing.h"

/// <summary>
/// Recognize_Doji constructor
/// </summary>
Recognizer_BearishEngulfing::Recognizer_BearishEngulfing() : Recognizer()
{
    //assign value for patern name
    this->Pattern_Name = "Bearish Engulfing";
    //assign value for pattern length
    this->Pattern_Length = 2;
}

/// <summary>
/// recognizing bearish engulfing pattern method
/// </summary>
/// <param name="scList">list of smart candlesticks</param>
/// <param name="index">index of the element</param>
/// <returns></returns>
bool Recognizer_BearishEngulfing::Recognize(List<SmartCandlestick^>^ scList, int index) {

    //create first smart candlestick
    SmartCandlestick^ sc1 = scList[index];

    //check condition if not out of bound
    if (index < scList->Count - 1)
    {
        //create second smart candlestick
        SmartCandlestick^ sc2 = scList[index + 1];
        //check condition 
        bool bearishEngulfing = (sc2->Close < sc2->Open) && (sc1->Close > sc1->Open) && (sc2->Close < sc1->Open) && (sc2->Open > sc1->Close);
        //add to dictionary
        sc1->candleStick_Patterns[this->Pattern_Name] = bearishEngulfing;
        //return value
        return bearishEngulfing;

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





