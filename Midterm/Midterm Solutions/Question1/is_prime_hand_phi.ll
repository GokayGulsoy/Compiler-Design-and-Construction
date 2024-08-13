; ModuleID = 'is_prime_hand_phi.ll'
source_filename = "prime_number.c"

define i32 @is_prime(i32 %n) {
entrance:
  %is_prime = icmp sle i32 %n, 1 ; if n is less than or equal to 1 n is not prime
  br i1 %is_prime, label %not_prime, label %for_body

for_body:
  %i = phi i32 [ 2, %entrance ], [ %next_i, %loop_inc ] ; phi function
  %next_i = add i32 %i, 1
  %remainder = srem i32 %n, %i
  %is_divisible = icmp eq i32 %remainder, 0
  br i1 %is_divisible, label %not_prime, label %loop_inc

loop_inc:
  %is_prime = icmp ne i32 %next_i, %n
  br i1 %is_prime, label %for_body, label %prime

not_prime:
  ret i32 0 ; return 0 if n is not prime

prime:
  ret i32 1 ; return 1 if n is prime
}
