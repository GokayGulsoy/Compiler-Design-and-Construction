//=========================================================
// FILE: 
//    MulToAdd.cpp
//      
//    DESCRIPTION:   
//         This pass transforms instructions that
//         multiply operand by two with addition by itself   
//         a = a * 2 or a = 2 * a 
//         should be replaced with a = a + a 
//
//    USAGE: opt -load-pass-plugin <BUILD_DIR>/lib/libMulToAdd.so/ '\'
//           -passes="mul-to-add" <bitcode-file>
//      
//==========================================================      
#include "MulToAdd.h"

#include "llvm/ADT/Statistic.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Value.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"

#include <random>

using namespace llvm;

#define DEBUG_TYPE "mul-to-add"
STATISTIC(SubstCount, "The # of substituted instructions");

//-----------------------------------------------------------
// MulToAdd implementation
//-----------------------------------------------------------
bool MulToAdd::runOnBasicBlock(BasicBlock &BB) {
    bool Changed = false; 

    // iterating over all instructions in basic block 
    for (auto Inst = BB.begin(), IE = BB.end(); Inst != IE; Inst++) {

        // we skip non-binary instructions 
        auto *BinOp = dyn_cast<BinaryOperator>(Inst);
        if (!BinOp) {
            continue;
        }

        // skip instructions other than mul
        unsigned OpCode = BinOp->getOpcode();
        if (OpCode != Instruction::Mul || !BinOp->getType()->isIntegerTy()) {
            
            continue;
        }

        auto *Op0 = BinOp->getOperand(0);
        auto *Op1 = BinOp->getOperand(1);

        ConstantInt *CI;
        Value *OperandToAddByItself; 
        // determining which operand is the constant integer 2
        if ((CI = dyn_cast<ConstantInt>(Op0)) && CI->equalsInt(2)) {
            OperandToAddByItself = Op1;
        }

        else if ((CI = dyn_cast<ConstantInt>(Op1)) && CI->equalsInt(2)) {
            OperandToAddByItself = Op0; 
        }

        else  {
            continue; 
        }

        // Creating new multiplication instruction 
        // and replacing it with previous instruction in basic block
        IRBuilder<> Builder(BinOp);
        Instruction *NewInst = BinaryOperator::CreateAdd(
                              OperandToAddByItself,
                              OperandToAddByItself);

        ReplaceInstWithInst(&BB,Inst,NewInst);
        Changed = true;

        // updating the statistics 
        SubstCount++;
    }

    return Changed;
}

PreservedAnalyses MulToAdd::run(llvm::Function &F,
                                llvm::FunctionAnalysisManager &) {
        
        bool Changed = false;
        
        for (auto &BB : F) {
            Changed |= runOnBasicBlock(BB);
        }

        return (Changed ? llvm::PreservedAnalyses::none() : 
                          llvm::PreservedAnalyses::all());                        
}

//-----------------------------------------------------------
// Registering our Pass
//-----------------------------------------------------------
llvm::PassPluginLibraryInfo getMulToAddPluginInfo() {
  return {LLVM_PLUGIN_API_VERSION, "mul-to-add", LLVM_VERSION_STRING,
          [](PassBuilder &PB) {
            PB.registerPipelineParsingCallback(
                [](StringRef Name, FunctionPassManager &FPM,
                   ArrayRef<PassBuilder::PipelineElement>) {
                  if (Name == "mul-to-add") {
                    FPM.addPass(MulToAdd());
                    return true;
                  }
                  return false;
                });
          }};
}

extern "C" LLVM_ATTRIBUTE_WEAK ::llvm::PassPluginLibraryInfo
llvmGetPassPluginInfo() {
  return getMulToAddPluginInfo();
}
