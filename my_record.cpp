//O script my_record trata-se simplesmente de um modelo para
//inserir dados num arquivo, que poderá ser acessado diretamente (acesso direto/aleatório) de acordo com
//o código nos arquivos bib_ref.h e bib_ref_class.cpp

#include <iostream> //cout
#include <fstream> //fstream
#include <cstring> //strcpy

using namespace std;

struct MyRecord {
  char title[80];
  char author[80];
  char publication[80];
  int year;
  int pageStart;
  int pageEnd;
  char id[20];
};

void  write(const char * filename) {
  ofstream output(filename,
		  //ios::out //abre arquivo para escrita.
		  ios::app //abre arquivo para escrita, adicionando ao fim do arquivo (append).
		  | ios::binary //arquivo binario.
		 );
  if (!output) {
    cout << " -> Erro ao abrir arquivo." << endl;
    return;
  }

  cout << " -> inserindo." << endl;
  MyRecord mr;

  fflush(stdin);
  strcpy(mr.title, "Artigo de Exemplo - Laboratório de Estruturas de Dados 2");
  strcpy(mr.author, "Lesath Souza Ramos");
  strcpy(mr.publication, "Revista de Exemplo, Implementações de Estruturas de Dados");
  mr.year = 2020;
  mr.pageStart = 15;
  mr.pageEnd = 40;
  strcpy(mr.id, "135792468");

  output.write((char *) &mr, sizeof(struct MyRecord));

  output.close();
}

void read(const char * filename) {
  ifstream input(filename,
		 ios::in //abre arquivo para leitura.
		 | ios::binary //arquivo binario.
		);
  if(!input) {
    cout << " -> Erro ao abrir arquivo." << endl;
    return;
  }

  MyRecord mr;
  input.read((char *) &mr, sizeof(struct MyRecord));
  input.close();
  
  cout << "Titulo: " << mr.title << endl;
  cout << "Autor: " << mr.author << endl;
  cout << "Publicado em: " <<mr.publication << endl;
  cout.setf(ios::fixed);
  cout << "Ano: " << mr.year << endl;
  cout << "Página de início: " << mr.pageStart << endl;
  cout << "Página final: " << mr.pageEnd << endl;
  cout << "Identificação: " << mr.id << endl;
}

int main() {
   fflush(stdin);
   const char * file = "myRecord.txt";

   //Cria/Abre um arquivo e insere um registro no fim
   write(file);

   //Abre o arquivo criado e le o registro
   read(file);
  
  return 0;
}