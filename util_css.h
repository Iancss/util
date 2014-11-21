/*
* Author:Shushan Chen
* chssian@gmail.com
* 21/11/2014
*/

#include <iosteream>
#include <string.h>
#include <vector>

class util_css{
	public:
		//Get file names from a directory
		static void getFiles(string path, vector<string>& files);
		
		// save data into files
		static void outputData2(string path, vector< vector<double> >& model);
		
		// read the file
		static int readFile(const string &filename);
	private:
};