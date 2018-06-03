#
# OpenSSL/crypto/ui/Makefile
#

DIR=	ui
TOP=	../..
CC=	cc
INCLUDES= -I.. -I$(TOP) -I../../include
CFLAG=-g
MAKEFILE=	Makefile
AR=		ar r

CFLAGS= $(INCLUDES) $(CFLAG)

GENERAL=Makefile
#TEST= uitest.c
TEST=
APPS=

COMPATSRC= ui_compat.c
COMPATOBJ= ui_compat.o

LIB=$(TOP)/libcrypto.a
LIBSRC= ui_err.c ui_lib.c ui_openssl.c ui_util.c $(COMPATSRC)
LIBOBJ= ui_err.o ui_lib.o ui_openssl.o ui_util.o $(COMPATOBJ)

SRC= $(LIBSRC)

EXHEADER= ui.h ui_compat.h
HEADER=	$(EXHEADER) ui_locl.h

ALL=    $(GENERAL) $(SRC) $(HEADER)

top:
	(cd ../..; $(MAKE) DIRS=crypto SDIRS=$(DIR) sub_all)

all:	lib

lib:	$(LIBOBJ)
	$(AR) $(LIB) $(LIBOBJ)
	$(RANLIB) $(LIB) || echo Never mind.
	@touch lib

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
	rm -f *.o */*.o *.obj lib tags core .pure .nfs* *.old *.bak fluff

# DO NOT DELETE THIS LINE -- make depend depends on it.

ui_compat.o: ../../include/openssl/e_os2.h ../../include/openssl/opensslconf.h
ui_compat.o: ../../include/openssl/ossl_typ.h ../../include/openssl/safestack.h
ui_compat.o: ../../include/openssl/stack.h ../../include/openssl/ui.h
ui_compat.o: ../../include/openssl/ui_compat.h c:\mingw\include\_mingw.h
ui_compat.o: c:\mingw\include\msvcrtver.h c:\mingw\include\sdkddkver.h
ui_compat.o: c:\mingw\include\string.h c:\mingw\include\strings.h
ui_compat.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
ui_compat.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h ui_compat.c
ui_err.o: ../../include/openssl/bio.h ../../include/openssl/crypto.h
ui_err.o: ../../include/openssl/e_os2.h ../../include/openssl/err.h
ui_err.o: ../../include/openssl/lhash.h ../../include/openssl/opensslconf.h
ui_err.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
ui_err.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
ui_err.o: ../../include/openssl/symhacks.h ../../include/openssl/ui.h
ui_err.o: c:\mingw\include\_mingw.h c:\mingw\include\errno.h
ui_err.o: c:\mingw\include\msvcrtver.h c:\mingw\include\sdkddkver.h
ui_err.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
ui_err.o: c:\mingw\include\sys/types.h c:\mingw\include\w32api.h
ui_err.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
ui_err.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h ui_err.c
ui_lib.o: ../../e_os.h ../../include/openssl/bio.h
ui_lib.o: ../../include/openssl/buffer.h ../../include/openssl/crypto.h
ui_lib.o: ../../include/openssl/e_os2.h ../../include/openssl/err.h
ui_lib.o: ../../include/openssl/lhash.h ../../include/openssl/opensslconf.h
ui_lib.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
ui_lib.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
ui_lib.o: ../../include/openssl/symhacks.h ../../include/openssl/ui.h
ui_lib.o: ../../ms/applink.c ../../ms/uplink.h ../cryptlib.h
ui_lib.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
ui_lib.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
ui_lib.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
ui_lib.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
ui_lib.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
ui_lib.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
ui_lib.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
ui_lib.o: c:\mingw\include\string.h c:\mingw\include\strings.h
ui_lib.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
ui_lib.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
ui_lib.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
ui_lib.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
ui_lib.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
ui_lib.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
ui_lib.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
ui_lib.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
ui_lib.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
ui_lib.o: c:\mingw\include\ws2tcpip.h
ui_lib.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
ui_lib.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h ui_lib.c ui_locl.h
ui_openssl.o: ../../e_os.h ../../include/openssl/bio.h
ui_openssl.o: ../../include/openssl/buffer.h ../../include/openssl/crypto.h
ui_openssl.o: ../../include/openssl/e_os2.h ../../include/openssl/err.h
ui_openssl.o: ../../include/openssl/lhash.h ../../include/openssl/opensslconf.h
ui_openssl.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
ui_openssl.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
ui_openssl.o: ../../include/openssl/symhacks.h ../../include/openssl/ui.h
ui_openssl.o: ../../ms/applink.c ../../ms/uplink.h ../cryptlib.h
ui_openssl.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
ui_openssl.o: c:\mingw\include\conio.h c:\mingw\include\dbt.h
ui_openssl.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
ui_openssl.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
ui_openssl.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
ui_openssl.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
ui_openssl.o: c:\mingw\include\signal.h c:\mingw\include\stdint.h
ui_openssl.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
ui_openssl.o: c:\mingw\include\string.h c:\mingw\include\strings.h
ui_openssl.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
ui_openssl.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
ui_openssl.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
ui_openssl.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
ui_openssl.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
ui_openssl.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
ui_openssl.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
ui_openssl.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
ui_openssl.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
ui_openssl.o: c:\mingw\include\ws2tcpip.h
ui_openssl.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
ui_openssl.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h ui_locl.h
ui_openssl.o: ui_openssl.c
ui_util.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
ui_util.o: ../../include/openssl/opensslconf.h ../../include/openssl/opensslv.h
ui_util.o: ../../include/openssl/ossl_typ.h ../../include/openssl/safestack.h
ui_util.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
ui_util.o: ../../include/openssl/ui.h c:\mingw\include\_mingw.h
ui_util.o: c:\mingw\include\msvcrtver.h c:\mingw\include\sdkddkver.h
ui_util.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
ui_util.o: c:\mingw\include\string.h c:\mingw\include\strings.h
ui_util.o: c:\mingw\include\sys/types.h c:\mingw\include\w32api.h
ui_util.o: c:\mingw\include\wchar.h
ui_util.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
ui_util.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h ui_locl.h ui_util.c
