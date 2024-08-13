//========================================================================
// FILE:
//    MulToAdd.h
//
// DESCRIPTION:
//    Declares the MulToAdd pass for pass manager.
//========================================================================
#ifndef LLVM_TUTOR_MUL_TO_ADD_H
#define LLVM_TUTOR_MUL_TO_ADD_H

#include "llvm/IR/PassManager.h"
#include "llvm/Pass.h"

struct MulToAdd : public llvm::PassInfoMixin<MulToAdd> {
  llvm::PreservedAnalyses run(llvm::Function &F,
                              llvm::FunctionAnalysisManager &);
  bool runOnBasicBlock(llvm::BasicBlock &B);

  // Without isRequired returning true, this pass will be skipped for functions
  // decorated with the optnone LLVM attribute. Note that clang -O0 decorates
  // all functions with optnone.
  static bool isRequired() { return true; }
};
#endif