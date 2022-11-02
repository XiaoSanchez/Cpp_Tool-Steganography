/*
 * @Description: 
 * @Logo:                                                               ▄   ▄
 * ░██████╗██╗░░██╗░█████╗░░██╗░░░░░░░██╗███╗░░██╗  ░█████╗░░█████╗░██╗ █▀█▀█
 * ██╔════╝██║░░██║██╔══██╗░██║░░██╗░░██║████╗░██║  ██╔══██╗██╔══██╗██║ █▄█▄█
 * ╚█████╗░███████║███████║░╚██╗████╗██╔╝██╔██╗██║  ██║░░╚═╝███████║██║ ███  ▄▄
 * ░╚═══██╗██╔══██║██╔══██║░░████╔═████║░██║╚████║  ██║░░██╗██╔══██║██║ ████▐█ █
 * ██████╔╝██║░░██║██║░░██║░░╚██╔╝░╚██╔╝░██║░╚███║  ╚█████╔╝██║░░██║██║ ████   █
 * ╚═════╝░╚═╝░░╚═╝╚═╝░░╚═╝░░░╚═╝░░░╚═╝░░╚═╝░░╚══╝  ░╚════╝░╚═╝░░╚═╝╚═╝ ▀▀▀▀▀▀▀
 * @Author: Shawn C
 * Copyright (c) 2022 by Shawn C., All Rights Reserved. 
 */
#include <iostream>
#include <fstream>
using namespace std;
class picture{
private:
	ifstream ifile_picture;
	ifstream ifile_txt;
	ofstream ofile_picture;
	ofstream ofile_txt;
	int length_ifile_picture, length_ifile_txt;
	char name_ifile_picture[50], name_ifile_txt[50], name_ofile_picture[50], name_ofile_txt[50];

public:
	void Open(ifstream &ifile, char *name, int &length);
	void Stegano(string name_ifile_picture, string name_ofile_picture, string name_ifile_txt);
	void UnStegano(string name_ifile_picture, string name_ofile_txt);
};
void picture::Open(ifstream &ifile, char *name, int &length){
	ifile.open(name, ios::binary | ios::in);
	if (!ifile){
		cout << "Open " << name << " failed!" << endl;
		return;
	}
	ifile.seekg(0, ios::end);
	length = ifile.tellg();
	ifile.seekg(0, ios::beg);
}