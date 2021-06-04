#include "controlador_bin.h"

string ReplaceAll3(string str, const string& from, const string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return str;
}

string *Controlador_bin::toCSV(email res)
{
    string* tot= new string();
    string total;
    string aux;
    string suma;
    int i;
    char ite;
    bool comillas=0;

    total=total+res.Identificador+",";
    total=total+res.Fecha+",";
    total=total+res.Hora+",";
    for(int j=0;j<6;j++){
        if(j==0)aux=res.From;
        //
        if(j==1)aux=res.To;
        //
        if(j==2)aux=res.CC;
        //
        if(j==3)aux=res.BCC;
        //
        if(j==4)aux=res.subject;
        //
        if(j==5)aux=res.Content;
        for(i=0;i<int(aux.length());i++){
            ite=aux[i];
            if(ite==',')
                comillas=1;
            else if(ite=='"'){
                suma+='"';
                comillas=1;
            }
            else if(ite=='\n')
                comillas=1;
            suma+=ite;
        }
        if(comillas)
            total=total+'"'+suma+'"'+",";
        else
            total=total+suma+",";
        suma.clear();
        comillas=0;
        aux.clear();
        ite='0';
    }

    *tot=total;
    return tot;


}

string *Controlador_bin::kaiser(unsigned long *ite, ifstream &fin)
{
    char act;
    string aux;
    bool token_comillas=0;
    string* token=new string();
    fin.seekg(*ite);
    fin.read(&act,sizeof(char));
    while(!fin.eof()){
        if(token_comillas){
            if(act=='"'){
                fin.seekg((*(ite))+1);
                fin.read(&act,sizeof(char));
                if(act=='"'){
                    aux+='"';
                    (*(ite))++;
                }
                else if(act==','){
                    (*ite)+=2;
                    break;
                }

            }
            else if(act=='\n'){
                aux+='\n';
            }
            else
                aux+=act;
        }
        else if(act=='"'){
            token_comillas=1;
        }
        else if(act==','){
            (*(ite))++;
            break;
        }
        else{
            aux+=act;
        }

        (*(ite))++;
        fin.seekg(*ite);
        fin.read(&act,sizeof(char));
    }
    if(fin.eof())
        token=nullptr;
    else
        *token=aux;
    return token;
}




unsigned long Controlador_bin::importarCSV(bool *modificarp, bool *final, int pos, string *recuperado){
    ifstream fin;
    int posicion_actual=0;
    unsigned long ite;
    fin.open("Copia_Seguridad.csv");
    if(!fin.is_open()){
        *final=0;
        return -1;
    }
    string aux[9];
    getline(fin,aux[0],'\n');
    int tamanio=(aux[0].length())-(ReplaceAll3(aux[0],",","").length());
    if(aux[0].length()%2==0)
        ite=aux[0].length();
    else
        ite=aux[0].length()+1;
    int res;
    for(int i=0;i<=pos;i++){
        getline(fin,aux[0],'\n');
    }

    string* token;
    while(!fin.eof()){
            for(int i=0;i<=tamanio;i++){
                token=kaiser(&ite,fin);
                if(token)
                    aux[i]=*token;
                else{
                    *final=0;
                    return -1;
                }
            }
                email z;
                    res = stoi(aux[0]);
                    stringstream ss;
                    ss << res;
                    string s;
                    ss >>s;
                    *recuperado=s;
                    strcpy(z.Identificador,s.c_str());
                    strcpy(z.Fecha, aux[1].c_str());
                    strcpy(z.Hora, aux[2].c_str());
                    strcpy(z.From, aux[3].c_str());
                    strcpy(z.To,aux[4].c_str());
                    strcpy(z.CC, aux[5].c_str());
                    strcpy(z.BCC, aux[6].c_str());
                    strcpy(z.subject,aux[7].c_str());
                    strcpy(z.Content,ReplaceAll3(aux[8],"\n\n","\n").c_str());
                    aux[0]="\0";aux[1]="\0";aux[2]="\0";aux[3]="\0";aux[4]="\0";aux[5]="\0";aux[6]="\0";aux[7]="\0";aux[8]="\0";

                    if(pos==posicion_actual and *modificarp==true){
                        pos++;
                        *modificarp=false;
                        modificar(z);
                    }
                    else if(pos<=posicion_actual and *modificarp==false){
                            if(!agregar(z)){
                                return posicion_actual;
                            }
                    }
                posicion_actual++;

    }
    fin.close();
    *final=0;
    return -1;
}

email Controlador_bin::busquedaIDCSV(string Id)
{
    ifstream fin;
    unsigned long ite;
    email Idcomparar;
    fin.open("Copia_Seguridad.csv");
    if(!fin.is_open()){
        fin.close();
        return Idcomparar;
    }
    string aux[9];
    getline(fin,aux[0],'\n');
    int tamanio=(aux[0].length())-(ReplaceAll3(aux[0],",","").length());
    if(aux[0].length()%2==0)
        ite=aux[0].length();
    else
        ite=aux[0].length()+1;
    int res;
    string* token;

    while(!fin.eof()){
            for(int i=0;i<=tamanio;i++){
                token=kaiser(&ite,fin);
                if(token)
                    aux[i]=*token;
                else{
                    return Idcomparar;
                }
            }
                email z;
                    res = stoi(aux[0]);
                    stringstream ss;
                    ss << res;
                    string s;
                    ss >>s;
                    if(Id==s){
                        strcpy(z.Identificador,s.c_str());
                        strcpy(z.Fecha, aux[1].c_str());
                        strcpy(z.Hora, aux[2].c_str());
                        strcpy(z.From, aux[3].c_str());
                        strcpy(z.To,aux[4].c_str());
                        strcpy(z.CC, aux[5].c_str());
                        strcpy(z.BCC, aux[6].c_str());
                        strcpy(z.subject,aux[7].c_str());
                        strcpy(z.Content,ReplaceAll3(aux[8],"\n\n","\n").c_str());
                        return z;
                    }
                    aux[0]="\0";aux[1]="\0";aux[2]="\0";aux[3]="\0";aux[4]="\0";aux[5]="\0";aux[6]="\0";aux[7]="\0";aux[8]="\0";
    }
    fin.close();
    return Idcomparar;
}

bool Controlador_bin::modificarCSV(email e)
{
    ifstream fin;
    ofstream fout("auxiliar.csv");
    unsigned long ite;
    fin.open("Copia_Seguridad.csv");
    if(!fin.is_open()){
        fin.close();
        return 0;
    }
    string aux[9];
    getline(fin,aux[0],'\n');
    int tamanio=(aux[0].length())-(ReplaceAll3(aux[0],",","").length());
    if(aux[0].length()%2==0)
        ite=aux[0].length();
    else
        ite=aux[0].length()+1;
    int res;
    bool salir =0;
    string* token;
    fout <<aux[0]<<endl;

    while(!fin.eof()){
        for(int i=0;i<=tamanio;i++){
            token=kaiser(&ite,fin);
            if(token)
                aux[i]=*token;
            else{
                salir = 1;
                break;
            }
        }
        if(salir==1)
            break;
            email z;
            aux[0]=ReplaceAll3(aux[0],"\n","");
                    res = stoi(aux[0]);
                    stringstream ss;
                    ss << res;
                    string s;
                    ss >>s;
                    string auxid=e.Identificador;

                    if(stoi(e.Identificador)==res){
                        if(e.Hora[0]=='-'){}
                        else
                        fout << *toCSV(e) <<endl;
                    }
                    else{
                    strcpy(z.Identificador,aux[0].c_str());
                    strcpy(z.Fecha, aux[1].c_str());
                    strcpy(z.Hora, aux[2].c_str());
                    strcpy(z.From, aux[3].c_str());
                    strcpy(z.To,aux[4].c_str());
                    strcpy(z.CC, aux[5].c_str());
                    strcpy(z.BCC, aux[6].c_str());
                    strcpy(z.subject,aux[7].c_str());
                    strcpy(z.Content,ReplaceAll3(aux[8],"\n\n","\n").c_str());
                    fout << *toCSV(z)<<endl;
                    }

                aux[0]="\0";aux[1]="\0";aux[2]="\0";aux[3]="\0";aux[4]="\0";aux[5]="\0";aux[6]="\0";aux[7]="\0";aux[8]="\0";
}
    fin.close();
    fout.close();
    remove("Copia_Seguridad.csv");
    rename("auxiliar.csv","Copia_Seguridad.csv");
    return 1;
}

char *Controlador_bin::toSerialize(email recibido, int *tamanio, char *&s)
{
    *tamanio=0;
    int tamanio_aux;
    string aux[9];
    int posicion_serializado=0;
    aux[0]=recibido.Identificador;
    aux[1]=recibido.Fecha;
    aux[2]=recibido.Hora;
    aux[3]=recibido.From;
    aux[4]=recibido.To;
    aux[5]=recibido.CC;
    aux[6]=recibido.BCC;
    aux[7]=recibido.subject;
    aux[8]=recibido.Content;
    for(int i= 0; i<9;i++)
        *tamanio+=sizeof(int)+aux[i].length();
    s = new char[*tamanio];
    for(int j=0;j<9;j++){
        tamanio_aux=aux[j].length();
        for(int i = 0;i<sizeof(int);i++,posicion_serializado++)
            s[posicion_serializado]= (((char*)&tamanio_aux))[i];
        char charaux[tamanio_aux];
        aux[j].copy(charaux,tamanio_aux);
        for(int i = 0;i<tamanio_aux;i++,posicion_serializado++)
            s[posicion_serializado]= charaux[i];
    }
    return s;
}

bool Controlador_bin::validaN(string entrada)
{
    bool valida=true;
    int tamanio=entrada.size();
    for(int i=0;i<tamanio;i++){
        if(entrada[i]<=48 or entrada[i]>=58){
                valida=false;
                break;
            }
    }
    return valida;
}
void Controlador_bin::exportarCdD()
{
    ifstream fin;
    ofstream fout;
    int secuencia=0;
    email correo_aux;
    fin.open("documento.txt",ios::binary);
    if(!fin.is_open())
        return;
    fout.open("Campos_de_Dimension.bin",ios::binary);
    fin.seekg(secuencia*sizeof(email));
    fin.read((char*) &correo_aux,sizeof(email));
    secuencia++;
    char* recibido;
    int* tamanio =new int(0);
    while(!fin.eof()){
        string aux=correo_aux.Identificador;
        if(aux.length()>0 )
            if(aux.length()<=10){
                if(validaN(aux)){
                    toSerialize(correo_aux,tamanio,recibido);
                    fout.write(recibido,*tamanio);
                    fout <<endl;
                }
            }
        fin.seekg(secuencia*sizeof(email));
        fin.read((char*) &correo_aux,sizeof(email));
        secuencia++;
        }
    fin.close();
    fout.close();
}

email Controlador_bin::busquedaIDCdD(string Id)
{
    ifstream fin;
    fin.open("Campos_de_Dimension.bin",ios::binary);
    email Idcomparar;
    char tamanio_recibido[4];
    int tamanio;
    char* aux;
    char auxendl;
    string auxstr="";
    if(!fin.is_open())
        return Idcomparar;
    while(!fin.eof()){
        for(int i=1;i<10;i++){
            fin.read(tamanio_recibido,sizeof (int));
            for(int j=0;j<sizeof (int);j++)
                ((char*)(&tamanio))[j]=tamanio_recibido[j];
            aux=new char[tamanio];
            fin.read(aux,tamanio);
            for(int j=0;j<tamanio;j++){
                auxstr=auxstr+aux[j];
            }
            if(i==1)
                 strcpy(Idcomparar.Identificador,auxstr.c_str());
            else if(i==2)
                strcpy(Idcomparar.Fecha,auxstr.c_str());
            else if(i==3)
                strcpy(Idcomparar.Hora,auxstr.c_str());
            else if(i==4)
                strcpy(Idcomparar.From,auxstr.c_str());
            else if(i==5)
                strcpy(Idcomparar.To,auxstr.c_str());
            else if(i==6)
                strcpy(Idcomparar.CC,auxstr.c_str());
            else if(i==7)
                strcpy(Idcomparar.BCC,auxstr.c_str());
            else if(i==8)
                strcpy(Idcomparar.subject,auxstr.c_str());
            else if(i==9)
                strcpy(Idcomparar.Content,auxstr.c_str());
            auxstr.clear();
        }
        fin.read((char*)&auxendl,sizeof(char));
        if(string(Idcomparar.Identificador)==Id)
            return Idcomparar;
    }
    return Idcomparar;
}

bool Controlador_bin::modificarCdD(email e, string old)
{
    ofstream fout;
    ifstream fin;
    fin.open("Campos_de_Dimension.bin",ios::binary);
    email Idcomparar;
    char tamanio_recibido[4];
    int tamanio;
    char* aux;
    char auxendl;
    string auxstr="";
    if(!fin.is_open())
        return false;
    fout.open("auxiliar.bin",ios::binary);
    char* recibido;
    int* tamanio2 =new int(0);
    for(int i=1;i<10;i++){
        fin.read(tamanio_recibido,sizeof (int));
        for(int j=0;j<sizeof (int);j++)
            ((char*)(&tamanio))[j]=tamanio_recibido[j];
        aux=new char[tamanio];
        fin.read(aux,tamanio);
        for(int j=0;j<tamanio;j++){
            auxstr=auxstr+aux[j];
        }
        if(i==1)
             strcpy(Idcomparar.Identificador,auxstr.c_str());
        else if(i==2)
            strcpy(Idcomparar.Fecha,auxstr.c_str());
        else if(i==3)
            strcpy(Idcomparar.Hora,auxstr.c_str());
        else if(i==4)
            strcpy(Idcomparar.From,auxstr.c_str());
        else if(i==5)
            strcpy(Idcomparar.To,auxstr.c_str());
        else if(i==6)
            strcpy(Idcomparar.CC,auxstr.c_str());
        else if(i==7)
            strcpy(Idcomparar.BCC,auxstr.c_str());
        else if(i==8)
            strcpy(Idcomparar.subject,auxstr.c_str());
        else if(i==9)
            strcpy(Idcomparar.Content,auxstr.c_str());
        auxstr.clear();
    }
    fin.read((char*)&auxendl,sizeof(char));
    while(!fin.eof()){
        if(string(Idcomparar.Identificador)!=old){
            toSerialize(Idcomparar,tamanio2,recibido);
            fout.write(recibido,*tamanio2);
            fout <<endl;
        }
        else if(e.Hora[0]!='-'){
            toSerialize(e,tamanio2,recibido);
            fout.write(recibido,*tamanio2);
            fout <<endl;

        }

        for(int i=1;i<10;i++){
            fin.read(tamanio_recibido,sizeof (int));
            for(int j=0;j<sizeof (int);j++)
                ((char*)(&tamanio))[j]=tamanio_recibido[j];
            aux=new char[tamanio];
            fin.read(aux,tamanio);
            for(int j=0;j<tamanio;j++){
                auxstr=auxstr+aux[j];
            }
            if(i==1)
                 strcpy(Idcomparar.Identificador,auxstr.c_str());
            else if(i==2)
                strcpy(Idcomparar.Fecha,auxstr.c_str());
            else if(i==3)
                strcpy(Idcomparar.Hora,auxstr.c_str());
            else if(i==4)
                strcpy(Idcomparar.From,auxstr.c_str());
            else if(i==5)
                strcpy(Idcomparar.To,auxstr.c_str());
            else if(i==6)
                strcpy(Idcomparar.CC,auxstr.c_str());
            else if(i==7)
                strcpy(Idcomparar.BCC,auxstr.c_str());
            else if(i==8)
                strcpy(Idcomparar.subject,auxstr.c_str());
            else if(i==9)
                strcpy(Idcomparar.Content,auxstr.c_str());
            auxstr.clear();
        }
        fin.read((char*)&auxendl,sizeof(char));

    }
    fin.close();
    fout.close();
    remove("Campos_de_Dimension.bin");
    rename("auxiliar.bin","Campos_de_Dimension.bin");
    return true;
}

email *Controlador_bin::BusquedaEnMemoriaArchivo(int *cont)
{
    ifstream fin("documento.txt",ios::binary);
    int secuencia=0;
    int centena=100;
    email correo_aux;
    if(!fin.is_open())
        return nullptr;
    email* lista_a_regresar=new email[100];
    fin.seekg(secuencia*sizeof(email));
    fin.read((char*) &correo_aux,sizeof(email));
    secuencia++;
    while(!fin.eof()){
        string aux=correo_aux.Identificador;
        if(aux.length()>0 )
            if(aux.length()<=10){
                if(validaN(aux)){
                    if(*cont>=centena){
                        centena=centena +100;
                        email *newlista=new email[centena];
                        for(int i=0;i<*cont;i++){
                            newlista[i]=lista_a_regresar[i];
                        }
                        delete []lista_a_regresar;
                        lista_a_regresar=newlista;
                    }
                    lista_a_regresar[*cont]=correo_aux;
                    (*cont)++;
                }
            }
        fin.seekg(secuencia*sizeof(email));
        fin.read((char*) &correo_aux,sizeof(email));
        secuencia++;
        }
    return lista_a_regresar;


}

unsigned long Controlador_bin::crearavl(int pos, string *recuperado, string *otronombre_recuperado)
{
    ifstream fin;
    string aux;
    email Idcomparar;
    stringstream ss;
    fin.open("documento.txt",ios::binary|ios::out|ios::in);
    if(!fin.is_open() or pos==-1){
        fin.close();
        return -1;
    }
    if(pos!=0)
        pos++;
    fin.seekg(pos*(sizeof(email)));
    while(!fin.eof()){
        fin.read((char*) &Idcomparar,sizeof(email));
        aux=Idcomparar.Identificador;
        if(aux.length()>0 )
            if(aux.length()<=10)
                if(validaN(aux)){
                    ss<<aux;
                    ss>>pos;
                    *recuperado=Idcomparar.From;
                    *otronombre_recuperado=Idcomparar.To;
                    return pos;
                }

    }
    fin.close();
    return -1;
}
#define NUM 4;
int Controlador_bin::Caesar_cipher(string contrasena)
{
    ifstream fin("Copia_Seguridad.csv");
    if(!fin.is_open())
        return 0;
    ofstream fout("CSV_Cifrada",ios::binary);
    for(int i=0;i<contrasena.length();i++){
        char letra_aux=contrasena[i];
        letra_aux=letra_aux+NUM
        fout.write(&letra_aux,sizeof(char));
    }

    char letra;
    fin.read(&letra,sizeof(char));
    letra=letra+NUM;
    while(!fin.eof()){
        fout.write(&(letra),sizeof(char));
        fin.read(&letra,sizeof(char));
        letra=letra+NUM;
    }
    fin.close();
    fout.close();
    return 1;
}

int Controlador_bin::Caesar_decipher(string contrasena)
{
    ifstream fin2("CSV_Cifrada",ios::binary);
    if(!fin2.is_open())
        return 0;
    for(int i=0;i<contrasena.length();i++){
        char letra_aux=contrasena[i];
        letra_aux=letra_aux+NUM
        char letra_rec;
        fin2.read(&letra_rec,sizeof(char));
        if(letra_rec!=letra_aux)
            return 0;
    }
    char letra;
    ofstream fout2("CSV_desde_el_caesar.csv");
    fin2.read(&letra,sizeof(char));
    letra=letra-NUM;
    while(!fin2.eof()){
        fout2.write(&letra,sizeof(char));
        fin2.read(&letra,sizeof(char));
        letra=letra-NUM;
    }
    return 1;
}

int Controlador_bin::RLE_compression()
{
    ifstream fin("Copia_Seguridad.csv");
    if(!fin.is_open())
        return 0;
    ofstream fout("CSV_Comprimido.txt");
    char letra;
    int i=1;
    char letra_act;
    fin.read(&letra,sizeof(char));
    letra_act=letra;
    while(!fin.eof()){
        fin.read(&letra,sizeof(char));
        if(letra_act==letra){
            i++;
        }
        else if(letra_act!=letra){
            fout<<i;
            fout.write(&letra_act,sizeof(char));
            i=1;
            letra_act=letra;
        }
    }
    return 1;
}

int Controlador_bin::RLE_decompression()
{
    ifstream fin("CSV_Comprimido.txt");
    if(!fin.is_open())
        return 0;
    ofstream fout("CSV_Descomprimido.csv");
    char letra;
    bool estado=0;
    int cant=1;
    fin.read(&letra,sizeof(char));
    while(!fin.eof()){
        if(estado){
            for(int i=0;i<cant;i++)
                fout.write(&letra,sizeof(char));
            estado=0;
        }
        else{
            cant=letra-48;
            estado=1;
        }
        fin.read(&letra,sizeof(char));
    }
    return 1;
}
Controlador_bin::Controlador_bin()
{

}

bool Controlador_bin::agregar(email e)
{
    fstream os;
    double input;
    stringstream sso;
    email comprobacion=busquedaID((string)e.Identificador);
    os.open("documento.txt",ios::binary|ios::out|ios::in);
    if(!os.is_open()){
        os.close();
        os.open("documento.txt",ios::binary|ios::out);
    }
    sso <<e.Identificador;
    sso >> input;
    if((string)comprobacion.Identificador==(string)e.Identificador){
        os.close();
        return 0;
    }
    os.seekp(input*(sizeof(email)));
    os.write((char *)&e,sizeof(email));

    ofstream fout("Indices_Primarios.bin",ios::binary|ios::in);
    char bandera[sizeof(unsigned int)*2]={'0','0','0','0','0','0','0','0'};
    fout.write(bandera,sizeof(unsigned int)*2);

    os.close();
    return 1;
}
bool Controlador_bin::modificar(email e)
{
    fstream os;
    double input;
    stringstream sso;
    char z[sizeof(email)];
    os.open("documento.txt",ios::binary|ios::out|ios::in);
    if(!os.is_open()){
        os.close();
        return 0;
    }
    sso <<e.Identificador;
    sso >> input;
    if((string)e.From==""){
        os.seekp(input*(sizeof(email)));
        os.write((char *)&z,sizeof(email));
    }
    else{
        os.seekp(input*(sizeof(email)));
        os.write((char *)&e,sizeof(email));
    }
    os.close();
    return 1;
}

void Controlador_bin::exportarCSV()
{
    fstream os;
    int secuencia=0;
    email correo_aux;
    os.open("documento.txt",ios::in);
    if(!os.is_open()){
        os.close();
        return;
    }
    ofstream oscsv("Copia_Seguridad.csv",ios::out);
    oscsv <<"Identificador"<< ','<<"Fecha de envio" << ','<<"Hora de envio" << ',' <<"Remitente"<< ',' << "Destinatario" << ',' <<"Copia Carbon" << ',' <<"Copia Carbon Ciega" << ',' <<"Asunto"<< ',' <<"Contenido" << endl;
    os.seekg(secuencia*sizeof(email));
    os.read((char*) &correo_aux,sizeof(email));
    secuencia++;
    while(!os.eof()){
        string aux=correo_aux.Identificador;
        if(aux.length()>0 )
            if(aux.length()<=10)
                if(validaN(aux))
                    oscsv << *toCSV(correo_aux) << endl;

        os.seekg(secuencia*sizeof(email));
        os.read((char*) &correo_aux,sizeof(email));
        secuencia++;
        }
    os.close();
    oscsv.close();

}

email Controlador_bin::busquedaID(string Id)
{
    fstream os;
    double input;
    stringstream sso;
    email Idcomparar;
    os.open("documento.txt",ios::binary|ios::out|ios::in);
    if(!os.is_open()){
        os.close();
        return Idcomparar;
    }
    sso << Id;
    sso >> input;
    os.seekg(input*(sizeof(email)));
    os.read((char*) &Idcomparar,sizeof(email));
    os.close();
    return Idcomparar;

}

email Controlador_bin::busquedaFrom(string From, double secuencia)
{
    fstream os;
    email Idcomparar;
    os.open("documento.txt",ios::binary|ios::out|ios::in);
    if(!os.is_open()){
        os.close();
        return Idcomparar;
    }
    while(!os.eof()){
    os.seekg(secuencia*sizeof(email));
    os.read((char*) &Idcomparar,sizeof(email));
    secuencia++;
    if((string)Idcomparar.From==From)
        break;
    }
    os.close();
    return Idcomparar;

}

