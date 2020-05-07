#include <ktf.h>
#include <asm-macros.h>
#include <processor.h>
#include <desc.h>

gdtdesc_t gdt[] __aligned(16) = {
    [GDT_NULL]      = GDT_ENTRY(0x0, 0x0, 0x0),
    [GDT_KERN_CS32] = GDT_ENTRY(DESC_FLAGS(GR, SZ, P, DPL0, S, CODE, R, A), 0x0, 0xfffff),
    [GDT_KERN_DS32] = GDT_ENTRY(DESC_FLAGS(GR, SZ, P, DPL0, S, DATA, W, A), 0x0, 0xfffff),
    [GDT_KERN_CS64] = GDT_ENTRY(DESC_FLAGS(GR,  L, P, DPL0, S, CODE, R, A), 0x0, 0x00000),
};

gdt_ptr_t gdt_ptr __section(".data") = {
    .size = sizeof(gdt) - 1,
    .addr = _ul(&gdt),
};

idt_entry_t idt[256] = {
   [X86_EX_DE]  = INTR_GATE(__KERN_CS, _ul(0), DPL0, PRESENT),
   [X86_EX_DB]  = INTR_GATE(__KERN_CS, _ul(0), DPL0, PRESENT),
   [X86_EX_NMI] = INTR_GATE(__KERN_CS, _ul(0), DPL0, PRESENT),
   [X86_EX_BP]  = INTR_GATE(__KERN_CS, _ul(0), DPL3, PRESENT),
   [X86_EX_OF]  = INTR_GATE(__KERN_CS, _ul(0), DPL3, PRESENT),
   [X86_EX_BR]  = INTR_GATE(__KERN_CS, _ul(0), DPL0, PRESENT),
   [X86_EX_UD]  = INTR_GATE(__KERN_CS, _ul(0), DPL0, PRESENT),
   [X86_EX_NM]  = INTR_GATE(__KERN_CS, _ul(0), DPL0, PRESENT),
   [X86_EX_DF]  = INTR_GATE(__KERN_CS, _ul(0), DPL0, PRESENT),
   [X86_EX_CS]  = INTR_GATE(__KERN_CS, _ul(0), DPL0, PRESENT),
   [X86_EX_TS]  = INTR_GATE(__KERN_CS, _ul(0), DPL0, PRESENT),
   [X86_EX_NP]  = INTR_GATE(__KERN_CS, _ul(0), DPL0, PRESENT),
   [X86_EX_SS]  = INTR_GATE(__KERN_CS, _ul(0), DPL0, PRESENT),
   [X86_EX_GP]  = INTR_GATE(__KERN_CS, _ul(0), DPL0, PRESENT),
   [X86_EX_PF]  = INTR_GATE(__KERN_CS, _ul(0), DPL0, PRESENT),
   [X86_EX_SPV] = INTR_GATE(__KERN_CS, _ul(0), DPL0, PRESENT),
   [X86_EX_MF]  = INTR_GATE(__KERN_CS, _ul(0), DPL0, PRESENT),
   [X86_EX_AC]  = INTR_GATE(__KERN_CS, _ul(0), DPL0, PRESENT),
   [X86_EX_MC]  = INTR_GATE(__KERN_CS, _ul(0), DPL0, PRESENT),
   [X86_EX_XM]  = INTR_GATE(__KERN_CS, _ul(0), DPL0, PRESENT),
   [X86_EX_VE]  = INTR_GATE(__KERN_CS, _ul(0), DPL0, PRESENT),
   [X86_EX_SE]  = INTR_GATE(__KERN_CS, _ul(0), DPL0, PRESENT),
};

idt_ptr_t idt_ptr __section(".data") = {
    .size = sizeof(idt) - 1,
    .addr = _ul(&idt),
};
