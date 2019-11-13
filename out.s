.section .data
println_int_format: .asciz "%d\n"
print_int_format: .asciz "%d"
println_str_format: .asciz "%s\n"
print_str_format: .asciz "%s"
bool_true: .asciz "true"
bool_false: .asciz "false"
.section .text
.balign 4
push {fp}
mov fp, sp
ldr r2, =0
str r2, [fp, -8]
ldr r2, =-854931904
str r2, [fp, -12]
ldr r2, =-854932064
str r2, [fp, -16]
sub sp, sp, #16
ldr r0, [fp, #-16]
ldr r0, [r0]
ldr r0, =print_int_format
mov r1, #0
bl printf
ldr r0, [fp, #-12]
ldr r0, [r0]
ldr r0, =print_int_format
mov r1, #0
bl printf
pop {pc}