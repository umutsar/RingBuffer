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
