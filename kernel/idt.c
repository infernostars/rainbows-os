#include "idt.h"
#include <stdint.h>
#include <stdbool.h>
idt_desc_t idt[IDT_MAX_DESCRIPTORS]; // Create an array of IDT entries; aligned for performance

void idt_set_descriptor(uint8_t vector, uintptr_t isr, uint8_t flags, uint8_t ist) {
    idt_desc_t* descriptor = &idt[vector];

    descriptor->isr_low = isr & 0xFFFF;
    descriptor->kernel_cs = GDT_OFFSET_KERNEL_CODE;
    descriptor->ist = ist;
    descriptor->attributes = flags;
    descriptor->isr_mid = (isr >> 16) & 0xFFFF;
    descriptor->isr_high = (isr >> 32) & 0xFFFFFFFF;
    descriptor->reserved = 0;
}

void idt_init() {
    idtr.base = (uintptr_t)&idt[0];
    idtr.limit = (uint16_t)sizeof(idt_desc_t) * IDT_MAX_DESCRIPTORS - 1;

    for (uint8_t vector = 0; vector < 32; vector++) {
        idt_set_descriptor(vector, isr_stub_table[vector], 0x8E, 1); 
        vectors[vector] = true;
    }
    __asm__ volatile("lidt %0" : : "memory"(idtr)); // load the new IDT
    __asm__ volatile("sti");                        // set the interrupt flag

}

void exception_handler() {
     __asm__ volatile ("cli; hlt"); // Completely hangs the computer
}
