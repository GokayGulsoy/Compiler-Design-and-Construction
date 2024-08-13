; ModuleID = 'is_prime'
source_filename = "prime_number.c"

define i32 @is_prime(i32 %n) {
entry:
    %cmp1 = icmp sle i32 %n, 1 ; check if n is <= 1
    br i1 %cmp1, label %not_prime, label %loop_entrance

loop_entrance:
    %i = add i32 0, 2  ; initialize i as 2
    br label %loop_condition

loop_condition:
    %is_less_than_n = icmp slt i32 %i, %n ; compare if i is less than n
    br i1 %is_less_than_n, label %loop_body, label %prime

loop_body:
    %remainder = srem i32 %n, %i ; check if n is divisible by i
    %is_divisible = icmp eq i32 %remainder, 0
    br i1 %is_divisible, label %not_prime, label %incr_i

incr_i:
    %i = add i32 %i, 1 ; increment i
    br label %loop_condition

not_prime:
    ret i32 0 ; if number is not prime return 0

prime:
    ret i32 1 ; if number is prime return 1
}
