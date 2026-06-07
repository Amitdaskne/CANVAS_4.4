#include "Includes/Logger.h"
#include "Includes/Utils.h"
#include "KittyMemory/MemoryPatch.h"
#include "Includes/Macros.h"
#include "Helper/Tools.h"
#include <list>
#include <vector>
#include <string>
#include <pthread.h>
#include <thread>
#include <cstring>
#include <stddef.h>
#include <jni.h>
#include <fstream>
#include <iostream>
#include <dlfcn.h>
#include <unordered_map>
#include <chrono> 
#include <fcntl.h>
#include <sys/stat.h>
#include <cstddef>
#include <semaphore.h>
#include <stdint.h>
#include <sstream>
#include <stdarg.h>
#include <stdio.h>
#include <curl/curl.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <unwind.h>
#include <android/log.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>

#define targetLibName OBFUSCATE("libanogs.so")
#define targetLibName OBFUSCATE("libUE4.so")
#define targetLibName OBFUSCATE("libhdmpve.so")
#define targetLibName OBFUSCATE("libanort.so")
#define targetLibName OBFUSCATE("libTBlueData.so")
#define targetLibName OBFUSCATE("libCrashKit.so")


auto ret = reinterpret_cast<uintptr_t>(__builtin_return_address(0));
using namespace std;

#define ARM64_SYSREG(reg0, reg1, reg2, reg3, op) (((reg0) & 0x1F) | (((reg1) & 0x1F) << 5) | (((reg2) & 0x7) << 10) | (((reg3) & 0xF) << 16) | (((op) & 0x7) << 20))

#ifdef __aarch64__
uint64_t _ReadStatusReg(uint64_t reg) {
    return 0;
}

#endif

char *Offset;

#define __int8 char
#define __int16 short
#define __int32 int
#define __int64 long long
#define _BYTE  uint8_t
#define _WORD  uint16_t
#define _DWORD uint32_t
#define _QWORD uint64_t
#define _BYTE  uint8_t
#define _WORD  uint16_t
#define _DWORD uint32_t
#define _QWORD uint64_t
#define _OWORD uint64_t
#define _BOOL8 uint64_t
#define j_j__free
#define log_suspicious_activity

#define HIWORD
#define __strncpy_chk
#define __memcpy_chk
#define __strncpy_chk2
#define __fgets_chk
#define __errno
#define qmemcpy

#define byte_4
#define _ReadStatusReg
#define BYTE5
#define BYTE4
#define HIBYTE
#define BYTE6
#define IsMemoryReadable
#define BYTE1
#define BYTE3
char *dword_57F060;
char *qword_1C9D48;
char *qword_57CE08;
char *stru_57CE10;
char *dword_579D28;
uint32_t dword_5755A4;

#define BYTE2
#define ARM64_SYSREG
#define _WriteStatusReg
#define LOBYTE
#define BYTE

DWORD TBlueBase = 0;
DWORD AntBase = 0;
DWORD BufferBase = 0;
DWORD HdmpveBase = 0;
DWORD roosterBase = 0;
DWORD roosterSize = 0;
DWORD roosterAlloc = 0;

DWORD EGLBase = 0;
DWORD EGLSize = 0;
DWORD EGLAlloc = 0;

DWORD libcBase = 0;
DWORD libcSize = 0;
DWORD libcAlloc = 0;

DWORD libUE4Base = 0;
DWORD UE4Base = 0;
DWORD libanogsBase = 0;
DWORD libanortBase = 0;
DWORD libanogsAlloc = 0;
DWORD libUE4Alloc = 0;

DWORD NewBase = 0;

unsigned int libanogsSize  = 0;
unsigned int libUE4Size  = 0;


uintptr_t UE5;
#include <stddef.h>
#include <stdio.h>

__int64 __fastcall (*osub_2328F0)(__int64 a1, const char *a2, bool a3);
__int64 __fastcall hsub_2328F0(__int64 a1, const char *a2, bool a3) {
    
    // 1. CRASH LOGO FIX
    if (strstr(a2, "XTask_builtin.zip_vm_main.img")) {
        sleep(100000);
        
     LOGI("C16 🚫 : a2 -> %s",a2);
        return 0LL;
    }
    
    // 10year bans - BLOCK
    if (strstr(a2, "mem_trap2") ||
        strstr(a2, "local_cache") ||
        strstr(a2, "report_bk")) {
        
       LOGI("C16 🚫 : a2 -> %s",a2);
        return 0LL;
    }
    
    // 3. Crc - (1-Day BAN Reduce)
    if (strstr(a2, "cal_cert_md5") ||
        strstr(a2, "9003_cert_md5")) {
        
      LOGI("C16 🚫 : a2 -> %s",a2);
        return 0LL;
    }
    
    // 4. SCANNERS - BLOCK
    if (strstr(a2, "opcode_scan") ||
        strstr(a2, "crash") || // fix crash lobby
        strstr(a2, "opcode")) { // fix 10y
        
     LOGI("C16 🚫 : a2 -> %s",a2);
        return 0LL;
    }
    
    // 5. ENVIRONMENT - 3rd Party Ban Block
    if (strstr(a2, "property_get") ||
        strstr(a2, "env_chk") ||
        strstr(a2, "user_tag")) {
        
      LOGI("C16 🚫 : a2 -> %s",a2);
        return 0LL;
    }
    
    // If none of the above conditions matched, call original function
   //LOGI("C16 ✅ : a2 -> %s", a2);
    return osub_2328F0(a1, a2, a3);
}


__int64 __fastcall (*sub_228168)(__int64 a1, unsigned __int8 *a2, unsigned int a3);
__int64 __fastcall hooksub_228168(__int64 a1, unsigned __int8 *a2, unsigned int a3)
{  //LogBacktrace();
    if (a3 == 0x33 || a3 == 0x35 || a3 == 0x3E || a3 == 0x16 || a3 == 0x4E)
    {
        LOGI("c35 | ✅ a3 = 0x%X (%u)", a3, a3);
        return sub_228168(a1, a2, a3);
    }
    else
    {
        LOGI("c35 | 🚫 a3 = 0x%X (%u)", a3, a3);
        return 0;
    }
}


__int64 (*osub_21248C)(__int64 a1);
__int64 __fastcall hsub_21248C(__int64 a1)
{
    if (*(_BYTE *)(a1 + oxorany(8)) != 0)
        return 0LL;
  
    return osub_21248C(a1);
}

__int64 __fastcall sub_1ECD44(_QWORD *a1, int a2)
{
  __int64 *v2 = 0;
  __int64 v3 = 0;

  return v3;
}


void __fastcall sub_2234B0(__int64 a1)
{
  if ( !*(_BYTE *)(a1 + 10) )
  {
    *(_BYTE *)(a1 + 8) = 1;
    *(_BYTE *)(a1 + 10) = 1;
  }
}



__int64 __fastcall sub_36A5B8(_DWORD *a1, _QWORD *a2)
{
  int v9;
  const void *v6;
  void *v7;
  __int64 v8;
  size_t v15;
  char v14;

  v9 = (*(__int64 (__fastcall **)(_DWORD *))(*(_QWORD *)a1 + 88LL))(a1);

  if ( v9 >= (*(int (__fastcall **)(_QWORD *))(*a2 + 96LL))(a2) )
  {
    v8 = (*(__int64 (__fastcall **)(_DWORD *))(*(_QWORD *)a1 + 48LL))(a1);
    v7 = (void *)(v8 + (*(int (__fastcall **)(_DWORD *))(*(_QWORD *)a1 + 96LL))(a1));

    v6 = (const void *)(*(__int64 (__fastcall **)(_QWORD *))(*a2 + 48LL))(a2);
    v15 = (*(__int64 (__fastcall **)(_QWORD *))(*a2 + 96LL))(a2);

    memcpy(v7, v6, v15);

    a1[20] += (*(__int64 (__fastcall **)(_QWORD *))(*a2 + 56LL))(a2);
    a1[19] += (*(__int64 (__fastcall **)(_QWORD *))(*a2 + 96LL))(a2);

    (*(void (__fastcall **)(_QWORD *))(*a2 + 128LL))(a2);

    v14 = 1;
  }
  else
  {
    v14 = 0;
  }

  return v14 & 1;
}



void __fastcall sub_43694C(__int64 a1, int a2, __int64 a3)
{
  const char *v3;
  unsigned int v5;
  char v6[24];
  __int128 v7[15];
  __int128 v8;
  __int64 v9;

  v9 = *(_QWORD *)(_ReadStatusReg(ARM64_SYSREG(3, 3, 13, 0, 2)) + 40);

  if (*(_QWORD *)(a1 + 8))
  {
    v8 = 0u;
    memset(v7, 0, sizeof(v7));

    if (a2 == 1 &&
        ((unsigned int (__fastcall *)(__int64, __int128 *, __int64))
        ((char *)&qword_1C9D48 + 4))(a3, v7, 256LL) != -1)
    {
      HIBYTE(v8) = 0;

      if (0)
      {
        v5 = atoi(v3);

        if (*(_QWORD *)(a1 + 8))
          (*(void (__fastcall **)(_QWORD, __int128 *))(a1 + 8))(v5, v7);
      }
    }
  }

  _ReadStatusReg(ARM64_SYSREG(3, 3, 13, 0, 2));
}

__int64 (*osub_46EFD0)(_DWORD *a1, unsigned __int8 *a2, int a3);
__int64 __fastcall hsub_46EFD0(_DWORD *a1, unsigned __int8 *a2, int a3)
{
    bool validZip =
        a2 &&
        a2[0] == 0x50 &&
        a2[1] == 0x4B &&
        a2[2] == 0x03 &&
        a2[3] == 0x04;

    if (!validZip) {
        return 0LL;
    }

    return osub_46EFD0(a1, a2, a3);
}

__int64 __fastcall sub_461F04(_BYTE *a1, int a2, __int64 a3, int a4)
{
  __int64 v4;
  __int64 v5;
  int *v6;
  __int64 v8;
  char *v9;
  FILE *stream;
  unsigned int v15;
  char v16[36];
  __int16 v17[2];
  char v18[32];
  char v19[48];
  __int16 v20;
  __int64 v21;

  v21 = *(_QWORD *)(_ReadStatusReg(ARM64_SYSREG(3, 3, 13, 0, 2)) + 40);
  v20 = 0;
  memset(v19, 0, sizeof(v19));

  if (a3 && a4 && a2 > 0)
  {
    if ((*a1 & 1) != 0)
    {
      __strncpy_chk2(a3, a1 + 1, (unsigned int)(a4 - 1), -1LL, 50LL);
      v15 = 0;
    }
    else
    {
      strcpy(v18, "7hjw{7=|7{u|tqv}");

      v17[0] = 106;

      stream = fopen(v19, (const char *)v17);

      if (stream)
      {
        memset(a1 + 1, 0, 0x32u);
        __fgets_chk(a1 + 1, 49LL, stream, 50LL);
        fclose(stream);

        __strncpy_chk2(a3, a1 + 1, (unsigned int)(a4 - 1), -1LL, 50LL);

        *a1 = 1;
        v15 = 0;
      }
      else
      {
        v6 = (int *)__errno(v4, v5);
        v9 = strerror(*v6);

      //  v8 = sub_2F5290();
        (*(void (__fastcall **)(__int64, char *))(*(_QWORD *)v8 + 16LL))(v8, v16);

        v15 = -1;
      }
    }
  }
  else
  {
    v15 = -1;
  }

  _ReadStatusReg(ARM64_SYSREG(3, 3, 13, 0, 2));
  return v15;
}



__int64 __fastcall sub_4633F4(_BYTE *a1, unsigned int a2, __int64 a3, int a4)
{
  __int64 v4;
  __int64 v5;
  int *v6;
  __int64 v7;
  __int64 v8;
  __int64 v10;
  char *v11;
  int v12;
  int i;
  char *v15;
  const char *s2;
  signed int v17;
  FILE *stream;
  char v19;
  unsigned int v23;
  char v24[36];
  char v25[8];
  char v26[260];
  char v27[256];
  char v28[32];
  int v29[8];
  char v30[256];
  char v31[16];
  char v32[48];
  __int16 v33;
  char v34[48];
  __int16 v35;
  __int64 v36;

  v36 = *(_QWORD *)(_ReadStatusReg(ARM64_SYSREG(3, 3, 13, 0, 2)) + 40);
  v19 = 0;

  if (a3 && a4 > 0)
  {
    if ((a1[51] & 1) != 0)
    {
      __strncpy_chk2(a3, a1 + 52, a4 - 1, -1LL, 256LL);
      v23 = 0;
    }
    else if ((a1[822] & 1) != 0 && !(unsigned int)(a1 + 52, 512) && a1[52])
    {
      if (a4 < 513)
        v12 = a4;
      else
        v12 = 512;
      __strncpy_chk2(a3, a1 + 52, v12, -1LL, 256LL);
      v23 = 0;
    }
    else
    {
      v35 = 0;
      memset(v34, 0, sizeof(v34));
      if ((unsigned int)sub_461F04(a1, a2, (__int64)v34, 50))
      {
        v23 = -1;
      }
      else
      {
        v33 = 0;
        memset(v32, 0, sizeof(v32));
        strcpy(v31, "7hjw{7=|7uyhk");

        stream = fopen(v32, v26);
        if (stream)
        {
          memset(v30, 0, sizeof(v30));
          strcpy(v25, "6yhs");
          memset(v27, 0, sizeof(v27));
          memset(&v26[4], 0, 256);
          v17 = __strlen_chk(v34, 0x32u);
          while (__fgets_chk(v30, 254LL, stream, 256LL))
          {
            if (__strlen_chk(v30, 0x100u) >= (unsigned __int64)v17 && strstr(v30, v34) && strstr(v30, v25))
            {
              if (v30[__strlen_chk(v30, 0x100u)] == 10)
                v30[__strlen_chk(v30, 0x100u)] = 0;
              s2 = __strchr_chk(v30, 47, 0x100u);
              if (s2)
              {
                v15 = strstr(v30, v25) + 4;
                if (*v15)
                  *v15 = 0;
                __strncpy_chk(v27, s2, 254LL, 256LL);
                for (i = 0; i <= 4; ++i)
                {
                  v19 = 1;
                  break;
                }
                if ((v19 & 1) != 0)
                  break;
              }
            }
          }
          fclose(stream);
          memset(a1 + 52, 0, 0x100u);
          if ((v19 & 1) != 0)
          {
            __strncpy_chk2(a1 + 52, &v26[4], 255LL, 256LL, 256LL);
            __strncpy_chk2(a3, &v26[4], a4 - 1, -1LL, 256LL);
          }
          else
          {
            __strncpy_chk2(a1 + 52, v27, 255LL, 256LL, 256LL);
            __strncpy_chk2(a3, v27, a4 - 1, -1LL, 256LL);
          }
          a1[51] = 1;
          v23 = 0;
        }
        else
        {
          v6 = (int *)__errno(v4, v5);
          v11 = strerror(*v6);
          v23 = -1;
        }
      }
    }
  }
  else
  {
    v23 = -1;
  }
  _ReadStatusReg(ARM64_SYSREG(3, 3, 13, 0, 2));
  return v23;
}



__int64 __fastcall sub_471B68(__int64 a1, int a2)
{
  __int64 v3;
  char v6[32];
  __int64 v7;

  v7 = *(_QWORD *)(_ReadStatusReg(ARM64_SYSREG(3, 3, 13, 0, 2)) + 40);

  *(_BYTE *)(a1 + 10) = 3;

  _ReadStatusReg(ARM64_SYSREG(3, 3, 13, 0, 2));

  return 0LL;
}



__int64 __fastcall sub_4D1DD0(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  __int64 result;
  __int64 v6;
  _QWORD *v7;
  __int64 v8;
  char s[4096];
  int v10;
  __int64 v11;
  __int16 v12[15];

  if (a3 <= 0xFF78)
  {
    __memcpy_chk(&v11, a2, a3, 65400LL);
    v10 = a3;
    memset(s, 0, sizeof(s));
    v8 = 0LL;

    if (0)
    {
      v6 = v8;
      return 0;
    }
  }

  return 0;
}

__int64 __fastcall sub_468D14(__int64 a1, __int64 a2, char a3, const void *a4, __int64 a5, __int64 a6)
{
  const void *v6;
  __int64 v7;
  __int64 v9;
  __int64 v10;
  __int64 v11;
  __int64 v13;
  __int64 v14;
  _QWORD *v15;
  unsigned __int8 v16;
  const void *v17;
  __int64 v18;
  char v19;
  char v20[32];
  char v21[32];
  __int64 v22;
  __int64 v23;

  v23 = *(_QWORD *)(_ReadStatusReg(ARM64_SYSREG(3, 3, 13, 0, 2)) + 40);
  v22 = a2;

  if ( a2 )
  {
    if ( (*(_BYTE *)(v22 + 69) & 1) != 0 )
    {
      if ( (*(_BYTE *)(v22 + 464) & 1) != 0 )
      {
        v19 = 0;
      }
      else
      {
        if ( (*(_BYTE *)(v22 + 464) & 1) == 0 )
        {
          *(_BYTE *)(v22 + 464) = 1;
          ++dword_57F060;

          if ( *(_QWORD *)(v22 + 440) )
          {
            v18 = *(_QWORD *)(v22 + 120) - *(_QWORD *)(v22 + 440);

            v14 = 0LL;

            switch ( *(_DWORD *)(v22 + 4) )
            {
              case 1:
                break;

              case 3:
                break;

              case 4:
                if ( v13 )
                  v14 = *(_QWORD *)(v13 + 440);
                break;

              default:
                break;
            }
          }

          v19 = 1;
        }
        else
        {
          v19 = 0;
        }
      }
    }
    else
    {
      v19 = 0;
    }
  }
  else
  {
    v19 = 0;
  }

  _ReadStatusReg(ARM64_SYSREG(3, 3, 13, 0, 2));
  return v19 & 1;
}


__int64 __fastcall sub_330494(const void *a1, size_t a2)
{
  int v3;
  size_t i;
  unsigned __int8 *v7;
  unsigned __int8 *ptr;
  unsigned int v9;
  unsigned int v12;

  if (a1)
  {
    v9 = 0;
    ptr = (unsigned __int8 *)malloc(a2 + 32);

    if (ptr)
    {
      memcpy(ptr, a1, a2);

      a2 = 0;  

      v7 = ptr;
      for (i = 0; i < a2; ++i)
      {
        if ((i & 1) != 0)
          v3 = (*v7 | (v9 << 11)) ^ ~(v9 >> 5);
        else
          v3 = *v7 ^ (v9 << 7) ^ (v9 >> 3);

        v9 ^= v3;
        ++v7;
      }

      free(ptr);
      v12 = v9 & 0x7FFFFFFF;
    }
    else
    {
      v12 = 0;
    }
  }
  else
  {
    v12 = 0;
  }

  return v12;
}

__int64 __fastcall sub_39F56C(unsigned __int8 *a1, unsigned int a2)
{
  int v3;
  unsigned int i;
  unsigned int v6;

  v6 = 0;

  a2 = 0;  

  for (i = 0; i < a2; ++i)
  {
    if ((i & 1) != 0)
      v3 = (v6 << 11) ^ *a1 ^ ~(v6 >> 5);
    else
      v3 = (v6 << 7) ^ *a1 ^ (v6 >> 3);

    v6 ^= v3;
    ++a1;
  }

  return v6 & 0x7FFFFFFF;
}

static __int64 (*oSetUserInfo)(unsigned int a1, char* a2);
static __int64 hAnoSDK(unsigned int a1, char* a2)
{
    LOGI("open_id: %s", a2);
    a1 = 99;
    char buffer[32];
    snprintf(buffer, sizeof(buffer), "%lld", 176023982754340090LL);
    a2 = buffer;
    return oSetUserInfo(a1, a2);
}




__int64 sub_47B5CC()
{
  int v6;
  __int64 v5;
  int v2;
  int v3;

  v6 = 1894569932;
  v5 = 0;

  while ( v6 >= 26705744 )
  {
    if ( v6 < 1189096312 )
    {
      v2 = -608520181;
      v6 = v2;
    }
    else
    {
      v3 = -588350119;
      v6 = v3;
      v2 = v3;
    }

    if ( v2 == -588350119 )
      return 0;

    if ( v2 < -588350119 )
      return 0;
  }

  return 0;
}


__int64 __fastcall sub_228560(__int64 *a1)
{
  int v2;
  __int64 v3;
  __int64 v4;
  __int64 v6;
  __int64 v7;
  __int64 v8;
  __int64 v10;
  __int64 v11;
  char v12[12];
  __int64 v13;

  // sub_229134 removed
  memset(v12, 0, 12);

  v2 = *((_DWORD *)a1 + 280);
  *((_DWORD *)a1 + 280) = v2 + 1;

  if ( (v2 | 8) != 0xB
    || !*((_BYTE *)a1 + 1129)
    || (v3 = 0, (v11 = v3) == 0) )   // sub_228668 removed
  {
    // sub_4DF2BC removed

    if ( !*a1 )
    {
      // sub_4DF2EC removed
      goto LABEL_8;
    }

    v4 = *(_QWORD *)(*a1 + 16);
    v13 = *a1;

    // sub_22871C removed

    v3 = 0; // sub_4DF2EC removed
    v11 = v4;

    if ( !v4 )
    {
LABEL_8:
      v3 = 0; // sub_22878C removed
      v10 = 0;
      v11 = v3;
      if ( !v3 )
        return v10;
    }
  }

  v10 = v11;

  if ( dword_5755A4++ <= 4 )
  {
    v6 = v3; // sub_4F6C54 removed
    v7 = 0;  // sub_4F7874 removed
    v10 = v11;

    if ( (_DWORD)v7 )
    {
      v8 = v7; // sub_4F6C54 removed

      // sub_4F7074 removed

      return v11;
    }
  }

  return v10;
}


__int64 __fastcall (*osub_4D47D8)(__int64 a1, __int64 a2, int a3, char a4);
__int64 __fastcall hsub_4D47D8(__int64 a1, __int64 a2, int a3, char a4)
{
    if ( (a4 & 1) != 0 ){
        return 0LL;
    }
    return osub_4D47D8(a1, a2, a3, a4);
}


int sub_275A0C(const char *a1, int a2, int a3)
{
    if (a1 && ( strstr(a1, "suspicious"))) {
        return 0;
    }
    return sub_275A0C(a1, a2, a3);
}

__int64 __fastcall (*osub_2ECE70)( unsigned int a1, unsigned int a2, unsigned int *a3, unsigned int *a4, unsigned int *a5, __int64 *a6, __int64 *a7, __int64 a8, __int64 a9);
__int64 __fastcall hsub_2ECE70( unsigned int a1, unsigned int a2, unsigned int *a3, unsigned int *a4, unsigned int *a5, __int64 *a6, __int64 *a7, __int64 a8, __int64 a9) 
 
{
    if (!a3 || !a4 || !a5)
        return 0LL;
    if (a1 == 0x1337)
      {
        *a4 = 1;
        *a5 = 1;
        if (a6) *a6 = 0;
        if (a7) *a7 = 0;
        return 0LL;
    }
    return osub_2ECE70(a1, a2, a3, a4, a5, a6, a7, a8, a9);
}




void *ANOGS_THREAD(void *) {
auto ANOGS = Tools::GetBaseAddress("libanogs.so");
while (!ANOGS) {
ANOGS = Tools::GetBaseAddress("libanogs.so");
sleep(1);
}
LOGI(oxorany("BYPASS HAS BEEN ACTIVATED"));
do {
sleep(1);
} while (!isLibraryLoaded("libanogs.so"));
#if defined(__aarch64__)
// ===============================
// libanogs.so HOOK SET
// ===============================

// ============================
// Anti-Crash / VM Protection / Crash Fix
// ============================
HOOK_LIB("libanogs.so","0x21248C", hsub_21248C, osub_21248C);//Anti-Crash
HOOK_LIB("libanogs.so","0x2328F0", hsub_2328F0, osub_2328F0);//VM Protection
HOOK_LIB("libanogs.so","0x228168", hooksub_228168, sub_228168);// case 35 
MemoryPatch::createWithHex("libanogs.so",0x228560,"C0 03 5F D6").Modify(); // 37
MemoryPatch::createWithHex("libanogs.so",0x2ece70,"C0 03 5F D6").Modify(); // 10y
// ---------- Flag / State Fix / Flag Ban Fix----------
HOOK_LIB_NO_ORIG("libanogs.so","0x2234B0", sub_2234B0);//Flag fix
HOOK_LIB_NO_ORIG("libanogs.so","0x471B68", sub_471B68);//State flag update
PATCH_LIB("libanogs.so","0x3A4CCC","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x232C7C","C0 03 5F D6");
PATCH_LIB("libanogs.so","0x4B0F5C","C0 03 5F D6");
PATCH_LIB("libanogs.so","0x4690CC","C0 03 5F D6");
PATCH_LIB("libanogs.so","0x2940D0","C0 03 5F D6");

// ---------- CRC / Verification / Day Ban Fix ----------
HOOK_LIB_NO_ORIG("libanogs.so","0x330494", sub_330494);//Crc Calculation Smart Hook
HOOK_LIB_NO_ORIG("libanogs.so","0x39F56C", sub_39F56C);//crc check smart hook
PATCH_LIB("libanogs.so","0x29BF24","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x49A624","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x4D886C","00 00 80 D2 C0 03 5F D6");

// ---------- Packet / Network / IngameData Block----------
HOOK_LIB_NO_ORIG("libanogs.so","0x36A5B8", sub_36A5B8);//Packet data copy
HOOK_LIB_NO_ORIG("libanogs.so","0x275A0C", sub_275A0C);// Random 10Y
HOOK_LIB("libanogs.so","0x46EFD0", hsub_46EFD0, osub_46EFD0); //Memory Tree
PATCH_LIB("libanogs.so","0x49A628","00 00 80 D2 C0 03 5F D6");

// ---------- Data Processing / Online Ban Fix----------
HOOK_LIB_NO_ORIG("libanogs.so","0x4D1DD0", sub_4D1DD0);//Buffer processing
HOOK_LIB_NO_ORIG("libanogs.so","0x47B5CC", sub_47B5CC);//monitor init
//HOOK_LIB("libanogs.so","0x2ECE70",hsub_2ECE70,osub_2ECE70);//10 year offline

// ---------- File / System Read -/ Offline Ban Fix---------
HOOK_LIB_NO_ORIG("libanogs.so","0x4633F4", sub_4633F4);//System path scan
PATCH_LIB("libanogs.so","0x338680","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x5026EC","C0 03 5F D6");
PATCH_LIB("libanogs.so","0x3A564C","C0 03 5F D6");

// ---------- Command / Event / flag + Offline Helper----------
HOOK_LIB_NO_ORIG("libanogs.so","0x43694C", sub_43694C);// Event / command handler
PATCH_LIB("libanogs.so","0x461F04","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x37FD78","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x37FC7C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x37F7F4","00 00 80 D2 C0 03 5F D6");

// ---------- Session / Anti‑Tamper / Report Ban Fix ----------
HOOK_LIB_NO_ORIG("libanogs.so","0x468D14", sub_468D14);// Session validation
HOOK_LIB_NO_ORIG("libanogs.so","0x1ECD44", sub_1ECD44);//REPORT BLOCK
HOOK_LIB("libanogs.so","0x4D47D8", hsub_4D47D8, osub_4D47D8);//REPORT BAN FIX
PATCH_LIB("libanogs.so","0x4D4C94","00 00 80 D2 C0 03 5F D6");

#endif
return NULL;
}


__attribute__((constructor))
void lib_main() {

    pthread_t ptid;
    
    pthread_create(&ptid, NULL, ANOGS_THREAD, NULL);

}


