#include "pch.h"
#include "Recognizer_Valley.h"

/// <summary>
/// Recognize_Valley constructor
/// </summary>
Recognizer_Valley::Recognizer_Valley() : Recognizer()
{
    //assign value for patern name
    this->Pattern_Name = "Valley";
    //assign value for pattern length
    this->Pattern_Length = 3;
}

/// <summary>
/// recognizing valley pattern method
/// </summary>
/// <param name="scList">list of smart candlesticks</param>
/// <param name="index">index of the element</param>
/// <returns></returns>
bool Recognizer_Valley::Recognize(List<SmartCandlestick^>^ scList, int index) {
    //check condition if out of bound
    if (index < scList->Count - 2)
    {
        //first smart candlestick
        SmartCandlestick^ sc1 = scList[index];
        //second smart candlestick
        SmartCandlestick^ sc2 = scList[index + 1];
        //third smart candlestick
        SmartCandlestick^ sc3 = scList[index + 2];
        //check condition
        bool valley = (sc2->Low < sc1->Low) && (sc2->Low > sc3->Low);
        //add the pattern to dictionary
        sc1->candleStick_Patterns[this->Pattern_Name] = valley;
        //return value
        return valley;
    }
    //check if it is out of bound
    else
    {
        //create the temp smart candlestick
        SmartCandlestick^ temp = scList[index];
        //add to the dictionary
        temp->candleStick_Patterns[this->Pattern_Name] = false;
        //return value
        return false;
    }
}







