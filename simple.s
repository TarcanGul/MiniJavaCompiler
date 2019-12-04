.section .data
args: .word 0
x: .word 1
y: .word 100
z: .word 0
bale: .word 0
abra: .word 1
hello: .word 0
concat: .word 0
_t0: .word 0
_t1: .word 0
_t2: .word 0
_t3: .word 0
_t4: .word 0
_strlt0: .asciz "This line should be printed. A bunch of expressions:"
_strlt1: .asciz "Reassigned string"
_t5: .word 0
_t6: .word 0
_strlt2: .word 0
_strlt3: .asciz "x = "
_strlt4: .asciz "y = "
_t7: .word 0
_t8: .word 0
_t9: .word 0
_t10: .word 0
_t11: .word 0
_t12: .word 0
_t13: .word 0
_t14: .word 0
i: .word 5
_t15: .word 0
_t16: .word 0
_t17: .word 0
_t18: .word 0
_strlt5: .asciz "z = "
_strlt6: .asciz "x+y = "
_t19: .word 0
_strlt7: .asciz "x*y-(y-1) = "
_t20: .word 0
_t21: .word 0
_t22: .word 0
a: .word 10
b: .word 100
_t23: .word 0
_t24: .word 0
_t25: .word 0
_t26: .word 0
_t27: .word 0
_t28: .word 0
_t29: .word 0
_strlt8: .asciz "a = "
_strlt9: .asciz "b = "
_strlt10: .asciz "z = "
_strlt11: .asciz "x+y = "
_t30: .word 0
_strlt12: .asciz "x*y-(b-1) = "
_t31: .word 0
_t32: .word 0
_t33: .word 0
array: .word 0
_t34: .word 0
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
ldr r4, =args
str r1, [r4]
push {fp}
mov fp, sp
sub sp, sp, #52
ldr r2, =array
ldr r2, [r2]
str r2, [fp, #-8]
ldr r2, =b
ldr r2, [r2]
str r2, [fp, #-12]
ldr r2, =a
ldr r2, [r2]
str r2, [fp, #-16]
ldr r2, =i
ldr r2, [r2]
str r2, [fp, #-20]
ldr r2, =concat
ldr r2, [r2]
str r2, [fp, #-24]
ldr r2, =hello
ldr r2, [r2]
str r2, [fp, #-28]
ldr r2, =abra
ldr r2, [r2]
str r2, [fp, #-32]
ldr r2, =bale
ldr r2, [r2]
str r2, [fp, #-36]
ldr r2, =z
ldr r2, [r2]
str r2, [fp, #-40]
ldr r2, =y
ldr r2, [r2]
str r2, [fp, #-44]
ldr r2, =x
ldr r2, [r2]
str r2, [fp, #-48]
ldr r2, =args
ldr r2, [r2]
str r2, [fp, #-52]
mov r0, #6
bl malloc
ldr r4, =hello
str r0, [r4]
mov r1, #104
ldr r4, =hello
ldr r4, [r4]
strb r1, [r4, #0]
mov r1, #101
ldr r4, =hello
ldr r4, [r4]
strb r1, [r4, #1]
mov r1, #108
ldr r4, =hello
ldr r4, [r4]
strb r1, [r4, #2]
mov r1, #108
ldr r4, =hello
ldr r4, [r4]
strb r1, [r4, #3]
mov r1, #111
ldr r4, =hello
ldr r4, [r4]
strb r1, [r4, #4]
mov r1, #0
strb r1, [r4, #5]
ldr r4, =hello
ldr r4, [r4]
str r4, [fp, #-28]
mov r0, #8
bl malloc
ldr r4, =concat
str r0, [r4]
mov r1, #32
ldr r4, =concat
ldr r4, [r4]
strb r1, [r4, #0]
mov r1, #99
ldr r4, =concat
ldr r4, [r4]
strb r1, [r4, #1]
mov r1, #111
ldr r4, =concat
ldr r4, [r4]
strb r1, [r4, #2]
mov r1, #110
ldr r4, =concat
ldr r4, [r4]
strb r1, [r4, #3]
mov r1, #99
ldr r4, =concat
ldr r4, [r4]
strb r1, [r4, #4]
mov r1, #97
ldr r4, =concat
ldr r4, [r4]
strb r1, [r4, #5]
mov r1, #116
ldr r4, =concat
ldr r4, [r4]
strb r1, [r4, #6]
mov r1, #0
strb r1, [r4, #7]
ldr r4, =concat
ldr r4, [r4]
str r4, [fp, #-24]
ldr r0, [fp, #-48]
mov r1, r0
ldr r0, [fp, #-44]
mul r0, r0, r1
ldr r4, =_t0
str r0, [r4]
ldr r4, =_t0
ldr r1, [r4]
ldr r0, [fp, #-44]
mov r1, r0
ldr r0, =#1
sub r0, r1, r0
ldr r4, =_t1
str r0, [r4]
ldr r4, =_t1
ldr r0, [r4]
sub r0, r1, r0
ldr r4, =_t2
str r0, [r4]
ldr r4, =_t2
ldr r1, [r4]
ldr r0, =#1
add r0, r0, r1
ldr r4, =_t3
str r0, [r4]
ldr r4, =_t3
ldr r0, [r4]
mov r4, r0
mov r4, r0
str r4, [fp, #-40]
ldr r0, =_strlt0
mov r1, r0
ldr r0, =println_str_format
bl printf
ldr r0, [fp, #-28]
mov r1, r0
ldr r0, =println_str_format
bl printf
ldr r0, =_strlt1
ldr r4, =_strlt1
mov r0, r4
mov r4, r0
str r4, [fp, #-28]
ldr r0, [fp, #-28]
mov r1, r0
ldr r0, [fp, #-24]
mov r4, r1
mov r5, r0
mov r0, r4
bl strlen
mov r6, r0
mov r0, r5
bl strlen
mov r7, r0
add r0, r6, r7
add r0, r0, #1
bl malloc
ldr r3, =_strlt2
str r0, [r3]
mov r1, r4
bl strcpy
mov r1, r5
bl strcat
ldr r4, =_t6
str r0, [r4]
mov r1, r0
ldr r0, =println_str_format
bl printf
ldr r0, [fp, #-28]
mov r1, r0
ldr r0, =println_str_format
bl printf
ldr r0, =_strlt3
mov r1, r0
ldr r0, =print_str_format
bl printf
ldr r0, [fp, #-48]
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, =_strlt4
mov r1, r0
ldr r0, =print_str_format
bl printf
ldr r0, [fp, #-44]
mov r1, r0
ldr r0, =#2
mul r0, r0, r1
ldr r4, =_t7
str r0, [r4]
ldr r4, =_t7
ldr r1, [r4]
ldr r0, =#2
add r0, r0, r1
ldr r4, =_t8
str r0, [r4]
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, =#4
mov r1, r0
ldr r0, [fp, #-48]
sub r0, r1, r0
ldr r4, =_t9
str r0, [r4]
ldr r4, =_t9
ldr r1, [r4]
ldr r0, =#16
mul r0, r0, r1
ldr r4, =_t10
str r0, [r4]
ldr r4, =_t10
ldr r0, [r4]
mov r4, r0
mov r4, r0
str r4, [fp, #-40]
ldr r0, [fp, #-48]
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, [fp, #-40]
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, [fp, #-32]
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
ldr r4, =_t12
str r0, [r4]
ldr r4, =_t12
ldr r1, [r4]
ldr r0, =#4
mul r0, r0, r1
ldr r4, =_t13
str r0, [r4]
mov r1, r0
ldr r0, =print_int_format
bl printf
ldr r0, =#1
mov r1, r0
ldr r0, =#0
and r0, r0, r1
ldr r4, =_t14
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
ldr r0, [fp, #-20]
mov r1, r0
ldr r0, =#0
cmp r1, r0
bgt _true2
_false2:
mov r0, #0
b _endif2
_true2:
mov r0, #1
b _endif2
_endif2:
ldr r4, =_t15
str r0, [r4]
cmp r0, #0
beq _endwhile0
push {fp}
mov fp, sp
sub sp, sp, #40
ldr r2, =args
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
ldr r2, =bale
ldr r2, [r2]
str r2, [fp, #-24]
ldr r2, =abra
ldr r2, [r2]
str r2, [fp, #-28]
ldr r2, =hello
ldr r2, [r2]
str r2, [fp, #-32]
ldr r2, =concat
ldr r2, [r2]
str r2, [fp, #-36]
ldr r2, =i
ldr r2, [r2]
str r2, [fp, #-40]
_while0:
ldr r0, =#420
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, [fp, #-40]
mov r1, r0
ldr r0, =#1
sub r0, r1, r0
ldr r4, =_t16
str r0, [r4]
ldr r4, =_t16
ldr r0, [r4]
mov r4, r0
mov r4, r0
str r4, [fp, #-40]
ldr r0, [fp, #-40]
mov r1, r0
ldr r0, =#0
cmp r1, r0
bgt _true3
_false3:
mov r0, #0
b _endif3
_true3:
mov r0, #1
b _endif3
_endif3:
ldr r4, =_t18
str r0, [r4]
cmp r0, #0
bne _while0
mov sp, fp
pop {fp}
_endwhile0:
ldr r0, =_strlt5
mov r1, r0
ldr r0, =print_str_format
bl printf
ldr r0, [fp, #-40]
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, =_strlt6
mov r1, r0
ldr r0, =print_str_format
bl printf
ldr r0, [fp, #-48]
mov r1, r0
ldr r0, [fp, #-44]
add r0, r0, r1
ldr r4, =_t19
str r0, [r4]
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, =_strlt7
mov r1, r0
ldr r0, =print_str_format
bl printf
ldr r0, [fp, #-48]
mov r1, r0
ldr r0, [fp, #-44]
mul r0, r0, r1
ldr r4, =_t20
str r0, [r4]
ldr r4, =_t20
ldr r1, [r4]
ldr r0, [fp, #-44]
mov r1, r0
ldr r0, =#1
sub r0, r1, r0
ldr r4, =_t21
str r0, [r4]
ldr r4, =_t21
ldr r0, [r4]
sub r0, r1, r0
ldr r4, =_t22
str r0, [r4]
mov r1, r0
ldr r0, =print_int_format
bl printf
ldr r0, [fp, #-48]
mov r1, r0
ldr r0, [fp, #-16]
add r0, r0, r1
ldr r4, =_t23
str r0, [r4]
ldr r4, =_t23
ldr r0, [r4]
mov r4, r0
mov r4, r0
str r4, [fp, #-48]
ldr r0, [fp, #-48]
mov r1, r0
ldr r0, [fp, #-44]
mul r0, r0, r1
ldr r4, =_t25
str r0, [r4]
ldr r4, =_t25
ldr r1, [r4]
ldr r0, [fp, #-12]
mov r1, r0
ldr r0, =#10
sub r0, r1, r0
ldr r4, =_t26
str r0, [r4]
ldr r4, =_t26
ldr r0, [r4]
sub r0, r1, r0
ldr r4, =_t27
str r0, [r4]
ldr r4, =_t27
ldr r1, [r4]
ldr r0, =#1
add r0, r0, r1
ldr r4, =_t28
str r0, [r4]
ldr r4, =_t28
ldr r0, [r4]
mov r4, r0
mov r4, r0
str r4, [fp, #-40]
ldr r0, =_strlt8
mov r1, r0
ldr r0, =print_str_format
bl printf
ldr r0, [fp, #-16]
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, =_strlt9
mov r1, r0
ldr r0, =print_str_format
bl printf
ldr r0, [fp, #-12]
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, =_strlt10
mov r1, r0
ldr r0, =print_str_format
bl printf
ldr r0, [fp, #-40]
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, =_strlt11
mov r1, r0
ldr r0, =print_str_format
bl printf
ldr r0, [fp, #-48]
mov r1, r0
ldr r0, [fp, #-44]
add r0, r0, r1
ldr r4, =_t30
str r0, [r4]
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, =_strlt12
mov r1, r0
ldr r0, =print_str_format
bl printf
ldr r0, [fp, #-48]
mov r1, r0
ldr r0, [fp, #-44]
mul r0, r0, r1
ldr r4, =_t31
str r0, [r4]
ldr r4, =_t31
ldr r1, [r4]
ldr r0, [fp, #-12]
mov r1, r0
ldr r0, =#1
sub r0, r1, r0
ldr r4, =_t32
str r0, [r4]
ldr r4, =_t32
ldr r0, [r4]
sub r0, r1, r0
ldr r4, =_t33
str r0, [r4]
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, =#20
bl malloc
ldr r4, =array
str r0, [r4]
ldr r0, =#45
ldr r4, =array
ldr r4, [r4]
ldr r0, =#2
mul r1, r0, r2
add r0, r4, r1
mov r1, r0
ldr r0, =#45
str r0, [r1]
ldr r4, =array
ldr r4, [r4]
ldr r0, =#2
ldr r1, =#4
mul r1, r1, r0
add r0, r4, r1
ldr r0, [r0]
mov r1, r0
ldr r0, =println_int_format
bl printf
mov sp, fp
pop {fp}
pop {pc}
