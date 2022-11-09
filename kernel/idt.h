#pragma once

#include <stdint.h>
#include <stdbool.h>

#define IDT_MAX_DESCRIPTORS 256
#define GDT_OFFSET_KERNEL_CODE (0x01 * 0x08) //!!!! just to test

extern uint64_t isr_stub_table[];


typedef struct {
    uint16_t isr_low;   // The lower 16 bits of the ISR's address
    uint16_t kernel_cs; // The GDT segment selector that the CPU will load into CS before calling the ISR
    uint8_t ist; // The IST in the TSS that the CPU will load into RSP; set to zero for now
    uint8_t attributes; // Type and attributes; see the IDT page
    uint16_t isr_mid;   // The higher 16 bits of the lower 32 bits of the ISR's address
    uint32_t isr_high;  // The higher 32 bits of the ISR's address
    uint32_t reserved;  // Set to zero
} __attribute__((packed)) idt_desc_t;



typedef struct {
    uint16_t limit;
    uint64_t base;
} __attribute__((packed)) idtr_t;

static idtr_t idtr;
void idt_reload(idtr_t* idtr);
void idt_set_descriptor(uint8_t vector, uintptr_t isr, uint8_t flags, uint8_t ist);



void idt_init(void);



static bool vectors[IDT_MAX_DESCRIPTORS];