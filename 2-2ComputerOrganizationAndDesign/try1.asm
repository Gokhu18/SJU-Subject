.globl main
.data
one: .asciiz "First Number : "
two: .asciiz "Second Number : "
msg: .asciiz "Answer : "

.text
main:
la $a0 one
li $v0 4
syscall #"First Number : " ���ڿ� ���
li $v0 5
syscall #���� �Է�

add $t0 $v0 $zero #�Էµ� ���� �������Ϳ� ����


la $a0 two
li $v0 4
syscall #"Second Number : " ���ڿ� ���
li $v0 5
syscall #���� �Է�

add $t1 $v0 $zero #�Էµ� ���� �������Ϳ� ����


addi $a0 $t0 0 # a0 = a
addi $a1 $t1 0 # a1 = n-1
addi $a2 $a1 -1 #a2 = n-2


# T(n) = T(n-1) + T(n-2) �ϴ� �����ϰ� �����غ���.

Tfunc :
addi $sp $sp -12
sw $ra 0($sp)
sw $a0 4($sp)
sw $a1 8($sp)
sw $a2 12($sp)

slti $t0 $a1 2 # if n < 2 , set t2 to 1.  if n >= 2, set  a0 to 0

beq $t0 $zero recursive
lw $a2 8($sp)
addi $a2 $a2 -1
beq $t0 $zero recursive
#if n < 2



jr $ra



recursive :
addi $a1 $a1 -1
jal Tfunc





la $a0 msg
li $v0 4
syscall #"Sum : " ���ڿ� ���
li $v0 1
syscall #���� �� ���

li $v0 10
syscall
#���α׷� ����
