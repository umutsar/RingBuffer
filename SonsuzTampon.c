#include <stdio.h>
#include <stdbool.h>

#define BufferBoyutu 6

typedef struct
{
    int buffer[BufferBoyutu];
    int okunanSayi;
    int yazmaIndexi;
    int okumaIndexi;
} RingBuffer;

void baslatRingBuffer(RingBuffer *Buffer)
{
    Buffer->okunanSayi = 0;
    Buffer->yazmaIndexi = 0;
    Buffer->okumaIndexi = 0;
}

int counter = 10;
void yaz(RingBuffer *Buffer, int yazilacakSayi)
{
    if ((Buffer->yazmaIndexi + 1) % BufferBoyutu  != Buffer->okumaIndexi) // Buffer dolumu diye kontrol ettik.
    {
        Buffer->buffer[Buffer->yazmaIndexi] = yazilacakSayi;
        Buffer->yazmaIndexi = (Buffer->yazmaIndexi + 1) % BufferBoyutu;
        counter++;
    }
    else
    {
        printf("Buffer dolu. Daha fazla yazamazsın! \n");
    }
}

int oku(RingBuffer *Buffer)
{
    Buffer->okunanSayi = -1;

    if (Buffer->okumaIndexi != Buffer->yazmaIndexi) // // Buffer boş mu diye kontrol ettik.
    {
        Buffer->okunanSayi = Buffer->buffer[Buffer->okumaIndexi];
        Buffer->okumaIndexi = (Buffer->okumaIndexi + 1) % BufferBoyutu;
    }
    else
    {
        printf("Buffer boş. Okuyacak bir şey kalmadı. \n");
    }

    return Buffer->okunanSayi;
}

int main()
{
    RingBuffer yeniBuffer;
    initRingBuffer(&yeniBuffer);
    int getLine;

/* Aşağıdaki kodlar ile 1'e tıklandığında "yaz" 2'ye tıklandığında "oku" çalışır. 
 Bu sayede programı test edebiliriz. */
    while (1)
    {
        printf("*******************************\n");

        printf("Islem numarasi giriniz(1: yaz, 2: oku): ");
        scanf("%d", &getLine);

        if (getLine == 1)
        {
            write(&yeniBuffer, counter);
        }
        else if (getLine == 2)
        {
            printf("Okunan Sayi: %d\n", read(&yeniBuffer));
        }

        printf("(yazmaIndexi: %d \t okumaIndexi: %d)\n", yeniBuffer.yazmaIndexi, yeniBuffer.okumaIndexi);
        printf("*******************************\n\n\n\n");
    }

    return 0;
}
