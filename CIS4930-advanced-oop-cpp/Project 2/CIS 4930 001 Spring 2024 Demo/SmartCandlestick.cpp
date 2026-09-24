#include "pch.h"
#include "SmartCandlestick.h"
#include "Candlestick.h"


/// <summary>
/// Calculates additional properties of a SmartCandlestick object and updates its member variables.
/// </summary>
Void SmartCandlestick::ComputeExtraProperties()
{
    // Calculate the total range of the candlestick
    Range = High - Low;

    // Determine the higher price between open and close
    topPrice = Math::Max(Open, Close);

    // Determine the lower price between open and close
    bottomPrice = Math::Min(Open, Close);

    // Calculate the range of the candlestick's body
    bodyRange = topPrice - bottomPrice;

    // Calculate the length of the upper tail
    upperTail = High - topPrice;

    // Calculate the length of the lower tail
    lowerTail = bottomPrice - Low;
}

/// <summary>
/// Calculates various candlestick patterns based on the properties of a SmartCandlestick object and updates its pattern dictionary.
/// </summary>
Void SmartCandlestick::ComputePatternProperties()
{
    // Add Bullish pattern: Close price greater than open price
    patterns->Add("Bullish", Close > Open);

    // Add Bearish pattern: Close price less than open price
    patterns->Add("Bearish", Close < Open);

    // Add Neutral pattern: Body range between 1% and 25% of total range
    patterns->Add("Neutral", (bodyRange >= 0.01 * Range) && (bodyRange <= 0.25 * Range));

    // Add Marubozu pattern: Almost no body, indicates strong buying or selling pressure
    patterns->Add("Marubozu", (Range - bodyRange <= 0.1 * Range));

    // Add Hammer pattern: Small body and long upper tail, bullish reversal signal
    patterns->Add("Hammer", (upperTail < 0.1 * Range) && (bodyRange >= 0.15 * Range) && (bodyRange <= 0.35 * Range));

    // Add Doji pattern: Very small body, indecision in the market
    patterns->Add("Doji", (bodyRange < 0.02 * Open));

    // Add Dragonfly Doji pattern: Doji with long upper tail, bullish reversal signal
    patterns->Add("Dragonfly Doji", (bodyRange < 0.02 * Open) && (upperTail < 0.02 * Range));

    // Add Gravestone Doji pattern: Doji with long lower tail, bearish reversal signal
    patterns->Add("Gravestone Doji", (bodyRange < 0.02 * Open) && (lowerTail < 0.02 * Range));
}
