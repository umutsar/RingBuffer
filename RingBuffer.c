/* 
    This code is optimized for microcontroller boards. Adjust the uint_size
    type according to your project goals. If you have a microcontroller project
    and plan to use communication protocols such as UART, I2C, or CAN, you need
    to use 8-bit data, as these protocols support it. Therefore, be mindful of
    the data type.
*/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define BufferSize 6

typedef struct
{
    int buffer[BufferSize];
    int readNumber;
    int writeIndex;
    int readIndex;
} RingBuffer;

void initRingBuffer(RingBuffer *newBuffer)
{
    newBuffer->writeIndex = 0;
    newBuffer->readIndex = 0;
}

int counter = 10;
void write(RingBuffer *newBuffer, int readNumberParam)
{
    if ((newBuffer->writeIndex + 1) % BufferSize  != newBuffer->readIndex)
    {
        newBuffer->buffer[newBuffer->writeIndex] = readNumberParam;
        newBuffer->writeIndex = (newBuffer->writeIndex + 1) % BufferSize;
        counter++;
    }
    else
    {
        printf("Buffer is FULL!\n");
    }
}

int read(RingBuffer *newBuffer)
{
    newBuffer->readNumber = -1;

    if (newBuffer->readIndex != newBuffer->writeIndex)
    {
        newBuffer->readNumber = newBuffer->buffer[newBuffer->readIndex];
        newBuffer->readIndex = (newBuffer->readIndex + 1) % BufferSize;
    }
    else
    {
        printf("Buffer is EMPTY!\n");
    }

    return newBuffer->readNumber;
}

int main()
{
    RingBuffer newBuffer1;
    initRingBuffer(&newBuffer1);
    int getLine;

    while (1)
    {
        printf("*******************************\n");

        printf("Enter process number (1: write, 2: read): ");
        scanf("%d", &getLine);

        if (getLine == 1)
        {
            write(&newBuffer1, counter);
        }
        else if (getLine == 2)
        {
            printf("Read Number: %d\n", read(&newBuffer1));
        }

        printf("(WriteIndex: %d \t ReadIndex: %d)\n", newBuffer1.writeIndex, newBuffer1.readIndex);
        printf("*******************************\n\n\n\n");
    }

    return 0;
}
