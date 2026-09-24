#pragma once
#include "candlestick.h"
#include "SmartCandleStick.h"
#include "Recognizer.h"
#include "Recognizer_Bullish.h"
#include "Recognizer_Bearish.h"
#include "Recognizer_BearishEngulfing.h"
#include "Recognizer_BearishHarami.h"
#include "Recognizer_BullishEngulfing.h"
#include "Recognizer_Doji.h"
#include "Recognizer_DragonFly_Doji.h"
#include "Recognizer_Hammer.h"
#include "Recognizer_Marubozu.h"
#include "Recognizer_Peak.h"
#include "Recognizer_Valley.h"
#include "Recognizer_Neutral.h"
#include "Recognizer_Gravestone_Doji.h"
#include "Recognizer_BullishHarami.h"
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
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;

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
		//dictionary Recognizer
		property Dictionary<String^, Recognizer^>^ Dictionary_Recognizer;
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
		//define initalize all recognizer
		void Form1::InitalizeRecognizer();
	public:
		Form1(void)
		{
			//initialize components
			InitializeComponent();

			//initialize recognizers
			InitalizeRecognizer();
			//
			//TODO: Add the constructor code here
			//
		}

		Form1(String^ stock_fileName, DateTime start, DateTime end) {

			InitializeComponent();

			InitalizeRecognizer();

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea5 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea6 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^ series5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->button_pickTicker = (gcnew System::Windows::Forms::Button());
			this->openFileDialog_TickerChooser = (gcnew System::Windows::Forms::OpenFileDialog());
			this->chart_OHLCV = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->dateTimePicker_startDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker_endDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->button_upDate = (gcnew System::Windows::Forms::Button());
			this->comboBox_Patterns = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_OHLCV))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button_pickTicker
			// 
			this->button_pickTicker->Location = System::Drawing::Point(263, 45);
			this->button_pickTicker->Margin = System::Windows::Forms::Padding(2);
			this->button_pickTicker->Name = L"button_pickTicker";
			this->button_pickTicker->Size = System::Drawing::Size(117, 33);
			this->button_pickTicker->TabIndex = 0;
			this->button_pickTicker->Text = L"Pick A Stock";
			this->button_pickTicker->UseVisualStyleBackColor = true;
			this->button_pickTicker->Click += gcnew System::EventHandler(this, &Form1::button_pickTicker_Click);
			// 
			// openFileDialog_TickerChooser
			// 
			this->openFileDialog_TickerChooser->Filter = L"All Files|*.CSV";
			this->openFileDialog_TickerChooser->FilterIndex = 2;
			this->openFileDialog_TickerChooser->Multiselect = true;
			this->openFileDialog_TickerChooser->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::tickerChooser_OpenFileDialog_FileOk);
			// 
			// chart_OHLCV
			// 
			chartArea5->Name = L"ChartArea_OHLC";
			chartArea6->AlignWithChartArea = L"ChartArea_OHLC";
			chartArea6->Name = L"Chart_Volume";
			this->chart_OHLCV->ChartAreas->Add(chartArea5);
			this->chart_OHLCV->ChartAreas->Add(chartArea6);
			this->chart_OHLCV->Dock = System::Windows::Forms::DockStyle::Top;
			this->chart_OHLCV->Location = System::Drawing::Point(0, 0);
			this->chart_OHLCV->Margin = System::Windows::Forms::Padding(2);
			this->chart_OHLCV->Name = L"chart_OHLCV";
			series5->ChartArea = L"ChartArea_OHLC";
			series5->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Candlestick;
			series5->CustomProperties = L"PriceDownColor=Red, PriceUpColor=Lime";
			series5->IsVisibleInLegend = false;
			series5->IsXValueIndexed = true;
			series5->Name = L"Series_OHLC";
			series5->XValueMember = L"Date";
			series5->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::DateTime;
			series5->YValueMembers = L"High, Low, Open, Close";
			series5->YValuesPerPoint = 4;
			series6->ChartArea = L"Chart_Volume";
			series6->IsVisibleInLegend = false;
			series6->IsXValueIndexed = true;
			series6->Name = L"Series_volume";
			series6->XValueMember = L"Date";
			series6->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::DateTime;
			series6->YValueMembers = L"Volume";
			series6->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::UInt64;
			this->chart_OHLCV->Series->Add(series5);
			this->chart_OHLCV->Series->Add(series6);
			this->chart_OHLCV->Size = System::Drawing::Size(1493, 459);
			this->chart_OHLCV->TabIndex = 4;
			this->chart_OHLCV->Text = L"chart2";
			// 
			// dateTimePicker_startDate
			// 
			this->dateTimePicker_startDate->Location = System::Drawing::Point(5, 53);
			this->dateTimePicker_startDate->Margin = System::Windows::Forms::Padding(2);
			this->dateTimePicker_startDate->Name = L"dateTimePicker_startDate";
			this->dateTimePicker_startDate->Size = System::Drawing::Size(248, 22);
			this->dateTimePicker_startDate->TabIndex = 5;
			this->dateTimePicker_startDate->Value = System::DateTime(2019, 1, 1, 19, 3, 0, 0);
			// 
			// dateTimePicker_endDate
			// 
			this->dateTimePicker_endDate->Location = System::Drawing::Point(506, 54);
			this->dateTimePicker_endDate->Margin = System::Windows::Forms::Padding(2);
			this->dateTimePicker_endDate->Name = L"dateTimePicker_endDate";
			this->dateTimePicker_endDate->Size = System::Drawing::Size(251, 22);
			this->dateTimePicker_endDate->TabIndex = 6;
			// 
			// button_upDate
			// 
			this->button_upDate->Location = System::Drawing::Point(384, 45);
			this->button_upDate->Margin = System::Windows::Forms::Padding(2);
			this->button_upDate->Name = L"button_upDate";
			this->button_upDate->Size = System::Drawing::Size(117, 33);
			this->button_upDate->TabIndex = 7;
			this->button_upDate->Text = L"Update";
			this->button_upDate->UseVisualStyleBackColor = true;
			this->button_upDate->Click += gcnew System::EventHandler(this, &Form1::button_upDate_Click);
			// 
			// comboBox_Patterns
			// 
			this->comboBox_Patterns->FormattingEnabled = true;
			this->comboBox_Patterns->Location = System::Drawing::Point(779, 54);
			this->comboBox_Patterns->Margin = System::Windows::Forms::Padding(2);
			this->comboBox_Patterns->Name = L"comboBox_Patterns";
			this->comboBox_Patterns->Size = System::Drawing::Size(138, 24);
			this->comboBox_Patterns->TabIndex = 8;
			this->comboBox_Patterns->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox_Patterns_SelectedIndexChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::SystemColors::Control;
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->dateTimePicker_endDate);
			this->groupBox1->Controls->Add(this->button_pickTicker);
			this->groupBox1->Controls->Add(this->button_upDate);
			this->groupBox1->Controls->Add(this->comboBox_Patterns);
			this->groupBox1->Controls->Add(this->dateTimePicker_startDate);
			this->groupBox1->Location = System::Drawing::Point(12, 483);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(941, 111);
			this->groupBox1->TabIndex = 9;
			this->groupBox1->TabStop = false;
			this->groupBox1->Enter += gcnew System::EventHandler(this, &Form1::groupBox1_Enter);
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::SystemColors::Control;
			this->textBox3->Location = System::Drawing::Point(779, 27);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 22);
			this->textBox3->TabIndex = 11;
			this->textBox3->Text = L"Pattern:";
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::Control;
			this->textBox2->Location = System::Drawing::Point(506, 27);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 22);
			this->textBox2->TabIndex = 10;
			this->textBox2->Text = L"End Date:";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::Control;
			this->textBox1->Location = System::Drawing::Point(7, 26);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 9;
			this->textBox1->Text = L"Start Date:";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1493, 626);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->chart_OHLCV);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Form1";
			this->Text = L"Form_StockPicker";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load_1);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_OHLCV))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
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
			arrow->Width = 1.0;
			//setting height for arrow
			arrow->Height = 6.0;
			//setting arrow size
			arrow->ArrowSize = 1;
			arrow->LineColor = Drawing::Color::MediumPurple;
			arrow->LineWidth = 5;
			arrow->BackColor = Color::MediumPurple;

			//check which pattern in smart candlesticks
			if (temp_scs->candleStick_Patterns[comboBox_Patterns->SelectedItem->ToString()])
			{
				if (Dictionary_Recognizer[comboBox_Patterns->SelectedItem->ToString()]->Pattern_Length == 1)
				{//setting up data point for arrow
					arrow->SetAnchor(dataPoint);
					//adding arrow to annotation of the chart
					this->chart_OHLCV->Annotations->Add(arrow);
				}
				else if (Dictionary_Recognizer[comboBox_Patterns->SelectedItem->ToString()]->Pattern_Length == 2)
				{
					RectangleAnnotation^ rectangle = gcnew RectangleAnnotation();
					rectangle->SetAnchor(dataPoint);

					double Ymax, Ymin;
					Ymax = (int)(Math::Max(temp_scs->High, boundlistOfSmartCandlesticks[i + 1]->High));
					Ymin = (int)(Math::Min(temp_scs->Low, boundlistOfSmartCandlesticks[i + 1]->Low));
					rectangle->AnchorOffsetX = (((90.0 / boundlistOfSmartCandlesticks->Count) * Dictionary_Recognizer[comboBox_Patterns->SelectedItem->ToString()]->Pattern_Length / Dictionary_Recognizer[comboBox_Patterns->SelectedItem->ToString()]->Pattern_Length) / 2 - 0.25);  //Offset even pattern for previous candlestick
					double width = (90.0 / boundlistOfSmartCandlesticks->Count) * Dictionary_Recognizer[comboBox_Patterns->SelectedItem->ToString()]->Pattern_Length; //Scale width to number of candlesticks
					double height = 40.0 * (Ymax - Ymin) / (chart_OHLCV->ChartAreas["ChartArea_OHLC"]->AxisY->Maximum - chart_OHLCV->ChartAreas["ChartArea_OHLC"]->AxisY->Minimum); ; //Scale height to chart bounds
					rectangle->Height = height;
					rectangle->Width = width;             //Set width and hight
					rectangle->Y = Ymax;                                             //Set Y to highest Y value for candlesticks
					rectangle->BackColor = Color::Transparent;                        //Set area to transparent to see chart
					rectangle->LineWidth = 2;                                        //Set perimeter width
					rectangle->LineDashStyle = ChartDashStyle::Dash;                  //Set perimeter style to dashed
					//Add annotation to chart
					chart_OHLCV->Annotations->Add(rectangle);
				}

				else
				{
					RectangleAnnotation^ rectangle = gcnew RectangleAnnotation();
					rectangle->SetAnchor(dataPoint);

					double Ymax, Ymin;
					Ymax = (int)(Math::Max(temp_scs->High, Math::Max(boundlistOfSmartCandlesticks[i + 1]->High, boundlistOfSmartCandlesticks[i + 2]->High)));
					Ymin = (int)(Math::Min(temp_scs->Low, Math::Min(boundlistOfSmartCandlesticks[i + 1]->Low, boundlistOfSmartCandlesticks[i + 2]->Low)));
					rectangle->AnchorOffsetX = (((90.0 / boundlistOfSmartCandlesticks->Count) * Dictionary_Recognizer[comboBox_Patterns->SelectedItem->ToString()]->Pattern_Length / Dictionary_Recognizer[comboBox_Patterns->SelectedItem->ToString()]->Pattern_Length) / 0.98);  //Offset even pattern for previous candlestick
					double width = (80.0 / boundlistOfSmartCandlesticks->Count) * Dictionary_Recognizer[comboBox_Patterns->SelectedItem->ToString()]->Pattern_Length; //Scale width to number of candlesticks
					double height = 40.0 * (Ymax - Ymin) / (chart_OHLCV->ChartAreas["ChartArea_OHLC"]->AxisY->Maximum - chart_OHLCV->ChartAreas["ChartArea_OHLC"]->AxisY->Minimum); ; //Scale height to chart bounds
					rectangle->Height = height;
					rectangle->Width = width;             //Set width and hight
					rectangle->Y = Ymax;                                             //Set Y to highest Y value for candlesticks
					rectangle->BackColor = Color::Transparent;                        //Set area to transparent to see chart
					rectangle->LineWidth = 2;                                        //Set perimeter width
					rectangle->LineDashStyle = ChartDashStyle::Dash;                  //Set perimeter style to dashed
					//Add annotation to chart
					chart_OHLCV->Annotations->Add(rectangle);
				}
			}
		}
	}
}
private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
}
};
}
