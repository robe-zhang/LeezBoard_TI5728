# Generated by h2py from /home/robe/ti-processor-sdk-linux-am57xx-evm-04.03.00.05/linux-devkit/sysroots/x86_64-arago-linux/usr/include/sys/types.h
_SYS_TYPES_H = 1

# Included from features.h
_FEATURES_H = 1
_DEFAULT_SOURCE = 1
_ISOC95_SOURCE = 1
_ISOC99_SOURCE = 1
_ISOC11_SOURCE = 1
_POSIX_SOURCE = 1
_POSIX_C_SOURCE = 200809L
_XOPEN_SOURCE = 700
_XOPEN_SOURCE_EXTENDED = 1
_LARGEFILE64_SOURCE = 1
_DEFAULT_SOURCE = 1
_ATFILE_SOURCE = 1
_DEFAULT_SOURCE = 1
__USE_ISOC11 = 1
__USE_ISOC99 = 1
__USE_ISOC95 = 1
__USE_ISOCXX11 = 1
__USE_POSIX_IMPLICITLY = 1
_POSIX_SOURCE = 1
_POSIX_C_SOURCE = 200809L
_POSIX_SOURCE = 1
_POSIX_C_SOURCE = 2
_POSIX_C_SOURCE = 199506L
_POSIX_C_SOURCE = 200112L
_POSIX_C_SOURCE = 200809L
__USE_POSIX_IMPLICITLY = 1
__USE_POSIX = 1
__USE_POSIX2 = 1
__USE_POSIX199309 = 1
__USE_POSIX199506 = 1
__USE_XOPEN2K = 1
__USE_ISOC95 = 1
__USE_ISOC99 = 1
__USE_XOPEN2K8 = 1
_ATFILE_SOURCE = 1
__USE_XOPEN = 1
__USE_XOPEN_EXTENDED = 1
__USE_UNIX98 = 1
_LARGEFILE_SOURCE = 1
__USE_XOPEN2K8 = 1
__USE_XOPEN2K8XSI = 1
__USE_XOPEN2K = 1
__USE_XOPEN2KXSI = 1
__USE_ISOC95 = 1
__USE_ISOC99 = 1
__USE_XOPEN_EXTENDED = 1
__USE_LARGEFILE = 1
__USE_LARGEFILE64 = 1
__USE_FILE_OFFSET64 = 1
__USE_MISC = 1
__USE_ATFILE = 1
__USE_GNU = 1
__USE_REENTRANT = 1
__USE_FORTIFY_LEVEL = 2
__USE_FORTIFY_LEVEL = 1
__USE_FORTIFY_LEVEL = 0

# Included from stdc-predef.h
_STDC_PREDEF_H = 1
__STDC_IEC_559__ = 1
__STDC_IEC_559__ = 1
__STDC_IEC_559_COMPLEX__ = 1
__STDC_IEC_559_COMPLEX__ = 1
__STDC_ISO_10646__ = 201505L
__STDC_NO_THREADS__ = 1
__GNU_LIBRARY__ = 6
__GLIBC__ = 2
__GLIBC_MINOR__ = 24

# Included from sys/cdefs.h
_SYS_CDEFS_H = 1
def __NTH(fct): return fct

def __NTH(fct): return fct

def __P(args): return args

def __PMT(args): return args

def __STRING(x): return #x

def __bos(ptr): return __builtin_object_size (ptr, __USE_FORTIFY_LEVEL > 1)

def __bos0(ptr): return __builtin_object_size (ptr, 0)

def __warnattr(msg): return __attribute__((__warning__ (msg)))

__flexarr = []
__flexarr = [0]
__flexarr = []
__flexarr = [1]
def __ASMNAME(cname): return __ASMNAME2 (__USER_LABEL_PREFIX__, cname)

def __attribute__(xyz): return  

def __attribute_alloc_size__(params): return \

def __attribute_alloc_size__(params): return  

def __attribute_format_arg__(x): return __attribute__ ((__format_arg__ (x)))

def __attribute_format_arg__(x): return  

def __glibc_unlikely(cond): return __builtin_expect ((cond), 0)

def __glibc_likely(cond): return __builtin_expect ((cond), 1)

def __glibc_unlikely(cond): return (cond)

def __glibc_likely(cond): return (cond)


# Included from bits/wordsize.h
__WORDSIZE = 64
__WORDSIZE = 32
__WORDSIZE_TIME64_COMPAT32 = 1
__SYSCALL_WORDSIZE = 64
__LDBL_COMPAT = 1
def __LDBL_REDIR_DECL(name): return \

__USE_LARGEFILE = 1
__USE_LARGEFILE64 = 1
__USE_EXTERN_INLINES = 1

# Included from gnu/stubs.h

# Included from gnu/stubs-64.h

# Included from bits/types.h
_BITS_TYPES_H = 1
__S32_TYPE = int
__SWORD_TYPE = int
__SLONG32_TYPE = int

# Included from bits/typesizes.h
_BITS_TYPESIZES_H = 1
__FSWORD_T_TYPE = __SWORD_TYPE
__PID_T_TYPE = __S32_TYPE
__DADDR_T_TYPE = __S32_TYPE
__KEY_T_TYPE = __S32_TYPE
__CLOCKID_T_TYPE = __S32_TYPE
__SSIZE_T_TYPE = __SWORD_TYPE
__OFF_T_MATCHES_OFF64_T = 1
__INO_T_MATCHES_INO64_T = 1
__FD_SETSIZE = 1024

# Included from time.h
_TIME_H = 1

# Included from bits/time.h
_STRUCT_TIMEVAL = 1
_BITS_TIME_H = 1
CLOCK_REALTIME = 0
CLOCK_MONOTONIC = 1
CLOCK_PROCESS_CPUTIME_ID = 2
CLOCK_THREAD_CPUTIME_ID = 3
CLOCK_MONOTONIC_RAW = 4
CLOCK_REALTIME_COARSE = 5
CLOCK_MONOTONIC_COARSE = 6
CLOCK_BOOTTIME = 7
CLOCK_REALTIME_ALARM = 8
CLOCK_BOOTTIME_ALARM = 9
CLOCK_TAI = 11
TIMER_ABSTIME = 1

# Included from bits/timex.h
_BITS_TIMEX_H = 1
ADJ_OFFSET = 0x0001
ADJ_FREQUENCY = 0x0002
ADJ_MAXERROR = 0x0004
ADJ_ESTERROR = 0x0008
ADJ_STATUS = 0x0010
ADJ_TIMECONST = 0x0020
ADJ_TAI = 0x0080
ADJ_SETOFFSET = 0x0100
ADJ_MICRO = 0x1000
ADJ_NANO = 0x2000
ADJ_TICK = 0x4000
ADJ_OFFSET_SINGLESHOT = 0x8001
ADJ_OFFSET_SS_READ = 0xa001
MOD_OFFSET = ADJ_OFFSET
MOD_FREQUENCY = ADJ_FREQUENCY
MOD_MAXERROR = ADJ_MAXERROR
MOD_ESTERROR = ADJ_ESTERROR
MOD_STATUS = ADJ_STATUS
MOD_TIMECONST = ADJ_TIMECONST
MOD_CLKB = ADJ_TICK
MOD_CLKA = ADJ_OFFSET_SINGLESHOT
MOD_TAI = ADJ_TAI
MOD_MICRO = ADJ_MICRO
MOD_NANO = ADJ_NANO
STA_PLL = 0x0001
STA_PPSFREQ = 0x0002
STA_PPSTIME = 0x0004
STA_FLL = 0x0008
STA_INS = 0x0010
STA_DEL = 0x0020
STA_UNSYNC = 0x0040
STA_FREQHOLD = 0x0080
STA_PPSSIGNAL = 0x0100
STA_PPSJITTER = 0x0200
STA_PPSWANDER = 0x0400
STA_PPSERROR = 0x0800
STA_CLOCKERR = 0x1000
STA_NANO = 0x2000
STA_MODE = 0x4000
STA_CLK = 0x8000
STA_RONLY = (STA_PPSSIGNAL | STA_PPSJITTER | STA_PPSWANDER | \
    STA_PPSERROR | STA_CLOCKERR | STA_NANO | STA_MODE | STA_CLK)
__clock_t_defined = 1
__time_t_defined = 1
__clockid_t_defined = 1
__timer_t_defined = 1
__timespec_defined = 1
TIME_UTC = 1

# Included from xlocale.h
_XLOCALE_H = 1
def __isleap(year): return \

__BIT_TYPES_DEFINED__ = 1

# Included from endian.h
_ENDIAN_H = 1
__LITTLE_ENDIAN = 1234
__BIG_ENDIAN = 4321
__PDP_ENDIAN = 3412

# Included from bits/endian.h
__BYTE_ORDER = __LITTLE_ENDIAN
__FLOAT_WORD_ORDER = __BYTE_ORDER
LITTLE_ENDIAN = __LITTLE_ENDIAN
BIG_ENDIAN = __BIG_ENDIAN
PDP_ENDIAN = __PDP_ENDIAN
BYTE_ORDER = __BYTE_ORDER

# Included from bits/byteswap.h
_BITS_BYTESWAP_H = 1
def __bswap_constant_16(x): return \


# Included from bits/byteswap-16.h
def __bswap_16(x): return \

def __bswap_16(x): return \

def __bswap_constant_32(x): return \

def __bswap_32(x): return \

def __bswap_32(x): return \

def __bswap_32(x): return \

def __bswap_constant_64(x): return \

def __bswap_64(x): return \

def __bswap_64(x): return \

def __bswap_constant_64(x): return \

def htobe16(x): return __bswap_16 (x)

def htole16(x): return (x)

def be16toh(x): return __bswap_16 (x)

def le16toh(x): return (x)

def htobe32(x): return __bswap_32 (x)

def htole32(x): return (x)

def be32toh(x): return __bswap_32 (x)

def le32toh(x): return (x)

def htobe64(x): return __bswap_64 (x)

def htole64(x): return (x)

def be64toh(x): return __bswap_64 (x)

def le64toh(x): return (x)

def htobe16(x): return (x)

def htole16(x): return __bswap_16 (x)

def be16toh(x): return (x)

def le16toh(x): return __bswap_16 (x)

def htobe32(x): return (x)

def htole32(x): return __bswap_32 (x)

def be32toh(x): return (x)

def le32toh(x): return __bswap_32 (x)

def htobe64(x): return (x)

def htole64(x): return __bswap_64 (x)

def be64toh(x): return (x)

def le64toh(x): return __bswap_64 (x)


# Included from sys/select.h
_SYS_SELECT_H = 1

# Included from bits/select.h
__FD_ZERO_STOS = "stosq"
__FD_ZERO_STOS = "stosl"
def __FD_ZERO(fdsp): return \

def __FD_ZERO(set): return \


# Included from bits/sigset.h
_SIGSET_H_types = 1
_SIGSET_H_fns = 1
def __sigmask(sig): return \

def __sigemptyset(set): return \

def __sigfillset(set): return \

def __sigisemptyset(set): return \

def __FD_ELT(d): return ((d) / __NFDBITS)

FD_SETSIZE = __FD_SETSIZE
def FD_ZERO(fdsetp): return __FD_ZERO (fdsetp)


# Included from bits/select2.h
def __FD_ELT(d): return \


# Included from sys/sysmacros.h
_SYS_SYSMACROS_H = 1
def major(dev): return gnu_dev_major (dev)

def minor(dev): return gnu_dev_minor (dev)


# Included from bits/pthreadtypes.h
_BITS_PTHREADTYPES_H = 1
__SIZEOF_PTHREAD_ATTR_T = 56
__SIZEOF_PTHREAD_MUTEX_T = 40
__SIZEOF_PTHREAD_MUTEXATTR_T = 4
__SIZEOF_PTHREAD_COND_T = 48
__SIZEOF_PTHREAD_CONDATTR_T = 4
__SIZEOF_PTHREAD_RWLOCK_T = 56
__SIZEOF_PTHREAD_RWLOCKATTR_T = 8
__SIZEOF_PTHREAD_BARRIER_T = 32
__SIZEOF_PTHREAD_BARRIERATTR_T = 4
__SIZEOF_PTHREAD_ATTR_T = 32
__SIZEOF_PTHREAD_MUTEX_T = 32
__SIZEOF_PTHREAD_MUTEXATTR_T = 4
__SIZEOF_PTHREAD_COND_T = 48
__SIZEOF_PTHREAD_CONDATTR_T = 4
__SIZEOF_PTHREAD_RWLOCK_T = 44
__SIZEOF_PTHREAD_RWLOCKATTR_T = 8
__SIZEOF_PTHREAD_BARRIER_T = 20
__SIZEOF_PTHREAD_BARRIERATTR_T = 4
__SIZEOF_PTHREAD_ATTR_T = 36
__SIZEOF_PTHREAD_MUTEX_T = 24
__SIZEOF_PTHREAD_MUTEXATTR_T = 4
__SIZEOF_PTHREAD_COND_T = 48
__SIZEOF_PTHREAD_CONDATTR_T = 4
__SIZEOF_PTHREAD_RWLOCK_T = 32
__SIZEOF_PTHREAD_RWLOCKATTR_T = 8
__SIZEOF_PTHREAD_BARRIER_T = 20
__SIZEOF_PTHREAD_BARRIERATTR_T = 4
__have_pthread_attr_t = 1
__PTHREAD_MUTEX_HAVE_PREV = 1
__PTHREAD_SPINS = 0, 0
__PTHREAD_SPINS = { 0, 0 }
__PTHREAD_RWLOCK_ELISION_EXTRA = 0, { 0, 0, 0 }
__PTHREAD_RWLOCK_ELISION_EXTRA = 0, { 0, 0, 0, 0, 0, 0, 0 }
__PTHREAD_RWLOCK_INT_FLAGS_SHARED = 1
__PTHREAD_RWLOCK_ELISION_EXTRA = 0
