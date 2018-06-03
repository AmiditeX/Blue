#
# OpenSSL/crypto/buffer/Makefile
#

DIR=	buffer
TOP=	../..
CC=	cc
INCLUDES= -I.. -I$(TOP) -I../../include
CFLAG=-g
MAKEFILE=	Makefile
AR=		ar r

CFLAGS= $(INCLUDES) $(CFLAG)

GENERAL=Makefile
TEST=
APPS=

LIB=$(TOP)/libcrypto.a
LIBSRC= buffer.c buf_str.c buf_err.c
LIBOBJ= buffer.o buf_str.o buf_err.o

SRC= $(LIBSRC)

EXHEADER= buffer.h
HEADER=	$(EXHEADER)

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
	rm -f *.o *.obj lib tags core .pure .nfs* *.old *.bak fluff

# DO NOT DELETE THIS LINE -- make depend depends on it.

buf_err.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
buf_err.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
buf_err.o: ../../include/openssl/err.h ../../include/openssl/lhash.h
buf_err.o: ../../include/openssl/opensslconf.h ../../include/openssl/opensslv.h
buf_err.o: ../../include/openssl/ossl_typ.h ../../include/openssl/safestack.h
buf_err.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
buf_err.o: buf_err.c c:\mingw\include\_mingw.h c:\mingw\include\errno.h
buf_err.o: c:\mingw\include\msvcrtver.h c:\mingw\include\sdkddkver.h
buf_err.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
buf_err.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
buf_err.o: c:\mingw\include\w32api.h
buf_err.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
buf_err.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h
buf_str.o: ../../e_os.h ../../include/openssl/bio.h
buf_str.o: ../../include/openssl/buffer.h ../../include/openssl/crypto.h
buf_str.o: ../../include/openssl/e_os2.h ../../include/openssl/err.h
buf_str.o: ../../include/openssl/lhash.h ../../include/openssl/opensslconf.h
buf_str.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
buf_str.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
buf_str.o: ../../include/openssl/symhacks.h ../../ms/applink.c
buf_str.o: ../../ms/uplink.h ../cryptlib.h buf_str.c c:\mingw\include\_mingw.h
buf_str.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
buf_str.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
buf_str.o: c:\mingw\include\io.h c:\mingw\include\limits.h
buf_str.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
buf_str.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
buf_str.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
buf_str.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
buf_str.o: c:\mingw\include\string.h c:\mingw\include\strings.h
buf_str.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
buf_str.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
buf_str.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
buf_str.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
buf_str.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
buf_str.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
buf_str.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
buf_str.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
buf_str.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
buf_str.o: c:\mingw\include\ws2tcpip.h
buf_str.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
buf_str.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h
buffer.o: ../../e_os.h ../../include/openssl/bio.h
buffer.o: ../../include/openssl/buffer.h ../../include/openssl/crypto.h
buffer.o: ../../include/openssl/e_os2.h ../../include/openssl/err.h
buffer.o: ../../include/openssl/lhash.h ../../include/openssl/opensslconf.h
buffer.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
buffer.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
buffer.o: ../../include/openssl/symhacks.h ../../ms/applink.c ../../ms/uplink.h
buffer.o: ../cryptlib.h buffer.c c:\mingw\include\_mingw.h
buffer.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
buffer.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
buffer.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
buffer.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
buffer.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
buffer.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
buffer.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
buffer.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
buffer.o: c:\mingw\include\sys\types.h c:\mingw\include\w32api.h
buffer.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
buffer.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
buffer.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
buffer.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
buffer.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
buffer.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
buffer.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
buffer.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
buffer.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
buffer.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h
