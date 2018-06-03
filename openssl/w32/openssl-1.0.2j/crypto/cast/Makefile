#
# OpenSSL/crypto/cast/Makefile
#

DIR=	cast
TOP=	../..
CC=	cc
CPP=	$(CC) -E
INCLUDES=
CFLAG=-g
MAKEFILE=	Makefile
AR=		ar r

CAST_ENC=c_enc.o

CFLAGS= $(INCLUDES) $(CFLAG)
ASFLAGS= $(INCLUDES) $(ASFLAG)
AFLAGS= $(ASFLAGS)

GENERAL=Makefile
TEST=casttest.c
APPS=

LIB=$(TOP)/libcrypto.a
LIBSRC=c_skey.c c_ecb.c c_enc.c c_cfb64.c c_ofb64.c 
LIBOBJ=c_skey.o c_ecb.o $(CAST_ENC) c_cfb64.o c_ofb64.o

SRC= $(LIBSRC)

EXHEADER= cast.h
HEADER=	cast_s.h cast_lcl.h $(EXHEADER)

ALL=    $(GENERAL) $(SRC) $(HEADER)

top:
	(cd ../..; $(MAKE) DIRS=crypto SDIRS=$(DIR) sub_all)

all:	lib

lib:	$(LIBOBJ)
	$(AR) $(LIB) $(LIBOBJ)
	$(RANLIB) $(LIB) || echo Never mind.
	@touch lib

cast-586.s:	asm/cast-586.pl ../perlasm/x86asm.pl ../perlasm/cbc.pl
	$(PERL)	asm/cast-586.pl $(PERLASM_SCHEME) $(CLAGS) $(PROCESSOR) > $@

files:
	$(PERL) $(TOP)/util/files.pl Makefile >> $(TOP)/MINFO

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

c_cfb64.o: ../../e_os.h ../../include/openssl/cast.h
c_cfb64.o: ../../include/openssl/e_os2.h ../../include/openssl/opensslconf.h
c_cfb64.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
c_cfb64.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
c_cfb64.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
c_cfb64.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
c_cfb64.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
c_cfb64.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
c_cfb64.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
c_cfb64.o: c:\mingw\include\string.h c:\mingw\include\strings.h
c_cfb64.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
c_cfb64.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
c_cfb64.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
c_cfb64.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
c_cfb64.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
c_cfb64.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
c_cfb64.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
c_cfb64.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
c_cfb64.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
c_cfb64.o: c:\mingw\include\ws2tcpip.h
c_cfb64.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
c_cfb64.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h c_cfb64.c cast_lcl.h
c_ecb.o: ../../e_os.h ../../include/openssl/cast.h
c_ecb.o: ../../include/openssl/e_os2.h ../../include/openssl/opensslconf.h
c_ecb.o: ../../include/openssl/opensslv.h c:\mingw\include\_mingw.h
c_ecb.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
c_ecb.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
c_ecb.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
c_ecb.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
c_ecb.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
c_ecb.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
c_ecb.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
c_ecb.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
c_ecb.o: c:\mingw\include\sys\types.h c:\mingw\include\w32api.h
c_ecb.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
c_ecb.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
c_ecb.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
c_ecb.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
c_ecb.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
c_ecb.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
c_ecb.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
c_ecb.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
c_ecb.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
c_ecb.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h c_ecb.c cast_lcl.h
c_enc.o: ../../e_os.h ../../include/openssl/cast.h
c_enc.o: ../../include/openssl/e_os2.h ../../include/openssl/opensslconf.h
c_enc.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
c_enc.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
c_enc.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
c_enc.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
c_enc.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
c_enc.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
c_enc.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
c_enc.o: c:\mingw\include\string.h c:\mingw\include\strings.h
c_enc.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
c_enc.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
c_enc.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
c_enc.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
c_enc.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
c_enc.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
c_enc.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
c_enc.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
c_enc.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
c_enc.o: c:\mingw\include\ws2tcpip.h
c_enc.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
c_enc.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h c_enc.c cast_lcl.h
c_ofb64.o: ../../e_os.h ../../include/openssl/cast.h
c_ofb64.o: ../../include/openssl/e_os2.h ../../include/openssl/opensslconf.h
c_ofb64.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
c_ofb64.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
c_ofb64.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
c_ofb64.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
c_ofb64.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
c_ofb64.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
c_ofb64.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
c_ofb64.o: c:\mingw\include\string.h c:\mingw\include\strings.h
c_ofb64.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
c_ofb64.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
c_ofb64.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
c_ofb64.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
c_ofb64.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
c_ofb64.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
c_ofb64.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
c_ofb64.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
c_ofb64.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
c_ofb64.o: c:\mingw\include\ws2tcpip.h
c_ofb64.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
c_ofb64.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h c_ofb64.c cast_lcl.h
c_skey.o: ../../e_os.h ../../include/openssl/cast.h
c_skey.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
c_skey.o: ../../include/openssl/opensslconf.h ../../include/openssl/opensslv.h
c_skey.o: ../../include/openssl/ossl_typ.h ../../include/openssl/safestack.h
c_skey.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
c_skey.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
c_skey.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
c_skey.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
c_skey.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
c_skey.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
c_skey.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
c_skey.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
c_skey.o: c:\mingw\include\string.h c:\mingw\include\strings.h
c_skey.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
c_skey.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
c_skey.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
c_skey.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
c_skey.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
c_skey.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
c_skey.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
c_skey.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
c_skey.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
c_skey.o: c:\mingw\include\ws2tcpip.h
c_skey.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
c_skey.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h c_skey.c cast_lcl.h
c_skey.o: cast_s.h
