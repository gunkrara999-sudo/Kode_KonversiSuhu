#include <stdio.h>

int inputInteger(const char message[]) {
    char inputText[100];
    int integerValue;
    char extraCharacter;

    while (1) {
        printf("%s", message);

        if (fgets(inputText, sizeof(inputText), stdin) == NULL) {
            continue;
        }

        if (sscanf(inputText, "%d %c",
                   &integerValue, &extraCharacter) == 1) {
            return integerValue;
        }

        printf("[ERROR] Input harus berupa angka!\n");  
    }
}

double inputDouble(const char message[]) {
    char inputText[100];
    double doubleValue;
    char extraCharacter;

    while (1) {
        printf("%s", message);

        if (fgets(inputText, sizeof(inputText), stdin) == NULL) {
            continue;
        }

        if (sscanf(inputText, "%lf %c",
                   &doubleValue, &extraCharacter) == 1) {
            return doubleValue;
        }

        printf("[ERROR] Input harus berupa angka!\n");
        
    }
}

int showAfterProcessMenu() {

    printf("\n========================================\n");
    printf("Apa yang ingin dilakukan selanjutnya?\n");
    printf("1. Ulangi proses\n");
    printf("2. Kembali ke menu utama\n");
    printf("3. Selesai\n");

    return inputInteger("Masukkan pilihan: ");
}

int main() {

    int menuChoice;
    int afterProcessChoice;
    int programRunning = 1;

    double temperatureCelsius;
    double temperatureFahrenheit;
    double temperatureKelvin;

    while (programRunning) {

        printf("\n========================================\n");
        printf("              KELOMPOK 1\n");
        printf("         PROGRAM KONVERSI SUHU\n");
        printf("========================================\n");

        printf("\nMENU UTAMA\n");
        printf("1. Konversi Suhu Celsius\n");
        printf("2. Selesai\n");

        menuChoice = inputInteger("Masukkan pilihan: ");

        switch (menuChoice) {

            case 1:

            do {
                
                printf("\n========================================\n");
                printf("           KONVERSI SUHU\n");
                printf("========================================\n");

                    temperatureCelsius =
                        inputDouble("Masukkan suhu Celsius (C): ");

                    temperatureFahrenheit =
                        (temperatureCelsius * 9.0 / 5.0) + 32.0;

                    temperatureKelvin =
                        temperatureCelsius + 273.15;

                    printf("\nHasil Konversi:\n");
                    printf("Celsius    : %.2f C\n",
                           temperatureCelsius);

                    printf("Fahrenheit : %.2f F\n",
                           temperatureFahrenheit);

                    printf("Kelvin     : %.2f K\n",
                           temperatureKelvin);

                    afterProcessChoice =
                        showAfterProcessMenu();

                    if (afterProcessChoice == 3) {
                        programRunning = 0;

                        printf("\n========================================\n");
                        printf("              TERIMA KASIH\n");
                        printf("        TELAH MENGGUNAKAN PROGRAM INI\n");
                        printf("========================================\n");
                    }
                    else if (afterProcessChoice == 1) {
                        printf("\n--- Mengulangi konversi suhu ---\n");
                    }
                    else if (afterProcessChoice == 2) {
                        printf("\n--- Kembali ke menu utama ---\n");
                    }
                    else {
                        
                        printf("[ERROR] Pilihan tidak tersedia!\n");
                        

                        afterProcessChoice = 2;
                    }

                } while (afterProcessChoice == 1);

                break;

            case 2:

                printf("\n========================================\n");
                printf("              TERIMA KASIH\n");
                printf("        TELAH MENGGUNAKAN PROGRAM INI\n");
                printf("========================================\n");

                programRunning = 0;

                break;

            default:

                printf("\n[ERROR] Pilihan menu tidak tersedia!\n");
                
                break;
        }
    }
    return 0;
}