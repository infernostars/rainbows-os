#include <stdint.h>

struct GDT {
        uint32_t base;
        uint32_t limit;
        uint8_t type;
        uint8_t flags;
};

extern void setGdt(uint8_t* limit, uint32_t base);
extern void reloadSegments(void);

uint8_t encodeGdtEntry(uint8_t *target, struct GDT source) {
        if (source.limit > 0xFFFFF) {return 1;}
        target[0] = source.limit & 0xFF;
        target[1] = (source.limit >> 8) & 0xFF;
        target[6] = (source.limit >> 16) & 0x0F;
        target[2] = source.base & 0xFF;
        target[3] = (source.base >> 8) & 0xFF;
        target[4] = (source.base >> 16) & 0xFF;
        target[7] = (source.base >> 24) & 0xFF;
        target[5] = source.type;
        target[6] |= (source.flags << 4);
        return 0;
}

void gdt_init(uint8_t* buffer) {
        struct GDT GdtEntries[5] = {
                {0, 0, 0, 0},           // Selector 0x00 cannot be used
                {0, 0xfffff, 0x9A, 0xC},// Selector 0x08 will be our code
                {0, 0xfffff, 0x92, 0xC},// Selector 0x10 will be our data
                {0, 0xfffff, 0xFA, 0xC},// Selector 0x18 will be user code
                {0, 0xfffff, 0xF2, 0xC} // Selector 0x20 will be user data

        };
        for (int i = 0; i < 5; i++) encodeGdtEntry(buffer+i*8, GdtEntries[i]);
        setGdt(buffer, 255);
        reloadSegments();
}