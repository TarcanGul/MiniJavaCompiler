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
push {fp, lr}
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
mov r0, #2
mul r0, r0, r1
ldr r4, =_t0
str r0, [r4]
ldr r4, =_t0
ldr r1, [r4]
mov r0, #2
add r0, r0, r1
ldr r4, =_t1
str r0, [r4]
mov r1, r0
ldr r0, =println_int_format
bl printf
mov r0, #4
mov r1, r0
mov r0, #5
sub r0, r1, r0
ldr r4, =_t2
str r0, [r4]
ldr r4, =_t2
ldr r1, [r4]
mov r0, #16
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
_false0:
ldr r0, =println_str_format
ldr r1, =bool_false
bl printf
_endif0:
mov sp, fp
pop {fp, pc}
