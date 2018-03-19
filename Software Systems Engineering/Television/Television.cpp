/*
Paige Eckstein
Software Systems Engineering
3/6/2018

Television class takes information from the user for the model number, screen
size, and price of a telvision set.

It implements exception handling to ensure the model number is less than
four digits, that the screen size is less than 70 but greater than 12, and that
the price is less than 5,000.

If an exception is caught for the above conditions, all the variables will be
set to 0.

The Television class also overloads the insertion and extraction operators.

Compilation:
g++ Television.cpp televisionTest.cpp

Execution:
a.exe

No requirements beyond standard library.
 */
#include "Television.h"

/**
 * [Television::Television Default constructor that initializes all variables
 * to 0.]
 */
Television::Television()
{
  model = "0";
  size = 0;
  price = 0;
}

/**
 * [Television::Television Non-default constructor that requires a model number
 * in the form of a string, the screen size in the form of an integer, and a
 * price in the form of a double.]
 * @param _model [String: Model Number of Television]
 * @param _size  [Integer: Screensize of Television]
 * @param _price [Double: Price of the Television]
 */
Television::Television(std::string _model, int _size, double _price)
{
  //validate information and set internal fields to external veriables
  //either set to given variables if passes Validation
  //or set all to 0 if fails validation
  try
  {
    validate(_model, _size, _price);
    model = _model;
    size = _size;
    price = _price;
  }
  catch (int e)
  {
    if(e == 1)
    {
      std::cout<<"Model number must be four or less characters."<<std::endl;
    }
    else if(e == 2)
    {
      std::cout<<"Size must be greater than 12 and less than 70."<<std::endl;
    }
    else if(e == 3)
    {
      std::cout<<"Price must be less than $5000.00"<<std::endl;
    }
    model = "0";
    size = 0;
    price = 0;
  }
}

/**
 * [Television::validate Validate television fields given the specifications
 * that model number must be at most four digits, size must be between 12 and 70,
 * and price must be less than 5000.]
 * @param model [String: Model number of television to validate]
 * @param size  [Int: Screensize of television to validate]
 * @param price [Double: price of television to validate]
 */
void Television::validate(std::string model, int size, double price)
{
  if(model.length()>4)
  {
    throw 1;
  }
  if(size < 12 || size > 70)
  {
    throw 2;
  }
  if(price > 5000)
  {
    throw 3;
  }
}

/**
 * [Television::setModel Setter for television model number]
 * @param _model [String: model number of television]
 */
void Television::setModel(std::string _model)
{
  model = _model;
}

/**
 * [Television::setSize setter for television screen size]
 * @param _size [Int: screensize of television]
 */
void Television::setSize(int _size)
{
  size = _size;
}

/**
 * [Television::setPrice Setter for television price]
 * @param _price [Double: Price of television]
 */
void Television::setPrice(double _price)
{
  price = _price;
}

/**
 * [Insertion Operator overload]
 * @param in [istream]
 * @param tv  [Television object]
 */
std::istream &operator >> (std::istream& in, Television& tv)
{
  std::cout<<"Enter the model number: "<<std::endl;
  in >> tv.model;
  std::cout<<"Enter the screen size: "<<std::endl;
  in >> tv.size;
  std::cout<<"Enter the price: "<<std::endl;
  in >> tv.price;

  //validate information about inputting
  try
  {
    tv.validate(tv.model,tv.size, tv.price);
  }
  catch (int e)
  {
    if(e == 1)
    {
      std::cout<<"Model number must be four or less characters."<<std::endl;
    }
    else if(e == 2)
    {
      std::cout<<"Size must be greater than 12 and less than 70."<<std::endl;
    }
    else if(e == 3)
    {
      std::cout<<"Price must be less than $5000.00"<<std::endl;
    }
    tv.setModel("0");
    tv.setSize(0);
    tv.setPrice(0);
  }
}

/**
 * [Extraction operator overload]
 * @param out [ostream]
 * @param tv [Television object]
 */
std::ostream &operator << (std::ostream& out, Television& tv)
{
  out << "Model Number: " << tv.model<<std::endl;
  out << "Screen Size: " << tv.size<<std::endl;
  out << "Total Price: " << tv.price<<std::endl;
}
