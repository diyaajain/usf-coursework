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


namespace WindowsFormsApp_COP_4365
{
    public partial class Form_Project_1 : Form
    {
        private List<Candlestick> candlesticks = null; // list of all candlesticks read from file
        private List<Candlestick> filterCandlesticks = null; // list of all date filtered candlestick
        private BindingList<Candlestick> boundCandlesticks = null; // binding list of candlesticks bound to datagridview
        private DateTime startDate = DateTime.Now; // variable to store start date
        private DateTime endDate = DateTime.Now; // variable to store end date

        /// <summary>
        /// Form constructor
        /// </summary>
        public Form_Project_1()
        {
            InitializeComponent();
            candlesticks = new List<Candlestick>(1024); // construct a list of candlesticks with a capacity of 1024
        }

        /// <summary>
        /// Event handler for the load ticker button click event
        /// opens the file dialog when the button is clicked
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button_openFile_Click(object sender, EventArgs e)
        {
            Text = "Opening File..."; // change the text of the window form on button click
            openFileDialog_stockPick.ShowDialog(); // display the file dialog on button click
        }

        /// <summary>
        /// Event handler for the "Update" button click event
        /// updates the displayed data to be within the specified date range
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button_Update_Click(object sender, EventArgs e)
        {
            if ((candlesticks.Count != 0) & (startDate <= endDate)) // Check if there is data to filter and if the dates are in a valid format (start date is before or equal to end date)
            {
                filterList(); // function call to filter the data of candlesticks
                displayCandlesticks(); // function call to display the candlesticks
            }
        }

        /// <summary>
        /// Event handler for the "FileOk" event of the open file dialog.
        /// opens the selected file, reads data from the file into a list.
        /// binds and displays the data to the data grid view and chart
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void openFileDialog_stockPick_FileOk(object sender, CancelEventArgs e)
        {
            goReadFile(); // read the file from the selected file
            filterList(); // filters the llist based on the specified date range
            displayCandlesticks(); // display the filtered candlesticks
        }

        /// <summary>
        /// Reads csv data from the specified file, stores it in a candlestick list, returns the list
        /// </summary>
        /// <param name="filename">"Name of the file"</param>
        /// <returns></returns>
        private List<Candlestick> goReadFile(string filename)
        {
            this.Text = Path.GetFileName(filename); // set the title of the form to the name of the file
            const string referenceString = "Date,Open,High,Low,Close,Adj Close,Volume"; // define a reference string to check the format of the CSV file

            List<Candlestick> list = new List<Candlestick>(); // create a new list to store candlestick data
            using (StreamReader sr = new StreamReader(filename)) // read data from a file
            {
                string line = sr.ReadLine();
                if (line == referenceString) // check if the first line matches the reference string
                {
                    while ((line = sr.ReadLine()) != null) // read each line of the file and create a new candlestick object
                    {
                        Candlestick cs = new Candlestick(line);
                        list.Add(cs);
                    }
                    list.Reverse(); // reverse the list to display to data in descending order
                }
                else
                { 
                    Text = "Bad File: " + Path.GetFileName(filename); // display message if the file format is incorrect
                }
                dateTimePicker_endDate.Value = endDate = list.First().date;
                dateTimePicker_startDate.Value = startDate = list.Last().date;
            }
            return list;
        }

        /// <summary>
        /// Overload of the goReadFile method without parameters.
        /// Reads data from the currently selected file in the file dialog,
        /// stores it in the candlesticks list, and binds it to the DataGridView.
        /// </summary>
        private void goReadFile()
        {
            candlesticks = goReadFile(openFileDialog_stockPick.FileName); // read data from the selected file
            boundCandlesticks = new BindingList<Candlestick>(candlesticks); // create a new binding list and bind it to candlestick list
        }

        /// <summary>
        /// Filters the candlesticks withinn a specified date range from the provided dates
        /// </summary>
        /// <param name="list">The list of candlesticks containing all data.</param>
        /// <param name="start">The start date of the desired date range.</param>
        /// <param name="end">The end date of the desired date range.</param>
        /// <returns></returns>
        private List<Candlestick> filterList(List<Candlestick> list, DateTime start, DateTime end)
        {
            List<Candlestick> filter = new List<Candlestick>(list.Count); // initialize a new list to store filtered candlesticks
            foreach (Candlestick cs in list) // iterate through list of candlesticks
            {
                if ((cs.date >= start) & (cs.date <= end)) // check if candlesticks date is within the specified date range
                { 
                    filter.Add(cs); // if yes, add the candlestick to the filtered list
                }
            }
            return filter;
        }

        /// <summary>
        /// Overload of the filterList method that filters candlesticks within the specified date range.
        /// </summary>
        private void filterList()
        {
            filterCandlesticks = filterList(candlesticks, startDate, endDate); // filter candlesticks within the specified date range
            boundCandlesticks = new BindingList<Candlestick>(filterCandlesticks); // create a new binding list of filtered candlesticks
        }

        /// <summary>
        /// Method to display candlestick data by binding it to the DataGridView and the chart.
        /// </summary>
        /// <param name="bindList">The binding list of candlesticks to be displayed.</param>
        private void displayCandlesticks(BindingList<Candlestick> bindList)
        {
            dataGridView_Candlestick.DataSource = bindList; // bind the candlestick data to the datagridview
            normalizeChart();
            chart_OHLCV.DataSource = bindList; // bind the candlestick data to the chart
            chart_OHLCV.DataBind();
        }

        /// <summary>
        /// Overload of the displayCandlesticks method to display candlestick data without passing a binding list explicitly.
        /// </summary>
        private void displayCandlesticks()
        {
            displayCandlesticks(boundCandlesticks); // Call the displayCandlesticks method with the bound candlestick list
        }

        /// <summary>
        /// Method to normalize the chart by adjusting the y-axis range based on the data in the binding list.
        /// </summary>
        /// <param name="bindList">The binding list of candlesticks containing the data to be displayed on the chart.</param>
        private void normalizeChart(BindingList<Candlestick> bindList)
        {
            decimal min = bindList.First().low, max = 0; 
            foreach (Candlestick c in bindList) // Iterate through the candlesticks to find the minimum and maximum values
            {
                if (c.low < min) { min = c.low; }
                if (c.high > max) { max = c.high; }
            }
            // Adjust the y-axis range with a small margin
            chart_OHLCV.ChartAreas["ChartArea_OHLC"].AxisY.Minimum = Math.Round(Decimal.ToDouble(min) * 0.98, 2);
            chart_OHLCV.ChartAreas["ChartArea_OHLC"].AxisY.Maximum = Math.Round(Decimal.ToDouble(max) * 1.02, 2);
        }

        /// <summary>
        /// Overload of the normalizeChart method, which normalizes the chart using the bound candlesticks.
        /// </summary>
        private void normalizeChart()
        {
            normalizeChart(boundCandlesticks); // Calls the normalizeChart method with the bound candlesticks
        }

        /// <summary>
        /// Event handler for the ValueChanged event of the start date picker.
        /// Updates the startDate variable when the value of the picker changes.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void dateTimePicker_startDate_ValueChanged(object sender, EventArgs e)
        {
            startDate = dateTimePicker_startDate.Value;
        }

        /// <summary>
        /// Event handler for the ValueChanged event of the end date picker.
        /// Updates the endDate variable when the value of the picker changes.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void dateTimePicker_endDate_ValueChanged(object sender, EventArgs e)
        {
            endDate = dateTimePicker_endDate.Value;
        }

        private void dataGridView_Candlestick_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }
    }
}
