#include "pch.h"
#include "Form_StockPicker.h"
#include "Candlestick.h"
#include "SmartCandlestick.h"

using namespace CppCLRWinFormsProject;
using namespace System::Windows::Forms::DataVisualization::Charting;

/// <summary>
/// Creates a dataGridView and a Chart based using data on the file selected in the openFileDialog
/// </summary>
/// <param name="sender"></param>
/// <param name="e"></param>
/// <returns>Void</returns>
Void Form_StockPicker::openFileDialog_stockPicker_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e)
{
	// Clear any existing annotations
	chart_OHLCV->Annotations->Clear();

	// Find filepath, display as text
	array<String^>^ files = openFileDialog_stockPicker->FileNames;
	String^ filePath = files[0];
	Text = "Parent " + Path::GetFileNameWithoutExtension(filePath);

	// Read data from file and create a list of candlesticks
	listOfSmartCandlesticks = ReadCandleStickDataFromFile(filePath);

	// Filter candlesticks within the required date range
	boundListOfSmartCandlesticks = filterCandlesticks(listOfSmartCandlesticks);

	// Initialize comboBox
	initializeComboBox(boundListOfSmartCandlesticks);

	// Normalize chart
	normalizeChart(boundListOfSmartCandlesticks);

	// Bind boundListOfCandlesticks to Chart
	displayChart(boundListOfSmartCandlesticks);

	for (int i = 1; i < files->Length; i++) {

		Form_StockPicker^ formsp = gcnew Form_StockPicker();

		// Clear any existing annotations
		formsp->chart_OHLCV->Annotations->Clear();

		String^ filePath = files[i];
		formsp->Text = "Child: " + Path::GetFileNameWithoutExtension(filePath);

		// Read data from file and create a list of candlesticks
		formsp->listOfSmartCandlesticks = formsp->ReadCandleStickDataFromFile(filePath);

		// Filter candlesticks within the required date range
		formsp->boundListOfSmartCandlesticks = formsp->filterCandlesticks(formsp->listOfSmartCandlesticks);

		// Initialize comboBox
		formsp->initializeComboBox(boundListOfSmartCandlesticks);

		// Normalize chart
		formsp->normalizeChart(formsp->boundListOfSmartCandlesticks);

		// Bind boundListOfCandlesticks to Chart
		formsp->displayChart(formsp->boundListOfSmartCandlesticks);

		formsp->Show();
	}
}

/// <summary>
/// Updates the boundListOfCandlesticks based on the newly specified date range
/// </summary>
/// <param name="sender"></param>
/// <param name="e"></param>
/// <returns>Void</returns>
Void Form_StockPicker::button_UpdatePicker_Click(System::Object^ sender, System::EventArgs^ e) 
{
	// Clear any existing annotations
	chart_OHLCV->Annotations->Clear();

	// Filter candlesticks within new data range
	filterCandlesticks();

	// Initialize comboBox
	initializeComboBox(boundListOfSmartCandlesticks);

	// Normalize the chart
	normalizeChart();

	// Bind new boundListOfCandlesticks to Chart
	displayChart();
}

/// <summary>
/// This reads data from the file.
/// </summary>
/// <param name="filePath">This is the path to the file to be read</param>
/// <returns>This will return a list of candlesticks</returns>
List<SmartCandlestick^>^ Form_StockPicker::ReadCandleStickDataFromFile(String^ filePath)
{
	// Clear existing listOfCandlesticks
	listOfSmartCandlesticks->Clear();

	if (File::Exists(filePath))
	{
		// Create reader for file
		StreamReader^ reader = gcnew StreamReader(filePath);

		// Skip header line
		String^ line = reader->ReadLine();

		// Loop through each row in the file
		while ((line = reader->ReadLine()) != nullptr)
		{
			// Create a new candlestick object using data from the Excel row
			Candlestick^ candlestick = gcnew Candlestick(line);
			SmartCandlestick^ smartCandlestick = gcnew SmartCandlestick(candlestick);
			// Add candlestick to the listOfCandlesticks
			listOfSmartCandlesticks->Add(smartCandlestick);

		}
		reader->Close();
	}
	else
	{
		// If file does not exist
		Console::Write("Error: File not found\n");
	}

	// Return listOfCandlesticks
	return listOfSmartCandlesticks;
}

/// <summary>
/// Calls ReadCandleStickDataFromFile by passing in the filepath from the openFileDialog
/// </summary>
/// <returns>Void</returns>
Void Form_StockPicker::ReadCandleStickDataFromFile() 
{
	// Call readCandleStickFromFile by passing in the chosen file
	listOfSmartCandlesticks = ReadCandleStickDataFromFile(openFileDialog_stockPicker->FileName);
}

/// <summary>
/// This filters the listOfCandlesticks according to the date range specified by the dateTimePickers
/// </summary>
/// <param name="loc">listOfCandlesticks that have to be filtered</param>
/// <returns>Returns a BindingList of Candlesticks, filtered by the required date range</returns>
BindingList<SmartCandlestick^>^ Form_StockPicker::filterCandlesticks(List<SmartCandlestick^>^ losc)
{
	// Create new list of selected candlesticks
	List<SmartCandlestick^>^ selectedSmartCandlesticks = gcnew List<SmartCandlestick^>(losc->Count);

	// Loop through all candlesticks and choose the ones required
	for (int i = 0; i < losc->Count; i++)
	{
		SmartCandlestick^ scs = losc[i];
		// Break if candlestick has passed end date
		if (dateTimePicker_End->Value < scs->Date) {
			break;
		}

		// Check if candlestick is in the required date range
		if (dateTimePicker_Start->Value <= scs->Date && scs->Date <= dateTimePicker_End->Value) {
			selectedSmartCandlesticks->Add(scs);
		}
	}

	// Create a BindingList from the selected candlesticks & return it
	BindingList<SmartCandlestick^>^ resultingBindingList = gcnew BindingList<SmartCandlestick^>(selectedSmartCandlesticks);
	return resultingBindingList;

}

/// <summary>
/// Calls filterCandlesticks which filters a listOfCandlesticks according to the date range specified by the dateTimePickers
/// </summary>
/// <returns>Void</returns>
Void Form_StockPicker::filterCandlesticks()
{
	// Filter the listOfCandlesticks according to the range specified by the dateTimePickers
	boundListOfSmartCandlesticks = filterCandlesticks(listOfSmartCandlesticks);
}

/// <summary>
/// Normalizes the y-axis for chartArea_OHLC according to the maximum high and minimum low of the candlesticks
/// </summary>
/// <param name="bloc"></param>
/// <returns>Void</returns>
Void Form_StockPicker::normalizeChart(BindingList<SmartCandlestick^>^ blosc) 
{

	// Skip if boundListOfCandlesticks is empty
	if (blosc->Count == 0) { return; }

	// Initialize max_High and min_Low variables
	double max_High = blosc[0]->High;
	double min_Low = blosc[0]->Low;

	// Loop through the binding list of candlesticks
	for (int i = 0; i < blosc->Count; i++) {

		// cs will be Candlestick at current index
		SmartCandlestick^ scs = blosc[i];

		// If Candlestick high greater than current high
		if (scs->High > max_High) { max_High = scs->High; }

		// If Candlestick low lower than current low
		if (scs->Low < min_Low) { min_Low = scs->Low; }

	}
	
	// Increase max_High by 2%
	max_High = max_High * 1.02;

	// Increase min_Low by 2%
	min_Low = min_Low * 1.02;

	// Set chart area axis y maximum to max_High
	chart_OHLCV->ChartAreas[0]->AxisY->Maximum = max_High;

	// Set chart area axis y minimum to min_Low
	chart_OHLCV->ChartAreas[0]->AxisY->Minimum = min_Low;
}

/// <summary>
/// Calls normalizeChart which normalizes the y-axis for chartArea_OHLC according to the maximum high and minimum low of the candlesticks
/// </summary>
/// <returns>Void</returns>
Void Form_StockPicker::normalizeChart() 
{
	// Normalize y-axis for the chart
	normalizeChart(boundListOfSmartCandlesticks);
}

/// <summary>
/// Displays a chart using the boundListOfCandlesticks. The chart shows the candlesticks along with their volume
/// </summary>
/// <param name="bloc"></param>
/// <returns>Void</returns>
Void Form_StockPicker::displayChart(BindingList<SmartCandlestick^>^ blosc) 
{
	// Set chart source to be the bound list of candlesticks & return
	chart_OHLCV->DataSource = blosc;
	chart_OHLCV->DataBind();

}

/// <summary>
/// Calls displayChart which displays a chart using the boundListOfCandlesticks
/// </summary>
/// <returns>Void</returns>
Void Form_StockPicker::displayChart() 
{
	// Display the chart using data from the boundListOfCandlesticks
	displayChart(boundListOfSmartCandlesticks);
}

/// <summary>
/// Initializes the combo box with patterns from the first SmartCandlestick in the binding list.
/// </summary>
/// <param name="blosc">The binding list of SmartCandlestick objects to initialize the combo box with.</param>
Void Form_StockPicker::initializeComboBox(BindingList<SmartCandlestick^>^ blosc) 
{
	// Get the first SmartCandlestick object from the binding list
	SmartCandlestick^ scs = blosc[0];

	// Clear existing items in the combo box
	comboBox_Patterns->Items->Clear();

	// Check if the SmartCandlestick object and its patterns dictionary are not null
	if (scs != nullptr && scs->patterns != nullptr)
	{
		// Get the patterns dictionary from the SmartCandlestick
		Dictionary<String^, bool>^ patterns = scs->patterns;

		// Add keys (patterns) from the dictionary to the combo box
		for each (String ^ key in patterns->Keys)
		{
			comboBox_Patterns->Items->Add(key);
		}
	}
}

/// <summary>
/// Event handler for the SelectedIndexChanged event of comboBox_Patterns.
/// Displays annotations on the chart based on the selected pattern.
/// </summary>
/// <param name="sender">The object that triggered the event.</param>
/// <param name="e">The event arguments.</param>
Void Form_StockPicker::comboBox_Patterns_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) 
{
	// Clear existing annotations on the chart
	chart_OHLCV->Annotations->Clear();

	// Get the selected pattern from the combo box
	String^ selectedPattern = comboBox_Patterns->SelectedItem->ToString();

	// Iterate through the smart candlesticks in the boundListOfSmartCandlesticks
	for (int i = 0; i < boundListOfSmartCandlesticks->Count; i++) {
		SmartCandlestick^ scs = boundListOfSmartCandlesticks[i];

		// Check if the selected pattern is true for the current smart candlestick
		if (scs->patterns[selectedPattern]) {
			// Create a new ArrowAnnotation object
			ArrowAnnotation^ arrow = gcnew ArrowAnnotation();

			// Set the anchor point to the candlestick data point
			arrow->IsSizeAlwaysRelative = false;
			arrow->AnchorDataPoint = chart_OHLCV->Series["Series_OHLC"]->Points[i];

			// Set the arrow properties for a single line with a triangular end
			arrow->ArrowStyle = System::Windows::Forms::DataVisualization::Charting::ArrowStyle::Simple;
			arrow->Width = 1.0;
			arrow->Height = 4.0; // Adjust the triangle height as needed
			arrow->ArrowSize = 1;
			arrow->LineColor = Drawing::Color::MediumPurple;
			arrow->LineWidth = 5;

			// Calculate the arrow direction and position
			DataPoint^ anchorPoint = arrow->AnchorDataPoint;
			double candleX = anchorPoint->XValue;
			double candleY = anchorPoint->YValues[2]; // Open value

			double arrowX = candleX + 1; // Offset the arrow slightly to the right

			// Set the ending anchor point of the arrow (commented out as not used)
			// arrow->EndingAnchor = gcnew Point(arrowX, candleY);

			// Add the annotation to the chart
			chart_OHLCV->Annotations->Add(arrow);
		}
	}
}