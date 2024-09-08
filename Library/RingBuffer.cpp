/* 
    This code is optimized for microcontroller boards. Adjust the uint_size
    type according to your project goals. If you have a microcontroller project
    and plan to use communication protocols such as UART, I2C, or CAN, you need
    to use 8-bit data, as these protocols support it. Therefore, be mindful of
    the data type.
*/

#include "RingBuffer.h"
#include <cstdlib>

RingBuffer::RingBuffer(uint16_t _bufferSize) {
	bufferSize = _bufferSize;
	writeIndex = 0;
	readIndex = 0;
    buffer = new uint8_t[bufferSize];
}

RingBuffer::~RingBuffer() {
    delete[] buffer; // Tamponu bellekten silmek için.
}

bool RingBuffer::write(uint8_t value) {
    if ((writeIndex + 1) % bufferSize != readIndex) {
        buffer[writeIndex] = value;
        writeIndex = (writeIndex + 1) % bufferSize;
        return true;
    } else {
        return false;
    }
}

int RingBuffer::read() {
    if (readIndex != writeIndex) {
        uint8_t readValue = buffer[readIndex];
        readIndex = (readIndex + 1) % bufferSize;
        return readValue;
    } else {
        return -1;
    }
}
