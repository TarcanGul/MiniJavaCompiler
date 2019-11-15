.section .data
x: .word 1
y: .word 100
z: .word 0
(null): .word 0
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
str r2, [fp, #-8]
ldr r2, =y
str r2, [fp, #-12]
ldr r2, =x
str r2, [fp, #-16]
ldr r0, [fp, #-16]
ldr r0, [r0]
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, [fp, #-12]
ldr r0, [r0]
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, [fp, #-16]
ldr r0, [r0]
mov r1, r0
mov r0, #3
ldr r4, =x
str r4, [fp, #-16]
ldr r0, [fp, #-16]
ldr r0, [r0]
mov r1, r0
ldr r0, =println_int_format
bl printf
mov sp, fp
pop {fp, pc}
