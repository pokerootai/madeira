#pragma once
/* Build-only shims for the standalone FEX iOS static-lib build.
 * The Madeira fork's FEX_IOS_HOST diagnostics reference Win32 memory-query
 * types; on device these resolve against the in-process Wine runtime at final
 * app link, so only declarations are needed to compile the static archive. */
#include <stdint.h>

typedef const void *LPCVOID;
typedef uintptr_t SIZE_T;

typedef struct _MEMORY_BASIC_INFORMATION {
  void    *BaseAddress;
  void    *AllocationBase;
  uint32_t AllocationProtect;
  uint16_t PartitionId;
  uint16_t _mad_pad0;
  SIZE_T   RegionSize;
  uint32_t State;
  uint32_t Protect;
  uint32_t Type;
} MEMORY_BASIC_INFORMATION, *PMEMORY_BASIC_INFORMATION;

#define MEM_COMMIT  0x1000u
#define MEM_RESERVE 0x2000u
#define MEM_MAPPED  0x40000u
#define MEM_PRIVATE 0x20000u
#define MEM_IMAGE   0x1000000u

#ifdef __cplusplus
extern "C" {
#endif
SIZE_T VirtualQuery(LPCVOID lpAddress, PMEMORY_BASIC_INFORMATION lpBuffer, SIZE_T dwLength);
#ifdef __cplusplus
}
#endif
