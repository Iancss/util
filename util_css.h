/*
* Author:Shushan Chen
* chssian@gmail.com
* 21/11/2014
*/

#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <dirent.h>
#include <io.h>

using namespace std;

class util_css{
	public:
		//Get file names from a directory, but need to be used on Windows
		void getFiles(string path, vector<string>& files);
		
		// Can be used on any platform
		int getFiles2(string path, vector<string>& files);
		
		// save data into files
		void outputData2(string path, vector< vector<double> >& model);
		
		// read the file
		int readFile(const string &filename);
		
		// trim the string
		void trim(string & str);
	private:
};