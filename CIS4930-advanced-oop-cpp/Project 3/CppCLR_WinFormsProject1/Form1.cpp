#include "pch.h"
#include "Form1.h"
#include<cfloat>
#include<cmath>

namespace CppCLRWinFormsProject {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace System::IO;
	using namespace System::Diagnostics;
	//create the list of candlestick variable to return 
	List<SmartCandlestick^>^ Form1::ReadCandlestickDataFromFile(String^ filePath) 
	{
		//create the list of candlestick variable to return 
		List<SmartCandlestick^>^ listOfCandlesticks = gcnew List<SmartCandlestick^>();
		//if the filePath exist, we will read the file
		if (File::Exists(filePath)) {
			//use the StreamReader object to read the data from the file
			StreamReader^ reader = gcnew StreamReader(filePath);
			//Skip the header line if present
			String^ line = reader->ReadLine();
			//while loop to check each line of the code if its not empty
			while ((line = reader->ReadLine()) != nullptr) {
				//This is where we need to instantiate the candlestick represented by the string
				SmartCandlestick^ candlestick = gcnew SmartCandlestick(line);
				//add candlestick object to the list
				listOfCandlesticks->Add(candlestick);
			}
			//close reading the file
			reader->Close();
		}

		//Recognize all pattern in list of smart candlesticks
		for each(Recognizer^ r in Dictionary_Recognizer->Values)
		{
			r->Recognize_All(listOfCandlesticks);
		}

		//return list of candlesticks
		return listOfCandlesticks;
	}

	/// <summary>
	/// This method is used to call the readCandlesticksFromFile method to read the data from the file
	/// </summary>
	void Form1::ReadCandleStickDataFromFile(){
		// call readCandlesticksFromFile and pass the file name into it to read the data from the file
		smartCandlesticks = ReadCandlestickDataFromFile(openFileDialog_TickerChooser->FileName);
	}


	/// <summary>
	/// This method is used to filter the list of candlesticks in the range of startDate and endDate and assign to binding list
	/// </summary>
	void Form1::filterCandlesticks() {
		//create the list of filtered candlesticks after use the helper function to filter
		List<SmartCandlestick^>^ filteredList = filterCandlesticks(smartCandlesticks, dateTimePicker_startDate->Value, dateTimePicker_endDate->Value);
		//assign to the binding list
		boundlistOfSmartCandlesticks = gcnew BindingList<SmartCandlestick^>(filteredList);

		updateComboBox();
	}


	List<SmartCandlestick^>^ Form1::filterCandlesticks(List<SmartCandlestick^>^ unfilteredList, DateTime startDate, DateTime endDate)
	{
		//This will be the resulting filtered list
		List<SmartCandlestick^>^ filterList = gcnew List<SmartCandlestick^>(unfilteredList->Count);
		//filter the candlestick
		for (int i = 0; i < unfilteredList->Count; ++i) {
			SmartCandlestick^ cs = unfilteredList[i];
			//Keep only the candlestricks in the chosen data range
			if (cs->Date >= startDate && cs->Date <= endDate) filterList->Add(cs);
			//Stop looking for more candlesticks if we have passed the end date
		}
		//Now that we have the selected candlesticks in a List<Candlestick^>^
		// We create a BindingList from it
		Debug::WriteLine(filterList->Count);
		return filterList;
	}
	/// <summary>
	/// This method is used to display candlesticks in the chart and dataGridView
	/// </summary>
	void Form1::displayCandlesticks() {
		//calling helper method displayCandlesticks
		displayCandlesticks(boundlistOfSmartCandlesticks);
	}

	/// <summary>
	/// Helper function to display candlesticks into the UI
	/// </summary>
	/// <param name="boundingLoc"></param>
	void Form1::displayCandlesticks(BindingList<SmartCandlestick^>^ boundingLoc)
	{
		//assign bindling list of candlesticks to chart datasrouce
		chart_OHLCV->DataSource = boundingLoc;
		//binding the chart
		chart_OHLCV->DataBind();

	}


	/// <summary>
	/// This method to modify the chart to display in full range 
	/// </summary>
	void Form1::normalizeChart() {
		//call the helper function normalizeChart and assign the value of boundlistOfCandleSticks
		normalizeChart(boundlistOfSmartCandlesticks);
	}

	/// <summary>
	/// The helper function to normalize the chart in the full range
	/// </summary>
	/// <param name="boundingLoc">binding list of candlesticks</param>
	/// <returns></returns>
	void Form1::normalizeChart(BindingList<SmartCandlestick^>^ boundingLoc)
	{
		//initialize minValue to compare
		double min = DBL_MAX;
		//inititalize maxValue to compare
		double max = 0;

		//iterate over binding list of candlesticks
		for (int i = 0; i < boundingLoc->Count; ++i)
		{
			//create temporary CandlesStick object
			Candlestick^ cs = boundingLoc[i];

			//find the new min value
			if (cs->Low < min) min = cs->Low;

			//find the new max value
			if (cs->High > max) max = cs->High;
		}

		//subtract 2% to the Minimum values of the Y Axis
		chart_OHLCV->ChartAreas["ChartArea_OHLC"]->AxisY->Minimum = Math::Round(min * 0.98,2);
		//add 2% to the Maximum values of the Y Axis
		chart_OHLCV->ChartAreas["ChartArea_OHLC"]->AxisY->Maximum = Math::Round(max * 1.02,2);
	}

	void Form1::update() {
		update(dateTimePicker_startDate->Value, dateTimePicker_endDate->Value);
	}

	void Form1::update(DateTime startDate, DateTime endDate) {
		// Don't update if the data values are in invalid conditions
		if (smartCandlesticks->Count == 0 || startDate > endDate) return;

		//call filterCandlesticks method
		filterCandlesticks();
		// call normalizeChart() method
		normalizeChart();
		//call displayCandlesticks method
		displayCandlesticks();
	}

	/// <summary>
/// The method to iterate over the first element of bindingList to attain all of type of candlestick
/// </summary>
/// <param name="bindingList">List of bounding candlesticks</param>
	void Form1::updateComboBox(BindingList<SmartCandlestick^>^ bindingList)
	{
		//check if the numbers of candle stick different than 0
		if (bindingList->Count != 0)
		{
			//calear items in combo box
			this->comboBox_Patterns->Items->Clear();
			//creating temp smart candle sticks
			SmartCandlestick^ temp_scs = bindingList[0];
			//iterating over keys of candle stick pattern dictionary
			for each(String^ key in temp_scs->candleStick_Patterns->Keys)
			{
				//add the pattern to the combo box on the form
				this->comboBox_Patterns->Items->Add(key);
			}
		}
	}

	/// <summary>
	/// the method to overrid updateComboBox method to hide the implementation
	/// </summary>
	void Form1::updateComboBox()
	{
		//calling updateComboBox method 
		this->updateComboBox(boundlistOfSmartCandlesticks);
	}

	/// <summary>
	/// Initialize Recognizer
	/// </summary>
	void Form1::InitalizeRecognizer() {

		Dictionary_Recognizer = gcnew Dictionary<String^, Recognizer^>();
		//Bullish Recognizer
		Recognizer^ r = gcnew Recognizer_Bullish();
		Dictionary_Recognizer->Add(r->Pattern_Name, r);
		//Bearish Recognizer
		r = gcnew Recognizer_Bearish();
		Dictionary_Recognizer->Add(r->Pattern_Name, r);
		//Neutral Recognizer
		r = gcnew Recognizer_Neutral();
		Dictionary_Recognizer->Add(r->Pattern_Name, r);
		//Marubozu Recognizer
		r = gcnew Recognizer_Marubozu();
		Dictionary_Recognizer->Add(r->Pattern_Name, r);
		//Hammer Recognizer
		r = gcnew Recognizer_Hammer();
		Dictionary_Recognizer->Add(r->Pattern_Name, r);
		//Doji Recognizer
		r = gcnew Recognizer_Doji();
		Dictionary_Recognizer->Add(r->Pattern_Name, r);
		//Dragonfly Doji Recognizer
		r = gcnew Recognizer_DragonFly_Doji();
		Dictionary_Recognizer->Add(r->Pattern_Name, r);
		//Gravestone Doji Recognizer
		r = gcnew Recognizer_Gravestone_Doji();
		Dictionary_Recognizer->Add(r->Pattern_Name, r);
		//Bullish Engulfing
		r = gcnew Recognizer_BullishEngulfing();
		Dictionary_Recognizer->Add(r->Pattern_Name, r);
		//Bearish Engulfing
		r = gcnew Recognizer_BearishEngulfing();
		Dictionary_Recognizer->Add(r->Pattern_Name, r);
		//Dragonfly Bearish Harami
		r = gcnew Recognizer_BearishHarami();
		Dictionary_Recognizer->Add(r->Pattern_Name, r);
		//Gravestone Doji Recognizer
		r = gcnew Recognizer_BullishHarami();
		Dictionary_Recognizer->Add(r->Pattern_Name, r);
		//Peak Recognizer
		r = gcnew Recognizer_Peak();
		Dictionary_Recognizer->Add(r->Pattern_Name, r);
		//Valley Recognizer
		r = gcnew Recognizer_Valley();
		Dictionary_Recognizer->Add(r->Pattern_Name, r);
		//Initialize Combo Box
		//iterating over keys of candle stick pattern dictionary
		for each (String ^ key in Dictionary_Recognizer->Keys)
		{
			//add the pattern to the combo box on the form
			this->comboBox_Patterns->Items->Add(key); 
		}
	}



}
