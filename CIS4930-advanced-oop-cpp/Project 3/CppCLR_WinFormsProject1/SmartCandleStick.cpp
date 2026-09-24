#include "pch.h"
#include "SmartCandleStick.h"
#include <algorithm>

//Constructor
SmartCandlestick::SmartCandlestick(String^ csv) : Candlestick(csv)
{
    //the range of the whole candlestick
    this->range = this->High - this->Low;
    //the larger of the open and close
    this->topPrice = std::max(this->Open, this->Close);
    //the lesser of the open and close
    this->bottomPrice = std::min(this->Open, this->Close);
    //the range from open to close
    this->bodyRange = this->topPrice - this->bottomPrice;
    //the height of the upper tail
    this->upperTail = this->High - this->topPrice;
    //the height of lower tail
    this->lowerTail = this->bottomPrice - this->Low;
    //calling IdentifyingPatterns
    this->candleStick_Patterns = gcnew Dictionary<String^, bool>();
    IdentifyingPatterns();
}

/// <summary>
 /// The method to identify the pattern and add to the dictionary
 /// </summary>
void SmartCandlestick::IdentifyingPatterns()
{
    //Bullish Pattern
    bool bullish = this->Close > this->Open;
    //add to the dictionary
    this->candleStick_Patterns["Bullish"] = bullish;

    //Bearish Pattern
    bool bearish = this->Open > this->Close;
    //add to the dictionary
    candleStick_Patterns["Bearish"] = bearish;

    //Neutral Pattern
    bool neutral = this->bodyRange <= (this->range * 0.2);
    //add to the dictionary
    candleStick_Patterns["Neutral"] = neutral;

    //Marubozu Pattern
    bool maruboza = (this->upperTail <= this->bodyRange * 0.2) && (this->lowerTail <= this->bodyRange * 0.2);
    //add to the dictionary
    candleStick_Patterns["Maruboza"] = maruboza;

    //Hammer Pattern
    bool hammer = (this->bodyRange < this->range * 0.25) && this->lowerTail > (0.7 * this->range);
    //add to the dictionary
    candleStick_Patterns["Hammer"] = hammer;

    //Doji Pattern
    bool doji = this->bodyRange <= (this->range * 0.03);
    //add to the dictionary
    candleStick_Patterns["Doji"] = doji;

    //DragonFly Doji Pattern
    bool dragonFlyDoji = doji && (this->lowerTail >= (0.7 * range));
    //add to the dictionary
    candleStick_Patterns["DragonFly Doji"] = dragonFlyDoji;


    //Gravestone Doji Pattern
    bool gravestoneDoji = doji && (this->upperTail >= (0.7 * range));
    //add to the dictionary
    candleStick_Patterns["Gravestone Doji"] = gravestoneDoji;

}