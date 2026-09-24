using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.DataVisualization.Charting;

namespace WindowsFormsApp_COP_4365
{
    public partial class Form_StockViewer : Form
    {
        //List of all candlesticks read from file
        private List<Candlestick> candlesticks = null;
        //Binding list of candlesticks bound to DataGridView 
        private BindingList<Candlestick> boundCandlesticks = null;
        //Variable to store starting date
        private DateTime startDate = new DateTime(2019, 1, 1);
        //Variable to store ending date
        private DateTime endDate = DateTime.Now;

        /// <summary>
        /// Base Form Constructor
        /// </summary>
        public Form_StockViewer()
        {
            InitializeComponent();

            //Construct list of candlesticks with size 1024
            candlesticks = new List<Candlestick>(1024);
            //Pre-set the date time picker to the specified start and current time end
            dateTimePicker_startDate.Value = startDate;
            dateTimePicker_endDate.Value = endDate;
        }

        /// <summary>
        /// Child Form Constructor
        /// </summary>
        /// <param name="stockPath">"File path of the child form (2 - n file selection)"</param>
        /// <param name="start">"Starting date of parent passed to child"</param>
        /// <param name="end">"Ending date of parent passed to child"</param>
        public Form_StockViewer(string stockPath, DateTime start, DateTime end)
        {
            InitializeComponent();

            //Set date from parent form
            dateTimePicker_startDate.Value = startDate = start;
            dateTimePicker_endDate.Value = endDate = end;
            //Read file of child
            candlesticks = goReadFile(stockPath);
            //Filter list of child
            filterList();
            //Display data of child
            displayCandlesticks();
        }

        /// <summary>
        /// Open stock file button event to open file explorer on button click
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button_openFile_Click(object sender, EventArgs e)
        {
            //On button click change text of window form
            Text = "Opening File...";
            //On button click display the file explorer
            openFileDialog_stockPick.ShowDialog();
        }

        /// <summary>
        /// Update button event to update displayed date to be within specified date range
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button_Update_Click(object sender, EventArgs e)
        {
            //Check if no data to filter or if dates are invalid format (start date is after end date)
            if ((candlesticks.Count != 0) & (startDate <= endDate))
            {
                //Filter list
                filterList();
                //Display data
                displayCandlesticks();
            }
        }

        /// <summary>
        /// Open file dialog event to open selected file,
        /// Then read data from file into list and pre-set date,
        /// Lastly bind and display data to data grid and chart
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void openFileDialog_stockPick_FileOk(object sender, CancelEventArgs e)
        {
            //Store number of files selected
            int n = openFileDialog_stockPick.FileNames.Count();
            //Go through each selected filename in the open file dialog
            for (int i = 0; i < n; ++i)
            {
                //Get the pathname of current file
                string pathName = openFileDialog_stockPick.FileNames[i];
                string ticker = Path.GetFileNameWithoutExtension(pathName);

                //Create form to view
                Form_StockViewer form_StockViewer;
                //If first form then set to parent
                if (i == 0)
                {
                    //Read the file and display the stock
                    form_StockViewer = this;
                    readAndDisplayStock();
                    form_StockViewer.Text = "Parent: " + ticker;
                }
                else
                {
                    //Instantiate new form using parameter constructor
                    form_StockViewer = new Form_StockViewer(pathName, startDate, endDate);
                    form_StockViewer.Text = "Child: " + ticker;
                }

                //Display the new form
                form_StockViewer.Show();
                form_StockViewer.BringToFront();
            }
        }

        /// <summary>
        /// Method that reads csv data from passed file, store in candlestick list, then return list
        /// </summary>
        /// <param name="filename">"Name of the file"</param>
        /// <returns></returns>
        private List<Candlestick> goReadFile(string filename)
        {
            //Display filename
            this.Text = Path.GetFileName(filename);
            //Initialize string for reference to starting line of opened CSV file
            const string referenceString = "Date,Open,High,Low,Close,Adj Close,Volume";
            
            //Construct list
            List<Candlestick> list = new List<Candlestick>();
            //Pass file path and filename to StreamReader constructor
            using (StreamReader sr = new StreamReader(filename))
            {
                //Read first line from new file
                string line = sr.ReadLine();
                //If starting line of file equals reference line: OK
                if (line == referenceString)
                {
                    //Read until end of file
                    while((line = sr.ReadLine()) != null)
                    {
                        //Instantiate Candlestick represented by string
                        SmartCandlestick cs = new SmartCandlestick(line);
                        list.Add(cs);
                    }
                }
                //Changes form text to error representing bad file opened
                else
                { Text = "Bad File: " + Path.GetFileName(filename); }
            }

            return list;
        }

        /// <summary>
        /// Overload of goReadFile
        /// </summary>
        private void goReadFile()
        {
            //Go read data from file into candlesticks list
            candlesticks = goReadFile(openFileDialog_stockPick.FileName);
            //Bind list to binding list
            boundCandlesticks = new BindingList<Candlestick>(candlesticks);
        }

        /// <summary>
        /// Method that parses through candlesticks,
        /// Add candlesticks within date range from candlestick list into new list,
        /// Return filtered list
        /// </summary>
        /// <param name="list">"Candlesticks list containing all data"</param>
        /// <returns></returns>
        private List<Candlestick> filterList(List<Candlestick> list, DateTime start, DateTime end)
        {
            List<Candlestick> filter = new List<Candlestick>(list.Count);
            //Iterate through each candlestick in list
            foreach (Candlestick cs in list) 
            {
                //Check if date is inclusively within range and store in filtered list
                if ((cs.date >= start) & (cs.date <= end))
                { filter.Add(cs); }
            }
            return filter;
        }

        /// <summary>
        /// Overload of filterList method
        /// </summary>
        private void filterList()
        {
            //Go filter the candlesticks list and place in temp variable called filter
            List<Candlestick> filterCandlesticks = filterList(candlesticks, startDate, endDate);
            //Bind filtered list to binding list
            boundCandlesticks = new BindingList<Candlestick>(filterCandlesticks);
            //Update Combo Box
            updateComboBox();
        }

        /// <summary>
        /// Method that displays the data to a chart after normalizing the Y axis
        /// </summary>
        /// <param name="bindList">"Binding list containing the data that needs to be displayed"</param>
        private void displayCandlesticks(BindingList<Candlestick> bindList)
        {
            //Dyanmically set the Y Axis of the chart to normalize chart size
            normalizeChart();

            //Clear annotations for new chart
            chart_OHLCV.Annotations.Clear();

            //Display data by binding list of data to chart
            chart_OHLCV.DataSource = bindList;
            chart_OHLCV.DataBind();
        }

        /// <summary>
        /// Overload of displayCandlesticks
        /// </summary>
        private void displayCandlesticks()
        {
            //Go set the data source of grid and chart to binding list and normalize chart
            displayCandlesticks(boundCandlesticks);
        }

        /// <summary>
        /// Normalizes the chart by finding the lowest and highest value in total data
        /// Sets the Y axis to 2% more and less than the highest and lowest value respectively
        /// </summary>
        /// <param name="bindList">"Binding list containing the data that needs to be displayed"</param>
        private void normalizeChart(BindingList<Candlestick> bindList)
        {
            //Set starting conditions for min and max variables
            decimal min = 1000000000, max = 0;
            //Iterate through each candle stick in list
            foreach (Candlestick c in bindList) 
            {
                //Check for greatest value (Ymax) and lowest value (Ymin)
                if (c.low < min) { min = c.low; }
                if (c.high > max) { max = c.high; }
            }
            //Set the Y axis of the chart area to (+-)2% of the ranges rounded to 2 decimal places
            chart_OHLCV.ChartAreas["ChartArea_OHLC"].AxisY.Minimum = Math.Floor(Decimal.ToDouble(min) * 0.98);
            chart_OHLCV.ChartAreas["ChartArea_OHLC"].AxisY.Maximum = Math.Ceiling(Decimal.ToDouble(max) * 1.02);
        }

        /// <summary>
        /// Overload of normalizeChart
        /// </summary>
        private void normalizeChart()
        {
            //Go find the minimum and maximum low and high values from all of the candlesticks
            normalizeChart(boundCandlesticks);
        }

        /// <summary>
        /// Updates the items in the comboBox_Patterns based on the specified binding list of Candlestick objects.
        /// </summary>
        /// <param name="bindList">The binding list of Candlestick objects to update the combo box with.</param>
        private void updateComboBox(BindingList<Candlestick> bindList)
        {
            // Check if the binding list is not empty.
            if (bindList.Count != 0)
            {
                // Clear existing items in the comboBox_Patterns.
                comboBox_Patterns.Items.Clear();

                // Get the first SmartCandlestick object from the binding list.
                SmartCandlestick scs = (SmartCandlestick)bindList[0];

                // Iterate through each key in the SmartCandlestick's pattern dictionary.
                foreach (string key in scs.Dictionary_Pattern.Keys)
                {
                    // Add the key (pattern name) to the comboBox_Patterns.
                    comboBox_Patterns.Items.Add(key);
                }
            }
        }


        /// <summary>
        /// Overload of updateComboBox
        /// </summary>
        private void updateComboBox()
        {
            updateComboBox(boundCandlesticks);
        }

        /// <summary>
        /// Reads the data from the file, filters the list by dates, and displays data to chart
        /// </summary>
        private void readAndDisplayStock()
        {
            //Read file
            goReadFile();
            //Filter list
            filterList();
            //Display data
            displayCandlesticks();
        }

        /// <summary>
        /// Date time picker event to update starting date when value of picker changed
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void dateTimePicker_startDate_ValueChanged(object sender, EventArgs e)
        {
            //Store starting date
            startDate = dateTimePicker_startDate.Value;
        }

        /// <summary>
        /// Date time picker event to update ending date when value of picker changed
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void dateTimePicker_endDate_ValueChanged(object sender, EventArgs e)
        {
            //Store ending date
            endDate = dateTimePicker_endDate.Value;
        }

        private void Form_Project_2_Load(object sender, EventArgs e)
        {

        }

        /// <summary>
        /// Event handler for the comboBox_Patterns_SelectedIndexChanged event.
        /// Adds arrow annotations to the chart based on selected patterns and candlestick data points.
        /// </summary>
        /// <param name="sender">The object that triggered the event.</param>
        /// <param name="e">The event arguments.</param>
        private void comboBox_Patterns_SelectedIndexChanged(object sender, EventArgs e)
        {
            // Clear any existing annotations on the chart.
            chart_OHLCV.Annotations.Clear();

            // Iterate through each bound candlestick in the list.
            for (int i = 0; i < boundCandlesticks.Count; i++)
            {
                // Retrieve the SmartCandlestick object at the current index.
                SmartCandlestick scs = (SmartCandlestick)boundCandlesticks[i];

                // Retrieve the data point at the current index from the chart's series.
                DataPoint dataPoint = chart_OHLCV.Series[0].Points[i];

                // Check if the SmartCandlestick object is not null.
                if (scs != null)
                {
                    // Create a new ArrowAnnotation object.
                    ArrowAnnotation arrow = new ArrowAnnotation();

                    // Set the X and Y axes for the arrow annotation.
                    arrow.AxisX = chart_OHLCV.ChartAreas[0].AxisX;
                    arrow.AxisY = chart_OHLCV.ChartAreas[0].AxisY;

                    // Set the width and height of the arrow.
                    arrow.Width = 1.0;
                    arrow.Height = 4.0;

                    // Check if the selected pattern exists in the SmartCandlestick's pattern dictionary.
                    if (scs.Dictionary_Pattern[comboBox_Patterns.SelectedItem.ToString()])
                    {
                        // Set the data point as the anchor point for the arrow annotation.
                        arrow.SetAnchor(dataPoint);

                        // Add the arrow annotation to the chart's annotations collection.
                        chart_OHLCV.Annotations.Add(arrow);
                    }
                }
            }
        }


        private void label_startDate_Click(object sender, EventArgs e)
        {

        }
    }
}