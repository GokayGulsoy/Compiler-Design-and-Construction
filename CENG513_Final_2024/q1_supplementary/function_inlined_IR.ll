; ModuleID = 'function_inlining_IR.ll'
source_filename = "function_inlining.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: nounwind uwtable
define dso_local i32 @sum(i32 noundef %0, i32 noundef %1) #0 {
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  store i32 %0, ptr %3, align 4
  store i32 %1, ptr %4, align 4
  %6 = load i32, ptr %3, align 4
  %7 = load i32, ptr %4, align 4
  %8 = add nsw i32 %6, %7
  store i32 %8, ptr %5, align 4
  %9 = load i32, ptr %5, align 4
  ret i32 %9
}

; Function Attrs: nounwind uwtable
define dso_local i32 @main() #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  %7 = alloca i32, align 4
  %8 = alloca i32, align 4
  store i32 0, ptr %4, align 4
  store i32 15, ptr %5, align 4
  store i32 20, ptr %6, align 4
  store i32 25, ptr %7, align 4
  %9 = load i32, ptr %5, align 4
  %10 = load i32, ptr %6, align 4
  call void @llvm.lifetime.start.p0(i64 4, ptr %1)
  call void @llvm.lifetime.start.p0(i64 4, ptr %2)
  call void @llvm.lifetime.start.p0(i64 4, ptr %3)
  store i32 %9, ptr %1, align 4
  store i32 %10, ptr %2, align 4
  %11 = load i32, ptr %1, align 4
  %12 = load i32, ptr %2, align 4
  %13 = add nsw i32 %11, %12
  store i32 %13, ptr %3, align 4
  %14 = load i32, ptr %3, align 4
  call void @llvm.lifetime.end.p0(i64 4, ptr %1)
  call void @llvm.lifetime.end.p0(i64 4, ptr %2)
  call void @llvm.lifetime.end.p0(i64 4, ptr %3)
  %15 = load i32, ptr %7, align 4
  %16 = add nsw i32 %14, %15
  store i32 %16, ptr %8, align 4
  ret i32 0
}

; Function Attrs: nocallback nofree nosync nounwind willreturn memory(argmem: readwrite)
declare void @llvm.lifetime.start.p0(i64 immarg, ptr nocapture) #1

; Function Attrs: nocallback nofree nosync nounwind willreturn memory(argmem: readwrite)
declare void @llvm.lifetime.end.p0(i64 immarg, ptr nocapture) #1

attributes #0 = { nounwind uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nocallback nofree nosync nounwind willreturn memory(argmem: readwrite) }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 8, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 2}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"clang version 19.0.0git (https://github.com/llvm/llvm-project.git 790bcecce6c135476d2551805c09ed670b9f8418)"}
