#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define BufferSize 6

typedef struct
{
    int buffer[BufferSize];
    int okunanSayi;

    int yazanIndex;
    int okuyanIndex;
} RingBuffer;

void yapiyiBaslat(RingBuffer *newBuffer)
{
    newBuffer->yazanIndex = 0;
    newBuffer->okuyanIndex = 0;
}

int counter = 10;
void yaz(RingBuffer *newBuffer, int yazilacakSayi)
{
    int yeniYazanIndex = (newBuffer->yazanIndex + 1) % BufferSize;

    if (yeniYazanIndex != newBuffer->okuyanIndex)
    {
        newBuffer->buffer[newBuffer->yazanIndex] = yazilacakSayi;
        newBuffer->yazanIndex = yeniYazanIndex;
        counter++;
    }
    else
    {
        printf("Buffer dolu! Yazma islemi gerceklestirilemedi.\n");
    }
}

int oku(RingBuffer *newBuffer)
{
    int okunanSayi = -1;

    if (newBuffer->okuyanIndex != newBuffer->yazanIndex)
    {
        okunanSayi = newBuffer->buffer[newBuffer->okuyanIndex];
        newBuffer->okuyanIndex = (newBuffer->okuyanIndex + 1) % BufferSize;
    }
    else
    {
        printf("Buffer bos! Okuma islemi gerceklestirilemedi.\n");
    }

    return okunanSayi;
}

int main()
{
    RingBuffer newBuffer1;
    yapiyiBaslat(&newBuffer1);
    int getLine;

    while (1)
    {
        printf("*******************************\n");

        printf("Islem Numarasi Giriniz (1: Yaz, 2: Oku): ");
        scanf("%d", &getLine);

        if (getLine == 1)
        {
            yaz(&newBuffer1, counter);
        }
        else if (getLine == 2)
        {
            printf("Okunan Sayi: %d\n", oku(&newBuffer1));
        }

        printf("(Yazan Index: %d \t Okuyan Index: %d)\n", newBuffer1.yazanIndex, newBuffer1.okuyanIndex);
        printf("*******************************\n\n\n\n");
    }

    return 0;
}
