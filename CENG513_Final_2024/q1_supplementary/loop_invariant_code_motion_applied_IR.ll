; ModuleID = 'loop_invariant_code_motion_IR.ll'
source_filename = "loop_invariant_code_motion.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@.str = private unnamed_addr constant [20 x i8] c"Value of a*b is: %d\00", align 1

; Function Attrs: noinline nounwind uwtable
define dso_local i32 @main() #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  store i32 0, ptr %1, align 4
  store i32 10, ptr %2, align 4
  store i32 20, ptr %3, align 4
  store i32 0, ptr %4, align 4
  %6 = load i32, ptr %2, align 4
  %7 = load i32, ptr %3, align 4
  %8 = add nsw i32 %6, %7
  %9 = load i32, ptr %2, align 4
  %10 = load i32, ptr %3, align 4
  %11 = mul nsw i32 %9, %10
  %.promoted = load i32, ptr %4, align 4
  %.promoted1 = load i32, ptr %5, align 1
  br label %12

12:                                               ; preds = %16, %0
  %13 = phi i32 [ %8, %16 ], [ %.promoted1, %0 ]
  %14 = phi i32 [ %18, %16 ], [ %.promoted, %0 ]
  %15 = icmp slt i32 %14, 5
  br i1 %15, label %16, label %19

16:                                               ; preds = %12
  %17 = call i32 (ptr, ...) @printf(ptr noundef @.str, i32 noundef %11)
  %18 = add nsw i32 %14, 1
  br label %12, !llvm.loop !6

19:                                               ; preds = %12
  %.lcssa2 = phi i32 [ %13, %12 ]
  %.lcssa = phi i32 [ %14, %12 ]
  store i32 %.lcssa, ptr %4, align 4
  store i32 %.lcssa2, ptr %5, align 1
  ret i32 0
}

declare i32 @printf(ptr noundef, ...) #1

attributes #0 = { noinline nounwind uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 8, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 2}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"clang version 19.0.0git (https://github.com/llvm/llvm-project.git 790bcecce6c135476d2551805c09ed670b9f8418)"}
!6 = distinct !{!6, !7}
!7 = !{!"llvm.loop.mustprogress"}
