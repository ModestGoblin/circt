//===- RTLTypes.h - types for the RTL dialect -------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// Types for the RTL dialect are mostly in tablegen. This file should contain
// C++ types used in MLIR type parameters.
//
//===----------------------------------------------------------------------===//

#ifndef CIRCT_DIALECT_RTL_TYPES_H
#define CIRCT_DIALECT_RTL_TYPES_H

#include "circt/Dialect/RTL/Dialect.h"
#include "mlir/IR/Types.h"

namespace circt {
namespace rtl {

struct FieldInfo {
  StringRef name;
  Type type;
  FieldInfo allocateInto(TypeStorageAllocator &alloc) const {
    return FieldInfo{alloc.copyInto(name), type};
  }
};
} // namespace rtl
} // namespace circt

#define GET_TYPEDEF_CLASSES
#include "circt/Dialect/RTL/RTLTypes.h.inc"

/// Return true if the specified type can be used as an RTL value type, that is
/// the set of types that can be composed together to represent synthesized,
/// hardware but not marker types like InOutType.
bool isRTLValueType(mlir::Type type);

mlir::Type getTypeByField(mlir::Type structVal, mlir::StringRef fieldName);

#endif // CIRCT_DIALECT_RTL_TYPES_H