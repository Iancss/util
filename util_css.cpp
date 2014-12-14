/*
* Author:Shushan Chen
* chssian@gmail.com
* 21/11/2014
*/

#include "util_css.h"

using namespace std;

//Get file names from a directory
void util_css::getFiles( string path, vector<string>& files )  
{  
    //文件句柄  
    long   hFile   =   0;  
    //文件信息  
    struct _finddata_t fileinfo;  
    string p;  
    if((hFile = _findfirst(p.assign(path).append("\\*").c_str(),&fileinfo)) !=  -1)  
    {  
        do  
        {  
            //如果是目录,迭代之  
            //如果不是,加入列表  
            if((fileinfo.attrib &  _A_SUBDIR))  
            {  
                if(strcmp(fileinfo.name,".") != 0  &&  strcmp(fileinfo.name,"..") != 0)  
                    getFiles( p.assign(path).append("\\").append(fileinfo.name), files );  
            }  
            else  
            {  
                //files.push_back(p.assign(path).append("\\").append(fileinfo.name) ); 
				files.push_back(fileinfo.name); 
            }  
        }while(_findnext(hFile, &fileinfo)  == 0);  
        _findclose(hFile);  
    }  
} 

// Can be used on any platform
int util_css::getFiles2(string path, vector<string>& files ){
	DIR* dirp;
    struct dirent* direntp;
	dirp = opendir( path.c_str() );
    if( dirp != NULL ) {
        for(;;) {
            direntp = readdir( dirp );
            if( direntp == NULL ) break;
			if(direntp->d_name[0] == '.') continue;
            files.push_back(direntp->d_name);
        }
        closedir( dirp );
		
		for(int i=0; i<files.size(); i++)
			cout << files[i] << endl;
		
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}


// save data into files
void util_css::outputData2(string path, vector< vector<double> >& model){
	ofstream savefile(path);
	savefile << model.size()+"\n";
	savefile << model[0].size()+"\n";
	
	for(int i=0; i<model.size(); i++){
		for(int j=0; j<model[i].size(); j++){
				savefile << model[i][j];
				savefile << " ";
		}
	}
}


int util_css::readFile(const string &filename)
{

    ifstream mfcc_in(filename.c_str());
    int len;
    mfcc_in>>len;
    
	/*
	* write as above...
	*/
    
    return 0;
}

void util_css::trim(string& str){
	while(str[0] == ' ') // delete the spaces in the begining
		str.erase(0,1);
	
	while(str[str.length()-1] == ' ') // delete the space in the end
		str.erase(str.length()-1,1);
}