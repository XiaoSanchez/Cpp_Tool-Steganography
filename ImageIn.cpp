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
#include "Image.h"
using namespace std;
void picture::Stegano(string name_ifile_picture, string name_ofile_picture, string name_ifile_txt){
	char *str;
	Open(this->ifile_picture, this->name_ifile_picture, this->length_ifile_picture);
	str = new char[length_ifile_picture + 5];
	this->ifile_picture.read(str, this->length_ifile_picture);
	while (1){
		if (str[this->length_ifile_picture - 2] == -1 && str[this->length_ifile_picture - 1] == -39)
			break; //ends FF D9
		else
			this->length_ifile_picture--;
	}
	this->ofile_picture.open(this->name_ofile_picture, ios::binary | ios::out);
	if (!this->ofile_picture){
		cout << "Open " << this->name_ofile_picture << " failed!" << endl;
		return;
	}
	this->ofile_picture.write(str, this->length_ifile_picture);
	this->ifile_picture.close();
	delete[] str;
	Open(this->ifile_txt, this->name_ifile_txt, this->length_ifile_txt);
	str = new char[length_ifile_txt + 5];
	this->ifile_txt.read(str, this->length_ifile_txt);
	this->ofile_picture.write(str, this->length_ifile_txt);
	this->ifile_txt.close();
	this->ofile_picture.close();
}
int main(int argc, char **argv) {
	picture img;
	string name_ifile_picture = argv[2];
	string name_ofile_picture = argv[3];
	string name_ifile_txt = argv[4];
	img.Stegano(name_ifile_picture, name_ofile_picture, name_ifile_txt);
	return 0;
}