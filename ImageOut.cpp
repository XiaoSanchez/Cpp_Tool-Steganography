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
void picture::UnStegano(string name_ifile_picture, string name_ofile_txt){
	char *str;
	Open(this->ifile_picture, this->name_ifile_picture, this->length_ifile_picture);
	str = new char[length_ifile_picture + 5];
	this->ifile_picture.read(str, this->length_ifile_picture);
	int l = this->length_ifile_picture;
	while (1){
		if (str[l - 2] == -1 && str[l - 1] == -39)
			break; //ends FF D9
		else
			l--;
	}
	this->ofile_txt.open(this->name_ofile_txt, ios::binary | ios::out);
	if (!this->ofile_picture){
		cout << "Open " << this->name_ofile_txt << " failed!" << endl;
		return;
	}
	this->ofile_txt.write(str + l, this->length_ifile_picture - l);
	this->ifile_picture.close();
	this->ofile_txt.close();
}
int main(int argc, char **argv) {
	picture img;
	string name_ifile_picture = argv[2];
	string name_ofile_txt = argv[3];
	img.UnStegano(name_ifile_picture, name_ofile_txt);
	return 0;
}