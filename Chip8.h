#ifndef CHIP8_CHIP8_H
#define CHIP8_CHIP8_H

#include <cstdint>

constexpr int PROGRAM_OFFSET = 0x200;
constexpr int MEMORY_SIZE = 4096;
constexpr int DISPLAY_WIDTH = 64;
constexpr int DISPLAY_HEIGHT = 32;
constexpr float TIMER_CLOCK_CYCLE = 1.f / 60.f;
constexpr uint8_t FONT_SET[] = {
    0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
    0x20, 0x60, 0x20, 0x20, 0x70, // 1
    0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
    0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
    0x90, 0x90, 0xF0, 0x10, 0x10, // 4
    0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
    0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
    0xF0, 0x10, 0x20, 0x40, 0x40, // 7
    0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
    0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
    0xF0, 0x90, 0xF0, 0x90, 0x90, // A
    0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
    0xF0, 0x80, 0x80, 0x80, 0xF0, // C
    0xE0, 0x90, 0x90, 0x90, 0xE0, // D
    0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
    0xF0, 0x80, 0xF0, 0x80, 0x80  // F
};

struct Chip8State {
    uint8_t memory[MEMORY_SIZE];
    uint8_t v[16]; // registers
    uint8_t soundTimer;
    uint8_t delayTimer;
    uint16_t pc;
    uint16_t sp;
    uint16_t stack[16];
    bool vram[DISPLAY_HEIGHT][DISPLAY_WIDTH]; // values are stored y, x (col, row)
};

class Chip8 {
public:
    Chip8();
    void initState();
    void load(std::string filename);
    Chip8State state;
};

#endif //CHIP8_CHIP8_H