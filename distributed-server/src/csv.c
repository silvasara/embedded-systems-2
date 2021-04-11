#include <csv.h>

FILE *p_file=NULL;

void write_columns(){
    p_file = fopen("log.csv", "w");
    fprintf(p_file, "TI,TE,TRef,Intensidade,DataHora\n");

    fclose(p_file);
}

void write_values(float TI, float TE, float TRef, double intensity){
    time_t t;
    struct tm *time_now;
    char datetime[50];

    time(&t);
    time_now = localtime(&t);
    strftime(datetime, 50, "%d/%m/%Y %H:%M:%S", time_now);

    p_file = fopen("log.csv", "a");

    fprintf(p_file, "%.2f,%.2f,%.2f,%.2lf,%s\n", TI, TE, TRef, intensity, datetime);

    fclose(p_file);
}
