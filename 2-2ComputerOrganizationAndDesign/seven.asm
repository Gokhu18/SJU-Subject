.globl main
.data
nmsg: .asciiz "n is : "
amsg: .asciiz "a is  : "
pmsg: .asciiz " "

.text
main:


la $a0 nmsg
li $v0 4
syscall
li $v0 5
syscall
#"n is : " ���ڿ� ���, ���� �Է�
add $t0 $v0 $zero



la $a0 amsg
li $v0 4
syscall
li $v0 5
syscall
#"a is : " ���ڿ� ���, ���� �Է�
add $t1 $v0 $zero



addi $t2  $zero 2 #tmp = 0 + 2 

# t0 = n
# t1 = a
# t2 = tmp


loop :


# save ����
addi $t2 $t2 1 # tmp++
add $s0 $s0 $t0 # save = save + a



