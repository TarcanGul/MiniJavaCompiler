.section .data
child: .word 0
tryr: .word 0
_t0: .word 0
_t1: .word 0
_strlt0: .asciz "55"
a: .word 0
_strlt1: .asciz "45"
_t2: .word 0
_strlt2: .asciz "Addition result: "
_t3: .word 0
_strlt3: .asciz "Addition result: "
_t4: .word 0
_t5: .word 0
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
sub sp, sp, #16
ldr r9, =a
ldr r9, [r9]
str r9, [fp, #-8]
ldr r9, =tryr
ldr r9, [r9]
str r9, [fp, #-12]
ldr r9, =child
ldr r9, [r9]
str r9, [fp, #-16]
ldr r4, =child
ldr r0, =#24
bl malloc
str r0, [r4]
ldr r0, =#2
mov r5, r0
ldr r0, =#3
mov r6, r0
mov r2, r7
mov r1, r6
mov r0, r5
bl _Dad_add
ldr r4, =tryr
ldr r0, =#24
bl malloc
str r0, [r4]
push {r1}
ldr r0, =#5
pop {r1}
ldr r0, =#5
mov r2, r0
ldr r4, =tryr
ldr r4, [r4]
ldr r1, =#24
add r0, r4, r1
str r2, [r0]
push {r1}
ldr r0, =#2
pop {r1}
ldr r0, =#2
mov r2, r0
ldr r4, =tryr
ldr r4, [r4]
ldr r1, =#20
add r0, r4, r1
str r2, [r0]
ldr r0, =_strlt0
bl atoi
str r0, [fp, #-8]
ldr r0, [fp, #-8]
mov r1, r0
ldr r0, =println_int_format
bl printf
ldr r0, =_strlt1
bl atoi
mov r1, r0
ldr r0, =println_int_format
bl printf
mov sp, fp
pop {fp}
b __end__
_AnotherClass_getPrice:
push {fp, lr}
mov fp, sp
sub sp, sp, #24
ldr r0, [fp, #-8]
mov r1, r0
push {r1}
ldr r0, [fp, #-12]
pop {r1}
mul r0, r0, r1
ldr r4, =_t2
str r0, [r4]
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
ldr r0, =_strlt2
mov r1, r0
ldr r0, =print_str_format
bl printf
ldr r0, [fp, #-8]
mov r1, r0
push {r1}
ldr r0, [fp, #-12]
pop {r1}
add r0, r0, r1
ldr r4, =_t3
str r0, [r4]
mov r1, r0
ldr r0, =println_int_format
bl printf
mov sp, fp
pop {fp, pc}
_Dad_add:
push {fp, lr}
mov fp, sp
sub sp, sp, #12
mov r9, r5
str r9, [fp, #-8]
mov r9, r6
str r9, [fp, #-12]
ldr r0, =_strlt3
mov r1, r0
ldr r0, =print_str_format
bl printf
ldr r0, [fp, #-8]
mov r1, r0
push {r1}
ldr r0, [fp, #-12]
pop {r1}
add r0, r0, r1
ldr r4, =_t4
str r0, [r4]
mov r1, r0
ldr r0, =println_int_format
bl printf
mov sp, fp
pop {fp, pc}
_Dad_getPrice:
push {fp, lr}
mov fp, sp
sub sp, sp, #24
ldr r0, [fp, #-8]
mov r1, r0
push {r1}
ldr r0, [fp, #-12]
pop {r1}
mul r0, r0, r1
ldr r4, =_t5
str r0, [r4]
mov sp, fp
pop {fp, pc}
__end__:
pop {pc}
