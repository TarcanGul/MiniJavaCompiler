.section .data
x: .word 1
y: .word 100
z: .word 0
abra: .word 1
_t0: .word 0
_t1: .word 0
_t2: .word 0
_t3: .word 0
_t4: .word 0
_t5: .word 0
_t6: .word 0
_t7: .word 0
_t8: .word 0
_t9: .word 0
println_int_format: .asciz "%d\n"
print_int_format: .asciz "%d"
println_str_format: .asciz "%s\n"
print_str_format: .asciz "%s"
bool_true: .asciz "true"
bool_false: .asciz "false"
.section .text
.global main
.balign 4
main: 
push {lr}
push {fp}
mov fp, sp
sub sp, sp, #20
ldr r2, =abra
ldr r2, [r2]
str r2, [fp, #-8]
ldr r2, =z
ldr r2, [r2]
str r2, [fp, #-12]
ldr r2, =y
ldr r2, [r2]
str r2, [fp, #-16]
ldr r2, =x
ldr r2, [r2]
str r2, [fp, #-20]
ldr r0, [fp, #-20]
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, [fp, #-16]
mov r1, r0
ldr r0, =#2
mul r0, r0, r1
ldr r4, =_t0
str r0, [r4]
ldr r4, =_t0
ldr r1, [r4]
ldr r0, =#2
add r0, r0, r1
ldr r4, =_t1
str r0, [r4]
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, =#4
mov r1, r0
ldr r0, =#5
sub r0, r1, r0
ldr r4, =_t2
str r0, [r4]
ldr r4, =_t2
ldr r1, [r4]
ldr r0, =#16
mul r0, r0, r1
ldr r4, =_t3
str r0, [r4]
ldr r4, =_t3
ldr r0, [r4]
mov r4, r0
str r4, [fp, #-20]
ldr r0, [fp, #-20]
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, [fp, #-8]
cmp r0, #1
bne _false0
_true0:
ldr r0, =println_str_format
ldr r1, =bool_true
bl printf
b _endif0
_false0:
ldr r0, =println_str_format
ldr r1, =bool_false
bl printf
_endif0:
ldr r0, =#4
mov r1, r0
ldr r0, =#4
mul r0, r0, r1
ldr r4, =_t5
str r0, [r4]
ldr r4, =_t5
ldr r1, [r4]
ldr r0, =#4
mul r0, r0, r1
ldr r4, =_t6
str r0, [r4]
mov r1, r0
ldr r0, =print_int_format
bl printf
ldr r0, =#1
mov r1, r0
ldr r0, =#0
and r0, r0, r1
ldr r4, =_t7
str r0, [r4]
cmp r0, #1
bne _false1
_true1:
ldr r0, =print_str_format
ldr r1, =bool_true
bl printf
b _endif1
_false1:
ldr r0, =print_str_format
ldr r1, =bool_false
bl printf
_endif1:
ldr r0, [fp, #-8]
mov r1, r0
ldr r0, =#0
orr r0, r0, r1
ldr r4, =_t8
str r0, [r4]
cmp r0, #0
beq _false2
_true2:
push {fp}
mov fp, sp
sub sp, sp, #20
ldr r2, =x
ldr r2, [r2]
str r2, [fp, #-8]
ldr r2, =y
ldr r2, [r2]
str r2, [fp, #-12]
ldr r2, =z
ldr r2, [r2]
str r2, [fp, #-16]
ldr r2, =abra
ldr r2, [r2]
str r2, [fp, #-20]
ldr r0, =#1000
mov r1, r0
ldr r0, =println_int_format
bl printf
mov sp, fp
pop {fp}
b _endif2
_false2:
push {fp}
mov fp, sp
sub sp, sp, #20
ldr r2, =x
ldr r2, [r2]
str r2, [fp, #-8]
ldr r2, =y
ldr r2, [r2]
str r2, [fp, #-12]
ldr r2, =z
ldr r2, [r2]
str r2, [fp, #-16]
ldr r2, =abra
ldr r2, [r2]
str r2, [fp, #-20]
ldr r0, =#959
mov r1, r0
neg r0, r0
ldr r4, =_t9
str r0, [r4]
mov r1, r0
ldr r0, =println_int_format
bl printf
mov sp, fp
pop {fp}
_endif2:
mov sp, fp
pop {fp}
pop {pc}
