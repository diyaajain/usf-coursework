#include "pch.h"
#include "Recognizer.h"

/// <summary>
/// the method to recognize all smart candlesticks
/// </summary>
/// <param name="scList"></param>
void Recognizer::Recognize_All(List<SmartCandlestick^>^ scList)
{
	//iterate over smart candlestick list
	for (int i = 0; i < scList->Count; i++)
	{
		//calling recognize method
		Recognize(scList, i);
	}
}
/// <summary>
/// constructor
/// </summary>
Recognizer::Recognizer() {

}