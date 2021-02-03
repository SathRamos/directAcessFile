//O script my_record trata-se simplesmente de um modelo para
//inserir dados num arquivo, que poderá ser acessado diretamente (acesso direto/aleatório) de acordo com
//o código nos arquivos bib_ref.h e bib_ref_class.cpp

#include <iostream> //cout
#include <fstream> //fstream
#include <cstring> //strcpy
#include <limits>

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

  char titleInsert[80];
  char authorInsert[80];
  char publicationInsert[80];
  int yearInsert;
  int pageStartInsert;
  int pageEndInsert;
  char idInsert[20];

  fflush(stdin);

  cout<<"Título do artigo: ";
  cin.getline(titleInsert, 100);
  strcpy(mr.title, titleInsert);

  cout<<"Autor(a) do artigo: ";
  cin.getline(authorInsert, 100);
  strcpy(mr.author, authorInsert);

  cout<<"Veículo de publicação: ";
  cin.getline(publicationInsert, 100);
  strcpy(mr.publication, publicationInsert);

  cout<<"Ano de publicação: ";
  cin>>yearInsert;
  mr.year = yearInsert;

  cout<<"Página de início do artigo: ";
  cin>>pageStartInsert;
  mr.pageStart = pageStartInsert;

  cout<<"Página final do artigo: ";
  cin>>pageEndInsert;
  mr.pageEnd = pageEndInsert;

  cout<<"Código do artigo: ";
  cin>>idInsert;
  strcpy(mr.id, idInsert);

  output.write((char *) &mr, sizeof(struct MyRecord));

  output.close();
}

void read(const char * filename) {
  fstream infile;
  infile.open("myRecord.txt", ios::binary | ios::in);

  int whichRecord = 0;
  cout<<"Qual registro deseja ver? \n";
  cin>>whichRecord;

  MyRecord mr;
  infile.seekp(whichRecord*sizeof(mr), ios::beg);
  infile.read((char *) &mr, sizeof(struct MyRecord));
  infile.close();
  cout<<"-----------------------------------";
  cout << "Titulo: " << mr.title << endl;
  cout << "Autor: " << mr.author << endl;
  cout << "Publicado em: " <<mr.publication << endl;
  cout.setf(ios::fixed);
  cout << "Ano: " << mr.year << endl;
  cout << "Página de início: " << mr.pageStart << endl;
  cout << "Página final: " << mr.pageEnd << endl;
  cout << "Identificação: " << mr.id << endl;
  cout<<"------------------------------------\n";

}

int main() {
  fflush(stdin);
  const char * file = "myRecord.txt";
  int ans;
  while(true){
    ans = 0;
    cout<<"Inserir registro: 1\nLer registro: 2\nSair: 3\n";
    cin>>ans;
    cin.clear();  // clears the error flags  
    //this line discards all the input waiting in the stream
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    fflush(stdin);
    if(ans == 1) write(file);   //Cria/Abre um arquivo e insere um registro no fim
    else{
      if(ans == 2) read(file);  //Abre o arquivo criado e le o registro
      else{
        if(ans == 3) return 0;
      }
    }
  }
  
  return 0;
}