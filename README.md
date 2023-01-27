# Security System in C++
## About
This is a project using C++ language, in which there will be various options like registration, login, change password, etc. <br>
This project use different concepts of C++ programming language, like switch case statements, loops, arrays, file handling operations, etc., to create this Security System Project in C++. <br>

## Features
In this C++ Project, you can register, login, and then, if you wish to change the password, you can also do that by clicking on the change password option.

## File Hnadling 
### ofstream:
To open a file to write the user informations in it.

- create an object of 'ofstream' class:
ofstream of1
- open the file:
of1.open("file.txt")

### ifstream: 
For reading the file

- create an object of 'ifstream' class:
ifstream of2
- open the file:
of2.open("file.txt")
- from 'eof()' function we can detect when the end of file is reached. (returns non-zero when end of file is reached, otherwise returns 0):<br>
while(!of2.eof())
- while with getline is used to read the file line-by-line:
while(getline(of2, text))
- istringstream object is used to stream the string and store it using the extraction operator
