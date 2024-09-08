/* 
    This code is optimized for microcontroller boards. Adjust the uint_size
    type according to your project goals. If you have a microcontroller project
    and plan to use communication protocols such as UART, I2C, or CAN, you need
    to use 8-bit data, as these protocols support it. Therefore, be mindful of
    the data type.
*/

#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#include <cstdint>

class RingBuffer {
public:
    RingBuffer(uint16_t _bufferSize);
    virtual ~RingBuffer();

    bool write(uint8_t value);
    int read();

private:
    uint8_t* buffer;
    uint16_t bufferSize;
    int writeIndex;
    int readIndex;
};

#endif // RINGBUFFER_H
