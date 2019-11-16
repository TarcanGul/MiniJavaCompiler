.section .data
x: .word 1
y: .word 100
z: .word 0
abra: .word 1
hello: .word 0
_strlt0: .asciz "This line should be printed. A bunch of expressions:"
_t0: .word 0
_t1: .word 0
_t2: .word 0
_t3: .word 0
_t4: .word 0
_t5: .word 0
_t6: .word 0
_t7: .word 0
_t8: .word 0
rr: .word 5
_t9: .word 0
i: .word 5
_t10: .word 0
_t11: .word 0
_t12: .word 0
_t13: .word 0
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
sub sp, sp, #24
ldr r2, =i
ldr r2, [r2]
str r2, [fp, #-8]
ldr r2, =hello
ldr r2, [r2]
str r2, [fp, #-8]
ldr r2, =abra
ldr r2, [r2]
str r2, [fp, #-12]
ldr r2, =z
ldr r2, [r2]
str r2, [fp, #-16]
ldr r2, =y
ldr r2, [r2]
str r2, [fp, #-20]
ldr r2, =x
ldr r2, [r2]
str r2, [fp, #-24]
mov r0, #6
bl malloc
ldr r4, =hello
str r0, [r4]
mov r1, #104
ldr r4, =hello
ldr r4, [r4]
str r1, [r4, #0]
mov r1, #101
ldr r4, =hello
ldr r4, [r4]
str r1, [r4, #1]
mov r1, #108
ldr r4, =hello
ldr r4, [r4]
str r1, [r4, #2]
mov r1, #108
ldr r4, =hello
ldr r4, [r4]
str r1, [r4, #3]
mov r1, #111
ldr r4, =hello
ldr r4, [r4]
str r1, [r4, #4]
mov r1, #0
str r1, [r4, #5]
ldr r0, =_strlt0
mov r1, r0
ldr r0, =println_str_format
bl printf
ldr r0, [fp, #-8]
mov r1, r0
ldr r0, =println_str_format
bl printf
ldr r0, [fp, #-24]
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, [fp, #-20]
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
ldr r0, [fp, #-24]
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
mov r4, r0
str r4, [fp, #-16]
ldr r0, [fp, #-24]
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, [fp, #-16]
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, [fp, #-12]
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
ldr r0, [fp, #-12]
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
sub sp, sp, #24
ldr r2, =rr
ldr r2, [r2]
str r2, [fp, #-8]
ldr r2, =x
ldr r2, [r2]
str r2, [fp, #-12]
ldr r2, =y
ldr r2, [r2]
str r2, [fp, #-16]
ldr r2, =z
ldr r2, [r2]
str r2, [fp, #-20]
ldr r2, =abra
ldr r2, [r2]
str r2, [fp, #-24]
ldr r2, =hello
ldr r2, [r2]
str r2, [fp, #-24]
ldr r0, =#1000
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, [fp, #-24]
cmp r0, #1
bne _false3
_true3:
ldr r0, =println_str_format
ldr r1, =bool_true
bl printf
b _endif3
_false3:
ldr r0, =println_str_format
ldr r1, =bool_false
bl printf
_endif3:
ldr r0, [fp, #-8]
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
ldr r2, =hello
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
ldr r0, [fp, #-8]
mov r1, r0
ldr r0, =#0
cmp r1, r0
bgt _true4
_false4:
mov r0, #0
b _endif4
_true4:
mov r0, #1
b _endif4
_endif4:
ldr r4, =_t10
str r0, [r4]
cmp r0, #0
beq _endwhile0
push {fp}
mov fp, sp
sub sp, sp, #24
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
ldr r2, =hello
ldr r2, [r2]
str r2, [fp, #-20]
ldr r2, =i
ldr r2, [r2]
str r2, [fp, #-24]
_while0:
ldr r0, =#420
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, [fp, #-24]
mov r1, r0
ldr r0, =#1
sub r0, r1, r0
ldr r4, =_t11
str r0, [r4]
ldr r4, =_t11
ldr r0, [r4]
mov r4, r0
mov r4, r0
str r4, [fp, #-24]
ldr r0, [fp, #-24]
mov r1, r0
ldr r0, =#0
cmp r1, r0
bgt _true5
_false5:
mov r0, #0
b _endif5
_true5:
mov r0, #1
b _endif5
_endif5:
ldr r4, =_t13
str r0, [r4]
cmp r0, #0
bne _while0
mov sp, fp
pop {fp}
_endwhile0:
mov sp, fp
pop {fp}
pop {pc}
