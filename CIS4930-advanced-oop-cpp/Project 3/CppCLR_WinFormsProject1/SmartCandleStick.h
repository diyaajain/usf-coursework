#pragma once
//pragma once helps to avoid override
#include "candlestick.h"
using namespace System;
using namespace System::Globalization;
using namespace System::Collections::Generic;
public ref class SmartCandlestick : public Candlestick
{

public:
    
    //define range property
    property double range;
    //define bodyRange property
    property double bodyRange;
    //define topPrice property
    property double topPrice;
    //define bottomPrice property
    property double bottomPrice;
    //define upperTail property
    property double upperTail;
    //define lowerTail property
    property double lowerTail;
 
    //Dictionary to store a pattern as a key and T/F as value
    property Dictionary<String^, bool>^ candleStick_Patterns;

    //Constructor
    SmartCandlestick(String^ rowOfData);

    /// The method to identify the pattern and add to the dictionary
    private: void IdentifyingPatterns();

};
