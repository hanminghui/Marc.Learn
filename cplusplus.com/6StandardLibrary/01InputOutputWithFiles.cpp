// Input / output with files
// --------------------------------------------------------------------------------
/*
C++ provides the following classes to 
perform output and input of characters to/from files:
	ofstream:	Stream class to write on files
	ifstream:	Stream class to read from files
	fstream:	Stream class to both read and write from/to files
These classes are derived directly or indirectly from trhe classes istream and ostream.
*/

// basic file operations
// ------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main ()
{
	ofstream myfile1;	// a stream
	myfile1.open ("myfile1.txt");
	myfile1 << "Writing this to a file.\n";
	myfile1.close();

// Open a file
// ------------------------------------------------------------
// stream_name.open (file_name, mode);
// any input or output operation performed on the stream object 
// will be applied to the physical file associated to it.

/* mode, optional parameter with a combination of the following flags:
	ios::in		Open for input operations.
	ios::out	Open for output operations.
	ios::binary	Open in binary mode.
	ios::ate	Set the initial position at the end of the file.
				If flag not set, the initial position is the beginning of the file.
	ios::app	All output operations are performed at the end of the file, 
				appending the content to the current content of the file.
	ios::trunc	If the file is opened for output operations and it already existed, 
				its previous content is deleted and replaced by the new one.
All the flags can be combined using the bitwise operator OR | .
Three class: ifstream, ofstream, fstream
*/
	// combine object construction and stream opening in a single statement:
	ofstream myfile2 { "myfile2.bin", ios::out | ios::app | ios::binary};
	// check if a file stream was successful opening a file:
	if (myfile2.is_open())
	{
		// OK, proceed
		myfile2 << "Myfile2 is opened.\n";
		myfile2.close();
	}
	else
		cout << "Unable to open file" << endl;

// Closing a file
// ------------------------------------------------------------
// stream_name.close();
// once this member function is called, the stream obejct can be re-used
// and the file is available again to be opened by other processes.
// In case that an object is destroyed while still associated with an open file, 
// the destructor automatically calls the member function close.

// Text files
// ------------------------------------------------------------
	string line;
	ifstream myfile3 ("01test.txt");
	if (myfile3.is_open())
	{
		while( getline (myfile3,line))	// return value of geline(), bool
		{
			cout << line << endl;
		}
		myfile3.close();
	}
	else cout << "Unable to open file" << endl;

// Checking state flags
// ------------------------------------------------------------
// The following member functions exist to check for specific states of a stream
// all of them return a bool value
/*
bad()
	returns true if a reading or writing operation fails
fail()
	returns true in the same cases as bad(), 
	but also in the case that a format error happens
eof()
	returns true if a file open for reading has reached the end
good()
	It is the most generic flag:
	it returns false in the same cases in which calling any of the previous functions 
	would return true.
	Note that good and bad are not exact opposites, good checks more states flags at once
clear()
	this member function can be used to reset the state flags.
*/

// get and put stream positioning
// ------------------------------------------------------------
// All i/o streams objects keep internally -at least- one internal position
// get position / put position

// tellg() and tellp()
// return a value of the member type streampos, 
// which is a type representing the current get position or the put position
// seekg() and seekp()
// These functions allow to change the location of the get and put positions.
// Both functions are overloaded with two different prototypes:
// seekg (position);					seekp (position);
// seekg (offset, direction);					seekp (offset, direction);
// position is type streampos, ios::pos_type
// offset is type streamoff, ios::off_type
// direction is an enumerated type: ios::beg, ios::cur, ios::end
// beginning of the stream, the current position, and the end of the stream

// obtain file size
	streampos begin, end;	// type streampos
	ifstream myfile4 ("01test.txt", ios::binary);
	begin = myfile4.tellg();
	myfile4.seekg (0, ios::end);
	end = myfile4.tellg();
	myfile4.close();
	cout << "the size of 01test.txt is: " << (end-begin) << " bytes." << endl;

// Binary files
// ------------------------------------------------------------
// File streams include two member functions specifically designed 
// to read and write binary data sequentially: 
// write (memory_block, size);
// read (memory_block, size);

// reading an entire binary file
	streampos size;
	char * memblock;
	ifstream file ("01test.txt", ios::in | ios::binary | ios::ate);
	// ios::ate means the get pointer will be positioned at the end of the file.
	if (file.is_open())
	{
		size = file.tellg();	// call tellg directly obtain the size of the file
		memblock = new char [size];
		file.seekg (0, ios::beg);
		file.read (memblock, size);
		file.close();

		cout << "the entire file content is in memory" << endl;
		cout << memblock << endl;

		delete[] memblock;
	}
	else
		cout << "Unable to open file" << endl;

// Buffers and Synchronization
// ------------------------------------------------------------
// When we operate with file streams, 
// these are associated to an internal buffer object of type streambuf.

	return 0;
}
