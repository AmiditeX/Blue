#
# OpenSSL/crypto/rc4/Makefile
#

DIR=	rc4
TOP=	../..
CC=	cc
CPP=    $(CC) -E
INCLUDES=
CFLAG=-g
AR=		ar r

RC4_ENC=rc4_enc.o rc4_skey.o

CFLAGS= $(INCLUDES) $(CFLAG)
ASFLAGS= $(INCLUDES) $(ASFLAG)
AFLAGS= $(ASFLAGS)

GENERAL=Makefile
TEST=rc4test.c
APPS=

LIB=$(TOP)/libcrypto.a
LIBSRC=rc4_skey.c rc4_enc.c rc4_utl.c
LIBOBJ=$(RC4_ENC) rc4_utl.o

SRC= $(LIBSRC)

EXHEADER= rc4.h
HEADER=	$(EXHEADER) rc4_locl.h

ALL=    $(GENERAL) $(SRC) $(HEADER)

top:
	(cd ../..; $(MAKE) DIRS=crypto SDIRS=$(DIR) sub_all)

all:	lib

lib:	$(LIBOBJ)
	$(AR) $(LIB) $(LIBOBJ)
	$(RANLIB) $(LIB) || echo Never mind.
	@touch lib

rc4-586.s:	asm/rc4-586.pl ../perlasm/x86asm.pl
	$(PERL) asm/rc4-586.pl $(PERLASM_SCHEME) $(CFLAGS) $(PROCESSOR) > $@

rc4-x86_64.s: asm/rc4-x86_64.pl
	$(PERL) asm/rc4-x86_64.pl $(PERLASM_SCHEME) > $@
rc4-md5-x86_64.s:	asm/rc4-md5-x86_64.pl
	$(PERL) asm/rc4-md5-x86_64.pl $(PERLASM_SCHEME) > $@

rc4-ia64.S: asm/rc4-ia64.pl
	$(PERL) asm/rc4-ia64.pl $(CFLAGS) > $@

rc4-parisc.s:	asm/rc4-parisc.pl
	$(PERL) asm/rc4-parisc.pl $(PERLASM_SCHEME) $@

rc4-ia64.s: rc4-ia64.S
	@case `awk '/^#define RC4_INT/{print$$NF}' $(TOP)/include/openssl/opensslconf.h` in \
	int)	set -x; $(CC) $(CFLAGS) -DSZ=4 -E rc4-ia64.S > $@ ;; \
	char)	set -x; $(CC) $(CFLAGS) -DSZ=1 -E rc4-ia64.S > $@ ;; \
	*)	exit 1 ;; \
	esac

# GNU make "catch all"
rc4-%.s:	asm/rc4-%.pl;	$(PERL) $< $(PERLASM_SCHEME) $@

files:
	$(PERL) $(TOP)/util/files.pl "RC4_ENC=$(RC4_ENC)" Makefile >> $(TOP)/MINFO

links:
	@$(PERL) $(TOP)/util/mklink.pl ../../include/openssl $(EXHEADER)
	@$(PERL) $(TOP)/util/mklink.pl ../../test $(TEST)
	@$(PERL) $(TOP)/util/mklink.pl ../../apps $(APPS)

install:
	@[ -n "$(INSTALLTOP)" ] # should be set by top Makefile...
	@headerlist="$(EXHEADER)"; for i in $$headerlist ; \
	do  \
	(cp $$i $(INSTALL_PREFIX)$(INSTALLTOP)/include/openssl/$$i; \
	chmod 644 $(INSTALL_PREFIX)$(INSTALLTOP)/include/openssl/$$i ); \
	done;

tags:
	ctags $(SRC)

tests:

lint:
	lint -DLINT $(INCLUDES) $(SRC)>fluff

update: depend

depend:
	@[ -n "$(MAKEDEPEND)" ] # should be set by upper Makefile...
	$(MAKEDEPEND) -- $(CFLAG) $(INCLUDES) $(DEPFLAG) -- $(PROGS) $(LIBSRC)

dclean:
	$(PERL) -pe 'if (/^# DO NOT DELETE THIS LINE/) {print; exit(0);}' $(MAKEFILE) >Makefile.new
	mv -f Makefile.new $(MAKEFILE)

clean:
	rm -f *.s *.o *.obj lib tags core .pure .nfs* *.old *.bak fluff

# DO NOT DELETE THIS LINE -- make depend depends on it.

rc4_enc.o: ../../e_os.h ../../include/openssl/bio.h
rc4_enc.o: ../../include/openssl/buffer.h ../../include/openssl/crypto.h
rc4_enc.o: ../../include/openssl/e_os2.h ../../include/openssl/err.h
rc4_enc.o: ../../include/openssl/lhash.h ../../include/openssl/opensslconf.h
rc4_enc.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
rc4_enc.o: ../../include/openssl/rc4.h ../../include/openssl/safestack.h
rc4_enc.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
rc4_enc.o: ../../ms/applink.c ../../ms/uplink.h ../cryptlib.h
rc4_enc.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
rc4_enc.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
rc4_enc.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
rc4_enc.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
rc4_enc.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
rc4_enc.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
rc4_enc.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
rc4_enc.o: c:\mingw\include\string.h c:\mingw\include\strings.h
rc4_enc.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
rc4_enc.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
rc4_enc.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
rc4_enc.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
rc4_enc.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
rc4_enc.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
rc4_enc.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
rc4_enc.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
rc4_enc.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
rc4_enc.o: c:\mingw\include\ws2tcpip.h
rc4_enc.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
rc4_enc.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h rc4_enc.c rc4_locl.h
rc4_skey.o: ../../e_os.h ../../include/openssl/bio.h
rc4_skey.o: ../../include/openssl/buffer.h ../../include/openssl/crypto.h
rc4_skey.o: ../../include/openssl/e_os2.h ../../include/openssl/err.h
rc4_skey.o: ../../include/openssl/lhash.h ../../include/openssl/opensslconf.h
rc4_skey.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
rc4_skey.o: ../../include/openssl/rc4.h ../../include/openssl/safestack.h
rc4_skey.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
rc4_skey.o: ../../ms/applink.c ../../ms/uplink.h ../cryptlib.h
rc4_skey.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
rc4_skey.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
rc4_skey.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
rc4_skey.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
rc4_skey.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
rc4_skey.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
rc4_skey.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
rc4_skey.o: c:\mingw\include\string.h c:\mingw\include\strings.h
rc4_skey.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
rc4_skey.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
rc4_skey.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
rc4_skey.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
rc4_skey.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
rc4_skey.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
rc4_skey.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
rc4_skey.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
rc4_skey.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
rc4_skey.o: c:\mingw\include\ws2tcpip.h
rc4_skey.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
rc4_skey.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h rc4_locl.h
rc4_skey.o: rc4_skey.c
rc4_utl.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
rc4_utl.o: ../../include/openssl/opensslconf.h ../../include/openssl/opensslv.h
rc4_utl.o: ../../include/openssl/ossl_typ.h ../../include/openssl/rc4.h
rc4_utl.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
rc4_utl.o: ../../include/openssl/symhacks.h c:\mingw\include\_mingw.h
rc4_utl.o: c:\mingw\include\msvcrtver.h c:\mingw\include\sdkddkver.h
rc4_utl.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
rc4_utl.o: c:\mingw\include\sys/types.h c:\mingw\include\w32api.h
rc4_utl.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
rc4_utl.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h rc4_utl.c
