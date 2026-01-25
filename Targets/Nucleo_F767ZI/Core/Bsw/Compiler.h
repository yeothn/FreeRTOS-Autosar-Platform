#ifndef COMPILER_H
#define COMPILER_H

#define _GNU_C_
#define INLINE              inline
#define LOCAL_INLINE        static inline

#define FUNC(rettype, memclass) rettype

#define VAR(vartype, memclass) vartype

#define P2VAR(ptrtype, memclass, ptrclass) ptrtype *

#define P2CONST(ptrtype, memclass, ptrclass) const ptrtype *

#define CONST(consttype, memclass) const consttype

#define CONSTP2VAR(ptrtype, memclass, ptrclass) ptrtype * const

#define CONSTP2CONST(ptrtype, memclass, ptrclass) const ptrtype * const

#ifndef NULL_PTR
  #define NULL_PTR ((void *)0)
#endif

#endif /* COMPILER_H */
