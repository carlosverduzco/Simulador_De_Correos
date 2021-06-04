#include "model_email.h"

Model_email::Model_email()
{

}
string ReplaceAlll(string str, const string& from, const string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return str;
}
int Model_email::agregar(string Id, string R, string D, string CC, string BCC, string S, string C)
{
    email z;
    Controlador_bin aka;
    if(Id.length()<=10){
        if(Id.length()>0){
            if(ReplaceAlll(ReplaceAlll(ReplaceAlll(ReplaceAlll(ReplaceAlll(ReplaceAlll(ReplaceAlll(ReplaceAlll(ReplaceAlll(ReplaceAlll(Id, string("9"), string("")), string("8"), string("")), string("7"), string("")), string("6"), string("")), string("5"), string("")), string("4"), string("")), string("3"), string("")), string("2"), string("")), string("1"), string("")), string("0"), string("")).length()==0){
                if(R.length()<=30 && R.length()>0){
                    if(D.length()<=30 && D.length()>0){
                        if(CC.length()<=50){
                            if(BCC.length()<=50){
                                if(S.length()<=30){
                                    if(C.length()<=100){
                                        strcpy(z.Identificador, Id.c_str());
                                        strcpy(z.From, R.c_str());
                                        strcpy(z.To,D.c_str());
                                        strcpy(z.CC, CC.c_str());
                                        strcpy(z.BCC, BCC.c_str());
                                        strcpy(z.subject,S.c_str());
                                        strcpy(z.Content, C.c_str());
                                        //sacar hora y fecha
                                        string prov;
                                        stringstream ss;
                                        time_t now= time(0);
                                        tm* time =localtime(&now);
                                        if(time->tm_mday<10)
                                            ss << "0";
                                        ss<< time->tm_mday <<"/";
                                        if((time->tm_mon+1)<10)
                                            ss << "0";
                                        ss<<time->tm_mon+1<<"/"<<time->tm_year+1900;
                                        ss >> prov;
                                        strcpy(z.Fecha,prov.c_str());
                                        ss.clear();
                                        ss <<endl;
                                        if(time->tm_hour<10)
                                            ss << "0";
                                        ss << time->tm_hour << ":";
                                        if(time->tm_min<10)
                                            ss << "0";
                                        ss <<time->tm_min;
                                        ss >> prov;
                                        strcpy(z.Hora, prov.c_str());
                                        //
                                        if(!aka.agregar(z))
                                            return 1;
                                        else
                                            return 0;

                                    }
                                    else{
                                        return 2;
                                    }
                                }else{
                                    return 3;
                                }
                            }else{
                                return 4;
                            }
                        }else{
                            return 5;
                        }
                    }else{
                       return 6;
                    }
                }else{
                   return 7;
                }
            }else{
                return 8;
            }
        }else{
            return 9;
        }
    }else{
        return 10;
    }
}

bool Model_email::leerDirecto(string *Id, string *F, string *H, string *R, string *D, string *CC, string *BCC, string *S, string *C)
{
        Model_email model;
        Controlador_bin aka;
        email regreso = aka.busquedaID(*Id);
        if((string)regreso.Identificador==*Id){
            *Id=regreso.Identificador;
            *F=regreso.Fecha;
            *H=regreso.Hora;
            *R=regreso.From;
            *D= regreso.To;
            *CC=regreso.CC;
            *BCC=regreso.BCC;
            *S=regreso.subject;
            *C=regreso.Content;
            return 1;
        }
        return 0;
}

bool Model_email::leerSecuencial(string *Id, string *F, string *H, string *R, string *D, string *CC, string *BCC, string *S, string *C, double input)
{
    Controlador_bin aka;
    email regreso = aka.busquedaFrom(*R,input+1);
    if((string)regreso.From==*R){
        *Id=regreso.Identificador;
        *F=regreso.Fecha;
        *H=regreso.Hora;
        *R=regreso.From;
        *D= regreso.To;
        *CC=regreso.CC;
        *BCC=regreso.BCC;
        *S=regreso.subject;
        *C=regreso.Content;
        return 1;
    }
    return 0;
}

int Model_email::modificar(string Id, string R, string D, string CC, string BCC, string S, string C)
{
    email z;
    Controlador_bin aka;
    if(Id.length()<=10){
        if(Id.length()>0){
            if(ReplaceAlll(ReplaceAlll(ReplaceAlll(ReplaceAlll(ReplaceAlll(ReplaceAlll(ReplaceAlll(ReplaceAlll(ReplaceAlll(ReplaceAlll(Id, string("9"), string("")), string("8"), string("")), string("7"), string("")), string("6"), string("")), string("5"), string("")), string("4"), string("")), string("3"), string("")), string("2"), string("")), string("1"), string("")), string("0"), string("")).length()==0){
                if(R.length()<=30 && R.length()>0){
                    if(D.length()<=30 && D.length()>0){
                        if(CC.length()<=50){
                            if(BCC.length()<=50){
                                if(S.length()<=30){
                                    if(C.length()<=100){
                                        strcpy(z.Identificador, Id.c_str());
                                        strcpy(z.From, R.c_str());
                                        strcpy(z.To,D.c_str());
                                        strcpy(z.CC, CC.c_str());
                                        strcpy(z.BCC, BCC.c_str());
                                        strcpy(z.subject,S.c_str());
                                        strcpy(z.Content, C.c_str());
                                        //sacar hora y fecha
                                        string prov;
                                        stringstream ss;
                                        time_t now= time(0);
                                        tm* time =localtime(&now);
                                        if(time->tm_mday<10)
                                            ss << "0";
                                        ss<< time->tm_mday <<"/";
                                        if((time->tm_mon+1)<10)
                                            ss << "0";
                                        ss<<time->tm_mon+1<<"/"<<time->tm_year+1900;
                                        ss >> prov;
                                        strcpy(z.Fecha,prov.c_str());
                                        ss.clear();
                                        ss <<endl;
                                        if(time->tm_hour<10)
                                            ss << "0";
                                        ss << time->tm_hour << ":";
                                        if(time->tm_min<10)
                                            ss << "0";
                                        ss <<time->tm_min;
                                        ss >> prov;
                                        strcpy(z.Hora, prov.c_str());
                                        //
                                        if(!aka.modificar(z))
                                            return 1;
                                        else
                                            return 0;

                                    }
                                    else{
                                        return 2;
                                    }
                                }else{
                                    return 3;
                                }
                            }else{
                                return 4;
                            }
                        }else{
                            return 5;
                        }
                    }else{
                       return 6;
                    }
                }else{
                   return 7;
                }
            }else{
                return 8;
            }
        }else{
            return 9;
        }
    }else{
        return 10;
    }
}

bool Model_email::eliminar(string Id)
{
    email z;
    if(Id.length()==0)
        return false;
    Controlador_bin aka;
    strcpy(z.Identificador, Id.c_str());
    strcpy(z.From, "");
    aka.modificar(z);
    return true;


}

void Model_email::exportar()
{
    Controlador_bin z;
    z.exportarCSV();

}

int Model_email::importar(bool *modificar, bool *final, int pos, string *recuperado)
{
    Controlador_bin z;
    return z.importarCSV(modificar, final,  pos,recuperado);


}

bool Model_email::leerDirectoCSV(string *Id, string *F, string *H, string *R, string *D, string *CC, string *BCC, string *S, string *C)
{

    Controlador_bin aka;
    email regreso = aka.busquedaIDCSV(*Id);
    if((string)regreso.Identificador==*Id){
        *Id=regreso.Identificador;
        *F=regreso.Fecha;
        *H=regreso.Hora;
        *R=regreso.From;
        *D= regreso.To;
        *CC=regreso.CC;
        *BCC=regreso.BCC;
        *S=regreso.subject;
        *C=regreso.Content;
        return 1;
    }
    return 0;
}

int Model_email::modificarCSV(string Id, string F, string H, string R, string D, string CC, string BCC, string S, string C)
{
    email z;
    Controlador_bin aka;
    if(Id.length()<=10){
        if(Id.length()>0){
            if(ReplaceAlll(ReplaceAlll(ReplaceAlll(ReplaceAlll(ReplaceAlll(ReplaceAlll(ReplaceAlll(ReplaceAlll(ReplaceAlll(ReplaceAlll(Id, string("9"), string("")), string("8"), string("")), string("7"), string("")), string("6"), string("")), string("5"), string("")), string("4"), string("")), string("3"), string("")), string("2"), string("")), string("1"), string("")), string("0"), string("")).length()==0){
                if(R.length()<=30 && R.length()>0){
                    if(D.length()<=30 && D.length()>0){
                        if(CC.length()<=50){
                            if(BCC.length()<=50){
                                if(S.length()<=30){
                                    if(C.length()<=100){
                                        strcpy(z.Identificador, Id.c_str());
                                        strcpy(z.From, R.c_str());
                                        strcpy(z.To,D.c_str());
                                        strcpy(z.CC, CC.c_str());
                                        strcpy(z.BCC, BCC.c_str());
                                        strcpy(z.subject,S.c_str());
                                        strcpy(z.Content, C.c_str());
                                        strcpy(z.Fecha,F.c_str());
                                        strcpy(z.Hora, H.c_str());

                                        if(!aka.modificarCSV(z))
                                            return 1;
                                        else
                                            return 0;

                                    }
                                    else{
                                        return 2;
                                    }
                                }else{
                                    return 3;
                                }
                            }else{
                                return 4;
                            }
                        }else{
                            return 5;
                        }
                    }else{
                       return 6;
                    }
                }else{
                   return 7;
                }
            }else{
                return 8;
            }
        }else{
            return 9;
        }
    }else{
        return 10;
    }
}

bool Model_email::eliminarCSV(string Id)
{
    Controlador_bin a;
    email z;
    strcpy(z.Identificador, Id.c_str());
    strcpy(z.Hora,"-");
    a.modificarCSV(z);
}

void Model_email::exportar2()
{
    Controlador_bin z;
    z.exportarCdD();
}

bool Model_email::leerDirectoCdD(string *Id, string *F, string *H, string *R, string *D, string *CC, string *BCC, string *S, string *C)
{
    Controlador_bin aka;
    email regreso = aka.busquedaIDCdD(*Id);
    if((string)regreso.Identificador==*Id){
        *Id=regreso.Identificador;
        *F=regreso.Fecha;
        *H=regreso.Hora;
        *R=regreso.From;
        *D= regreso.To;
        *CC=regreso.CC;
        *BCC=regreso.BCC;
        *S=regreso.subject;
        *C=regreso.Content;
        return 1;
    }

    return 0;
}

int Model_email::modificarCdD(string Id, string F, string H, string R, string D, string CC, string BCC, string S, string C, string newid)
{
    email z;
    Controlador_bin aka;
    email regreso = aka.busquedaIDCdD(newid);
    if((string)regreso.Identificador==newid)
        return 11;
    if(newid.length()<=10){
        if(newid.length()>0){
            if(ReplaceAlll(ReplaceAlll(ReplaceAlll(ReplaceAlll(ReplaceAlll(ReplaceAlll(ReplaceAlll(ReplaceAlll(ReplaceAlll(ReplaceAlll(Id, string("9"), string("")), string("8"), string("")), string("7"), string("")), string("6"), string("")), string("5"), string("")), string("4"), string("")), string("3"), string("")), string("2"), string("")), string("1"), string("")), string("0"), string("")).length()==0){
                if(R.length()<=30 && R.length()>0){
                    if(D.length()<=30 && D.length()>0){
                        if(CC.length()<=50){
                            if(BCC.length()<=50){
                                if(S.length()<=30){
                                    if(C.length()<=100){
                                        strcpy(z.Identificador, newid.c_str());
                                        strcpy(z.From, R.c_str());
                                        strcpy(z.To,D.c_str());
                                        strcpy(z.CC, CC.c_str());
                                        strcpy(z.BCC, BCC.c_str());
                                        strcpy(z.subject,S.c_str());
                                        strcpy(z.Content, C.c_str());
                                        strcpy(z.Fecha,F.c_str());
                                        strcpy(z.Hora, H.c_str());

                                        if(!aka.modificarCdD(z,Id))
                                            return 1;
                                        else
                                            return 0;

                                    }
                                    else{
                                        return 2;
                                    }
                                }else{
                                    return 3;
                                }
                            }else{
                                return 4;
                            }
                        }else{
                            return 5;
                        }
                    }else{
                       return 6;
                    }
                }else{
                   return 7;
                }
            }else{
                return 8;
            }
        }else{
            return 9;
        }
    }else{
        return 10;
    }
}

bool Model_email::eliminarCdD(string Id)
{
    Controlador_bin a;
    email z;
    strcpy(z.Identificador, Id.c_str());
    strcpy(z.Hora,"-");
    a.modificarCdD(z,Id);
}

email *Model_email::BusquedaEnMemoria(int *cont)
{
    Controlador_bin a;
    return a.BusquedaEnMemoriaArchivo(cont);
}

int Model_email::crearavl(int pos, string *recuperado, string *otronombre_recuperado)
{
    Controlador_bin z;
    return z.crearavl(pos,recuperado,otronombre_recuperado);
}

int Model_email::CifrarDescifrar(bool opcion, string contrasena)
{
    Controlador_bin z;
    if(contrasena.length()!=4){
        return 1;
    }
    for(int i=0;i<contrasena.length();i++){
        if(!('0' <= contrasena[i] && contrasena[i] <= '9')){
            return 2;
        }
    }
    if(opcion){
        z.Caesar_cipher(contrasena);
    }
    else{
        z.Caesar_decipher(contrasena);
    }
    return 0;
}

int Model_email::ComprimirDescomprimir(bool opcion)
{
    Controlador_bin k;
    if(opcion){
        k.RLE_compression();
    }
    else{
        k.RLE_decompression();
    }
}
