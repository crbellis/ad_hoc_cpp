//This program reads the lines of a file, creates dynamically allocated arrays for each object within the file, sets the values of each object, and finally outputs the best seller of each obejct to a file.
//----------------------------------------------------------------------------//
// Name: Chase Bellisime                                                      //
// Student ID: 1026408                                                        //
// Assignment: #3                                                             //
//----------------------------------------------------------------------------//

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

//Symbolic constant for the number of information possible for each part
#define PARTINFO_CNT 15

using namespace std;

//Car class definition
class Car {
	public:
		Car();
		Car(const string& uBrand, const string& uModel, const int& uYear);
		string getBrand()const;
		string getModel()const;
		int getYear()const;
	private:
		string brand;
		string model;
		int year;	
};

//Car default constructor
Car::Car(){
	brand = "";
	model = "";
	year = 0;
}

//Car parameterized constructor
Car::Car(const string& uBrand, const string& uModel, const int& uYear) {
	brand = uBrand;
	model = uModel;
	year = uYear;
}

//Car getter functions
string Car::getBrand()const {
	return brand;
}

string Car::getModel()const {
	return model;
}

int Car::getYear()const {
	return year;
}

//Manufacturer class definition
class Manufacturer {
	public:
		Manufacturer();
		Manufacturer(const string& uManu);
		string getName()const;
	private:
		string name;
};

//Manufacturer default constructor
Manufacturer::Manufacturer() {
	name = "";
}

//Manufacturer setter function
Manufacturer::Manufacturer(const string& uManu) {
	name = uManu;
}

//Manufacturer getter functions
string Manufacturer::getName()const { 
	return name;
}

//Parts class definition
class Parts {
	public:
		Parts();
		Parts& setDescrip(const string& userDesc);
		Parts& setPrice(const float& uPrice);
		Parts&  setQuantSold(const int& uQuant);
		Parts& setManufacturer(const Manufacturer& uManufac);
		string getDescrip()const;
		float getPrice()const;
		int getQuantSold()const;
		string getManufacturer()const;
		void displayData(ofstream& fileOut)const;
	protected:
		float price;
		int quantSold;
		Manufacturer manuName;
		string description;
};

//Parts default constructor
Parts::Parts() { 
	price = 0.0f;
	quantSold = 0;
	description = "";
}

//Parts class setter functions
Parts& Parts::setDescrip(const string& userDesc) {
	description = userDesc;
	return *this;
}

Parts& Parts::setPrice(const float& uPrice) {
	price = uPrice;
	return *this;
}

Parts& Parts::setQuantSold(const int& uQuant) {
	quantSold = uQuant;
	return *this;
}

Parts& Parts::setManufacturer(const Manufacturer& uManufac) {
	manuName = uManufac;
	return *this;
}

//Parts getter functions
string Parts::getDescrip()const {
	return description;
}

float Parts::getPrice()const { 
	return price;
}

int Parts::getQuantSold()const {
	return quantSold;
}

string Parts::getManufacturer()const {
	return manuName.getName();
}

//Function to display Parts class data
void Parts::displayData(ofstream& fileOut)const {
	fileOut << "\tDescription: " << description << endl;
	fileOut << "\tPrice: " << price << endl << "\tManufacturer: " << manuName.getName() << endl;
	fileOut << "\tQtySold: " << quantSold << endl; 
}

//Brakes class definition, inheriting from the Parts class
class Brakes : public Parts {
	friend ostream& operator<<(ostream& out, const Brakes& uBrake);
	public:
		Brakes();
		Brakes& setCar(const Car& userCar);
		Brakes& setMaterial(const string& uMaterial);
	private:
		Car uCar;
		string material;
};

//Brakes class default constructor
Brakes::Brakes() {
	material = "";
}

//Setter functions
Brakes& Brakes::setCar(const Car& userCar) {
	uCar = userCar;
	return *this;
}

Brakes& Brakes::setMaterial(const string& uMaterial) {
	material = uMaterial;
	return *this;
}

//Lights class definition, inheriting from the Parts class
class Lights : public Parts {
	//Use of ostream operator<< as a friend for easy output
	friend ostream& operator<<(ostream& out, const Lights& uLights);
	public:
		Lights& setWatts(const int& uWatts);
		Lights& setCar(const Car& userCar);
		int getWatts()const;
		string getBrand()const;
		string getModel()const;
		int getYear()const;
	private:
		int watts;
		Car uCar;
};

//Lights setter functions for private data members 'watts' and 'uCar'
Lights& Lights::setWatts(const int& uWatts) {
	watts = uWatts;
	return *this;
}

Lights& Lights::setCar(const Car& userCar) {
	uCar = userCar;
	return *this;
}

//Lights class getter functions
int Lights::getWatts()const {
	return watts;
}

string Lights::getBrand()const {
	return uCar.getBrand();
}

string Lights::getModel()const {
	return uCar.getModel();
}

int Lights::getYear()const {
	return uCar.getYear();
}

//Oil class definition
class Oil : public Parts {
	//Use of ostream operator<< as a friend for easy output
	friend ostream& operator<<(ostream& out, const Oil& uOil);
	public:
		Oil();
		Oil& setWeight(const string& uWeight);
		Oil& setType(const string& uType);
		Oil& setQuarts(const int& uQuarts);
		string getWeight()const;
		string getType()const;
		int getQuarts()const;
	private: 
		string weight, type;
		int quarts;
};

//Oil class default constructor
Oil::Oil() {
	weight = "";
	type = "";
	quarts = 0;
}

//Oil class setter functions
Oil& Oil::setWeight(const string& uWeight) {
	weight = uWeight;
	return *this;
}

Oil& Oil::setType(const string& uType) {
	type = uType;
	return *this;
}

Oil& Oil::setQuarts(const int& uQuarts) {
	quarts = uQuarts;
	return *this;
}

//Oil class getter functions
string Oil::getWeight()const {
	return weight;
}

string Oil::getType()const {
	return type;
}

int Oil::getQuarts()const { 
	return quarts;
}

//Tires class definition
class Tires : public Parts {
	///Use of ostream operator<< as a friend for easy output
	friend ostream& operator<<(ostream& out, const Tires& uTires);
	public:
		Tires();
		Tires& setSize(const string& uSize);
		Tires& setWarranty(const int& uWarranty);
	private:
		string size;
		int warranty;
};

//Tires default constructor
Tires::Tires() {
	size = "";
	warranty = 0;
}

//Tires setter functions 
Tires& Tires::setSize(const string& uSize) {
	size = uSize;
	return *this;
}

Tires& Tires::setWarranty(const int& uWarranty) {
	warranty = uWarranty;
	return *this;
}

//Global function prototypess
void parseLineToTokens(string lineText, string tokens[]);
void lineCount(ifstream& fileIn, int& count);
void objTypeCount(ifstream& fileIn, int& oCount, int& bCount, int& tCount, int& liCount);
void dataScrape(ifstream& fileIn, Oil uOil[], Brakes uBrakes[], Tires uTires[], Lights uLights[]);
template <class T> void bestSellerCalc(ofstream& fileOut, const T data[], const int& max);


int main() {
	//Initializing and declaring counter variables for each of the objects anticipating to be created
	//line count
    int lcount = 0;
	//stores the number of each object for dynamically allocated arrays
	int oilCount = 0, brakeCount = 0, tireCount = 0, lightCount = 0;


	//Opening the file "Parts_List.txt"
	ifstream fileIn("Parts_List.txt");
	if (fileIn.is_open()) {
		//Opening/creating a file for output later
		ofstream fileOut("Best_Sellers.txt");
		//Function to count the lines in the file
		lineCount(fileIn, lcount);

		//Function which counts the number of each objects within the fileIn object
		objTypeCount(fileIn, oilCount, brakeCount, tireCount, lightCount);

		//Declaring arrays of the correc size for each object
		Oil *uOil = new Oil[oilCount];
		Brakes *uBrakes = new Brakes[brakeCount];
		Tires *uTires = new Tires[tireCount];
		Lights *uLights = new Lights[lightCount];

		//Function to populate the arrays with the appropriate data
		dataScrape(fileIn, uOil, uBrakes, uTires, uLights);
		if (fileOut.is_open()) {
			//Writes and calculates the best selling item for each object
			fileOut << "** Brakes **" << endl;
			bestSellerCalc(fileOut, uBrakes, brakeCount);
			fileOut << "** Lights **" << endl;
			bestSellerCalc(fileOut, uLights, lightCount);
			fileOut << "** Oil **" << endl;
			bestSellerCalc(fileOut, uOil, oilCount);
			fileOut << "** Tires **" << endl;
			bestSellerCalc(fileOut, uTires, tireCount);
			
			//Closing the fileOut file
			fileOut.close();
		}

		//Closing the fileIn file
		fileIn.close();

		//Deleting dynamically allocated arrays
		delete [] uBrakes;
		delete [] uLights;
		delete [] uOil;
		delete [] uTires;
	}
	else {
		cerr << "Error opening file. Please try again." << endl;
		exit(1);
	}
}

// Parse a line of text into tokens and store them in an array of strings
void parseLineToTokens(string lineText, string tokens[]) {
	int end, start;
	start = -2;
	for (int j = 0; j < PARTINFO_CNT; j++) {
		start = start + 3;
		end = lineText.find('"', start);
		tokens[j] = lineText.substr(start, end - start);
		start = end;
	}
}

//Counts the lines in the file passed as a parameter, stores the number of lines in the count variable which is passed by reference
void lineCount(ifstream& fileIn, int& count) { 
    fileIn.clear();
	fileIn.seekg(0, ios::beg);
	string tempString;
    if(fileIn.is_open()) {
        while(getline(fileIn, tempString)) {
            count++;
        }
    }
}

//Counts the number of each type of object is in the file
void objTypeCount(ifstream& fileIn, int& oCount, int& bCount, int& tCount, int& liCount) {
	fileIn.clear();
	fileIn.seekg(0, ios::beg);
	string tempString;
	string *tokens;
	getline(fileIn, tempString);
	tokens = new string [PARTINFO_CNT];
	//This loops until the the end of file is reached
	while(getline(fileIn, tempString)) {
		//Parsing the lines into indiviual tokens
		parseLineToTokens(tempString, tokens);
		//if statements to test each token if it begins with test condition
			if (tokens[0] == "Oil") {
				oCount++;				}
			else if(tokens[0] == "Brakes") {
				bCount++;
			}
			else if(tokens[0] == "Tires") {
				tCount++;
			}
			else
				liCount++;
		}
	delete [] tokens;
}

//This function passes the arrays of objects and updates them with the appropriate values for each data member
void dataScrape(ifstream& fileIn, Oil uOil[], Brakes uBrakes[], Tires uTires[], Lights uLights[]) {
	fileIn.clear();
	fileIn.seekg(0, ios::beg);
	string tempString;
	string *tokens;
	int i = 0, j = 0, k = 0, l = 0;

	//Gets the first line
	getline(fileIn, tempString);
	tokens = new string [PARTINFO_CNT];

	//This loop loops through each line and if the beginning of the line begins with the object type, the consecutive values are stored in the passed array
	while(getline(fileIn, tempString)) { 
		parseLineToTokens(tempString, tokens);
		if (tokens[0] == "Oil") {
			Manufacturer temp(tokens[3]);
			uOil[i].setDescrip(tokens[1]).setPrice(stof(tokens[2])).setQuantSold(stoi(tokens[4])).setManufacturer(temp);
			uOil[i].setWeight(tokens[10]).setType(tokens[11]).setQuarts(stoi(tokens[12]));
			i++;
		}
		else if (tokens[0] == "Brakes") {
			Manufacturer temp(tokens[3]);
			Car carTemp(tokens[5], tokens[6], stoi(tokens[7]));
			uBrakes[j].setDescrip(tokens[1]).setPrice(stof(tokens[2])).setQuantSold(stoi(tokens[4])).setManufacturer(temp);
			uBrakes[j].setCar(carTemp).setMaterial(tokens[8]);
			j++;
		}
		else if (tokens[0] == "Tires") {
			Manufacturer temp(tokens[3]);
			uTires[k].setDescrip(tokens[1]).setPrice(stof(tokens[2])).setQuantSold(stoi(tokens[4])).setManufacturer(temp);
			uTires[k].setSize(tokens[13]).setWarranty(stoi(tokens[14]));
			k++;
		}
		else if (tokens[0] == "Lights") {
			Manufacturer temp(tokens[3]);
			Car carTemp(tokens[5], tokens[6], stoi(tokens[7]));
			uLights[l].setDescrip(tokens[1]).setPrice(stof(tokens[2])).setQuantSold(stoi(tokens[4])).setManufacturer(temp);
			uLights[l].setCar(carTemp).setWatts(stoi(tokens[9]));
			l++;
		}
	}	
}

//Function template to which takes the fileOut object, one of the objects and the "max" number of said object. It then calculates which is the best selling item and writes that item to the file
template <class T>
void bestSellerCalc(ofstream& fileOut, const T data[], const int& max) {
	int index = 0;
	float maxRev = data[0].getPrice() * data[0].getQuantSold();
	for (int i = 0; i < max; i++){
		if ((data[i].getPrice() * data[i].getQuantSold()) > maxRev){
			maxRev = (data[i].getPrice() * data[i].getQuantSold());
			index = i;
		}
	}
	data[index].displayData(fileOut);
	fileOut << data[index] << endl;
}

//Overloaded operator<< to output the values of each object
ostream& operator<<(ostream& out, const Brakes& uBrake) {
	out << "\tCar: " << endl << "\t\tBrand: " << uBrake.uCar.getBrand() << endl << "\t\tModel: " << uBrake.uCar.getModel() << endl; 
	out << "\t\tYear: " << uBrake.uCar.getYear() << endl << "\tMaterial: " << uBrake.material << endl;
	return out;
}

ostream& operator<<(ostream& out, const Lights& uLights) {
	out << "\tCar: " << endl << "\t\tBrand: " << uLights.uCar.getBrand() << endl << "\t\tModel: " << uLights.uCar.getModel() << endl; 
	out << "\t\tYear: " << uLights.uCar.getYear() << endl << "\tWatts: " << uLights.watts << endl;
	return out;
}

ostream& operator<<(ostream& out, const Tires& uTires) {
	out << "\tSize: " << uTires.size << endl << "\tWarranty: " << uTires.warranty << endl;
	return out;
}

ostream& operator<<(ostream& out, const Oil& uOil) {
	out << "\tWeight: " << uOil.weight << endl << "\tType: " << uOil.type << endl << "\tQuarts: " << uOil.quarts << endl;
	return out;
}
