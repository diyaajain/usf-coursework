#pragma once
#include "candllestick.h"
#include "SmartCandleStick.h"
#using <System.dll>

namespace CppCLRWinFormsProject {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace System::Diagnostics;
	using namespace System::Windows::Forms::DataVisualization::Charting;

	public ref class Form1 : public System::Windows::Forms::Form
	{
	//crete the smart candlesticks list
	private:List<SmartCandlestick^>^ smartCandlesticks;
	private: System::Windows::Forms::Button^ button_pickTicker;
	private: System::Windows::Forms::ComboBox^ comboBox_Patterns;

	//create the bounding list smart candlesticks
	private:BindingList<SmartCandlestick^>^ boundlistOfSmartCandlesticks;
	//define the helper ReadCandlestickDataFromFil method
	private:List<SmartCandlestick^>^ ReadCandlestickDataFromFile(String^ filePath);
	//define the helper displayCandlesticks method
	private: void displayCandlesticks(BindingList<SmartCandlestick^>^ boundingLoc);
	//define the helper filterCandlesticks method
	private: List<SmartCandlestick^>^ filterCandlesticks(List<SmartCandlestick^>^ loc, DateTime startDate, DateTime endDate);
	//define helper normalizeChart method
	private:void Form1::normalizeChart(BindingList<SmartCandlestick^>^ boundingLoc);
	//define hepler update method
	private:void Form1::update(DateTime startDate, DateTime endDate);

	private:void updateComboBox(BindingList<SmartCandlestick^>^ bindingList);

	private:void updateComboBox();
	public:
		//define ReadCandleStickDataFromFile method
		void Form1::ReadCandleStickDataFromFile();
		//define filterCandleStick method
		void Form1::filterCandlesticks();
		//define displayCandlesticks method
		void Form1::displayCandlesticks();
		//define normalizeChart method
		void Form1::normalizeChart();
		//define update method
		void Form1::update();
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		Form1(String^ stock_fileName, DateTime start, DateTime end) {
			InitializeComponent();

			openFileDialog_TickerChooser->FileName = stock_fileName;

			dateTimePicker_startDate->Value = start;

			dateTimePicker_endDate->Value = end;

			//call readCandlesticksFromFile method
			smartCandlesticks = ReadCandlestickDataFromFile(stock_fileName);
			//call readCandlesticksFromFile method
			filterCandlesticks();
			// call normalizeChart() method
			normalizeChart();
			//call displayCandlesticks method
			displayCandlesticks();

		}
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog_TickerChooser;
	public:

	public:

	protected:

		   /// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
		}	
	protected:

	protected:
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;

	private: System::Windows::Forms::DataGridView^ dataGridView2;

	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart_OHLCV;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker_startDate;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker_endDate;
	private: System::Windows::Forms::Button^ button_upDate;





	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->button_pickTicker = (gcnew System::Windows::Forms::Button());
			this->openFileDialog_TickerChooser = (gcnew System::Windows::Forms::OpenFileDialog());
			this->chart_OHLCV = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->dateTimePicker_startDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker_endDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->button_upDate = (gcnew System::Windows::Forms::Button());
			this->comboBox_Patterns = (gcnew System::Windows::Forms::ComboBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_OHLCV))->BeginInit();
			this->SuspendLayout();
			// 
			// button_pickTicker
			// 
			this->button_pickTicker->Location = System::Drawing::Point(1176, 845);
			this->button_pickTicker->Margin = System::Windows::Forms::Padding(4);
			this->button_pickTicker->Name = L"button_pickTicker";
			this->button_pickTicker->Size = System::Drawing::Size(234, 63);
			this->button_pickTicker->TabIndex = 0;
			this->button_pickTicker->Text = L"Pick A Stock";
			this->button_pickTicker->UseVisualStyleBackColor = true;
			this->button_pickTicker->Click += gcnew System::EventHandler(this, &Form1::button_pickTicker_Click);
			// 
			// openFileDialog_TickerChooser
			// 
			this->openFileDialog_TickerChooser->Filter = L"All Files|*.CSV|Monthly|*-Month.CSV|Weekly|*-Week.CSV|Daily|*-Day.CSV";
			this->openFileDialog_TickerChooser->FilterIndex = 2;
			this->openFileDialog_TickerChooser->Multiselect = true;
			this->openFileDialog_TickerChooser->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::tickerChooser_OpenFileDialog_FileOk);
			// 
			// chart_OHLCV
			// 
			chartArea1->Name = L"ChartArea_OHLC";
			chartArea2->AlignWithChartArea = L"ChartArea_OHLC";
			chartArea2->Name = L"Chart_Volume";
			this->chart_OHLCV->ChartAreas->Add(chartArea1);
			this->chart_OHLCV->ChartAreas->Add(chartArea2);
			legend1->Name = L"Legend1";
			this->chart_OHLCV->Legends->Add(legend1);
			this->chart_OHLCV->Location = System::Drawing::Point(103, 161);
			this->chart_OHLCV->Margin = System::Windows::Forms::Padding(4);
			this->chart_OHLCV->Name = L"chart_OHLCV";
			series1->ChartArea = L"ChartArea_OHLC";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Candlestick;
			series1->CustomProperties = L"PriceDownColor=Red, PriceUpColor=Lime";
			series1->IsVisibleInLegend = false;
			series1->IsXValueIndexed = true;
			series1->Legend = L"Legend1";
			series1->Name = L"Series_OHLC";
			series1->XValueMember = L"Date";
			series1->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::DateTime;
			series1->YValueMembers = L"High, Low, Open, Close";
			series1->YValuesPerPoint = 4;
			series2->ChartArea = L"Chart_Volume";
			series2->IsVisibleInLegend = false;
			series2->IsXValueIndexed = true;
			series2->Legend = L"Legend1";
			series2->Name = L"Series_volume";
			series2->XValueMember = L"Date";
			series2->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::DateTime;
			series2->YValueMembers = L"Volume";
			series2->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::UInt64;
			this->chart_OHLCV->Series->Add(series1);
			this->chart_OHLCV->Series->Add(series2);
			this->chart_OHLCV->Size = System::Drawing::Size(1785, 372);
			this->chart_OHLCV->TabIndex = 4;
			this->chart_OHLCV->Text = L"chart2";
			// 
			// dateTimePicker_startDate
			// 
			this->dateTimePicker_startDate->Location = System::Drawing::Point(59, 855);
			this->dateTimePicker_startDate->Margin = System::Windows::Forms::Padding(4);
			this->dateTimePicker_startDate->Name = L"dateTimePicker_startDate";
			this->dateTimePicker_startDate->Size = System::Drawing::Size(491, 38);
			this->dateTimePicker_startDate->TabIndex = 5;
			this->dateTimePicker_startDate->Value = System::DateTime(2022, 1, 1, 19, 3, 0, 0);
			// 
			// dateTimePicker_endDate
			// 
			this->dateTimePicker_endDate->Location = System::Drawing::Point(1438, 855);
			this->dateTimePicker_endDate->Margin = System::Windows::Forms::Padding(4);
			this->dateTimePicker_endDate->Name = L"dateTimePicker_endDate";
			this->dateTimePicker_endDate->Size = System::Drawing::Size(474, 38);
			this->dateTimePicker_endDate->TabIndex = 6;
			// 
			// button_upDate
			// 
			this->button_upDate->Location = System::Drawing::Point(573, 845);
			this->button_upDate->Margin = System::Windows::Forms::Padding(4);
			this->button_upDate->Name = L"button_upDate";
			this->button_upDate->Size = System::Drawing::Size(250, 63);
			this->button_upDate->TabIndex = 7;
			this->button_upDate->Text = L"Update";
			this->button_upDate->UseVisualStyleBackColor = true;
			this->button_upDate->Click += gcnew System::EventHandler(this, &Form1::button_upDate_Click);
			// 
			// comboBox_Patterns
			// 
			this->comboBox_Patterns->FormattingEnabled = true;
			this->comboBox_Patterns->Location = System::Drawing::Point(870, 855);
			this->comboBox_Patterns->Name = L"comboBox_Patterns";
			this->comboBox_Patterns->Size = System::Drawing::Size(273, 39);
			this->comboBox_Patterns->TabIndex = 8;
			this->comboBox_Patterns->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox_Patterns_SelectedIndexChanged);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(2007, 934);
			this->Controls->Add(this->comboBox_Patterns);
			this->Controls->Add(this->button_upDate);
			this->Controls->Add(this->dateTimePicker_endDate);
			this->Controls->Add(this->dateTimePicker_startDate);
			this->Controls->Add(this->chart_OHLCV);
			this->Controls->Add(this->button_pickTicker);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Form1";
			this->Text = L"Form_StockPicker";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load_1);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_OHLCV))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	/// <summary>
	/// The event that open the dialog file once users click on it
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	private: System::Void button_pickTicker_Click(System::Object^ sender, System::EventArgs^ e) {
		//openFileDialog_TickerChooser element call the ShowDialog() method
		openFileDialog_TickerChooser->ShowDialog();

	}

	/// <summary>
	/// This method will be executed after the user click OK in the openFileDialog event
	/// After users press OK, they will see the date displayed in DataGridView and Chart
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	private: System::Void tickerChooser_OpenFileDialog_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
		int count = openFileDialog_TickerChooser->FileNames->Length;
		for (int i = 0; i < count; i++) 
		{
			Form1^ formsp;

			if (i == 0) {
				formsp = this;

				formsp->Text = openFileDialog_TickerChooser->FileNames[i];

				smartCandlesticks = ReadCandlestickDataFromFile(openFileDialog_TickerChooser->FileName);
				//call readCandlesticksFromFile method
				filterCandlesticks();
				// call normalizeChart() method
				normalizeChart();
				//call displayCandlesticks method
				displayCandlesticks();

			}
			else {
				
				formsp = gcnew Form1(openFileDialog_TickerChooser->FileNames[i], dateTimePicker_startDate->Value, dateTimePicker_endDate->Value);

				formsp->Text = openFileDialog_TickerChooser->FileNames[i];



			}

			formsp->Show();
			formsp->BringToFront();


		}
		
	}

	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void Form1_Load_1(System::Object^ sender, System::EventArgs^ e) {}
		/// <summary>
	   /// Update event that update the UI after change the range of startDate and endDate
	   /// </summary>
	   /// <param name="sender"></param>
	   /// <param name="e"></param>
	private: System::Void button_upDate_Click(System::Object^ sender, System::EventArgs^ e) {
		//call update method to update the UI in the range of startDate and endDate
		update();
	}


private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void comboBox_Patterns_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	//clear annotation before assigning new ones
	this->chart_OHLCV->Annotations->Clear();
	//iterating over the bounding list of smart candlesticks
	for (int i = 0; i < this->boundlistOfSmartCandlesticks->Count; i++)
	{
		//creating temporary smart candlesticks
		SmartCandlestick^ temp_scs = boundlistOfSmartCandlesticks[i];
		//accessing to the series points of candlestick
		DataPoint^ dataPoint = chart_OHLCV->Series[0]->Points[i];
		//check if temporary smart candlestick is null
		if (temp_scs != nullptr)
		{
			//creating ArrowAnnotion object
			ArrowAnnotation^ arrow = gcnew ArrowAnnotation();
			//setting up x axis for arrow
			arrow->AxisX = chart_OHLCV->ChartAreas[0]->AxisX;
			//setting up y axis for arrow
			arrow->AxisY = chart_OHLCV->ChartAreas[0]->AxisY;
			//setting with for arrow
			arrow->Width = 1;
			//setting height for arrow
			arrow->Height = 1;
			arrow->BackColor = Color::Black;
			//check which pattern in smart candlesticks
			if (temp_scs->candleStick_Patterns[comboBox_Patterns->SelectedItem->ToString()])
			{
				//setting up data point for arrow
				arrow->SetAnchor(dataPoint);
				//adding arrow to annotation of the chart
				this->chart_OHLCV->Annotations->Add(arrow);
			}
		}
	}
}
};
}
