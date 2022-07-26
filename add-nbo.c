#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>

uint32_t readInt(char* fileName) {
        FILE* pFile = fopen(fileName, "rb");
        if (pFile == NULL) {
                printf("NULL ERROR!");
                exit(1);
        }

        uint32_t n;
        size_t readLen = fread(&n, 1, sizeof(n), pFile);
        if (readLen != sizeof(n)) {
                printf("SIZE ERROR!");
                exit(1);
        }

        n = ntohl(n);
        fclose(pFile);
        return n;
}

int main(int argc, char* argv[]){

        uint32_t n1 = readInt(argv[1]);
        uint32_t n2 = readInt(argv[2]);

        printf("%d(0x(%x) + %d(0x%x) = %d(0x%x)\n", n1, n1, n2, n2, n1+n2, n1+n2);
        return 0;
}

