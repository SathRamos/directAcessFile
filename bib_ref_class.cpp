//Esse código em c++ consiste no algoritmo de acesso aleatório de memória (DMA - direct memory access).
//Seu funcionamento está comentado dentro do código.

#define _CRT_SECURE_NO_WARNINGS

#include "bib_ref.h"
#include <iostream>
#include <cstring>

bibRef::bibRef() : idLen(20), titleLen(100), authorLen(40), pubLen(100) {
	ID = new char[idLen + 1];
	title = new char[idLen + 1];
    author = new char[authorLen + 1];
    pub = new char[pubLen + 1];
}

//Id, Title, Author, Publication, Year, PageStart, PageEnd
bibRef::bibRef(char* id, char* t, char* a, char* p, int y, int ps, int pe) : idLen(20), titleLen(100), authorLen(40), pubLen(100) {
	id = new char[idLen + 1];
	title = new char[idLen + 1];
    author = new char[authorLen + 1];
    pub = new char[pubLen + 1];
	strcpy(ID, id);
	strcpy(title, t);
	strcpy(author, a);
    strcpy(pub, p);
	year = y;
	pageStart = ps;
    pageEnd = pe;
}

//Escreve no arquivo cada um dos atributos de uma entrada de referência bibliográfica
void bibRef::writeToFile(fstream& out)  {
	
	out.write(ID, idLen);
	out.write(title, titleLen);
	out.write(author, authorLen);
    out.write(pub, pubLen);
	out.write(reinterpret_cast <char*>(&year), sizeof(int));
	out.write(reinterpret_cast <char*>(&pageStart), sizeof(long));
    out.write(reinterpret_cast <char*>(&pageEnd), sizeof(long));
}

//Lê do arquivo, cada um dos atributos de uma entrada de referência bibliográfica
void bibRef::readFromFile(fstream& in) {
	
	in.read(ID, idLen);
	in.read(title, titleLen);
	in.read(author, authorLen);
    in.read(pub, pubLen);
	in.read(reinterpret_cast <char*>(&year), sizeof(int));
	in.read(reinterpret_cast <char*>(&pageStart), sizeof(long));
    in.read(reinterpret_cast <char*>(&pageEnd), sizeof(long));
}

//Lê no arquivo o identificador de uma entrada de referência bibliográfica
void bibRef::readKey() {
	char s[100];
	cout << "Digite o ID";
	cin.getline(s, 100);
	strncpy(ID, s, idLen);
}

//Escreve de forma legível os atributos de uma entrada de referência bibliográfica
ostream& bibRef::writeLegibly(ostream& out) {
	ID[idLen] = title[titleLen] = author[authorLen] = pub[pubLen] = '\0';
	out << "ID = " << ID << ", Title = " << title << ", Author = " << author << "Publication = " << pub <<
     ", Year = " << year << ", At pages = " << pageStart << "-" <<pageEnd;
	return out;
}

//Lê do terminal os dados para compor os atributos de uma entrada de referência bibliográfica
istream& bibRef::readFromConsole(istream& in) {
	ID[idLen] = title[titleLen] = author[authorLen] = pub[pubLen] = '\0';
	char s[80];
	cout << "ID: ";
	in.getline(s, 100);
	strncpy(ID, s, idLen);
	cout << "Title: ";
	in.getline(s, 100);
	strncpy(title, s, titleLen);
	cout << "Author: ";
	in.getline(s, 100);
	strncpy(author, s, authorLen);
    cout << "Publication: ";
	in.getline(s, 100);
	strncpy(pub, s, pubLen);
	cout << "Year: ";
	in >> year;
	cout << "Start Page: ";
	in >> pageStart;
    cout << "End Page: ";
    in >> pageEnd;
	in.ignore();
	return in;
}