; ModuleID = 'is_prime_hand_alloca.ll'
source_filename = "prime_number.c"

define i32 @is_prime(i32 %n) {
entrance:
  %is_prime = icmp sle i32 %n, 1 ; if n is less than or equal to 1 n is not prime
  br i1 %is_prime, label %not_prime, label %initialize

initialize:
  %i_addr = alloca i32   ; allocate memory for i
  store i32 2, i32* %i_addr ;store the initial value of i in allocated address
  br label %loop_cond

loop_cond:
  %i = load i32, i32* %i_addr ; reload the value at memory pointed by i_addr
  %is_loop_end = icmp sle i32 %i, %n
  br i1 %is_loop_end, label %for_body, label %prime

for_body:
  %remainder = srem i32 %n, %i
  %is_divisible = icmp eq i32 %remainder, 0
  br i1 %is_divisible, label %not_prime, label %loop_inc

loop_inc:
  %i_new = add i32 %i, 1 ; create a variable i_new to hold the new value
  store i32 %i_new, i32* %i_addr ; store the new value of i at memory pointed by i_addr
  br label %loop_cond

not_prime:
  ret i32 0


prime:
  ret i32 1
}
