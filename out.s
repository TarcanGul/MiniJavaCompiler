.section .data
x: .word 1
y: .word 100
z: .word 0
_t0: .word 0
_t1: .word 0
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
sub sp, sp, #16
ldr r2, =z
ldr r2, [r2]
str r2, [fp, #-8]
ldr r2, =y
ldr r2, [r2]
str r2, [fp, #-12]
ldr r2, =x
ldr r2, [r2]
str r2, [fp, #-16]
ldr r0, [fp, #-16]
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, [fp, #-12]
mov r1, r0
mov r0, #2
mul r0, r0, r1
str r0, =_t0
mov r1, r0
mov r0, #2
add r0, r0, r1
str r0, =_t1
mov r1, r0
ldr r0, =println_int_format
bl printf
mov sp, fp
pop {fp, pc}
