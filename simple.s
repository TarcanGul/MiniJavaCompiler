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
_t5: .word 0
_t6: .word 0
_t7: .word 0
_t8: .word 0
_strlt0: .asciz "This line should be printed. A bunch of expressions:"
_strlt1: .asciz "Reassigned string"
_t9: .word 0
_strlt2: .asciz "Reassigned string"
_t10: .word 0
_strlt3: .word 0
_strlt4: .asciz "x = "
_strlt5: .asciz "y = "
_t11: .word 0
_t12: .word 0
_t13: .word 0
_t14: .word 0
_t15: .word 0
_t16: .word 0
_t17: .word 0
_t18: .word 0
_t19: .word 0
_t20: .word 0
i: .word 5
_t21: .word 0
_t22: .word 0
_t23: .word 0
_t24: .word 0
_t25: .word 0
_strlt6: .asciz "z = "
_strlt7: .asciz "x+y = "
_t26: .word 0
_strlt8: .asciz "x*y-(y-1) = "
_t27: .word 0
_t28: .word 0
_t29: .word 0
a: .word 10
b: .word 100
_t30: .word 0
_t31: .word 0
_t32: .word 0
_t33: .word 0
_t34: .word 0
_t35: .word 0
_t36: .word 0
_t37: .word 0
_t38: .word 0
_t39: .word 0
_t40: .word 0
_t41: .word 0
_strlt9: .asciz "a = "
_strlt10: .asciz "b = "
_strlt11: .asciz "z = "
_t42: .word 0
_t43: .word 0
_t44: .word 0
_t45: .word 0
array: .word 0
_t46: .word 0
_t47: .word 0
_strlt12: .asciz "array length: "
array2: .word 0
_t48: .word 0
_t49: .word 0
array3: .word 0
_strlt13: .asciz "Hello"
_t50: .word 0
_strlt14: .asciz "Hello"
_strlt15: .asciz " world!"
_t51: .word 0
_strlt16: .asciz " world!"
obj: .word 0
_t52: .word 0
_strlt17: .asciz "Hey from the other side!"
_t53: .word 0
_strlt18: .asciz "Hey from the other side!"
_strlt19: .asciz "soe"
resu: .word 0
_strlt20: .asciz "resu: "
_t54: .word 0
v: .word 0
_t55: .word 0
_t56: .word 0
_strlt21: .asciz "Addition result: "
_t57: .word 0
ab: .word 345
_strlt22: .asciz "Called doSomething()"
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
sub sp, sp, #64
ldr r9, =resu
ldr r9, [r9]
str r9, [fp, #-8]
ldr r9, =obj
ldr r9, [r9]
str r9, [fp, #-12]
ldr r9, =array3
ldr r9, [r9]
str r9, [fp, #-16]
ldr r9, =array2
ldr r9, [r9]
str r9, [fp, #-20]
ldr r9, =array
ldr r9, [r9]
str r9, [fp, #-24]
ldr r9, =b
ldr r9, [r9]
str r9, [fp, #-28]
ldr r9, =a
ldr r9, [r9]
str r9, [fp, #-32]
ldr r9, =i
ldr r9, [r9]
str r9, [fp, #-36]
ldr r9, =concat
ldr r9, [r9]
str r9, [fp, #-40]
ldr r9, =hello
ldr r9, [r9]
str r9, [fp, #-44]
ldr r9, =abra
ldr r9, [r9]
str r9, [fp, #-48]
ldr r9, =bale
ldr r9, [r9]
str r9, [fp, #-52]
ldr r9, =z
ldr r9, [r9]
str r9, [fp, #-56]
ldr r9, =y
ldr r9, [r9]
str r9, [fp, #-60]
ldr r9, =x
ldr r9, [r9]
str r9, [fp, #-64]
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
str r4, [fp, #-44]
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
str r4, [fp, #-40]
push {r1}
ldr r0, [fp, #-64]
mov r1, r0
push {r1}
ldr r0, [fp, #-60]
pop {r1}
mul r0, r0, r1
ldr r4, =_t0
str r0, [r4]
ldr r4, =_t0
ldr r1, [r4]
push {r1}
ldr r0, [fp, #-60]
mov r1, r0
push {r1}
ldr r0, =#1
pop {r1}
sub r0, r1, r0
ldr r4, =_t1
str r0, [r4]
pop {r1}
ldr r4, =_t1
ldr r0, [r4]
sub r0, r1, r0
ldr r4, =_t2
str r0, [r4]
ldr r4, =_t2
ldr r1, [r4]
push {r1}
ldr r0, =#1
pop {r1}
add r0, r0, r1
ldr r4, =_t3
str r0, [r4]
pop {r1}
ldr r4, =_t3
ldr r0, [r4]
ldr r0, [fp, #-64]
mov r1, r0
push {r1}
ldr r0, [fp, #-60]
pop {r1}
mul r0, r0, r1
ldr r4, =_t5
str r0, [r4]
ldr r4, =_t5
ldr r1, [r4]
push {r1}
ldr r0, [fp, #-60]
mov r1, r0
push {r1}
ldr r0, =#1
pop {r1}
sub r0, r1, r0
ldr r4, =_t6
str r0, [r4]
pop {r1}
ldr r4, =_t6
ldr r0, [r4]
sub r0, r1, r0
ldr r4, =_t7
str r0, [r4]
ldr r4, =_t7
ldr r1, [r4]
push {r1}
ldr r0, =#1
pop {r1}
add r0, r0, r1
ldr r4, =_t8
str r0, [r4]
mov r4, r0
str r4, [fp, #-56]
ldr r0, =_strlt0
mov r1, r0
ldr r0, =println_str_format
bl printf
ldr r0, [fp, #-44]
mov r1, r0
ldr r0, =println_str_format
bl printf
push {r1}
ldr r0, =_strlt1
pop {r1}
ldr r4, =_strlt1
mov r0, r4
ldr r0, =_strlt2
mov r4, r0
str r4, [fp, #-44]
ldr r0, [fp, #-44]
mov r1, r0
push {r1}
ldr r0, [fp, #-40]
pop {r1}
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
ldr r3, =_strlt3
str r0, [r3]
mov r1, r4
bl strcpy
mov r1, r5
bl strcat
ldr r4, =_t10
str r0, [r4]
mov r1, r0
ldr r0, =println_str_format
bl printf
ldr r0, [fp, #-44]
mov r1, r0
ldr r0, =println_str_format
bl printf
ldr r0, =_strlt4
mov r1, r0
ldr r0, =print_str_format
bl printf
ldr r0, [fp, #-64]
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, =_strlt5
mov r1, r0
ldr r0, =print_str_format
bl printf
ldr r0, [fp, #-60]
mov r1, r0
push {r1}
ldr r0, =#2
pop {r1}
mul r0, r0, r1
ldr r4, =_t11
str r0, [r4]
ldr r4, =_t11
ldr r1, [r4]
push {r1}
ldr r0, =#2
pop {r1}
add r0, r0, r1
ldr r4, =_t12
str r0, [r4]
mov r1, r0
ldr r0, =println_int_format
bl printf
push {r1}
ldr r0, =#4
mov r1, r0
push {r1}
ldr r0, [fp, #-64]
pop {r1}
sub r0, r1, r0
ldr r4, =_t13
str r0, [r4]
ldr r4, =_t13
ldr r1, [r4]
push {r1}
ldr r0, =#16
pop {r1}
mul r0, r0, r1
ldr r4, =_t14
str r0, [r4]
pop {r1}
ldr r4, =_t14
ldr r0, [r4]
ldr r0, =#4
mov r1, r0
push {r1}
ldr r0, [fp, #-64]
pop {r1}
sub r0, r1, r0
ldr r4, =_t16
str r0, [r4]
ldr r4, =_t16
ldr r1, [r4]
push {r1}
ldr r0, =#16
pop {r1}
mul r0, r0, r1
ldr r4, =_t17
str r0, [r4]
mov r4, r0
str r4, [fp, #-56]
ldr r0, [fp, #-64]
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, [fp, #-56]
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, [fp, #-48]
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
push {r1}
ldr r0, =#4
pop {r1}
mul r0, r0, r1
ldr r4, =_t18
str r0, [r4]
ldr r4, =_t18
ldr r1, [r4]
push {r1}
ldr r0, =#4
pop {r1}
mul r0, r0, r1
ldr r4, =_t19
str r0, [r4]
mov r1, r0
ldr r0, =print_int_format
bl printf
ldr r0, =#1
mov r1, r0
push {r1}
ldr r0, =#0
pop {r1}
and r0, r0, r1
ldr r4, =_t20
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
ldr r0, [fp, #-36]
mov r1, r0
push {r1}
ldr r0, =#0
pop {r1}
cmp r1, r0
bgt _true2
_false2:
mov r0, #0
b _endif2
_true2:
mov r0, #1
b _endif2
_endif2:
ldr r4, =_t21
str r0, [r4]
cmp r0, #0
beq _endwhile0
push {fp}
mov fp, sp
sub sp, sp, #36
ldr r9, =x
ldr r9, [r9]
str r9, [fp, #-8]
ldr r9, =y
ldr r9, [r9]
str r9, [fp, #-12]
ldr r9, =z
ldr r9, [r9]
str r9, [fp, #-16]
ldr r9, =bale
ldr r9, [r9]
str r9, [fp, #-20]
ldr r9, =abra
ldr r9, [r9]
str r9, [fp, #-24]
ldr r9, =hello
ldr r9, [r9]
str r9, [fp, #-28]
ldr r9, =concat
ldr r9, [r9]
str r9, [fp, #-32]
ldr r9, =i
ldr r9, [r9]
str r9, [fp, #-36]
_while0:
ldr r0, =#420
mov r1, r0
ldr r0, =println_int_format
bl printf
push {r1}
ldr r0, [fp, #-36]
mov r1, r0
push {r1}
ldr r0, =#1
pop {r1}
sub r0, r1, r0
ldr r4, =_t22
str r0, [r4]
pop {r1}
ldr r4, =_t22
ldr r0, [r4]
ldr r0, [fp, #-36]
mov r1, r0
push {r1}
ldr r0, =#1
pop {r1}
sub r0, r1, r0
ldr r4, =_t24
str r0, [r4]
mov r4, r0
str r4, [fp, #-36]
ldr r0, [fp, #-36]
mov r1, r0
push {r1}
ldr r0, =#0
pop {r1}
cmp r1, r0
bgt _true3
_false3:
mov r0, #0
b _endif3
_true3:
mov r0, #1
b _endif3
_endif3:
ldr r4, =_t25
str r0, [r4]
cmp r0, #0
bne _while0
mov sp, fp
pop {fp}
_endwhile0:
ldr r0, =_strlt6
mov r1, r0
ldr r0, =print_str_format
bl printf
ldr r0, [fp, #-56]
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, =_strlt7
mov r1, r0
ldr r0, =print_str_format
bl printf
ldr r0, [fp, #-64]
mov r1, r0
push {r1}
ldr r0, [fp, #-60]
pop {r1}
add r0, r0, r1
ldr r4, =_t26
str r0, [r4]
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, =_strlt8
mov r1, r0
ldr r0, =print_str_format
bl printf
ldr r0, [fp, #-64]
mov r1, r0
push {r1}
ldr r0, [fp, #-60]
pop {r1}
mul r0, r0, r1
ldr r4, =_t27
str r0, [r4]
ldr r4, =_t27
ldr r1, [r4]
push {r1}
ldr r0, [fp, #-60]
mov r1, r0
push {r1}
ldr r0, =#1
pop {r1}
sub r0, r1, r0
ldr r4, =_t28
str r0, [r4]
pop {r1}
ldr r4, =_t28
ldr r0, [r4]
sub r0, r1, r0
ldr r4, =_t29
str r0, [r4]
mov r1, r0
ldr r0, =print_int_format
bl printf
push {r1}
ldr r0, [fp, #-64]
mov r1, r0
push {r1}
ldr r0, [fp, #-32]
pop {r1}
add r0, r0, r1
ldr r4, =_t30
str r0, [r4]
pop {r1}
ldr r4, =_t30
ldr r0, [r4]
ldr r0, [fp, #-64]
mov r1, r0
push {r1}
ldr r0, [fp, #-32]
pop {r1}
add r0, r0, r1
ldr r4, =_t32
str r0, [r4]
mov r4, r0
str r4, [fp, #-64]
push {r1}
ldr r0, [fp, #-64]
mov r1, r0
push {r1}
ldr r0, [fp, #-60]
pop {r1}
mul r0, r0, r1
ldr r4, =_t33
str r0, [r4]
ldr r4, =_t33
ldr r1, [r4]
push {r1}
ldr r0, [fp, #-28]
mov r1, r0
push {r1}
ldr r0, =#10
pop {r1}
sub r0, r1, r0
ldr r4, =_t34
str r0, [r4]
pop {r1}
ldr r4, =_t34
ldr r0, [r4]
sub r0, r1, r0
ldr r4, =_t35
str r0, [r4]
ldr r4, =_t35
ldr r1, [r4]
push {r1}
ldr r0, =#1
pop {r1}
add r0, r0, r1
ldr r4, =_t36
str r0, [r4]
pop {r1}
ldr r4, =_t36
ldr r0, [r4]
ldr r0, [fp, #-64]
mov r1, r0
push {r1}
ldr r0, [fp, #-60]
pop {r1}
mul r0, r0, r1
ldr r4, =_t38
str r0, [r4]
ldr r4, =_t38
ldr r1, [r4]
push {r1}
ldr r0, [fp, #-28]
mov r1, r0
push {r1}
ldr r0, =#10
pop {r1}
sub r0, r1, r0
ldr r4, =_t39
str r0, [r4]
pop {r1}
ldr r4, =_t39
ldr r0, [r4]
sub r0, r1, r0
ldr r4, =_t40
str r0, [r4]
ldr r4, =_t40
ldr r1, [r4]
push {r1}
ldr r0, =#1
pop {r1}
add r0, r0, r1
ldr r4, =_t41
str r0, [r4]
mov r4, r0
str r4, [fp, #-56]
ldr r0, =_strlt9
mov r1, r0
ldr r0, =print_str_format
bl printf
ldr r0, [fp, #-32]
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, =_strlt10
mov r1, r0
ldr r0, =print_str_format
bl printf
ldr r0, [fp, #-28]
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, =_strlt11
mov r1, r0
ldr r0, =print_str_format
bl printf
ldr r0, [fp, #-56]
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, [fp, #-64]
mov r1, r0
push {r1}
ldr r0, [fp, #-60]
pop {r1}
add r0, r0, r1
ldr r4, =_t42
str r0, [r4]
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, [fp, #-64]
mov r1, r0
push {r1}
ldr r0, [fp, #-60]
pop {r1}
mul r0, r0, r1
ldr r4, =_t43
str r0, [r4]
ldr r4, =_t43
ldr r1, [r4]
push {r1}
ldr r0, [fp, #-28]
mov r1, r0
push {r1}
ldr r0, =#1
pop {r1}
sub r0, r1, r0
ldr r4, =_t44
str r0, [r4]
pop {r1}
ldr r4, =_t44
ldr r0, [r4]
sub r0, r1, r0
ldr r4, =_t45
str r0, [r4]
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, =#20
bl malloc
ldr r4, =array
str r0, [r4]
push {r1}
ldr r0, =#45
pop {r1}
ldr r4, =array
ldr r4, [r4]
ldr r0, =#2
ldr r2, =#4
mul r1, r0, r2
add r0, r4, r1
mov r1, r0
ldr r0, =#45
str r0, [r1]
push {r1}
ldr r0, =#34343
pop {r1}
ldr r4, =array
ldr r4, [r4]
ldr r0, =#4
ldr r2, =#4
mul r1, r0, r2
add r0, r4, r1
mov r1, r0
ldr r0, =#34343
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
ldr r4, =array
ldr r4, [r4]
ldr r0, =#4
ldr r1, =#4
mul r1, r1, r0
add r0, r4, r1
ldr r0, [r0]
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, =_strlt12
mov r1, r0
ldr r0, =print_str_format
bl printf
ldr r0, [fp, #-24]
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, =#24
bl malloc
ldr r4, =array2
str r0, [r4]
push {r1}
ldr r0, =#1
pop {r1}
ldr r4, =array2
ldr r4, [r4]
ldr r0, =#5
ldr r2, =#4
mul r1, r0, r2
add r0, r4, r1
mov r1, r0
ldr r0, =#1
str r0, [r1]
push {r1}
ldr r0, =#0
pop {r1}
ldr r4, =array2
ldr r4, [r4]
ldr r0, =#4
ldr r2, =#4
mul r1, r0, r2
add r0, r4, r1
mov r1, r0
ldr r0, =#0
str r0, [r1]
ldr r4, =array2
ldr r4, [r4]
ldr r0, =#5
ldr r1, =#4
mul r1, r1, r0
add r0, r4, r1
ldr r0, [r0]
cmp r0, #1
bne _false4
_true4:
ldr r0, =println_str_format
ldr r1, =bool_true
bl printf
b _endif4
_false4:
ldr r0, =println_str_format
ldr r1, =bool_false
bl printf
_endif4:
ldr r4, =array2
ldr r4, [r4]
ldr r0, =#4
ldr r1, =#4
mul r1, r1, r0
add r0, r4, r1
ldr r0, [r0]
cmp r0, #1
bne _false5
_true5:
ldr r0, =println_str_format
ldr r1, =bool_true
bl printf
b _endif5
_false5:
ldr r0, =println_str_format
ldr r1, =bool_false
bl printf
_endif5:
ldr r0, =#32
bl malloc
ldr r4, =array3
str r0, [r4]
push {r1}
ldr r0, =_strlt13
pop {r1}
ldr r4, =_strlt13
mov r0, r4
ldr r4, =array3
ldr r4, [r4]
ldr r0, =#1
ldr r2, =#8
mul r1, r0, r2
add r0, r4, r1
mov r1, r0
ldr r0, =_strlt14
str r0, [r1]
push {r1}
ldr r0, =_strlt15
pop {r1}
ldr r4, =_strlt15
mov r0, r4
ldr r4, =array3
ldr r4, [r4]
ldr r0, =#2
ldr r2, =#8
mul r1, r0, r2
add r0, r4, r1
mov r1, r0
ldr r0, =_strlt16
str r0, [r1]
ldr r4, =array3
ldr r4, [r4]
ldr r0, =#1
ldr r1, =#8
mul r1, r1, r0
add r0, r4, r1
ldr r0, [r0]
mov r1, r0
ldr r0, =println_str_format
bl printf
ldr r4, =obj
ldr r0, =#32
bl malloc
str r0, [r4]
push {r1}
ldr r0, =#5
pop {r1}
ldr r0, =#5
mov r2, r0
ldr r4, =obj
ldr r4, [r4]
ldr r1, =#32
add r0, r4, r1
str r2, [r0]
push {r1}
ldr r0, =_strlt17
pop {r1}
ldr r4, =_strlt17
mov r0, r4
ldr r0, =_strlt18
mov r2, r0
ldr r4, =obj
ldr r4, [r4]
ldr r1, =#24
add r0, r4, r1
str r2, [r0]
ldr r4, =obj
ldr r4, [r4]
ldr r1, =#32
add r0, r4, r1
ldr r0, [r0]
mov r1, r0
ldr r0, =print_int_format
bl printf
ldr r4, =obj
ldr r4, [r4]
ldr r1, =#24
add r0, r4, r1
ldr r0, [r0]
mov r1, r0
ldr r0, =println_str_format
bl printf
bl _AnotherClass_doSomething
ldr r0, =#23
mov r5, r0
ldr r0, =#42
mov r6, r0
mov r2, r7
mov r1, r6
mov r0, r5
bl _AnotherClass_add
ldr r0, =#34
mov r5, r0
ldr r0, =#23
mov r6, r0
ldr r0, =#12
mov r7, r0
mov r3, r8
mov r2, r7
mov r1, r6
mov r0, r5
bl _AnotherClass_comp_stuff
ldr r0, =#21
mov r5, r0
ldr r0, =_strlt19
mov r6, r0
mov r2, r7
mov r1, r6
mov r0, r5
bl _AnotherClass_get_mult
str r0, [fp, #-8]
ldr r0, =_strlt20
mov r1, r0
ldr r0, =print_str_format
bl printf
ldr r0, [fp, #-8]
mov r1, r0
ldr r0, =println_int_format
bl printf
mov sp, fp
pop {fp}
b __end__
_AnotherClass_get_mult:
push {fp, lr}
mov fp, sp
sub sp, sp, #12
mov r9, r5
str r9, [fp, #-8]
mov r9, r6
str r9, [fp, #-12]
ldr r0, [fp, #-12]
mov r1, r0
ldr r0, =println_str_format
bl printf
ldr r0, [fp, #-8]
mov sp, fp
pop {fp, pc}
_AnotherClass_comp_stuff:
push {fp, lr}
mov fp, sp
sub sp, sp, #20
ldr r9, =v
ldr r9, [r9]
str r9, [fp, #-8]
mov r9, r5
str r9, [fp, #-12]
mov r9, r6
str r9, [fp, #-16]
mov r9, r7
str r9, [fp, #-20]
ldr r0, [fp, #-12]
mov r1, r0
push {r1}
ldr r0, [fp, #-16]
pop {r1}
mul r0, r0, r1
ldr r4, =_t54
str r0, [r4]
str r0, [fp, #-8]
ldr r0, [fp, #-8]
mov r1, r0
push {r1}
ldr r0, [fp, #-20]
mov r1, r0
push {r1}
ldr r0, [fp, #-12]
pop {r1}
sub r0, r1, r0
ldr r4, =_t55
str r0, [r4]
pop {r1}
ldr r4, =_t55
ldr r0, [r4]
mul r0, r0, r1
ldr r4, =_t56
str r0, [r4]
mov r1, r0
ldr r0, =println_int_format
bl printf
mov sp, fp
pop {fp, pc}
_AnotherClass_add:
push {fp, lr}
mov fp, sp
sub sp, sp, #12
mov r9, r5
str r9, [fp, #-8]
mov r9, r6
str r9, [fp, #-12]
ldr r0, =_strlt21
mov r1, r0
ldr r0, =print_str_format
bl printf
ldr r0, [fp, #-8]
mov r1, r0
push {r1}
ldr r0, [fp, #-12]
pop {r1}
add r0, r0, r1
ldr r4, =_t57
str r0, [r4]
mov r1, r0
ldr r0, =println_int_format
bl printf
mov sp, fp
pop {fp, pc}
_AnotherClass_doSomething:
push {fp, lr}
mov fp, sp
sub sp, sp, #36
ldr r9, =ab
ldr r9, [r9]
str r9, [fp, #-8]
ldr r0, [fp, #-8]
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, =_strlt22
mov r1, r0
ldr r0, =println_str_format
bl printf
mov sp, fp
pop {fp, pc}
__end__:
pop {pc}
