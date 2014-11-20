/*
* Author:Shushan Chen
* chssian@gmail.com
* 21/11/2014
*/

//Get file names from a directory
static void getFiles( string path, vector<string>& files )  
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


// save data into files
static void outputData2(string path, vector< vector<double> >& model){
	ofstream savefile(path);
	savefile << this->word+"\n";
	savefile << model.size()+"\n";
	savefile << model[0].size()+"\n";
	
	for(int i=0; i<model.size(); i++){
		for(int j=0; j<model[i].size(); j++){
				savefile << model[i][j];
				savefile << " ";
		}
	}
}


static int readFrame(const string &filename)
{

    ifstream mfcc_in(filename.c_str());
    int len;
    mfcc_in>>len;
    
	/*
	* write as above...
	*/
    
    return 0;
}