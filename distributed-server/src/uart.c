#include <uart.h>

int uart0_filestream = -1;

void open_uart(){
    uart0_filestream = open("/dev/serial0", O_RDWR | O_NOCTTY | O_NDELAY);      //Open in non blocking read/write mode
    if (uart0_filestream == -1){
        printf("Erro - Não foi possível iniciar a UART.\n");
    }
    else{
        printf("UART inicializada!\n");
    }   

    struct termios options;
    tcgetattr(uart0_filestream, &options);
    options.c_cflag = B9600 | CS8 | CLOCAL | CREAD;     //<Set baud rate
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;

    tcflush(uart0_filestream, TCIFLUSH);
    tcsetattr(uart0_filestream, TCSANOW, &options);
}

float get_temperature(char code){
    int status = write_on_uart(code);
    if (status < 0){
        return status;
    }

    sleep(1);

    return read_from_uart();
}

float read_from_uart(){
    float temperature = -1;

    if (uart0_filestream != -1){
        // Read up to 255 characters from the port if they are there
        unsigned char rx_buffer[256];
        int rx_length = read(uart0_filestream, (void*)rx_buffer, 255);      //Filestream, buffer to store in, number of bytes to read (max)
        if (rx_length < 0){
            printf("Erro na leitura.\n"); //An error occured (will occur if there are no bytes)
        }
        else if (rx_length == 0){
            printf("Nenhum dado disponível.\n"); //No data waiting
        }
        else{
            memcpy(&temperature, &rx_buffer[3], 4);
        }
    }

    return temperature;

}

int write_on_uart(char code){
    unsigned char tx_buffer[9] = {0x01, 0x23, code, 0x04, 0x07, 0x05, 0x02};

    short crc = calcula_CRC(tx_buffer, 7);
    memcpy(&tx_buffer[7], &crc, 2);
    if (uart0_filestream != -1){
        printf("Escrevendo caracteres na UART ...");
        int count = write(uart0_filestream, &tx_buffer[0], 7+2);
        if (count < 0){
            printf("UART TX error\n");
            return count;
        }
    }
    printf("Escrito!\n");
    return 0;
}

void close_uart(){
    close(uart0_filestream);
}
