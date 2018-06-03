#
# crypto/aes/Makefile
#

DIR=	aes
TOP=	../..
CC=	cc
CPP=	$(CC) -E
INCLUDES=
CFLAG=-g
MAKEFILE=	Makefile
AR=		ar r

AES_ENC=aes_core.o aes_cbc.o

CFLAGS= $(INCLUDES) $(CFLAG)
ASFLAGS= $(INCLUDES) $(ASFLAG)
AFLAGS= $(ASFLAGS)

GENERAL=Makefile
#TEST=aestest.c
TEST=
APPS=

LIB=$(TOP)/libcrypto.a
LIBSRC=aes_core.c aes_misc.c aes_ecb.c aes_cbc.c aes_cfb.c aes_ofb.c \
       aes_ctr.c aes_ige.c aes_wrap.c
LIBOBJ=aes_misc.o aes_ecb.o aes_cfb.o aes_ofb.o aes_ctr.o aes_ige.o aes_wrap.o \
       $(AES_ENC)

SRC= $(LIBSRC)

EXHEADER= aes.h
HEADER= aes_locl.h $(EXHEADER)

ALL=    $(GENERAL) $(SRC) $(HEADER)

top:
	(cd ../..; $(MAKE) DIRS=crypto SDIRS=$(DIR) sub_all)

all:	lib

lib:	$(LIBOBJ)
	$(AR) $(LIB) $(LIBOBJ)
	$(RANLIB) $(LIB) || echo Never mind.
	@touch lib

aes-ia64.s: asm/aes-ia64.S
	$(CC) $(CFLAGS) -E asm/aes-ia64.S > $@

aes-586.s:	asm/aes-586.pl ../perlasm/x86asm.pl
	$(PERL) asm/aes-586.pl $(PERLASM_SCHEME) $(CFLAGS) $(PROCESSOR) > $@
vpaes-x86.s:	asm/vpaes-x86.pl ../perlasm/x86asm.pl
	$(PERL) asm/vpaes-x86.pl $(PERLASM_SCHEME) $(CFLAGS) $(PROCESSOR) > $@
aesni-x86.s:	asm/aesni-x86.pl ../perlasm/x86asm.pl
	$(PERL) asm/aesni-x86.pl $(PERLASM_SCHEME) $(CFLAGS) $(PROCESSOR) > $@

aes-x86_64.s: asm/aes-x86_64.pl
	$(PERL) asm/aes-x86_64.pl $(PERLASM_SCHEME) > $@
vpaes-x86_64.s:	asm/vpaes-x86_64.pl
	$(PERL) asm/vpaes-x86_64.pl $(PERLASM_SCHEME) > $@
bsaes-x86_64.s:	asm/bsaes-x86_64.pl
	$(PERL) asm/bsaes-x86_64.pl $(PERLASM_SCHEME) > $@
aesni-x86_64.s: asm/aesni-x86_64.pl
	$(PERL) asm/aesni-x86_64.pl $(PERLASM_SCHEME) > $@
aesni-sha1-x86_64.s:	asm/aesni-sha1-x86_64.pl
	$(PERL) asm/aesni-sha1-x86_64.pl $(PERLASM_SCHEME) > $@
aesni-sha256-x86_64.s:	asm/aesni-sha256-x86_64.pl
	$(PERL) asm/aesni-sha256-x86_64.pl $(PERLASM_SCHEME) > $@
aesni-mb-x86_64.s:	asm/aesni-mb-x86_64.pl
	$(PERL) asm/aesni-mb-x86_64.pl $(PERLASM_SCHEME) > $@

aes-sparcv9.s: asm/aes-sparcv9.pl
	$(PERL) asm/aes-sparcv9.pl $(CFLAGS) > $@
aest4-sparcv9.s: asm/aest4-sparcv9.pl ../perlasm/sparcv9_modes.pl
	$(PERL) asm/aest4-sparcv9.pl $(CFLAGS) > $@

aes-ppc.s:	asm/aes-ppc.pl
	$(PERL) asm/aes-ppc.pl $(PERLASM_SCHEME) $@
vpaes-ppc.s:	asm/vpaes-ppc.pl
	$(PERL) asm/vpaes-ppc.pl $(PERLASM_SCHEME) $@
aesp8-ppc.s:	asm/aesp8-ppc.pl
	$(PERL) asm/aesp8-ppc.pl $(PERLASM_SCHEME) $@

aes-parisc.s:	asm/aes-parisc.pl
	$(PERL) asm/aes-parisc.pl $(PERLASM_SCHEME) $@

aes-mips.S:	asm/aes-mips.pl
	$(PERL) asm/aes-mips.pl $(PERLASM_SCHEME) $@

aesv8-armx.S:	asm/aesv8-armx.pl
	$(PERL) asm/aesv8-armx.pl $(PERLASM_SCHEME) $@
aesv8-armx.o:	aesv8-armx.S

# GNU make "catch all"
aes-%.S:	asm/aes-%.pl;	$(PERL) $< $(PERLASM_SCHEME) > $@
aes-armv4.o:	aes-armv4.S
bsaes-%.S:	asm/bsaes-%.pl;	$(PERL) $< $(PERLASM_SCHEME) $@
bsaes-armv7.o:	bsaes-armv7.S

files:
	$(PERL) $(TOP)/util/files.pl "AES_ENC=$(AES_ENC)" Makefile >> $(TOP)/MINFO

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

aes_cbc.o: ../../include/openssl/aes.h ../../include/openssl/modes.h
aes_cbc.o: ../../include/openssl/opensslconf.h aes_cbc.c
aes_cbc.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h
aes_cfb.o: ../../include/openssl/aes.h ../../include/openssl/modes.h
aes_cfb.o: ../../include/openssl/opensslconf.h aes_cfb.c
aes_cfb.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h
aes_core.o: ../../include/openssl/aes.h ../../include/openssl/e_os2.h
aes_core.o: ../../include/openssl/opensslconf.h aes_core.c aes_locl.h
aes_core.o: c:\mingw\include\_mingw.h c:\mingw\include\assert.h
aes_core.o: c:\mingw\include\msvcrtver.h c:\mingw\include\sdkddkver.h
aes_core.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
aes_core.o: c:\mingw\include\string.h c:\mingw\include\strings.h
aes_core.o: c:\mingw\include\sys/types.h c:\mingw\include\w32api.h
aes_core.o: c:\mingw\include\wchar.h
aes_core.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
aes_core.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h
aes_ctr.o: ../../include/openssl/aes.h ../../include/openssl/modes.h
aes_ctr.o: ../../include/openssl/opensslconf.h aes_ctr.c
aes_ctr.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h
aes_ecb.o: ../../include/openssl/aes.h ../../include/openssl/e_os2.h
aes_ecb.o: ../../include/openssl/opensslconf.h aes_ecb.c aes_locl.h
aes_ecb.o: c:\mingw\include\_mingw.h c:\mingw\include\assert.h
aes_ecb.o: c:\mingw\include\msvcrtver.h c:\mingw\include\sdkddkver.h
aes_ecb.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
aes_ecb.o: c:\mingw\include\string.h c:\mingw\include\strings.h
aes_ecb.o: c:\mingw\include\sys/types.h c:\mingw\include\w32api.h
aes_ecb.o: c:\mingw\include\wchar.h
aes_ecb.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
aes_ecb.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h
aes_ige.o: ../../e_os.h ../../include/openssl/aes.h ../../include/openssl/bio.h
aes_ige.o: ../../include/openssl/buffer.h ../../include/openssl/crypto.h
aes_ige.o: ../../include/openssl/e_os2.h ../../include/openssl/err.h
aes_ige.o: ../../include/openssl/lhash.h ../../include/openssl/opensslconf.h
aes_ige.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
aes_ige.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
aes_ige.o: ../../include/openssl/symhacks.h ../../ms/applink.c
aes_ige.o: ../../ms/uplink.h ../cryptlib.h aes_ige.c aes_locl.h
aes_ige.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
aes_ige.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
aes_ige.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
aes_ige.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
aes_ige.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
aes_ige.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
aes_ige.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
aes_ige.o: c:\mingw\include\string.h c:\mingw\include\strings.h
aes_ige.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
aes_ige.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
aes_ige.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
aes_ige.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
aes_ige.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
aes_ige.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
aes_ige.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
aes_ige.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
aes_ige.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
aes_ige.o: c:\mingw\include\ws2tcpip.h
aes_ige.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
aes_ige.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h
aes_misc.o: ../../include/openssl/aes.h ../../include/openssl/crypto.h
aes_misc.o: ../../include/openssl/e_os2.h ../../include/openssl/opensslconf.h
aes_misc.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
aes_misc.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
aes_misc.o: ../../include/openssl/symhacks.h aes_locl.h aes_misc.c
aes_misc.o: c:\mingw\include\_mingw.h c:\mingw\include\msvcrtver.h
aes_misc.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdio.h
aes_misc.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
aes_misc.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
aes_misc.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
aes_misc.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
aes_misc.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h
aes_ofb.o: ../../include/openssl/aes.h ../../include/openssl/modes.h
aes_ofb.o: ../../include/openssl/opensslconf.h aes_ofb.c
aes_ofb.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h
aes_wrap.o: ../../e_os.h ../../include/openssl/aes.h
aes_wrap.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
aes_wrap.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
aes_wrap.o: ../../include/openssl/err.h ../../include/openssl/lhash.h
aes_wrap.o: ../../include/openssl/modes.h ../../include/openssl/opensslconf.h
aes_wrap.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
aes_wrap.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
aes_wrap.o: ../../include/openssl/symhacks.h ../../ms/applink.c
aes_wrap.o: ../../ms/uplink.h ../cryptlib.h aes_wrap.c
aes_wrap.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
aes_wrap.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
aes_wrap.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
aes_wrap.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
aes_wrap.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
aes_wrap.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
aes_wrap.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
aes_wrap.o: c:\mingw\include\string.h c:\mingw\include\strings.h
aes_wrap.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
aes_wrap.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
aes_wrap.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
aes_wrap.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
aes_wrap.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
aes_wrap.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
aes_wrap.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
aes_wrap.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
aes_wrap.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
aes_wrap.o: c:\mingw\include\ws2tcpip.h
aes_wrap.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
aes_wrap.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h
