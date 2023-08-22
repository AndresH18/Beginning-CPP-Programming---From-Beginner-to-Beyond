# IO and Streams

## File, Streams and IO

- C++ uses streams as an interface between the program and input/output devices
- Independent of the actual device
- Sequence of bytes
- Input stream provides data to the program
- Output stream receives data from the program

**Common Header files**:

| Header File | Description                                                              |
|:------------|:-------------------------------------------------------------------------|
| `iostream`  | Provides definitions for formatted input and output from/to streams      |
| `fstream`   | Provides definitions for formatted input and output from/to file streams |
| `iomanip`   | Provides definitions for manipulators used to format stream I/O          | 

By including these *headers* we'll get access to many classes:

| Class           | Description                                                                                                         |
|:----------------|:--------------------------------------------------------------------------------------------------------------------|
| `ios`           | Provides basic support for formatted and un-formatted I/O operations.<br/> Base class for most other classes        |
| `ifstream`      | Provides for High-level input operations on file based streams                                                      | 
| `ofstream`      | Provides for High-level output operation on file based streams                                                      |
| `fstream`       | Provides for High-level I/O operations on file based streams. <br/>Derived from `ofstream` and `ifstream`           |
| `stringstream ` | Provides for High-level I/O operation on memory bases strings.<br/>Derived from `istringstream` and `ostringstream` |

**Global Stream Objects**

| Object | Description                                                                                                                    | 
|:-------|:-------------------------------------------------------------------------------------------------------------------------------|
| `cin`  | Standard input stream - by default 'connected' to the standard input device (keyboard). <br/> Instance of `istream`            |
| `cout` | Standard output stream - by default 'connected' to the standard output device (console). <br/>Instance of `ostream`            |
| `cerr` | Standard error stream - by default 'connected' to the standard error device (console).<br/>Instance of `ostream`*(unbuffered)* |
| `clog` | Standard log stream - by default 'connected' to the standard log device (console). <br/>Instance of `ostream`*(unbuffered)*    |

Global objects - Initialized before main executes.  
Best practice is to use `cerr` for error messages and `clog` for log messages.

## Stream Manipulators

`#include <iomanip>`

- Streams have useful member functions to control formatting.
- Can be used on input and output streams.
- The time of the effect on the stream varies.
- Can be used as member functions or as a manipulator
  ```c++
  std::cout.width(10);      // member function
  std::cout << std::setw(10);// manipulator
  ```

### Common Stream Manipulators

- [Boolean](#boolean-formatters)
    - `boolalpha`
    - `noboolalpha`
- [Integer](#integer-formatters)
    - `dec`
    - `hex`
    - `oct`
    - `showbase`
    - `noshowbase`
    - `showpos`
    - `noshowpos`
    - `uppercase`
    - `nouppercase`
- [Floating point](#floating-point-formatters)
    - `fixed`
    - `scientific`
    - `setprecision`
    - `showpoint`
    - `noshowpoint`
    - `showpos`
    - `noshowpos`
- [Field width, justification and fill](#field-width-justification-and-fill-formatters)
    - `setw`
    - `left`
    - `right`
    - `internal`
    - `setfill`
- Others
    - `endl`
    - `flush`
    - `skipws`
    - `noskipws`
    - `ws`

> [!IMPORTANT]
> By using the _no_ prefixed versions, the flag/manipulator is disabled.

## Boolean Formatters

Default behaviour when displaying boolean values is _1_ or _0_. Sometimes the strings _true_ and _false_ are more
apropiate.

```c++
std::cout << (10 == 10) << std::endl;   // 1
std::cout << (10 == 20) << std::endl;   // 0

// manipulator
std::cout << std::boolalpha;            // display booleans as true or false
std::cout << (10 == 10) << std::endl;   // true
std::cout << (10 == 20) << std::endl;   // false
// member function
std::cout.setf(std::ios::noboolapha);   // display booleans as 1 and 0
std::cout << (10 == 10) << std::endl;   // 1
std::cout << (10 == 20) << std::endl;   // 0

std::cout << std::resetiosflags(std::ios::boolalpha); // reset stream flags to the original value of the flag
```

## Integer Formatters

Default when displaying an integer value:

- `dec` (base 10)
- `noshowbase`: prefix used to show hexadecimal or octal
- `nouppercase`: when displaying prefix and hex values it will be lower case
- `noshowpos`: no '+' is displayed for positive numbers

_These manipulators affect all further output to the stream_

```c++
int num{255};

std::cout << std::dec << num << std::endl;  // 255
std::cout << std::hex << num << std::endl;  // ff
std::cout << std::oct << num << std::endl;  // 377

std::cout << std::showbase;
std::cout << std::dec << num << std::endl;  // 255
std::cout << std::hex << num << std::endl;  // 0xff - prefix 0x for hexadecimal
std::cout << std::oct << num << std::endl;  // 0377 - prefix 0 for octal

std::cout << std::uppercase;
std::cout << std::hex << num << std::endl;  // 0XFF - capitalized XFF


int num1{255};
int num2{-255};

std::cout << num1 << std::endl;     //  255
std::cout << num2 << std::endl;     // -255

std::cout << std::showpos;  
std:.cout << num1 << std::endl;     // +255
std:.cout << num1 << std::endl;     // -255
```

### Setting/Resetting Integer Types

**Set using `setf`:**

```c++
std::cout.setf(std::ios::showbase);
std::cout.setf(std::ios::uppercase);
std::cout.setf(std::ios::showpos);
```

**Reset to defaults:**

```c++
std::cout << std::resetiosflags(std::ios::basefield);
std::cout << std::resetiosflags(std::ios::showbase);
std::cout << std::resetiosflags(std::ios::showpos);
std::cout << std::resetiosflags(std::ios::uppercase);
```

## Floating Point Formatters

Defaults when displaying floating point values:

- `setprecision`: number of digits (6)
- `fixed`: not fixed to a specific number of digits after the decimal point
- `noshowpoint`: trailing zeroes are not displayed
- `nouppercase`: when displaying in scientific notation
- `noshowpos`: no '+' is displayed for positive numbers

_These manipulators affect all further output to the stream_

```c++
double num{1234.5678};

std::cout << num << std::endl;      // 1234.56 - precision is 6 and rounding

double num1{123456789.987654321};
std::cout << num1 << std::endl;     // 1.23456e+008 - precision is 6
// ---
std::cout << std::setprecision(9);
std::cout << num1 << std::endl;     // 1234567890 - Note rounding error 
// ---
std::cout << std::fixed;            // use precision for the number digits after decimal point
std::cout << num1 << std::endl;     // 123456789.987654
// ---
std::cout << std::setprecision(3) << std::fixed;    // display 3 digits after the decimal point, rounding will occur
std::cout << num << std::endl;      // 123456789.988
// ---
std::cout << std::setprecision(3) << std::scientific;   // show 3 numbers with cientific notation
std::cout << num << std::endl;      // 1.23e+008
std::cout << std::uppercase;        // display notations in capital letter
std::cout << num << std::endl;      // 1.23E+008    
// ---
std::cout << std::showpos;          // positive numbers with +
std::cout << num << std::endl;      // +1234.5678
// ---
double num2{12.34};
std::cout << num2 << std::endl;     // 12.34
std::cout << std::showpoint;
std::cout << num2 << std::endl;     // 12.3400 - trailing zeroes up to precision
```

### Returning to General Floating Point Settings

`unsetf`

```c++
std::cout.unsetf(std::ios::scientific | std::ios::fixed);
```

Or

```c++
std::cout << std::resetiosflags(std::ios::floatfield);
```

> [!NOTE]
> Refer to the documentation for other set/reset flags

## Field Width, Justification and Fill Formatters

Work with any type of data.

Default:

- `setw`: not set by default
- `left`: when no field _width_, _right_ when using field width. **When not using any justification, it will be _right_
  **
- `fill`: not set by default - blank space is used

> [!NOTE]
> Some of this manipulators affect only the next data element put on the stream

```c++
double num{1234.5678};
std::string hello {"Hello"};

std::cout << num << hello << std::endl; // 1234.57Hello - Notice rounding
// ---
std::cout << std::setw(10) << num << hello << std::endl;
// ====== 1234567890123456789012345678901234567890 == ruler
//output:    1234.57Hello       no justification was specified, so right is used.
std::cout << std::setw(10) << num 
          << std::setw(10) << hello
          << std::setw(10) << hello << std::endl;
// ====== 1234567890123456789012345678901234567890 == ruler
//output:    1234.57     Hello     Hello

std::cout << std::setw(10) << std::left << num // only affects num
          << hello << std::endl;
// ====== 1234567890123456789012345678901234567890 == ruler
//output: 1234.57   Hello

std::cout << std::setw(10) << num
          << std::setw(10) << std::right << hello
          << std::setw(15) << std::right << hello
          << std::endl;
// ====== 1234567890123456789012345678901234567890 == ruler
//output:    1234.57     Hello          Hello

std::cout << std::setfill('-')
          << std::setw(10) << num
          << hello << std::endl;
// ====== 1234567890123456789012345678901234567890 == ruler
//output: ---1234.57Hello

std::cout << std::setfill('*') << std::setw(10) << num
          << std::setfill('-') << std::setw(10) << std::right << hello
          << std::setw(15) << std::right << hello
          << std::endl;
// ====== 1234567890123456789012345678901234567890 == ruler
//output: ***1234.57-----Hello----------Hello
```

## Reading Text from a File

**Input Files**

`fstream`and `ifstream` are commonly used for input files

1. `#include <fstream>`
2. Declare an `fstream` or `ifstream`
3. Connect it to a file on your file system (opens it for reading)
4. Read data from the file via the stream
5. Close the stream

> [!NOTE]
> Generally to read a file we use `ifstream`. When we need to both read and write we use `fstream`

_**Opening a file for reading with `fstream`**_

```c++
#include <fstream>
. . .

std::fstream in_file {"../file.txt", std::ios::in};

// Open for reading in binary mode
std::fstream in_bin_file {"../bin_file.txt", std::ios::in | std::ios::bin};
```

_**Opening a file for reading with `ifstream`**_

```c++
std::ifstream in_file {"filename.txt", std::ios::in};

std::ifstream in_file {"filename.txt"};

// opening read in binary mode
std::ifstream in_file {"filename.txt", std::ios::binary};
```

> [!IMPORTANT]
> We have two ways of opening file streams:
> 1. On initialization of the stream by using a filename, it is automatically
     opened. `std::fstream file_stream{"filename", <mode-flags>);`
> 2. By using `open`. Declare file stream: `std::fstream file_stream;`. Open file
     stream: `file_stream.open("filename", <mode-flags>`


Example

```c++
#include <fstream>

std::ifstream in_file;
std::string filename;
std::cin >> filename;   // get file name using console

/// Open File stream
in_file.open(filename);
// or
in_file.open(filename, std::ios::binary);

/// Check if file opened successfully - using is_open
if (in_file.is_open()){
    // read from it
} else {
    // file could not be opened. 
}
/// Check if file opened successfully - using stream object
if (in_file){
    // read from it
} else {
    // file could not be opened. 
}

// close File
in_file.close();
```

> [!WARNING]
> Always close opened files using `ifstream::close()`

### Reading from the file

#### Reading with the `>>` Operator

We can use the extraction operator for formatted read. Same way it was used with cin.
file:

```
100
255.67
Andres
```

```c++
int num{};
double total{};
std::string name{};
in_file >> num;
in_file >> total >> name;
/* num: 100
 * total: 255.67
 * name: Andres 
 */
```

#### Reading using `getline`

file:

```
This is a line
This is another line
This is a third line
```

```c++
std::ifstream in_file {"../file.txt"}; // open file
std::string line{};
if (!in_file) { // check if file is open
    std::cerr << "File open error" << endl;
    return;
} 

std::getline(in_file, line); // read single line

// reading multiple lines
while (!in_file.eof()) {            // while not at the end
    std::getline(in_file, line);    // read a line
    std::cout << line << std::endl; // display the line (use read line)
}
in_file.close();    // close the file
```

**Other way to read multiple lines**

```c++
std::ifstream in_file {"../file.txt"}; // open file
std::string line{};
if (!in_file) { // check if file is open
    std::cerr << "File open error" << endl;
    return;
} 

// reading multiple lines
while (std::getline(in_file, line)) {   // While reading line
    std::cout << line << std::endl; // display the line (use read line)
}
in_file.close();    // close the file
```

#### Reading using `get`

Reading text file one character at a time.

```c++
std::ifstream in_file {"file.txt"}; // open file
char c;

if (!in_file) {
    std::cerr << "File open Error" << std::endl
    return;
}
while (in_file.get(c)) // read a character
    cout << c;      // display the character

in_file.close();    // close the file
```

## Writing to a Text file

Output files.

`fstream` and `ofstream` are commonly used for output files (writing to files).

1. `#include <fstream>`
2. Declare an `fstream` or `ofstream` object
3. Connect it to a file on your system (opens it for writing).
4. Write data to the file via the stream
5. Close the stream

- Output files will be created if they don't exist
- Output files will be overwritten (truncated) by default
- Can be opened so that new writes append
- Can be open in text or binary modes

_**Opening a file for writing with `fstream`**_:

```c++
std::fstream out_file {"../myfile.txt", std::ios::out};

// Open for writing in binary mode
std::fstream out_file {"../myfile.txt", std::ios::out | std::ios::binary};
```

_**Opening a file for writing with `ofstram`**_

```c++
std::ofstream out_file {"filename.txt", std::ios::out};

std::ofstream out_file {"filename.txt"};

// Open for writing in binary mode
std::ofstream out_file {"filename.txt", std::ios::binary};
```

> [!NOTE]
> We use commonly use `ofstream` to only write to files. If we need to read and write to files we use `fstream`


**Truncating, Append, eof**

```c++
// Truncate (discard contents) when opening
std::ofstream out_file { "myfile.txt", std::ios::trun };

// append on each write
std::ofstream out_file { "myfile.txt", std::ios::app };

// seek to end of stream when opening
std::ofstream out_file { "myfile.txt", std::ios::ate };
```

**Opening a file with Open**

```c++
std::ofstream out_file;
std::string filename;
std::cin >> filename;   // get filename using console

out_file.open(filename);
// or
out_file.open(filename, std::ios::binary);
```

> [!IMPORTANT]
> We have two ways of opening file streams:
> 1. On initialization of the stream by using a filename, it is automatically
     opened. `std::fstream file_stream{"filename", <mode-flags>);`
> 2. By using `open`. Declare file stream: `std::fstream file_stream;`. Open file
     stream: `file_stream.open("filename", <mode-flags>`

**Check if file was opened successfully**

```c++
if (out_file.is_open()) {
    // use file 
}

// Or
if (out_file) {
    // use file
}
```

**Close file stream**

```c++
out_file.close();
```

> [!WARNING]
> Always close opened files using `ifstream::close()`. This is important because the 'write' buffer might not have
> written to the file yet.

### Writing to the file

#### Writing with the `<<` Operator

We can use the insertion operator for formatted write. The same way we used it with `cout`.

```c++
int num {100};
double total {255.67};
std::string name {"Andres"};

out_file << num << "\n"
         << total << "\n"
         << name << std::endl;
```

File:

```
100
255.67
Andres
```

> [!NOTE]
> `std::endl` will flush any unwritten buffers

##### Copying Text File to Another File

Copying a text file to another one line at the time

```c++
std::ifstream in_file("source_file.txt");   // open source file
std::ofstream out_file("target_file.txt");   // open target file

if (!(in_file && out_file)) { // check if files where opened 
    std::cer << "File open Error" << std::endl;
}

std::string line{};

while(std::getline(in_file, line)) {    // read line
    out_file << line << "\n";           // write line
}

// close the files
in_file.close()
out_file.close()
```

#### Writing one character at the time

```c++
char c:

while (in_file.get(c)) // read character
    out_file.put(c);

// close the files
in_file.close()
out_file.close()
```

## String Streams

Allows to use in-memory string objects as streams. Allows us to read or write from strings in memory much as we would
write to files.

1. `#include <sstream>`
2. Declare an `stringstream`, `istringstream` or `ostringstream` object
3. Connect it to a `std::string`
4. Read/write data from/to the string stream using formatted I/O

> [!NOTE]
> - `istringstream` is used to read a String Stream
> - `ostringstream` is used to write to a String Stream
> - `stringstream` is used to read and write to a String Stream

### Reading from a String Stream

```c++
#include <sstream>

int num {};
double total{};
std::string name{};
std::string info {"Andres 200 1234.5"};

std::istringstream iss {info};
iss >> name >> num >> total;
/*
 * num: Andres
 * total: 200
 * name: 1234.5
 */
```

### Writing to a String Stream

```c++
#include <sstream>

int num {200};
int total {1234.5};
std::string name {"Andres"};

std::ostringstream oss{};
oss << name << " " << num " " << total;
std::cout << oss.str() << std::endl;    // Andres 200 1234.5
```

### Validating Input with String Stream

```c++
int value{};
std::string input{};

std::cout << "Enter an integer: ";
std::cin >> input;

std::stringstream ss{input};
if (ss >> value) // try to extract the string into 'value'
    std::cout << "An integer was entered";
else 
    std::cout << "An integer was NOT entered"; 
```

## File Locations and IDEs

| IDE                   | File Path                           |
|:----------------------|:------------------------------------|
| CodeLite              | `std::fstream file{"../file.txt"};` |
| Windows Visual Studio | `std::fstream file{"file.txt"};`    |
| Code::Blocks          | `std::fstream file{"file.txt"};`    |
| CLion                 | `std::fstream file{"../file.txt"};` |

These differences are due to the compilation process used by the IDE.

- Visual Studio compiles 'file.txt' with the program into the output directory.
- CLion compiles the program to the output directory, which is inside the project directory, but doesn't include '
  file.txt'.
