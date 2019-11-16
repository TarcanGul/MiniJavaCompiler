.section .data
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
_strlt2: .asciz "x = "
_strlt3: .asciz "y = "
_t7: .word 0
_t8: .word 0
_t9: .word 0
_t10: .word 0
_t11: .word 0
_t12: .word 0
_t13: .word 0
_t14: .word 0
_t15: .word 0
rr: .word 5
_t16: .word 0
i: .word 5
_t17: .word 0
_t18: .word 0
_t19: .word 0
_t20: .word 0
_strlt4: .asciz "z = "
_strlt5: .asciz "x+y = "
_t21: .word 0
_strlt6: .asciz "x*y-(y-1) = "
_t22: .word 0
_t23: .word 0
_t24: .word 0
a: .word 10
b: .word 100
_t25: .word 0
_t26: .word 0
_t27: .word 0
_t28: .word 0
_t29: .word 0
_t30: .word 0
_t31: .word 0
_strlt7: .asciz "a = "
_strlt8: .asciz "b = "
_strlt9: .asciz "z = "
_strlt10: .asciz "x+y = "
_t32: .word 0
_strlt11: .asciz "x*y-(b-1) = "
_t33: .word 0
_t34: .word 0
_t35: .word 0
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
sub sp, sp, #44
ldr r2, =b
ldr r2, [r2]
str r2, [fp, #-8]
ldr r2, =a
ldr r2, [r2]
str r2, [fp, #-12]
ldr r2, =i
ldr r2, [r2]
str r2, [fp, #-16]
ldr r2, =concat
ldr r2, [r2]
str r2, [fp, #-20]
ldr r2, =hello
ldr r2, [r2]
str r2, [fp, #-24]
ldr r2, =abra
ldr r2, [r2]
str r2, [fp, #-28]
ldr r2, =bale
ldr r2, [r2]
str r2, [fp, #-32]
ldr r2, =z
ldr r2, [r2]
str r2, [fp, #-36]
ldr r2, =y
ldr r2, [r2]
str r2, [fp, #-40]
ldr r2, =x
ldr r2, [r2]
str r2, [fp, #-44]
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
ldr r4, =hello
ldr r4, [r4]
str r4, [fp, #-24]
mov r0, #8
bl malloc
ldr r4, =concat
str r0, [r4]
mov r1, #32
ldr r4, =concat
ldr r4, [r4]
str r1, [r4, #0]
mov r1, #99
ldr r4, =concat
ldr r4, [r4]
str r1, [r4, #1]
mov r1, #111
ldr r4, =concat
ldr r4, [r4]
str r1, [r4, #2]
mov r1, #110
ldr r4, =concat
ldr r4, [r4]
str r1, [r4, #3]
mov r1, #99
ldr r4, =concat
ldr r4, [r4]
str r1, [r4, #4]
mov r1, #97
ldr r4, =concat
ldr r4, [r4]
str r1, [r4, #5]
mov r1, #116
ldr r4, =concat
ldr r4, [r4]
str r1, [r4, #6]
mov r1, #0
str r1, [r4, #7]
ldr r4, =concat
ldr r4, [r4]
str r4, [fp, #-20]
ldr r0, [fp, #-44]
mov r1, r0
ldr r0, [fp, #-40]
mul r0, r0, r1
ldr r4, =_t0
str r0, [r4]
ldr r4, =_t0
ldr r1, [r4]
ldr r0, [fp, #-40]
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
str r4, [fp, #-36]
ldr r0, =_strlt0
mov r1, r0
ldr r0, =println_str_format
bl printf
ldr r0, [fp, #-24]
mov r1, r0
ldr r0, =println_str_format
bl printf
ldr r0, =_strlt1
ldr r4, =_strlt1
ldr r0, [r4]
mov r4, r0
str r4, [fp, #-24]
ldr r0, [fp, #-24]
mov r1, r0
ldr r0, [fp, #-20]
mov r2, r0
mov r0, r1
mov r1, r2
bl strcat
ldr r4, =_t6
str r0, [r4]
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, =_strlt2
mov r1, r0
ldr r0, =print_str_format
bl printf
ldr r0, [fp, #-44]
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, =_strlt3
mov r1, r0
ldr r0, =print_str_format
bl printf
ldr r0, [fp, #-40]
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
ldr r0, [fp, #-44]
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
str r4, [fp, #-36]
ldr r0, [fp, #-44]
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, [fp, #-36]
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, [fp, #-28]
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
ldr r0, [fp, #-28]
mov r1, r0
ldr r0, =#0
orr r0, r0, r1
ldr r4, =_t15
str r0, [r4]
cmp r0, #0
beq _false2
_true2:
push {fp}
mov fp, sp
sub sp, sp, #36
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
ldr r0, =#1000
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, [fp, #-28]
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
sub sp, sp, #32
ldr r2, =x
ldr r2, [r2]
str r2, [fp, #-8]
ldr r2, =y
ldr r2, [r2]
str r2, [fp, #-12]
ldr r2, =z
ldr r2, [r2]
str r2, [fp, #-16]
ldr r2, =bale
ldr r2, [r2]
str r2, [fp, #-20]
ldr r2, =abra
ldr r2, [r2]
str r2, [fp, #-24]
ldr r2, =hello
ldr r2, [r2]
str r2, [fp, #-28]
ldr r2, =concat
ldr r2, [r2]
str r2, [fp, #-32]
ldr r0, =#959
mov r1, r0
neg r0, r0
ldr r4, =_t16
str r0, [r4]
mov r1, r0
ldr r0, =println_int_format
bl printf
mov sp, fp
pop {fp}
_endif2:
ldr r0, [fp, #-16]
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
ldr r4, =_t17
str r0, [r4]
cmp r0, #0
beq _endwhile0
push {fp}
mov fp, sp
sub sp, sp, #36
ldr r2, =x
ldr r2, [r2]
str r2, [fp, #-8]
ldr r2, =y
ldr r2, [r2]
str r2, [fp, #-12]
ldr r2, =z
ldr r2, [r2]
str r2, [fp, #-16]
ldr r2, =bale
ldr r2, [r2]
str r2, [fp, #-20]
ldr r2, =abra
ldr r2, [r2]
str r2, [fp, #-24]
ldr r2, =hello
ldr r2, [r2]
str r2, [fp, #-28]
ldr r2, =concat
ldr r2, [r2]
str r2, [fp, #-32]
ldr r2, =i
ldr r2, [r2]
str r2, [fp, #-36]
_while0:
ldr r0, =#420
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, [fp, #-36]
mov r1, r0
ldr r0, =#1
sub r0, r1, r0
ldr r4, =_t18
str r0, [r4]
ldr r4, =_t18
ldr r0, [r4]
mov r4, r0
mov r4, r0
str r4, [fp, #-36]
ldr r0, [fp, #-36]
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
ldr r4, =_t20
str r0, [r4]
cmp r0, #0
bne _while0
mov sp, fp
pop {fp}
_endwhile0:
ldr r0, =_strlt4
mov r1, r0
ldr r0, =print_str_format
bl printf
ldr r0, [fp, #-36]
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, =_strlt5
mov r1, r0
ldr r0, =print_str_format
bl printf
ldr r0, [fp, #-44]
mov r1, r0
ldr r0, [fp, #-40]
add r0, r0, r1
ldr r4, =_t21
str r0, [r4]
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, =_strlt6
mov r1, r0
ldr r0, =print_str_format
bl printf
ldr r0, [fp, #-44]
mov r1, r0
ldr r0, [fp, #-40]
mul r0, r0, r1
ldr r4, =_t22
str r0, [r4]
ldr r4, =_t22
ldr r1, [r4]
ldr r0, [fp, #-40]
mov r1, r0
ldr r0, =#1
sub r0, r1, r0
ldr r4, =_t23
str r0, [r4]
ldr r4, =_t23
ldr r0, [r4]
sub r0, r1, r0
ldr r4, =_t24
str r0, [r4]
mov r1, r0
ldr r0, =print_int_format
bl printf
ldr r0, [fp, #-44]
mov r1, r0
ldr r0, [fp, #-12]
add r0, r0, r1
ldr r4, =_t25
str r0, [r4]
ldr r4, =_t25
ldr r0, [r4]
mov r4, r0
mov r4, r0
str r4, [fp, #-44]
ldr r0, [fp, #-44]
mov r1, r0
ldr r0, [fp, #-40]
mul r0, r0, r1
ldr r4, =_t27
str r0, [r4]
ldr r4, =_t27
ldr r1, [r4]
ldr r0, [fp, #-8]
mov r1, r0
ldr r0, =#10
sub r0, r1, r0
ldr r4, =_t28
str r0, [r4]
ldr r4, =_t28
ldr r0, [r4]
sub r0, r1, r0
ldr r4, =_t29
str r0, [r4]
ldr r4, =_t29
ldr r1, [r4]
ldr r0, =#1
add r0, r0, r1
ldr r4, =_t30
str r0, [r4]
ldr r4, =_t30
ldr r0, [r4]
mov r4, r0
mov r4, r0
str r4, [fp, #-36]
ldr r0, =_strlt7
mov r1, r0
ldr r0, =print_str_format
bl printf
ldr r0, [fp, #-12]
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, =_strlt8
mov r1, r0
ldr r0, =print_str_format
bl printf
ldr r0, [fp, #-8]
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, =_strlt9
mov r1, r0
ldr r0, =print_str_format
bl printf
ldr r0, [fp, #-36]
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, =_strlt10
mov r1, r0
ldr r0, =print_str_format
bl printf
ldr r0, [fp, #-44]
mov r1, r0
ldr r0, [fp, #-40]
add r0, r0, r1
ldr r4, =_t32
str r0, [r4]
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, =_strlt11
mov r1, r0
ldr r0, =print_str_format
bl printf
ldr r0, [fp, #-44]
mov r1, r0
ldr r0, [fp, #-40]
mul r0, r0, r1
ldr r4, =_t33
str r0, [r4]
ldr r4, =_t33
ldr r1, [r4]
ldr r0, [fp, #-8]
mov r1, r0
ldr r0, =#1
sub r0, r1, r0
ldr r4, =_t34
str r0, [r4]
ldr r4, =_t34
ldr r0, [r4]
sub r0, r1, r0
ldr r4, =_t35
str r0, [r4]
mov r1, r0
ldr r0, =println_int_format
bl printf
mov sp, fp
pop {fp}
pop {pc}
