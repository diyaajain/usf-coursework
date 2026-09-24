#pragma once
#include "Candlestick.h"
#include "Form_StockViewer.h"
namespace CppCLRWinFormsProject
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class Form_StockPicker : public System::Windows::Forms::Form
	{
	private:List<Candlestick^>^ listOfCandlesticks;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart_OHLCV; //initializes a chart variable
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker_StartDate; //initializes a date time picker variable that will help filter the candlestick data
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker_EndDate; //initializes a date time picker variable to be used to filter the candlestick data
	private: System::Windows::Forms::TextBox^ textBox_StartDate; //textbox variable that displays "Start date:"
	private: System::Windows::Forms::TextBox^ textBox_EndDate; //textbox variable that displays "End date:"
	private: System::Windows::Forms::Button^ button_Update; //this variable displays "Update" that will be used to filter the candlestick data
	private:BindingList<Candlestick^>^ boundlistOfCandlesticks; //initializing a bindling list of type Candlestick 
	/// <summary>
	/// This is the constructor
	/// </summary>
	public:
		Form_StockPicker(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	/// <summary>
	/// This is the destructor
	/// </summary>
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form_StockPicker()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button_loader;
	protected:
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog_stockPicker;
	private: System::Windows::Forms::DataGridView^ dataGridView_candlesticks;


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
			this->button_loader = (gcnew System::Windows::Forms::Button());
			this->openFileDialog_stockPicker = (gcnew System::Windows::Forms::OpenFileDialog());
			this->dataGridView_candlesticks = (gcnew System::Windows::Forms::DataGridView());
			this->chart_OHLCV = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->dateTimePicker_StartDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker_EndDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->textBox_StartDate = (gcnew System::Windows::Forms::TextBox());
			this->textBox_EndDate = (gcnew System::Windows::Forms::TextBox());
			this->button_Update = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_candlesticks))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_OHLCV))->BeginInit();
			this->SuspendLayout();
			// 
			// button_loader
			// 
			this->button_loader->Location = System::Drawing::Point(28, 172);
			this->button_loader->Margin = System::Windows::Forms::Padding(2);
			this->button_loader->Name = L"button_loader";
			this->button_loader->Size = System::Drawing::Size(123, 31);
			this->button_loader->TabIndex = 0;
			this->button_loader->Text = L"Load Ticker";
			this->button_loader->UseVisualStyleBackColor = true;
			this->button_loader->Click += gcnew System::EventHandler(this, &Form_StockPicker::button_loader_Click);
			// 
			// openFileDialog_stockPicker
			// 
			this->openFileDialog_stockPicker->Filter = L"All Files|*.csv|Monthly|*-Month.csv|Weekly|*-Week.csv|Daily|*-Day.csv";
			this->openFileDialog_stockPicker->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form_StockPicker::openFileDialog_stockPicker_FileOk);
			// 
			// dataGridView_candlesticks
			// 
			this->dataGridView_candlesticks->AllowDrop = true;
			this->dataGridView_candlesticks->AllowUserToOrderColumns = true;
			this->dataGridView_candlesticks->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->dataGridView_candlesticks->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_candlesticks->Location = System::Drawing::Point(286, 11);
			this->dataGridView_candlesticks->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView_candlesticks->Name = L"dataGridView_candlesticks";
			this->dataGridView_candlesticks->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->dataGridView_candlesticks->RowHeadersWidth = 82;
			this->dataGridView_candlesticks->RowTemplate->Height = 33;
			this->dataGridView_candlesticks->Size = System::Drawing::Size(933, 252);
			this->dataGridView_candlesticks->TabIndex = 2;
			// 
			// chart_OHLCV
			// 
			chartArea1->Name = L"ChartArea_OHLC";
			chartArea2->AlignWithChartArea = L"ChartArea_OHLC";
			chartArea2->Name = L"ChartArea_Volume";
			this->chart_OHLCV->ChartAreas->Add(chartArea1);
			this->chart_OHLCV->ChartAreas->Add(chartArea2);
			legend1->Name = L"Legend1";
			this->chart_OHLCV->Legends->Add(legend1);
			this->chart_OHLCV->Location = System::Drawing::Point(28, 279);
			this->chart_OHLCV->Margin = System::Windows::Forms::Padding(2);
			this->chart_OHLCV->Name = L"chart_OHLCV";
			series1->ChartArea = L"ChartArea_OHLC";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Candlestick;
			series1->CustomProperties = L"PriceDownColor=Red, PriceUpColor=Lime";
			series1->Legend = L"Legend1";
			series1->Name = L"Series_OHLC";
			series1->XValueMember = L"Date";
			series1->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::DateTime;
			series1->YValueMembers = L"High,Low,Open,Close";
			series1->YValuesPerPoint = 4;
			series2->ChartArea = L"ChartArea_Volume";
			series2->Legend = L"Legend1";
			series2->Name = L"Series_Volume";
			series2->XValueMember = L"Date";
			series2->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::DateTime;
			series2->YValueMembers = L"Volume";
			this->chart_OHLCV->Series->Add(series1);
			this->chart_OHLCV->Series->Add(series2);
			this->chart_OHLCV->Size = System::Drawing::Size(1191, 367);
			this->chart_OHLCV->TabIndex = 3;
			this->chart_OHLCV->Text = L"chart_OHLCV";
			// 
			// dateTimePicker_StartDate
			// 
			this->dateTimePicker_StartDate->Location = System::Drawing::Point(28, 65);
			this->dateTimePicker_StartDate->Margin = System::Windows::Forms::Padding(2);
			this->dateTimePicker_StartDate->Name = L"dateTimePicker_StartDate";
			this->dateTimePicker_StartDate->Size = System::Drawing::Size(241, 22);
			this->dateTimePicker_StartDate->TabIndex = 4;
			this->dateTimePicker_StartDate->Value = System::DateTime(2019, 1, 1, 0, 0, 0, 0);
			// 
			// dateTimePicker_EndDate
			// 
			this->dateTimePicker_EndDate->Location = System::Drawing::Point(28, 130);
			this->dateTimePicker_EndDate->Margin = System::Windows::Forms::Padding(2);
			this->dateTimePicker_EndDate->Name = L"dateTimePicker_EndDate";
			this->dateTimePicker_EndDate->Size = System::Drawing::Size(241, 22);
			this->dateTimePicker_EndDate->TabIndex = 5;
			// 
			// textBox_StartDate
			// 
			this->textBox_StartDate->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_StartDate->Location = System::Drawing::Point(28, 39);
			this->textBox_StartDate->Margin = System::Windows::Forms::Padding(2);
			this->textBox_StartDate->Name = L"textBox_StartDate";
			this->textBox_StartDate->Size = System::Drawing::Size(85, 22);
			this->textBox_StartDate->TabIndex = 6;
			this->textBox_StartDate->Text = L"Start date:";
			// 
			// textBox_EndDate
			// 
			this->textBox_EndDate->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_EndDate->Location = System::Drawing::Point(28, 104);
			this->textBox_EndDate->Margin = System::Windows::Forms::Padding(2);
			this->textBox_EndDate->Name = L"textBox_EndDate";
			this->textBox_EndDate->Size = System::Drawing::Size(85, 22);
			this->textBox_EndDate->TabIndex = 7;
			this->textBox_EndDate->Text = L"End date:";
			// 
			// button_Update
			// 
			this->button_Update->Location = System::Drawing::Point(155, 172);
			this->button_Update->Margin = System::Windows::Forms::Padding(2);
			this->button_Update->Name = L"button_Update";
			this->button_Update->Size = System::Drawing::Size(114, 31);
			this->button_Update->TabIndex = 8;
			this->button_Update->Text = L"Update";
			this->button_Update->UseVisualStyleBackColor = true;
			this->button_Update->Click += gcnew System::EventHandler(this, &Form_StockPicker::button_Update_Click);
			// 
			// Form_StockPicker
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1242, 675);
			this->Controls->Add(this->button_Update);
			this->Controls->Add(this->textBox_EndDate);
			this->Controls->Add(this->textBox_StartDate);
			this->Controls->Add(this->dateTimePicker_EndDate);
			this->Controls->Add(this->dateTimePicker_StartDate);
			this->Controls->Add(this->chart_OHLCV);
			this->Controls->Add(this->dataGridView_candlesticks);
			this->Controls->Add(this->button_loader);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Form_StockPicker";
			this->Text = L"Form_StockPicker";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_candlesticks))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_OHLCV))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	/// <summary>
	/// Event handler for the "Load Stock" button click event.
	/// Opens the file dialog for selecting .csv files.
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	/// <returns></returns>
	private: System::Void button_loader_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		openFileDialog_stockPicker->ShowDialog(); // opens the file dialog to choose a file
	}


	/// <summary>
	/// Event handler for the FileOk event of the open file dialog
	/// reads the selected .csv file into a list of candlesticks objects and displays them on the chart
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	/// <returns></returns>
	private: System::Void openFileDialog_stockPicker_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e)
	{
		String^ filePath = openFileDialog_stockPicker->FileName; // get the selected file path from the file dialog
		listOfCandlesticks = ReadCandlestickDataFromFile(filePath); // reads candlestick data from the selected csv file into a list
		displayCandleStick(); // display the candlestick data on the chart
	}
	
	/// <summary>
	/// This method helps to read the candlestick data from a csv file and store it in a lits of type Candlestick
	/// </summary>
	/// <param name="filePath"></param>
	/// <returns></returns>
	private:List<Candlestick^>^ ReadCandlestickDataFromFile(String^ filePath) 
	{
		listOfCandlesticks = gcnew List<Candlestick^>(1024); // create a new list of type candlestick to hold candlestick data with a capacity of 1024
		listOfCandlesticks->Clear(); // clear the list to remove previous data
			
		if (File::Exists(filePath)) //checks if the filepath exists or not
		{
			StreamReader^ reader = gcnew StreamReader(filePath);
			String^ line = reader->ReadLine();
			while ((line = reader->ReadLine()) != nullptr) // read each file of line until the end
			{
				Candlestick^ candlestick = gcnew Candlestick(line); // create a new candlestick object using the data from the current line
				listOfCandlesticks->Add(candlestick); //add the candlestick object to the list
			}
			listOfCandlesticks->Reverse();
			reader->Close();
		}
		else
		{
			//handle the case where the file does not exist
			Console::WriteLine("CSV File does not exist!");
		}
			
		return listOfCandlesticks; // returns the list of candlesticks after the file has been read 
	}


    /// <summary>
	/// Filters candlestick data based on the selected date range and updates the DataGridView and Chart controls.
	/// </summary>
	/// <returns></returns>
	private:System::Void filterCandleStick()
	{
		List<Candlestick^>^ tempList = gcnew List<Candlestick^>(1024); // create a temporary list to hold filtered candlestick data
		for each (Candlestick ^ cs in listOfCandlesticks) // move through each candlestick in the original list
		{
			if (DateTime::Compare(cs->Date, dateTimePicker_StartDate->Value) >= 0 && DateTime::Compare(cs->Date, dateTimePicker_EndDate->Value) < 0) // check if the candlestick's date falls within the selected date range
			{
				tempList->Add(cs); // if yes, then add it to the temporary list
			}
		}
		boundlistOfCandlesticks = gcnew BindingList<Candlestick^>(tempList); // create a new binding list using the filtered data
		dataGridView_candlesticks->DataSource = boundlistOfCandlesticks; // update the datsource propety of the datagrid view to display the filtered candlesticks
		chart_OHLCV->DataSource = boundlistOfCandlesticks; // update datasource property of chart to display filtered candlesticks
		chart_OHLCV->DataBind(); // refresh chart source
	}

	/// <summary>
	/// This method helps to display the list of candlesticks on the chart
	/// </summary>
	/// <returns></returns>
	private:System::Void displayCandleStick()
	{
		boundlistOfCandlesticks = gcnew BindingList<Candlestick^>(listOfCandlesticks); // create a new binding list using the original list of candlesticks
		dataGridView_candlesticks->DataSource = boundlistOfCandlesticks; // update the datsource propety of the datagrid view to display the filtered candlesticks
		chart_OHLCV->DataSource = boundlistOfCandlesticks; // update datasource property of chart to display filtered candlesticks
		chart_OHLCV->DataBind(); // refresh chart source
	}

	/// <summary>
	/// This method is the event handler for when the button "Update" is clicked
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	/// <returns></returns>
	private: System::Void button_Update_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		filterCandleStick();
	}
};

}