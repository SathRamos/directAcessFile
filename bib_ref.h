//Essa biblioteca contem a construção da classe de referência bibliográfica propriamente dita.
//Possui as instâncias Id do trabalho, Título do trabalho, Autor do trabalho, veículo de Publicação do trabalho,
//ano de publicação do trabalho, e as Páginas Incial e Final do veículo onde se encontra o trabalho. 

#ifndef BIB_REF
#define BIB_REF

#include <fstream>
#include <cstring>
#include <iostream>

using namespace std;

class bibRef {
public:		
	bibRef();
	//Id, Title, Author, Publication, Year, PageStart, PageEnd
	bibRef(char*, char*, char*, char*, int, int, int);
	void writeToFile(fstream&) ;
	void readFromFile(fstream&);
	void readKey();
	//tamanho do arquivo
	int size() const {
		return idLen + titleLen + authorLen + pubLen + sizeof(year) + sizeof(pageStart) + sizeof(pageEnd);
	}

protected:
	const int titleLen, authorLen, pubLen, idLen;
	char *ID, *title, *author, *pub;
	int year, pageStart, pageEnd;
	ostream& writeLegibly(ostream&);
	friend ostream& operator<<(ostream& out, bibRef& pr) {
		return pr.writeLegibly(out);
	}
	istream& readFromConsole(istream&);
	friend istream& operator>>(istream& in, bibRef& pr) {
		return pr.readFromConsole(in);
	}	
};

#endif