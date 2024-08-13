; ModuleID = 'prime_number.c'
source_filename = "prime_number.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: nofree norecurse nosync nounwind memory(none) uwtable
define dso_local i32 @is_prime(i32 noundef %0) local_unnamed_addr #0 {
  %2 = icmp slt i32 %0, 2
  br i1 %2, label %19, label %3

3:                                                ; preds = %1
  %4 = icmp eq i32 %0, 2
  %5 = and i32 %0, 1
  %6 = icmp eq i32 %5, 0
  br i1 %6, label %16, label %7

7:                                                ; preds = %3, %11
  %8 = phi i32 [ %9, %11 ], [ 2, %3 ]
  %9 = add nuw nsw i32 %8, 1
  %10 = icmp eq i32 %9, %0
  br i1 %10, label %14, label %11, !llvm.loop !5

11:                                               ; preds = %7
  %12 = urem i32 %0, %9
  %13 = icmp eq i32 %12, 0
  br i1 %13, label %14, label %7, !llvm.loop !5

14:                                               ; preds = %7, %11
  %15 = icmp sge i32 %9, %0
  br label %16

16:                                               ; preds = %14, %3
  %17 = phi i1 [ %4, %3 ], [ %15, %14 ]
  %18 = zext i1 %17 to i32
  br label %19

19:                                               ; preds = %16, %1
  %20 = phi i32 [ 0, %1 ], [ %18, %16 ]
  ret i32 %20
}

attributes #0 = { nofree norecurse nosync nounwind memory(none) uwtable "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.module.flags = !{!0, !1, !2, !3}
!llvm.ident = !{!4}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 8, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 2}
!4 = !{!"clang version 19.0.0git (https://github.com/llvm/llvm-project.git 790bcecce6c135476d2551805c09ed670b9f8418)"}
!5 = distinct !{!5, !6, !7}
!6 = !{!"llvm.loop.mustprogress"}
!7 = !{!"llvm.loop.unroll.disable"}
