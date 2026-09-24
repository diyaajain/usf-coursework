#pragma once 
using namespace System; 
using namespace System::Globalization; 
using namespace System::Collections::Generic; 
using namespace System::IO; 

namespace CppCLRWinFormsProject
{
	public ref class Candlestick // public class
	{
	public:
		property DateTime Date; // Declares a property called Date of type DateTime
		property double Open; // Declares a property called Open of type double
		property double High; // Declares a property called High of type double
		property double Low; // Declares a property called Low of type double
		property double Close; // Declares a property called Close of type double
		property double AdjClose; // Declares a property called AdjClose of type double
		property UInt64 Volume; // Declares a property called Volume of type UInt64

		//Constructor
		Candlestick(String^ csvLine); 

		//Other methods and members can be added here
	};
};
