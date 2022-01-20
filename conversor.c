#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char HexaValor[1004]; // Tengo que crear esta variable porque no puedo pasar una cadena de caracteres como return de una función


long long Pot (int Base, int Exponente) {
    if (Exponente==0) {
        return 1;
    } else {
        return Base*Pot(Base,Exponente-1);
    }
}

char HexaConverter (int Numero) { // Funcion para Convertir Decimal a Hexa a un solo Numero. El Numero tiene que estar entre 0 y 15
        // NUMERO A LETRA
    if (Numero >= 0 && Numero <= 15) {
        if(Numero<10) {
            return Numero+'0';
        } else {
            switch (Numero) {
                // NUMERO A LETRA
                case 10 :
                    return 'A';
                break;
                case 11 :
                    return 'B';
                break;
                case 12 :
                    return 'C';
                break;
                case 13 :
                    return 'D';
                break;
                case 14 :
                    return 'E';
                break;
                case 15 :
                    return 'F';
                break;
            }
        }
    }
    return '0';
}

int HexaToDecConverter (char Hexa) {
        // LETRA A NUMERO
    if (Hexa=='1') {return atoi(&Hexa);}
    if (Hexa=='2') {return atoi(&Hexa);}
    if (Hexa=='3') {return atoi(&Hexa);}
    if (Hexa=='4') {return atoi(&Hexa);}
    if (Hexa=='5') {return atoi(&Hexa);}
    if (Hexa=='6') {return atoi(&Hexa);}
    if (Hexa=='7') {return atoi(&Hexa);}
    if (Hexa=='8') {return atoi(&Hexa);}
    if (Hexa=='9') {return atoi(&Hexa);}
    if (Hexa=='A') {return 10;}
    if (Hexa=='B') {return 11;}
    if (Hexa=='C') {return 12;}
    if (Hexa=='D') {return 13;}
    if (Hexa=='E') {return 14;}
    return -1;
}

long long BinToDec (char Binario[1000]) {

    long long Decimal=0;
    int i;

    for (i=0;i<1000;i++) {
        if(Binario[i]=='1'){
            Decimal=Decimal+Pot(2,i);
            if ((Decimal+Pot(2,i)) > 9223372036854) { printf ("\n         ERROR: Desbordamiento De Memoria en BinToDec.\n             Los Resultado a Continuación Pueden ser Incorrectos."); return -1; }
        } else if (Binario[i]=='0') {
            // No hacer nada
        } else if (Binario[i]=='$') {
            // No hacer nada
        } else {
            printf("ERROR EN EL BINARIO INGRESADO: Se ingreso un %c en la posicion %i", Binario[i], i);
            return -1;
        }
    }

    return Decimal;
}

long long DecToOct (long long Decimal) {
    long long Dividendo=Decimal, Cociente=0;
    int Divisor=8, Resto=0, i=0;
    char Octal[1000]="";

    if (Dividendo > (Divisor-1) ) {
        while(Dividendo > (Divisor-1) ) {
            Resto=Dividendo%Divisor;
            Cociente=Dividendo/Divisor;

            Octal[i]=Resto+'0';
            i++;

            Dividendo=Cociente;
        }


    } else return Decimal;

    char SWAP=' ';
    int Largo=0;
    for(i=0;i<1000;i++) {
        if (Octal[i]=='0' || Octal[i]=='1' || Octal[i]=='2' || Octal[i]=='3' || Octal[i]=='4' || Octal[i]=='5' || Octal[i]=='6' || Octal[i]=='7' || Octal[i]=='8' || Octal[i]=='9') Largo++;
    }

    for (i=0;i<(Largo/2);i++) {
        SWAP=Octal[i];
        Octal[i]=Octal[(Largo-1)-i];
        Octal[(Largo-1)-i]=SWAP;
    }

        // Agrega al Valor final el Cociente Final
    long long OctaValor=0;
    for(i=0;i<Largo;i++){
        if (Octal[i]=='0' || Octal[i]=='1' || Octal[i]=='2' || Octal[i]=='3' || Octal[i]=='4' || Octal[i]=='5' || Octal[i]=='6' || Octal[i]=='7') OctaValor=OctaValor+((Octal[i]-'0') * Pot(10, Largo-i-1));
            if ((OctaValor+((Octal[i]-'0') * Pot(10, Largo-i-1))) > 9223372036854) { printf ("\n         ERROR: Desbordamiento De Memoria en DecToOct.\n             Los Resultado a Continuación Pueden ser Incorrectos."); return -1; }
    }
    OctaValor=OctaValor+(Cociente * Pot(10, Largo));
        if ((OctaValor+(Cociente * Pot(10, Largo))) > 9223372036854) { printf ("\n         ERROR: Desbordamiento De Memoria en DecToOct.\n             Los Resultado a Continuación Pueden ser Incorrectos."); return -1; }


    return OctaValor;

}

long long DecToHex (long long Decimal) { //Pongo long long pero igualmente esta funcion no devuelve nada
    long long Dividendo=Decimal, Cociente=0;
    int Divisor=16, Resto=0, i=0;
    char Hexa[1000]="";

    if (Dividendo > (Divisor-1) ) {
        while(Dividendo > (Divisor-1) ) {
            Resto=Dividendo%Divisor;
            Cociente=Dividendo/Divisor;

            Hexa[i]=HexaConverter(Resto);
            i++;


            Dividendo=Cociente;
        }

    } else { HexaValor[0]=HexaConverter(Decimal); return 1; }

    sprintf(HexaValor,"%s%c", Hexa, HexaConverter(Cociente)); // Agrega al Valor final el Cociente Final

    char SWAP=' ';
    int Largo=0;
    for(i=0;i<1000;i++) {
        if (HexaValor[i]=='0' || HexaValor[i]=='1' || HexaValor[i]=='2' || HexaValor[i]=='3' || HexaValor[i]=='4' || HexaValor[i]=='5' || HexaValor[i]=='6' || HexaValor[i]=='7' || HexaValor[i]=='8' || HexaValor[i]=='9' || HexaValor[i]=='A' || HexaValor[i]=='B' || HexaValor[i]=='C' || HexaValor[i]=='D' || HexaValor[i]=='E' || HexaValor[i]=='F') Largo++;
    }

    for (i=0;i<(Largo/2);i++) {
        SWAP=HexaValor[i];
        HexaValor[i]=HexaValor[(Largo-1)-i];
        HexaValor[(Largo-1)-i]=SWAP;
    }

    return atoll(HexaValor); // EN VALORES GRANDES NO FUNCIONA !!!!!! Por eso se usa HexaValor para devolver el resultado
}

long long DecToBin (long long Decimal) {
    if (Decimal == -1) return 0; // LLAVE DE CORTE EN CASO DE ERROR EN EL OctToDec YA QUE SI INGRESO UN OCTAL DE MAYOR TAMAÑO QUE UN Long Long O QUE EL PROCESAMIENTO DEVUELVE UN RESULTADO MAYOR QUE LA VARIABLE Long Long EN LA FUNCION OctToDec LA FUNCION DEVUELVE UN -1, EL CUAL SI ES METE EN ESTA FUNCION COMO PARAMETRO, IMPRIME UN VALOR CUALQUIERA AL FINAL DEL CARTEL DE AVISO DE ERROR

    long long Dividendo=Decimal, Cociente=0;
    int Divisor=2, Resto=0, i=0;
    char Binario[1000]=" ";

    if (Dividendo > (Divisor-1) ) {
        while(Dividendo > (Divisor-1) ) {
            Resto=Dividendo%Divisor;
            Cociente=Dividendo/Divisor;

            Binario[i]=Resto+'0';
            i++;

            Dividendo=Cociente;
        }

        sprintf(Binario,"%s%i", Binario, Cociente); // Agrega al Valor final el Cociente Final

    char SWAP=' ';
    int Largo=0;
    for(i=0;i<1000;i++) {
        if (Binario[i]=='0' || Binario[i]=='1') Largo++;
    }

    for (i=0;i<(Largo/2);i++) {
        SWAP=Binario[i];
        Binario[i]=Binario[(Largo-1)-i];
        Binario[(Largo-1)-i]=SWAP;
    }

    printf("%s\n", Binario);
    return atoll(Binario); // EN VALORES GRANDES NO FUNCIONA !!!!!!
    } else {
        printf("%lld\n",Decimal);
        return Decimal;
    }

}

long long OctToDec (char Octal[1000]) {
    int i=0, Base=8, Largo=-1; // Tengo que inicializar el Largo en -1 ya que si lo inicializo en 0, el primero número del vector que se encuentre va a ser un Largo++ y va a quedar como 1, pero para el vector necesito que el numero que exista en la primera posicion sea 0
    long long Decimal=0;

    for(i=0;i<1000;i++) {
        if (Octal[i]=='0' || Octal[i]=='1' || Octal[i]=='2' || Octal[i]=='3' || Octal[i]=='4' || Octal[i]=='5' || Octal[i]=='6' || Octal[i]=='7') Largo++;
    }

    for(i=999; i>=0; i--) {
        if ((Octal[i])!='$') {
            Decimal=Decimal+((Octal[i]-'0')*(Pot(Base,(Largo-i)))); // Con el -'0' convertimos un caracter en entero ya que sacamos el codigo ascii al caracter. Ejemplo: Tomamos que el entero 2 tenga un valor en ascii de 50 y el entero 0 de 48, si hacemos Octal[i]-'0' estariamos haciendo un 50-48 que daria 2
            if ((Decimal+((Octal[i]-'0')*(Pot(Base,(Largo-i))))) > 9223372036854) { printf ("\n         ERROR: Desbordamiento De Memoria en OctToDec.\n             Los Resultado a Continuación Pueden ser Incorrectos."); return -1; }
        }
    }

    return Decimal;
}

long long HexToDec (char Hexa[1000]) {
     int i=0, Base=16, Largo=-1; // Tengo que inicializar el Largo en -1 ya que si lo inicializo en 0, el primero número del vector que se encuentre va a ser un Largo++ y va a quedar como 1, pero para el vector necesito que el numero que exista en la primera posicion sea 0
     long long Decimal=0;

    for(i=0;i<1000;i++) {
        if (Hexa[i]=='0' || Hexa[i]=='1' || Hexa[i]=='2' || Hexa[i]=='3' || Hexa[i]=='4' || Hexa[i]=='5' || Hexa[i]=='6' || Hexa[i]=='7' || Hexa[i]=='8' || Hexa[i]=='9' || Hexa[i]=='A' || Hexa[i]=='B' || Hexa[i]=='C' || Hexa[i]=='D' || Hexa[i]=='E' || Hexa[i]=='F') Largo++;
    }

    for(i=Largo; i>=0; i--) {
            Decimal=Decimal+((HexaToDecConverter(Hexa[i]))*(Pot(Base,(Largo-i))));
            if (Decimal+((HexaToDecConverter(Hexa[i]))*(Pot(Base,(Largo-i)))) > 9223372036854) { printf ("\n         ERROR: Desbordamiento De Memoria en HexToDec.\n             Los Resultado a Continuación Pueden ser Incorrectos."); return -1; }
    }

    return Decimal;
}

int main () {
    char Valor[1000], Caract=' ', Eleccion=' ';
    int i, Largo=0;

    for(i=0;i<1004;i++){
        HexaValor[i]=' ';
    }

    system("clear");

    for (i=0;i<1000;i++) {
        Valor[i]='$';
    }

    printf("Ingese la Unidad a Convertir:\n\t1.- Binario\n\t2.- Decimal\n\t3.- Octal\n\t4.- Hexadecimal\n\t5.- Salir\n\n Ingese Respuesta: ");
    fflush(stdin);
    Eleccion=getchar();

    if (Eleccion=='5') return 0;

    i=0;
    getchar(); // Por algun Motivo tengo que poner un getchar suelto para que agarre basura o un salto de linea por culpa del selector de unidad a convertir de arriba. Ni con un fflush se soluciona
    printf("\n Ingrese el Numero a Procesar: ");
    fflush(stdin);
    Caract=getchar();
    while (Caract!='\n') {
        Valor[i]=Caract;
        i++;
        fflush(stdin);
        Caract=getchar();
    }

    for(i=0;i<1000;i++) {
        if (Valor[i]!='$') Largo++;
    }

    printf("%lld", atoll(Valor));

    if (( (atoll(Valor) == 9223372036854775807 && Eleccion != '1') || atoll(Valor)<=-1 || (Largo > 63 && Eleccion == '1')/*  Limite de Caracteres y Numericos de Long Long */)) {
        char Desicion;
        printf("\n\n El Numero Ingresado Supera a la Memoria asignada en el Programa. Esto Puede Causar Resultados Erroneos!!");
        printf("  Desesa Continuar de Todos Modos? (1/0) > ");
        fflush(stdin);
        Desicion=getchar();
        if (Desicion=='n' || Desicion=='N' || Desicion=='0') {  system("clear"); main(); return 0; }
        getchar(); // Elimina Basura
    }

    char SWAP; // Para Invertar el Vector en Binario
    switch (Eleccion) {
        case '1' :

            printf("\n\n------\n El Numero En Binario es "); for(i=0;i<1000;i++) if (Valor[i]!='$') printf ("%c", Valor[i]);

               //Invierte el Vector ya que si ingeso un 000001 piensa que es 32
                        for (i=0;i<(Largo/2);i++) {
                SWAP=Valor[i];
                Valor[i]=Valor[(Largo-1)-i];
                Valor[(Largo-1)-i]=SWAP;
            }

            printf("\n\n El Numero En Decimal es %lld\n", BinToDec(Valor));
            printf("\n El Numero En Octal es %lld\n", DecToOct(BinToDec(Valor)));
            DecToHex(BinToDec(Valor));
            printf("\n El Numero En Hexadecimal es %s\n------\n", HexaValor);
            fflush(stdin);
            getchar();
        break;

        case '2' :
            printf("\n\n-----\n El Numero En Binario es ");
            DecToBin(atoll(Valor));
            printf("\n El Numero En Decimal es %lld" , atoll(Valor));/*  for(i=0;i<1000;i++) if (Valor[i]!='$') printf ("%c", Valor[i]);*/
            printf("\n\n El Numero En Octal es %lld\n", DecToOct(atoll(Valor)));
            DecToHex(atoll(Valor));
            printf("\n El Numero En Hexadecimal es %s\n------\n", HexaValor);
            fflush(stdin);
            getchar();
        break;

        case '3' :

            for(i=0;i<1000;i++) if (Valor[i]=='8' || Valor[i]=='9') { printf("\n\n      Ingrese un Numero Octal Entero!\n"); fflush(stdin); getchar(); system("clear"); main(); return -1; }
            printf("\n\n------\n El Numero En Binario es ");
            DecToBin(OctToDec(Valor));
            printf("\n El Numero En Decimal es %lld\n", OctToDec(Valor));
            printf("\n El Numero En Octal es %lld", atoll(Valor)); /*for(i=0;i<1000;i++) if (Valor[i]!='$') printf ("%c", Valor[i]);*/
            DecToHex(OctToDec((Valor)));
            printf("\n\n El Numero En Hexadecimal es %s\n------\n", HexaValor);
            fflush(stdin);
            getchar();
        break;

        case '4' :
            printf("\n\n------\n El Numero En Binario es ");
            DecToBin(HexToDec(Valor));
            printf("\n El Numero En Decimal es %lld\n", HexToDec(Valor));
            printf("\n El Numero En Octal es %lld\n", DecToOct(HexToDec(Valor)));
            printf("\n El Numero En Hexadecimal es "); for(i=0;i<1000;i++) if (Valor[i]!='$') printf ("%c", Valor[i]);
            printf("\n------\n");
            fflush(stdin);
            getchar();
        break;

        default :

        break;
    }

    system("clear");
    main();
}

